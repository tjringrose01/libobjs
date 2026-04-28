/**
 *  LedgerEntry.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the LedgerEntry model.
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
 *  - Balanced entry has either debit or credit populated, not both.
 */

#include "LedgerEntry.hpp"

/** @brief Construct a default ledger entry. */
LedgerEntry::LedgerEntry()
    : entryId(""),
      referenceNo(""),
      entryDate(Dt()),
      type(LedgerEntryType::UNKNOWN),
      debit(CurrencyAmount(0)),
      credit(CurrencyAmount(0)),
      notes("") {}

/** @brief Construct a ledger entry with explicit values. */
LedgerEntry::LedgerEntry(const std::string& entryId,
                         const std::string& referenceNo,
                         const Dt& entryDate,
                         LedgerEntryType type,
                         const CurrencyAmount& debit,
                         const CurrencyAmount& credit,
                         const std::string& notes)
    : entryId(entryId),
      referenceNo(referenceNo),
      entryDate(entryDate),
      type(type),
      debit(debit),
      credit(credit),
      notes(notes) {}

/** @brief Get entry identifier. */
std::string LedgerEntry::getEntryId() const { return entryId; }

/** @brief Get reference number. */
std::string LedgerEntry::getReferenceNo() const { return referenceNo; }

/** @brief Get entry date. */
Dt LedgerEntry::getEntryDate() const { return entryDate; }

/** @brief Get ledger entry type. */
LedgerEntryType LedgerEntry::getType() const { return type; }

/** @brief Get debit amount. */
CurrencyAmount LedgerEntry::getDebit() const { return debit; }

/** @brief Get credit amount. */
CurrencyAmount LedgerEntry::getCredit() const { return credit; }

/** @brief Get entry notes. */
std::string LedgerEntry::getNotes() const { return notes; }

/** @brief Return true when exactly one side carries value. */
bool LedgerEntry::isBalanced() const {
    const CurrencyAmount zeroDebit(debit.getCurrencyCode(), 0);
    const CurrencyAmount zeroCredit(credit.getCurrencyCode(), 0);
    const bool hasDebit = debit > zeroDebit;
    const bool hasCredit = credit > zeroCredit;
    return hasDebit != hasCredit;
}

/** @brief Compute net amount as debit minus credit. */
CurrencyAmount LedgerEntry::netAmount() const { return debit - credit; }

/** @brief Convert ledger entry type enum to text. */
std::string LedgerEntry::ledgerEntryTypeToString(LedgerEntryType type) {
    switch (type) {
        case LedgerEntryType::INVOICE_ISSUED:
            return "INVOICE_ISSUED";
        case LedgerEntryType::PAYMENT_RECEIVED:
            return "PAYMENT_RECEIVED";
        case LedgerEntryType::REFUND_ISSUED:
            return "REFUND_ISSUED";
        case LedgerEntryType::CREDIT_APPLIED:
            return "CREDIT_APPLIED";
        case LedgerEntryType::ADJUSTMENT:
            return "ADJUSTMENT";
        case LedgerEntryType::UNKNOWN:
        default:
            return "UNKNOWN";
    }
}

/** @brief Convert this ledger entry to a human-readable string. */
std::string LedgerEntry::to_string() const {
    return "entryId=" + entryId +
           "; referenceNo=" + referenceNo +
           "; entryDate=" + entryDate.to_string() +
           "; type=" + ledgerEntryTypeToString(type) +
           "; debit=" + debit.to_string() +
           "; credit=" + credit.to_string() +
           "; notes=" + notes;
}

/** @brief Compare two ledger entry values. */
bool LedgerEntry::operator==(const LedgerEntry& other) const {
    return entryId == other.entryId &&
           referenceNo == other.referenceNo &&
           entryDate == other.entryDate &&
           type == other.type &&
           debit == other.debit &&
           credit == other.credit &&
           notes == other.notes;
}

/** @brief Stream a ledger entry value. */
std::ostream& operator<<(std::ostream& os, const LedgerEntry& entry) {
    os << entry.to_string();
    return os;
}
