/**
 *  BankAccount.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the BankAccount model.
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
 *  - Routing numbers must be 9 numeric digits.
 *  - Only the last four account digits are retained for masking.
 */

#include "BankAccount.hpp"

#include <cctype>

/** @brief Construct a default bank account value. */
BankAccount::BankAccount()
    : accountHolder(""),
      bankName(""),
      routingNumber(""),
      accountNumberLast4(""),
      accountType(BankAccountType::UNKNOWN) {}

/** @brief Construct a bank account value with explicit fields. */
BankAccount::BankAccount(const std::string& accountHolder,
                         const std::string& bankName,
                         const std::string& routingNumber,
                         const std::string& accountNumberLast4,
                         BankAccountType accountType)
    : accountHolder(accountHolder),
      bankName(bankName),
      routingNumber(routingNumber),
      accountNumberLast4(accountNumberLast4),
      accountType(accountType) {}

/** @brief Get the account holder name. */
std::string BankAccount::getAccountHolder() const { return accountHolder; }

/** @brief Get the bank name. */
std::string BankAccount::getBankName() const { return bankName; }

/** @brief Get the routing number text. */
std::string BankAccount::getRoutingNumber() const { return routingNumber; }

/** @brief Get the last four account digits. */
std::string BankAccount::getAccountNumberLast4() const { return accountNumberLast4; }

/** @brief Get the account type enum value. */
BankAccountType BankAccount::getAccountType() const { return accountType; }

/** @brief Set account holder name. */
void BankAccount::setAccountHolder(const std::string& accountHolder) { this->accountHolder = accountHolder; }

/** @brief Set bank name. */
void BankAccount::setBankName(const std::string& bankName) { this->bankName = bankName; }

/** @brief Set routing number text. */
void BankAccount::setRoutingNumber(const std::string& routingNumber) { this->routingNumber = routingNumber; }

/** @brief Set account number fragment, retaining only the final 4 digits. */
void BankAccount::setAccountNumberLast4(const std::string& accountNumberFragment) {
    if (accountNumberFragment.size() <= 4) {
        accountNumberLast4 = accountNumberFragment;
        return;
    }

    accountNumberLast4 = accountNumberFragment.substr(accountNumberFragment.size() - 4);
}

/** @brief Set account type enum value. */
void BankAccount::setAccountType(BankAccountType accountType) { this->accountType = accountType; }

/** @brief Return masked account string. */
std::string BankAccount::maskedAccountNumber() const { return "****" + accountNumberLast4; }

/** @brief Validate routing number has exactly nine digits. */
bool BankAccount::isValidRoutingNumber(const std::string& routingNumber) {
    if (routingNumber.size() != 9) {
        return false;
    }

    for (char c : routingNumber) {
        if (!std::isdigit(static_cast<unsigned char>(c))) {
            return false;
        }
    }

    return true;
}

/** @brief Convert account type enum to text. */
std::string BankAccount::bankAccountTypeToString(BankAccountType accountType) {
    switch (accountType) {
        case BankAccountType::CHECKING:
            return "CHECKING";
        case BankAccountType::SAVINGS:
            return "SAVINGS";
        case BankAccountType::UNKNOWN:
        default:
            return "UNKNOWN";
    }
}

/** @brief Convert this bank account to a human-readable string. */
std::string BankAccount::to_string() const {
    return "accountHolder=" + accountHolder +
           "; bankName=" + bankName +
           "; routingNumber=" + routingNumber +
           "; accountNumber=" + maskedAccountNumber() +
           "; accountType=" + bankAccountTypeToString(accountType);
}

/** @brief Compare two bank account values. */
bool BankAccount::operator==(const BankAccount& other) const {
    return accountHolder == other.accountHolder &&
           bankName == other.bankName &&
           routingNumber == other.routingNumber &&
           accountNumberLast4 == other.accountNumberLast4 &&
           accountType == other.accountType;
}

/** @brief Stream a bank account value. */
std::ostream& operator<<(std::ostream& os, const BankAccount& account) {
    os << account.to_string();
    return os;
}
