/**
 *  CurrencyAmount.hh - Currency Class Definition - This class is responsible
 *                      for defining a currency amount.
 *
 *  Copyright 2022 Timothy Ringrose
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

#include "CurrencyAmount.hh"
#include <sstream>
#include <iomanip>

CurrencyAmount::CurrencyAmount(const std::string& currency_code, double amount)
    : currency_code_(currency_code), amount_(amount) {}

std::string CurrencyAmount::getCurrencyCode() const {
    return currency_code_;
}

double CurrencyAmount::getAmount() const {
    return amount_;
}

void CurrencyAmount::setCurrencyCode(const std::string& currency_code) {
    currency_code_ = currency_code;
}

void CurrencyAmount::setAmount(double amount) {
    amount_ = amount;
}

std::string CurrencyAmount::toString() const {
    // Use a stringstream to build the string representation of the currency amount
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << amount_ << " " << currency_code_;
    return oss.str();
}

CurrencyAmount CurrencyAmount::operator+(const CurrencyAmount& other) const {
    // Make sure the currency codes match
    if (currency_code_ != other.currency_code_) {
        throw std::invalid_argument("Currency codes do not match.");
    }

    // Add the amounts together and return a new CurrencyAmount object
    return CurrencyAmount(currency_code_, amount_ + other.amount_);
}

CurrencyAmount CurrencyAmount::operator-(const CurrencyAmount& other) const {
    // Make sure the currency codes match
    if (currency_code_ != other.currency_code_) {
        throw std::invalid_argument("Currency codes do not match.");
    }

    // Subtract the other amount from this amount and return a new CurrencyAmount object
    return CurrencyAmount(currency_code_, amount_ - other.amount_);
}

bool CurrencyAmount::operator==(const CurrencyAmount& other) const {
    // Two currency amounts are equal if they have the same currency code and amount
    return (currency_code_ == other.currency_code_) && (amount_ == other.amount_);
}

bool CurrencyAmount::operator!=(const CurrencyAmount& other) const {
    // Two currency amounts are not equal if they do not have the same currency code or amount
    return !(*this == other);
}

bool CurrencyAmount::operator<(const CurrencyAmount& other) const {
    // We can only compare currency amounts with the same currency code
    if (currency_code_ != other.currency_code_) {
        throw std::invalid_argument("Currency codes do not match.");
    }

    // Compare the amounts
    return amount_ < other.amount_;
}

bool CurrencyAmount::operator<=(const CurrencyAmount& other) const {
    // We can only compare currency amounts with the same currency code
    if (currency_code_ != other.currency_code_) {
        throw std::invalid_argument("Currency codes do not match.");
    }

    // Compare the amounts
    return amount_ <= other.amount_;
}

bool CurrencyAmount::operator>(const CurrencyAmount& other) const {
    // We can only compare currency amounts with the same currency code
    if (currency_code_ != other.currency_code_) {
        throw std::invalid_argument("Currency codes do not match.");
    }

    // Compare the amounts
    return amount_ > other.amount_;
}

bool CurrencyAmount::operator>=(const CurrencyAmount& other) const {
    // We can only compare currency amounts with the same currency code
    if (currency_code_ != other.currency_code_) {
        throw std::invalid_argument("Currency codes do not match.");
    }

    // Compare the amounts
    return amount_ >= other.amount_;
}
