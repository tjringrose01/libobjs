/**
 *  Receipt.hpp - Receipt Class Definition.
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
 *  along with libobjs.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef LIBOBJS_RECEIPT_HPP
#define LIBOBJS_RECEIPT_HPP

#include <ostream>
#include <string>
#include "CurrencyAmount.hpp"
#include "Dt.hpp"
#include "Payment.hpp"

/**
 * Represents a payment receipt tied to an invoice.
 */
/**
 * @brief Receipt model.
 */
class Receipt {
private:
    std::string receiptNo;
    std::string invoiceNo;
    Dt issuedDate;
    CurrencyAmount amountReceived;
    PaymentMethod method;
    std::string paymentReferenceId;

public:
    /**
     * Construct default receipt.
     */
    Receipt();

    /**
     * Construct receipt.
     *
     * @param receiptNo Receipt number.
     * @param invoiceNo Invoice number.
     * @param issuedDate Receipt date.
     * @param amountReceived Amount received.
     * @param method Payment method.
     * @param paymentReferenceId Payment reference.
     */
    Receipt(const std::string& receiptNo,
            const std::string& invoiceNo,
            const Dt& issuedDate,
            const CurrencyAmount& amountReceived,
            PaymentMethod method,
            const std::string& paymentReferenceId);

    /**
     * Get receipt number.
     *
     * @return Receipt number.
     */
    std::string getReceiptNo() const;

    /**
     * Get invoice number.
     *
     * @return Invoice number.
     */
    std::string getInvoiceNo() const;

    /**
     * Get issued date.
     *
     * @return Issued date.
     */
    Dt getIssuedDate() const;

    /**
     * Get amount received.
     *
     * @return Amount received.
     */
    CurrencyAmount getAmountReceived() const;

    /**
     * Get payment method.
     *
     * @return Payment method.
     */
    PaymentMethod getMethod() const;

    /**
     * Get payment reference.
     *
     * @return Payment reference ID.
     */
    std::string getPaymentReferenceId() const;

    /**
     * Convert receipt to text.
     *
     * @return String representation.
     */
    std::string to_string() const;

    /**
     * Compare receipts.
     *
     * @param other Other receipt.
     * @return True when all fields match.
     */
    bool operator==(const Receipt& other) const;

    /**
     * Stream receipt.
     *
     * @param os Output stream.
     * @param receipt Receipt object.
     * @return Output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Receipt& receipt);
};

#endif  // LIBOBJS_RECEIPT_HPP
