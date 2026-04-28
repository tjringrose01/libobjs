/**
 *  PaymentSchedule.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the PaymentSchedule model.
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
 *  - Remaining balance only counts payments that match schedule invoice number.
 */

#include "PaymentSchedule.hpp"

/** @brief Construct a default payment schedule. */
PaymentSchedule::PaymentSchedule() : invoiceNo(""), dueDates(), dueAmounts(), autoPayEnabled(false) {}

/** @brief Construct a payment schedule for a specific invoice. */
PaymentSchedule::PaymentSchedule(const std::string& invoiceNo)
    : invoiceNo(invoiceNo), dueDates(), dueAmounts(), autoPayEnabled(false) {}

/** @brief Get invoice number. */
std::string PaymentSchedule::getInvoiceNo() const { return invoiceNo; }

/** @brief Set invoice number. */
void PaymentSchedule::setInvoiceNo(const std::string& invoiceNo) { this->invoiceNo = invoiceNo; }

/** @brief Get due dates list. */
std::vector<Dt> PaymentSchedule::getDueDates() const { return dueDates; }

/** @brief Get due amounts list. */
std::vector<CurrencyAmount> PaymentSchedule::getDueAmounts() const { return dueAmounts; }

/** @brief Get auto-pay enabled flag. */
bool PaymentSchedule::isAutoPayEnabled() const { return autoPayEnabled; }

/** @brief Set auto-pay enabled flag. */
void PaymentSchedule::setAutoPayEnabled(bool enabled) { autoPayEnabled = enabled; }

/** @brief Add one installment date and amount. */
void PaymentSchedule::addInstallment(const Dt& dueDate, const CurrencyAmount& dueAmount) {
    dueDates.push_back(dueDate);
    dueAmounts.push_back(dueAmount);
}

/** @brief Get number of installments. */
std::size_t PaymentSchedule::getInstallmentCount() const { return dueAmounts.size(); }

/** @brief Calculate total scheduled amount. */
CurrencyAmount PaymentSchedule::getTotalScheduled() const {
    CurrencyAmount total("USD", 0);
    if (!dueAmounts.empty()) {
        total = CurrencyAmount(dueAmounts[0].getCurrencyCode(), 0);
    }

    for (const CurrencyAmount& amount : dueAmounts) {
        total = total + amount;
    }

    return total;
}

/** @brief Return true when scheduled total equals expected total. */
bool PaymentSchedule::isBalancedAgainst(const CurrencyAmount& expectedTotal) const {
    return getTotalScheduled() == expectedTotal;
}

/** @brief Calculate remaining amount after invoice-matching payments. */
CurrencyAmount PaymentSchedule::remainingAfterPayments(const std::vector<Payment>& payments) const {
    CurrencyAmount paid("USD", 0);
    const CurrencyAmount scheduled = getTotalScheduled();
    if (scheduled.getCurrencyCode() != "") {
        paid = CurrencyAmount(scheduled.getCurrencyCode(), 0);
    }

    for (const Payment& payment : payments) {
        if (payment.getInvoiceNo() == invoiceNo) {
            paid = paid + payment.getAmount();
        }
    }

    if (paid >= scheduled) {
        return CurrencyAmount(scheduled.getCurrencyCode(), 0);
    }

    return scheduled - paid;
}

/** @brief Convert this payment schedule to a human-readable string. */
std::string PaymentSchedule::to_string() const {
    return "invoiceNo=" + invoiceNo +
           "; installmentCount=" + std::to_string(dueAmounts.size()) +
           "; totalScheduled=" + getTotalScheduled().to_string() +
           "; autoPayEnabled=" + std::string(autoPayEnabled ? "true" : "false");
}

/** @brief Compare two payment schedule values. */
bool PaymentSchedule::operator==(const PaymentSchedule& other) const {
    return invoiceNo == other.invoiceNo &&
           dueDates == other.dueDates &&
           dueAmounts == other.dueAmounts &&
           autoPayEnabled == other.autoPayEnabled;
}

/** @brief Stream a payment schedule value. */
std::ostream& operator<<(std::ostream& os, const PaymentSchedule& schedule) {
    os << schedule.to_string();
    return os;
}
