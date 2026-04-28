/**
 *  LedgerEntry.hpp - LedgerEntry Class Definition.
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

#ifndef LIBOBJS_LEDGER_ENTRY_HPP
#define LIBOBJS_LEDGER_ENTRY_HPP

#include <ostream>
#include <string>
#include "CurrencyAmount.hpp"
#include "Dt.hpp"

/**
 * Supported ledger entry types.
 */
/**
 * @brief LedgerEntryType enumeration.
 */
enum class LedgerEntryType {
    UNKNOWN = 0,
    INVOICE_ISSUED = 1,
    PAYMENT_RECEIVED = 2,
    REFUND_ISSUED = 3,
    CREDIT_APPLIED = 4,
    ADJUSTMENT = 5
};

/**
 * Represents one ledger event with debit and credit values.
 */
/**
 * @brief LedgerEntry model.
 */
class LedgerEntry {
private:
    std::string entryId;
    std::string referenceNo;
    Dt entryDate;
    LedgerEntryType type;
    CurrencyAmount debit;
    CurrencyAmount credit;
    std::string notes;

public:
    /**
     * Construct default ledger entry.
     */
    LedgerEntry();

    /**
     * Construct ledger entry.
     *
     * @param entryId Entry ID.
     * @param referenceNo External reference.
     * @param entryDate Date posted.
     * @param type Ledger type.
     * @param debit Debit amount.
     * @param credit Credit amount.
     * @param notes Entry notes.
     */
    LedgerEntry(const std::string& entryId,
                const std::string& referenceNo,
                const Dt& entryDate,
                LedgerEntryType type,
                const CurrencyAmount& debit,
                const CurrencyAmount& credit,
                const std::string& notes);

    /**
     * Get entry ID.
     *
     * @return Entry ID.
     */
    std::string getEntryId() const;

    /**
     * Get reference number.
     *
     * @return Reference number.
     */
    std::string getReferenceNo() const;

    /**
     * Get entry date.
     *
     * @return Entry date.
     */
    Dt getEntryDate() const;

    /**
     * Get entry type.
     *
     * @return Entry type.
     */
    LedgerEntryType getType() const;

    /**
     * Get debit amount.
     *
     * @return Debit amount.
     */
    CurrencyAmount getDebit() const;

    /**
     * Get credit amount.
     *
     * @return Credit amount.
     */
    CurrencyAmount getCredit() const;

    /**
     * Get notes.
     *
     * @return Notes text.
     */
    std::string getNotes() const;

    /**
     * Return true when only one side of entry is non-zero.
     *
     * @return True if entry shape is valid.
     */
    bool isBalanced() const;

    /**
     * Return net amount (debit - credit).
     *
     * @return Net amount.
     */
    CurrencyAmount netAmount() const;

    /**
     * Convert enum to text.
     *
     * @param type Ledger type.
     * @return Type label.
     */
    static std::string ledgerEntryTypeToString(LedgerEntryType type);

    /**
     * Convert entry to text.
     *
     * @return String representation.
     */
    std::string to_string() const;

    /**
     * Compare ledger entries.
     *
     * @param other Other entry.
     * @return True when all fields match.
     */
    bool operator==(const LedgerEntry& other) const;

    /**
     * Stream ledger entry.
     *
     * @param os Output stream.
     * @param entry Ledger entry.
     * @return Output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const LedgerEntry& entry);
};

#endif  // LIBOBJS_LEDGER_ENTRY_HPP
