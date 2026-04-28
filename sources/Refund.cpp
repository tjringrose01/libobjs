/**
 *  Refund.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the Refund model.
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
 *  - Refund applicability is based on invoice number match.
 */

#include "Refund.hpp"

#include "Invoice.hpp"

/** @brief Construct a default refund. */
Refund::Refund()
    : refundNo(""),
      invoiceNo(""),
      paymentReferenceId(""),
      amount(CurrencyAmount(0)),
      refundDate(Dt()),
      reason("") {}

/** @brief Construct a refund with explicit values. */
Refund::Refund(const std::string& refundNo,
               const std::string& invoiceNo,
               const std::string& paymentReferenceId,
               const CurrencyAmount& amount,
               const Dt& refundDate,
               const std::string& reason)
    : refundNo(refundNo),
      invoiceNo(invoiceNo),
      paymentReferenceId(paymentReferenceId),
      amount(amount),
      refundDate(refundDate),
      reason(reason) {}

/** @brief Get refund number. */
std::string Refund::getRefundNo() const { return refundNo; }

/** @brief Get invoice number. */
std::string Refund::getInvoiceNo() const { return invoiceNo; }

/** @brief Get payment reference identifier. */
std::string Refund::getPaymentReferenceId() const { return paymentReferenceId; }

/** @brief Get refund amount. */
CurrencyAmount Refund::getAmount() const { return amount; }

/** @brief Get refund date. */
Dt Refund::getRefundDate() const { return refundDate; }

/** @brief Get refund reason. */
std::string Refund::getReason() const { return reason; }

/** @brief Return true when refund invoice number matches invoice. */
bool Refund::appliesToInvoice(const Invoice& invoice) const {
    return invoiceNo == invoice.getInvoiceNo();
}

/** @brief Convert this refund to a human-readable string. */
std::string Refund::to_string() const {
    return "refundNo=" + refundNo +
           "; invoiceNo=" + invoiceNo +
           "; paymentReferenceId=" + paymentReferenceId +
           "; amount=" + amount.to_string() +
           "; refundDate=" + refundDate.to_string() +
           "; reason=" + reason;
}

/** @brief Compare two refund values. */
bool Refund::operator==(const Refund& other) const {
    return refundNo == other.refundNo &&
           invoiceNo == other.invoiceNo &&
           paymentReferenceId == other.paymentReferenceId &&
           amount == other.amount &&
           refundDate == other.refundDate &&
           reason == other.reason;
}

/** @brief Stream a refund value. */
std::ostream& operator<<(std::ostream& os, const Refund& refund) {
    os << refund.to_string();
    return os;
}
