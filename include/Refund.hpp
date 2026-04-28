/**
 *  Refund.hpp - Refund Class Definition.
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

#ifndef LIBOBJS_REFUND_HPP
#define LIBOBJS_REFUND_HPP

#include <ostream>
#include <string>
#include "CurrencyAmount.hpp"
#include "Dt.hpp"

class Invoice;

/**
 * Represents a refund event against an invoice or payment.
 */
/**
 * @brief Refund model.
 */
class Refund {
private:
    std::string refundNo;
    std::string invoiceNo;
    std::string paymentReferenceId;
    CurrencyAmount amount;
    Dt refundDate;
    std::string reason;

public:
    /**
     * Construct default refund.
     */
    Refund();

    /**
     * Construct refund.
     *
     * @param refundNo Refund ID.
     * @param invoiceNo Invoice number.
     * @param paymentReferenceId Payment reference.
     * @param amount Refund amount.
     * @param refundDate Refund date.
     * @param reason Refund reason.
     */
    Refund(const std::string& refundNo,
           const std::string& invoiceNo,
           const std::string& paymentReferenceId,
           const CurrencyAmount& amount,
           const Dt& refundDate,
           const std::string& reason);

    /**
     * Get refund number.
     *
     * @return Refund number.
     */
    std::string getRefundNo() const;

    /**
     * Get invoice number.
     *
     * @return Invoice number.
     */
    std::string getInvoiceNo() const;

    /**
     * Get payment reference.
     *
     * @return Payment reference.
     */
    std::string getPaymentReferenceId() const;

    /**
     * Get refund amount.
     *
     * @return Refund amount.
     */
    CurrencyAmount getAmount() const;

    /**
     * Get refund date.
     *
     * @return Refund date.
     */
    Dt getRefundDate() const;

    /**
     * Get reason.
     *
     * @return Reason text.
     */
    std::string getReason() const;

    /**
     * True when refund invoice number matches given invoice.
     *
     * @param invoice Invoice to compare.
     * @return Match status.
     */
    bool appliesToInvoice(const Invoice& invoice) const;

    /**
     * Convert refund to text.
     *
     * @return String representation.
     */
    std::string to_string() const;

    /**
     * Compare refunds.
     *
     * @param other Other refund.
     * @return True when fields match.
     */
    bool operator==(const Refund& other) const;

    /**
     * Stream refund.
     *
     * @param os Output stream.
     * @param refund Refund object.
     * @return Output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Refund& refund);
};

#endif  // LIBOBJS_REFUND_HPP
