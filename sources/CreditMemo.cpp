/**
 *  CreditMemo.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the CreditMemo model.
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
 *  - Remaining credit cannot become negative.
 */

#include "CreditMemo.hpp"

/** @brief Construct a default credit memo. */
CreditMemo::CreditMemo()
    : memoNo(""), invoiceNo(""), issueDate(Dt()), amount(CurrencyAmount(0)), reason(""), applied(false) {}

/** @brief Construct a credit memo with explicit values. */
CreditMemo::CreditMemo(const std::string& memoNo,
                       const std::string& invoiceNo,
                       const Dt& issueDate,
                       const CurrencyAmount& amount,
                       const std::string& reason)
    : memoNo(memoNo), invoiceNo(invoiceNo), issueDate(issueDate), amount(amount), reason(reason), applied(false) {}

/** @brief Get memo number. */
std::string CreditMemo::getMemoNo() const { return memoNo; }

/** @brief Get invoice number. */
std::string CreditMemo::getInvoiceNo() const { return invoiceNo; }

/** @brief Get issue date. */
Dt CreditMemo::getIssueDate() const { return issueDate; }

/** @brief Get credit amount. */
CurrencyAmount CreditMemo::getAmount() const { return amount; }

/** @brief Get memo reason. */
std::string CreditMemo::getReason() const { return reason; }

/** @brief Get whether memo is applied. */
bool CreditMemo::isApplied() const { return applied; }

/** @brief Mark credit memo as applied. */
void CreditMemo::apply() { applied = true; }

/** @brief Mark credit memo as unapplied. */
void CreditMemo::unapply() { applied = false; }

/** @brief Return remaining credit after amount usage. */
CurrencyAmount CreditMemo::remainingCreditAfter(const CurrencyAmount& usedAmount) const {
    if (usedAmount >= amount) {
        return CurrencyAmount(amount.getCurrencyCode(), 0);
    }

    return amount - usedAmount;
}

/** @brief Convert this credit memo to a human-readable string. */
std::string CreditMemo::to_string() const {
    return "memoNo=" + memoNo +
           "; invoiceNo=" + invoiceNo +
           "; issueDate=" + issueDate.to_string() +
           "; amount=" + amount.to_string() +
           "; reason=" + reason +
           "; applied=" + (applied ? "true" : "false");
}

/** @brief Compare two credit memo values. */
bool CreditMemo::operator==(const CreditMemo& other) const {
    return memoNo == other.memoNo &&
           invoiceNo == other.invoiceNo &&
           issueDate == other.issueDate &&
           amount == other.amount &&
           reason == other.reason &&
           applied == other.applied;
}

/** @brief Stream a credit memo value. */
std::ostream& operator<<(std::ostream& os, const CreditMemo& memo) {
    os << memo.to_string();
    return os;
}
