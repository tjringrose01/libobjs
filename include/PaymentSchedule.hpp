/**
 *  PaymentSchedule.hpp - PaymentSchedule Class Definition.
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

#ifndef LIBOBJS_PAYMENT_SCHEDULE_HPP
#define LIBOBJS_PAYMENT_SCHEDULE_HPP

#include <ostream>
#include <string>
#include <vector>
#include "CurrencyAmount.hpp"
#include "Dt.hpp"
#include "Payment.hpp"

/**
 * Represents an installment schedule for an invoice.
 */
/**
 * @brief PaymentSchedule model.
 */
class PaymentSchedule {
private:
    std::string invoiceNo;
    std::vector<Dt> dueDates;
    std::vector<CurrencyAmount> dueAmounts;
    bool autoPayEnabled;

public:
    /**
     * Construct default schedule.
     */
    PaymentSchedule();

    /**
     * Construct schedule with invoice number.
     *
     * @param invoiceNo Invoice number.
     */
    explicit PaymentSchedule(const std::string& invoiceNo);

    /**
     * Get invoice number.
     *
     * @return Invoice number.
     */
    std::string getInvoiceNo() const;

    /**
     * Set invoice number.
     *
     * @param invoiceNo Invoice number.
     */
    void setInvoiceNo(const std::string& invoiceNo);

    /**
     * Get due dates.
     *
     * @return Due dates.
     */
    std::vector<Dt> getDueDates() const;

    /**
     * Get due amounts.
     *
     * @return Due amounts.
     */
    std::vector<CurrencyAmount> getDueAmounts() const;

    /**
     * Get auto-pay state.
     *
     * @return True when auto-pay is enabled.
     */
    bool isAutoPayEnabled() const;

    /**
     * Enable or disable auto-pay.
     *
     * @param enabled Auto-pay state.
     */
    void setAutoPayEnabled(bool enabled);

    /**
     * Add installment.
     *
     * @param dueDate Installment date.
     * @param dueAmount Installment amount.
     */
    void addInstallment(const Dt& dueDate, const CurrencyAmount& dueAmount);

    /**
     * Number of installments.
     *
     * @return Installment count.
     */
    std::size_t getInstallmentCount() const;

    /**
     * Total scheduled amount.
     *
     * @return Sum of due amounts.
     */
    CurrencyAmount getTotalScheduled() const;

    /**
     * Compare schedule total with expected total.
     *
     * @param expectedTotal Expected amount.
     * @return True if totals match.
     */
    bool isBalancedAgainst(const CurrencyAmount& expectedTotal) const;

    /**
     * Remaining schedule balance after payments for this invoice.
     *
     * @param payments Payments to apply.
     * @return Remaining amount (never negative).
     */
    CurrencyAmount remainingAfterPayments(const std::vector<Payment>& payments) const;

    /**
     * Convert schedule to text.
     *
     * @return String representation.
     */
    std::string to_string() const;

    /**
     * Compare schedules.
     *
     * @param other Other schedule.
     * @return True when fields match.
     */
    bool operator==(const PaymentSchedule& other) const;

    /**
     * Stream schedule.
     *
     * @param os Output stream.
     * @param schedule Schedule object.
     * @return Output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const PaymentSchedule& schedule);
};

#endif  // LIBOBJS_PAYMENT_SCHEDULE_HPP
