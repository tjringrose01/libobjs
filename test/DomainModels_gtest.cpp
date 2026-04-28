/**
 *  DomainModels_gtest.cpp - Extended Domain Model Tests
 *
 *  Copyright 2026 Timothy Ringrose
 *
 *  This file is part of libobjs.
 *
 *  libobjs is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  libobjs is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with libobjs. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <gtest/gtest.h>

#include <vector>

#include "BankAccount.hpp"
#include "CreditMemo.hpp"
#include "CurrencyAmount.hpp"
#include "Dt.hpp"
#include "Invoice.hpp"
#include "InvoiceWorkflow.hpp"
#include "LedgerEntry.hpp"
#include "Money.hpp"
#include "Payment.hpp"
#include "PaymentSchedule.hpp"
#include "PurchaseOrder.hpp"
#include "Quote.hpp"
#include "QuoteItem.hpp"
#include "Receipt.hpp"
#include "Refund.hpp"
#include "TaxProfile.hpp"
#include "TaxRule.hpp"

TEST(DomainModelsTest, QuoteAndQuoteItemRecalculateTotals) {
    Quote quote;
    quote.setQuoteNo("Q-1");
    quote.addLineItem(QuoteItem("widget", 2, CurrencyAmount("USD", 10.00)));
    quote.addLineItem(QuoteItem("service", 1, CurrencyAmount("USD", 15.00)));
    quote.setTaxes(CurrencyAmount("USD", 2.50));
    quote.setShipping(CurrencyAmount("USD", 5.00));

    EXPECT_EQ(CurrencyAmount("USD", 35.00), quote.getSubtotal());
    EXPECT_EQ(CurrencyAmount("USD", 42.50), quote.getTotal());
}

TEST(DomainModelsTest, TaxProfileCalculatesCompoundTaxes) {
    TaxProfile profile("US-SALES");
    profile.addRule(TaxRule("US-OH", "state", 0.05, false));
    profile.addRule(TaxRule("US-OH", "county", 0.02, true));

    const CurrencyAmount tax = profile.calculateTotalTax(CurrencyAmount("USD", 100.00));

    EXPECT_EQ(CurrencyAmount("USD", 7.10), tax);
    EXPECT_EQ(CurrencyAmount("USD", 107.10), profile.applyToNet(CurrencyAmount("USD", 100.00)));
}

TEST(DomainModelsTest, LedgerEntryValidationAndNet) {
    LedgerEntry debit("L1",
                      "INV-1",
                      Dt(2026, 4, 28),
                      LedgerEntryType::INVOICE_ISSUED,
                      CurrencyAmount("USD", 100.00),
                      CurrencyAmount("USD", 0.00),
                      "");

    LedgerEntry invalid("L2",
                        "INV-1",
                        Dt(2026, 4, 28),
                        LedgerEntryType::ADJUSTMENT,
                        CurrencyAmount("USD", 10.00),
                        CurrencyAmount("USD", 5.00),
                        "");

    EXPECT_TRUE(debit.isBalanced());
    EXPECT_EQ(CurrencyAmount("USD", 100.00), debit.netAmount());
    EXPECT_FALSE(invalid.isBalanced());
}

TEST(DomainModelsTest, RefundAndCreditMemoBehavior) {
    Invoice invoice;
    invoice.setInvoiceNo("INV-77");

    Refund refund("R-1",
                  "INV-77",
                  "TXN-1",
                  CurrencyAmount("USD", 20.00),
                  Dt(2026, 4, 28),
                  "duplicate payment");
    EXPECT_TRUE(refund.appliesToInvoice(invoice));

    CreditMemo memo("CM-1", "INV-77", Dt(2026, 4, 28), CurrencyAmount("USD", 50.00), "discount");
    EXPECT_FALSE(memo.isApplied());
    memo.apply();
    EXPECT_TRUE(memo.isApplied());
    EXPECT_EQ(CurrencyAmount("USD", 15.00), memo.remainingCreditAfter(CurrencyAmount("USD", 35.00)));
}

TEST(DomainModelsTest, PurchaseOrderTotals) {
    PurchaseOrder po;
    po.setPoNo("PO-9");
    po.addLineItem(QuoteItem("item-a", 3, CurrencyAmount("USD", 4.00)));
    po.addLineItem(QuoteItem("item-b", 2, CurrencyAmount("USD", 5.00)));

    EXPECT_EQ(CurrencyAmount("USD", 22.00), po.getTotal());
}

TEST(DomainModelsTest, BankAccountValidationAndMasking) {
    BankAccount account("Alice", "Bank", "123456789", "3210", BankAccountType::CHECKING);

    EXPECT_TRUE(BankAccount::isValidRoutingNumber("123456789"));
    EXPECT_FALSE(BankAccount::isValidRoutingNumber("1234A6789"));
    EXPECT_EQ("****3210", account.maskedAccountNumber());
}

TEST(DomainModelsTest, ReceiptAndMoneyBasics) {
    Receipt receipt("RCPT-1",
                    "INV-9",
                    Dt(2026, 4, 28),
                    CurrencyAmount("USD", 25.00),
                    PaymentMethod::CARD,
                    "AUTH-1");

    EXPECT_NE(std::string::npos, receipt.to_string().find("method=CARD"));

    Money m1 = Money::fromDouble("USD", 12.34);
    Money m2("USD", 66);
    EXPECT_EQ(Money("USD", 1300), m1 + m2);
}

TEST(DomainModelsTest, PaymentScheduleCalculations) {
    PaymentSchedule schedule("INV-500");
    schedule.addInstallment(Dt(2026, 5, 1), CurrencyAmount("USD", 50.00));
    schedule.addInstallment(Dt(2026, 6, 1), CurrencyAmount("USD", 50.00));

    std::vector<Payment> payments;
    payments.push_back(Payment("INV-500",
                               CurrencyAmount("USD", 40.00),
                               Dt(2026, 5, 1),
                               PaymentMethod::ACH,
                               "P-1",
                               ""));
    payments.push_back(Payment("INV-OTHER",
                               CurrencyAmount("USD", 99.00),
                               Dt(2026, 5, 1),
                               PaymentMethod::ACH,
                               "P-2",
                               ""));

    EXPECT_EQ(CurrencyAmount("USD", 100.00), schedule.getTotalScheduled());
    EXPECT_EQ(CurrencyAmount("USD", 60.00), schedule.remainingAfterPayments(payments));
}

TEST(DomainModelsTest, InvoiceWorkflowTransitions) {
    InvoiceWorkflow workflow("INV-88");

    EXPECT_EQ(InvoiceStatus::DRAFT, workflow.getStatus());
    EXPECT_TRUE(workflow.canTransitionTo(InvoiceStatus::ISSUED));
    EXPECT_FALSE(workflow.canTransitionTo(InvoiceStatus::PAID));

    workflow.transitionTo(InvoiceStatus::ISSUED, Dt(2026, 4, 28));
    workflow.transitionTo(InvoiceStatus::PARTIALLY_PAID, Dt(2026, 4, 29));
    workflow.transitionTo(InvoiceStatus::PAID, Dt(2026, 4, 30));

    EXPECT_EQ(InvoiceStatus::PAID, workflow.getStatus());
    EXPECT_FALSE(workflow.canTransitionTo(InvoiceStatus::VOIDED));
}
