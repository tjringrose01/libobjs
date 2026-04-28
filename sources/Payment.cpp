/**
 *  Payment.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the Payment model.
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
 *  Domain Rules:
 *  - Invoice comparisons require matching invoice numbers.
 *  - Remaining balance is clamped at zero.
 */

#include "Payment.hpp"

#include <stdexcept>

#include "Invoice.hpp"

/** @brief Validate this payment belongs to the same invoice number. */
static void ensure_invoice_match(const std::string& paymentInvoiceNo, const Invoice& invoice) {
    if (paymentInvoiceNo != invoice.getInvoiceNo()) {
        throw std::invalid_argument("ERROR: payment invoice number does not match invoice");
    }
}

/** @brief Construct a default payment value. */
Payment::Payment()
    : invoiceNo(""),
      amount(CurrencyAmount(0)),
      paymentDate(Dt()),
      method(PaymentMethod::UNKNOWN),
      referenceId(""),
      notes("") {}

/** @brief Construct a payment value with explicit fields. */
Payment::Payment(const std::string& invoiceNo,
                 const CurrencyAmount& amount,
                 const Dt& paymentDate,
                 PaymentMethod method,
                 const std::string& referenceId,
                 const std::string& notes)
    : invoiceNo(invoiceNo),
      amount(amount),
      paymentDate(paymentDate),
      method(method),
      referenceId(referenceId),
      notes(notes) {}

/** @brief Get invoice number. */
std::string Payment::getInvoiceNo() const { return invoiceNo; }

/** @brief Get payment amount. */
CurrencyAmount Payment::getAmount() const { return amount; }

/** @brief Get payment date. */
Dt Payment::getPaymentDate() const { return paymentDate; }

/** @brief Get payment method. */
PaymentMethod Payment::getMethod() const { return method; }

/** @brief Get external reference identifier. */
std::string Payment::getReferenceId() const { return referenceId; }

/** @brief Get payment notes. */
std::string Payment::getNotes() const { return notes; }

/** @brief Set invoice number. */
void Payment::setInvoiceNo(const std::string& invoiceNo) { this->invoiceNo = invoiceNo; }

/** @brief Set payment amount. */
void Payment::setAmount(const CurrencyAmount& amount) { this->amount = amount; }

/** @brief Set payment date. */
void Payment::setPaymentDate(const Dt& paymentDate) { this->paymentDate = paymentDate; }

/** @brief Set payment method. */
void Payment::setMethod(PaymentMethod method) { this->method = method; }

/** @brief Set external reference identifier. */
void Payment::setReferenceId(const std::string& referenceId) { this->referenceId = referenceId; }

/** @brief Set payment notes text. */
void Payment::setNotes(const std::string& notes) { this->notes = notes; }

/** @brief Return true when payment amount is less than invoice total. */
bool Payment::isPartialFor(const Invoice& invoice) const {
    ensure_invoice_match(invoiceNo, invoice);
    return amount < invoice.getTotal();
}

/** @brief Return true when payment amount is greater than invoice total. */
bool Payment::isOverpaymentFor(const Invoice& invoice) const {
    ensure_invoice_match(invoiceNo, invoice);
    return amount > invoice.getTotal();
}

/** @brief Return remaining invoice balance after this payment. */
CurrencyAmount Payment::remainingBalance(const Invoice& invoice) const {
    ensure_invoice_match(invoiceNo, invoice);

    if (amount >= invoice.getTotal()) {
        return CurrencyAmount(invoice.getTotal().getCurrencyCode(), 0);
    }

    return invoice.getTotal() - amount;
}

/** @brief Convert payment method enum to text label. */
std::string Payment::paymentMethodToString(PaymentMethod method) {
    switch (method) {
        case PaymentMethod::ACH:
            return "ACH";
        case PaymentMethod::CHECK:
            return "CHECK";
        case PaymentMethod::CARD:
            return "CARD";
        case PaymentMethod::WIRE:
            return "WIRE";
        case PaymentMethod::CASH:
            return "CASH";
        case PaymentMethod::UNKNOWN:
        default:
            return "UNKNOWN";
    }
}

/** @brief Convert this payment to a human-readable string. */
std::string Payment::to_string() const {
    return "invoiceNo=" + invoiceNo +
           "; amount=" + amount.to_string() +
           "; paymentDate=" + paymentDate.to_string() +
           "; method=" + paymentMethodToString(method) +
           "; referenceId=" + referenceId +
           "; notes=" + notes;
}

/** @brief Compare two payment values. */
bool Payment::operator==(const Payment& other) const {
    return invoiceNo == other.invoiceNo &&
           amount == other.amount &&
           paymentDate == other.paymentDate &&
           method == other.method &&
           referenceId == other.referenceId &&
           notes == other.notes;
}

/** @brief Stream a payment value. */
std::ostream& operator<<(std::ostream& os, const Payment& payment) {
    os << payment.to_string();
    return os;
}
