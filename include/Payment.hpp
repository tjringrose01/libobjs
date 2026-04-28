/**
 *  Payment.hpp - Payment Class Definition.
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

#ifndef LIBOBJS_PAYMENT_HPP
#define LIBOBJS_PAYMENT_HPP

#include <ostream>
#include <string>
#include "CurrencyAmount.hpp"
#include "Dt.hpp"

class Invoice;

/**
 * Supported payment methods for invoice settlement.
 */
/**
 * @brief PaymentMethod enumeration.
 */
enum class PaymentMethod {
    UNKNOWN = 0,
    ACH = 1,
    CHECK = 2,
    CARD = 3,
    WIRE = 4,
    CASH = 5
};

/**
 * Represents a payment applied to an invoice.
 */
/**
 * @brief Payment model.
 */
class Payment {
private:
    std::string invoiceNo;
    CurrencyAmount amount;
    Dt paymentDate;
    PaymentMethod method;
    std::string referenceId;
    std::string notes;

public:
    /**
     * Construct an empty payment.
     */
    Payment();

    /**
     * Construct a payment.
     *
     * @param invoiceNo Invoice number this payment applies to.
     * @param amount Payment amount.
     * @param paymentDate Date the payment was made.
     * @param method Payment method.
     * @param referenceId External reference (for example check number or txn id).
     * @param notes Optional notes.
     */
    Payment(const std::string& invoiceNo,
            const CurrencyAmount& amount,
            const Dt& paymentDate,
            PaymentMethod method,
            const std::string& referenceId,
            const std::string& notes);

    /**
     * Get invoice number.
     *
     * @return Invoice number.
     */
    std::string getInvoiceNo() const;

    /**
     * Get payment amount.
     *
     * @return Payment amount.
     */
    CurrencyAmount getAmount() const;

    /**
     * Get payment date.
     *
     * @return Payment date.
     */
    Dt getPaymentDate() const;

    /**
     * Get payment method.
     *
     * @return Payment method enum value.
     */
    PaymentMethod getMethod() const;

    /**
     * Get payment reference ID.
     *
     * @return Reference ID.
     */
    std::string getReferenceId() const;

    /**
     * Get notes.
     *
     * @return Notes text.
     */
    std::string getNotes() const;

    /**
     * Set invoice number.
     *
     * @param invoiceNo Invoice number.
     */
    void setInvoiceNo(const std::string& invoiceNo);

    /**
     * Set payment amount.
     *
     * @param amount Payment amount.
     */
    void setAmount(const CurrencyAmount& amount);

    /**
     * Set payment date.
     *
     * @param paymentDate Payment date.
     */
    void setPaymentDate(const Dt& paymentDate);

    /**
     * Set payment method.
     *
     * @param method Payment method.
     */
    void setMethod(PaymentMethod method);

    /**
     * Set payment reference ID.
     *
     * @param referenceId Reference ID.
     */
    void setReferenceId(const std::string& referenceId);

    /**
     * Set notes.
     *
     * @param notes Notes text.
     */
    void setNotes(const std::string& notes);

    /**
     * Determine if this payment is a partial payment for the given invoice.
     *
     * @param invoice Invoice to compare against.
     * @return True if payment amount is less than invoice total.
     */
    bool isPartialFor(const Invoice& invoice) const;

    /**
     * Determine if this payment overpays the given invoice.
     *
     * @param invoice Invoice to compare against.
     * @return True if payment amount is greater than invoice total.
     */
    bool isOverpaymentFor(const Invoice& invoice) const;

    /**
     * Calculate invoice balance remaining after this payment.
     *
     * @param invoice Invoice to compare against.
     * @return Remaining balance (never negative).
     */
    CurrencyAmount remainingBalance(const Invoice& invoice) const;

    /**
     * Convert payment to text.
     *
     * @return String representation of payment.
     */
    std::string to_string() const;

    /**
     * Convert a payment method enum to text.
     *
     * @param method Payment method.
     * @return Method label.
     */
    static std::string paymentMethodToString(PaymentMethod method);

    /**
     * Compare two Payment objects.
     *
     * @param other Other payment.
     * @return True when all fields match.
     */
    bool operator==(const Payment& other) const;

    /**
     * Stream payment.
     *
     * @param os Output stream.
     * @param payment Payment object.
     * @return Output stream reference.
     */
    friend std::ostream& operator<<(std::ostream& os, const Payment& payment);
};

#endif  // LIBOBJS_PAYMENT_HPP
