/**
 *  CreditMemo.hpp - CreditMemo Class Definition.
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

#ifndef LIBOBJS_CREDIT_MEMO_HPP
#define LIBOBJS_CREDIT_MEMO_HPP

#include <ostream>
#include <string>
#include "CurrencyAmount.hpp"
#include "Dt.hpp"

/**
 * Represents a credit memo that can reduce invoice balance.
 */
/**
 * @brief CreditMemo model.
 */
class CreditMemo {
private:
    std::string memoNo;
    std::string invoiceNo;
    Dt issueDate;
    CurrencyAmount amount;
    std::string reason;
    bool applied;

public:
    /**
     * Construct default credit memo.
     */
    CreditMemo();

    /**
     * Construct credit memo.
     *
     * @param memoNo Memo number.
     * @param invoiceNo Invoice number.
     * @param issueDate Issue date.
     * @param amount Credit amount.
     * @param reason Memo reason.
     */
    CreditMemo(const std::string& memoNo,
               const std::string& invoiceNo,
               const Dt& issueDate,
               const CurrencyAmount& amount,
               const std::string& reason);

    /**
     * Get memo number.
     *
     * @return Memo number.
     */
    std::string getMemoNo() const;

    /**
     * Get invoice number.
     *
     * @return Invoice number.
     */
    std::string getInvoiceNo() const;

    /**
     * Get issue date.
     *
     * @return Issue date.
     */
    Dt getIssueDate() const;

    /**
     * Get amount.
     *
     * @return Credit amount.
     */
    CurrencyAmount getAmount() const;

    /**
     * Get reason.
     *
     * @return Reason text.
     */
    std::string getReason() const;

    /**
     * Get applied state.
     *
     * @return True when already applied.
     */
    bool isApplied() const;

    /**
     * Mark memo as applied.
     */
    void apply();

    /**
     * Mark memo as unapplied.
     */
    void unapply();

    /**
     * Calculate remaining credit after usage.
     *
     * @param usedAmount Consumed amount.
     * @return Remaining available credit (never negative).
     */
    CurrencyAmount remainingCreditAfter(const CurrencyAmount& usedAmount) const;

    /**
     * Convert credit memo to text.
     *
     * @return String representation.
     */
    std::string to_string() const;

    /**
     * Compare credit memos.
     *
     * @param other Other memo.
     * @return True when fields match.
     */
    bool operator==(const CreditMemo& other) const;

    /**
     * Stream credit memo.
     *
     * @param os Output stream.
     * @param memo Memo object.
     * @return Output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const CreditMemo& memo);
};

#endif  // LIBOBJS_CREDIT_MEMO_HPP
