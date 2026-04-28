/**
 *  BankAccount.hpp - BankAccount Class Definition.
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

#ifndef LIBOBJS_BANK_ACCOUNT_HPP
#define LIBOBJS_BANK_ACCOUNT_HPP

#include <ostream>
#include <string>

/**
 * Supported account types.
 */
/**
 * @brief BankAccountType enumeration.
 */
enum class BankAccountType {
    UNKNOWN = 0,
    CHECKING = 1,
    SAVINGS = 2
};

/**
 * Represents a bank account identity used for payment rails.
 */
/**
 * @brief BankAccount model.
 */
class BankAccount {
private:
    std::string accountHolder;
    std::string bankName;
    std::string routingNumber;
    std::string accountNumberLast4;
    BankAccountType accountType;

public:
    /**
     * Construct default bank account.
     */
    BankAccount();

    /**
     * Construct bank account.
     *
     * @param accountHolder Holder name.
     * @param bankName Bank name.
     * @param routingNumber Routing number.
     * @param accountNumberLast4 Last 4 digits of account number.
     * @param accountType Account type.
     */
    BankAccount(const std::string& accountHolder,
                const std::string& bankName,
                const std::string& routingNumber,
                const std::string& accountNumberLast4,
                BankAccountType accountType);

    /**
     * Get account holder.
     *
     * @return Holder name.
     */
    std::string getAccountHolder() const;

    /**
     * Get bank name.
     *
     * @return Bank name.
     */
    std::string getBankName() const;

    /**
     * Get routing number.
     *
     * @return Routing number.
     */
    std::string getRoutingNumber() const;

    /**
     * Get account last 4.
     *
     * @return Last 4 digits.
     */
    std::string getAccountNumberLast4() const;

    /**
     * Get account type.
     *
     * @return Account type.
     */
    BankAccountType getAccountType() const;

    /**
     * Set account holder.
     *
     * @param accountHolder Holder name.
     */
    void setAccountHolder(const std::string& accountHolder);

    /**
     * Set bank name.
     *
     * @param bankName Bank name.
     */
    void setBankName(const std::string& bankName);

    /**
     * Set routing number.
     *
     * @param routingNumber Routing number.
     */
    void setRoutingNumber(const std::string& routingNumber);

    /**
     * Set account number fragment (stores only last four digits).
     *
     * @param accountNumberFragment Raw fragment.
     */
    void setAccountNumberLast4(const std::string& accountNumberFragment);

    /**
     * Set account type.
     *
     * @param accountType Account type.
     */
    void setAccountType(BankAccountType accountType);

    /**
     * Return masked account number.
     *
     * @return Masked account string.
     */
    std::string maskedAccountNumber() const;

    /**
     * Validate ABA routing number shape (9 digits).
     *
     * @param routingNumber Routing number.
     * @return True if valid shape.
     */
    static bool isValidRoutingNumber(const std::string& routingNumber);

    /**
     * Convert account type enum to text.
     *
     * @param accountType Account type.
     * @return Account type label.
     */
    static std::string bankAccountTypeToString(BankAccountType accountType);

    /**
     * Convert bank account to text.
     *
     * @return String representation.
     */
    std::string to_string() const;

    /**
     * Compare bank accounts.
     *
     * @param other Other account.
     * @return True when fields match.
     */
    bool operator==(const BankAccount& other) const;

    /**
     * Stream bank account.
     *
     * @param os Output stream.
     * @param account Bank account.
     * @return Output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const BankAccount& account);
};

#endif  // LIBOBJS_BANK_ACCOUNT_HPP
