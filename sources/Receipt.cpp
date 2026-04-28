/**
 *  Receipt.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the Receipt model.
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
 *  - Receipt captures immutable payment confirmation details.
 */

#include "Receipt.hpp"

/** @brief Construct a default receipt. */
Receipt::Receipt()
    : receiptNo(""),
      invoiceNo(""),
      issuedDate(Dt()),
      amountReceived(CurrencyAmount(0)),
      method(PaymentMethod::UNKNOWN),
      paymentReferenceId("") {}

/** @brief Construct a receipt with explicit values. */
Receipt::Receipt(const std::string& receiptNo,
                 const std::string& invoiceNo,
                 const Dt& issuedDate,
                 const CurrencyAmount& amountReceived,
                 PaymentMethod method,
                 const std::string& paymentReferenceId)
    : receiptNo(receiptNo),
      invoiceNo(invoiceNo),
      issuedDate(issuedDate),
      amountReceived(amountReceived),
      method(method),
      paymentReferenceId(paymentReferenceId) {}

/** @brief Get receipt number. */
std::string Receipt::getReceiptNo() const { return receiptNo; }

/** @brief Get invoice number. */
std::string Receipt::getInvoiceNo() const { return invoiceNo; }

/** @brief Get issued date. */
Dt Receipt::getIssuedDate() const { return issuedDate; }

/** @brief Get amount received. */
CurrencyAmount Receipt::getAmountReceived() const { return amountReceived; }

/** @brief Get payment method. */
PaymentMethod Receipt::getMethod() const { return method; }

/** @brief Get payment reference identifier. */
std::string Receipt::getPaymentReferenceId() const { return paymentReferenceId; }

/** @brief Convert this receipt to a human-readable string. */
std::string Receipt::to_string() const {
    return "receiptNo=" + receiptNo +
           "; invoiceNo=" + invoiceNo +
           "; issuedDate=" + issuedDate.to_string() +
           "; amountReceived=" + amountReceived.to_string() +
           "; method=" + Payment::paymentMethodToString(method) +
           "; paymentReferenceId=" + paymentReferenceId;
}

/** @brief Compare two receipt values. */
bool Receipt::operator==(const Receipt& other) const {
    return receiptNo == other.receiptNo &&
           invoiceNo == other.invoiceNo &&
           issuedDate == other.issuedDate &&
           amountReceived == other.amountReceived &&
           method == other.method &&
           paymentReferenceId == other.paymentReferenceId;
}

/** @brief Stream a receipt value. */
std::ostream& operator<<(std::ostream& os, const Receipt& receipt) {
    os << receipt.to_string();
    return os;
}
