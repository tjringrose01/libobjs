/**
 *  Payment_gtest.cpp - Payment Class Tests
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

#include <sstream>
#include <stdexcept>

#include "CurrencyAmount.hpp"
#include "Dt.hpp"
#include "Invoice.hpp"
#include "Payment.hpp"

namespace {

Invoice makeInvoice(const std::string& invoiceNo, const CurrencyAmount& total) {
    Invoice invoice;
    invoice.setInvoiceNo(invoiceNo);
    invoice.setTotal(total);
    return invoice;
}

}  // namespace

TEST(PaymentTest, DefaultConstructor) {
    const Payment payment;

    EXPECT_EQ("", payment.getInvoiceNo());
    EXPECT_EQ(CurrencyAmount(0), payment.getAmount());
    EXPECT_EQ(Dt(), payment.getPaymentDate());
    EXPECT_EQ(PaymentMethod::UNKNOWN, payment.getMethod());
    EXPECT_EQ("", payment.getReferenceId());
    EXPECT_EQ("", payment.getNotes());
}

TEST(PaymentTest, ConstructorAndEquality) {
    const Payment payment("INV-001",
                          CurrencyAmount("USD", 100.50),
                          Dt(2026, 4, 28),
                          PaymentMethod::ACH,
                          "TXN-123",
                          "Paid in full");

    const Payment same("INV-001",
                       CurrencyAmount("USD", 100.50),
                       Dt(2026, 4, 28),
                       PaymentMethod::ACH,
                       "TXN-123",
                       "Paid in full");

    EXPECT_EQ("INV-001", payment.getInvoiceNo());
    EXPECT_EQ(CurrencyAmount("USD", 100.50), payment.getAmount());
    EXPECT_EQ(Dt(2026, 4, 28), payment.getPaymentDate());
    EXPECT_EQ(PaymentMethod::ACH, payment.getMethod());
    EXPECT_EQ("TXN-123", payment.getReferenceId());
    EXPECT_EQ("Paid in full", payment.getNotes());
    EXPECT_TRUE(payment == same);
}

TEST(PaymentTest, PartialOverpaymentAndRemainingBalance) {
    const Invoice invoice = makeInvoice("INV-200", CurrencyAmount("USD", 250.00));

    const Payment partial("INV-200",
                          CurrencyAmount("USD", 100.00),
                          Dt(2026, 4, 28),
                          PaymentMethod::CARD,
                          "AUTH-100",
                          "");

    EXPECT_TRUE(partial.isPartialFor(invoice));
    EXPECT_FALSE(partial.isOverpaymentFor(invoice));
    EXPECT_EQ(CurrencyAmount("USD", 150.00), partial.remainingBalance(invoice));

    const Payment exact("INV-200",
                        CurrencyAmount("USD", 250.00),
                        Dt(2026, 4, 28),
                        PaymentMethod::WIRE,
                        "WIRE-200",
                        "");

    EXPECT_FALSE(exact.isPartialFor(invoice));
    EXPECT_FALSE(exact.isOverpaymentFor(invoice));
    EXPECT_EQ(CurrencyAmount("USD", 0.00), exact.remainingBalance(invoice));

    const Payment overpay("INV-200",
                          CurrencyAmount("USD", 300.00),
                          Dt(2026, 4, 28),
                          PaymentMethod::CHECK,
                          "CHK-300",
                          "");

    EXPECT_FALSE(overpay.isPartialFor(invoice));
    EXPECT_TRUE(overpay.isOverpaymentFor(invoice));
    EXPECT_EQ(CurrencyAmount("USD", 0.00), overpay.remainingBalance(invoice));
}

TEST(PaymentTest, InvoiceNumberMismatchThrows) {
    const Invoice invoice = makeInvoice("INV-777", CurrencyAmount("USD", 50.00));
    const Payment payment("INV-999",
                          CurrencyAmount("USD", 10.00),
                          Dt(2026, 4, 28),
                          PaymentMethod::CASH,
                          "RCPT-1",
                          "");

    EXPECT_THROW(payment.isPartialFor(invoice), std::invalid_argument);
    EXPECT_THROW(payment.isOverpaymentFor(invoice), std::invalid_argument);
    EXPECT_THROW(payment.remainingBalance(invoice), std::invalid_argument);
}

TEST(PaymentTest, MethodLabelAndOutput) {
    EXPECT_EQ("ACH", Payment::paymentMethodToString(PaymentMethod::ACH));
    EXPECT_EQ("UNKNOWN", Payment::paymentMethodToString(PaymentMethod::UNKNOWN));

    const Payment payment("INV-OUT",
                          CurrencyAmount("USD", 42.00),
                          Dt(2026, 4, 28),
                          PaymentMethod::ACH,
                          "TXN-OUT",
                          "memo");

    const std::string text = payment.to_string();
    EXPECT_NE(std::string::npos, text.find("invoiceNo=INV-OUT"));
    EXPECT_NE(std::string::npos, text.find("method=ACH"));
    EXPECT_NE(std::string::npos, text.find("amount=42.00 USD"));

    std::stringstream ss;
    ss << payment;
    EXPECT_EQ(text, ss.str());
}
