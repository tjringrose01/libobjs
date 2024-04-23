/**
 *  CurrencyAmount.cpp - Currency Class Definition - This class is responsible
 *                       for defining a currency amount.
 *
 *  Copyright 2023 Timothy Ringrose
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

#include "CurrencyAmount.hpp"
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

/**
 * Constructor for CurrencyAmount with a double amount.
 *
 * @param currency_code The currency code as a string.
 * @param amount The amount as a double.
 */
CurrencyAmount::CurrencyAmount() {
    this->currency_code_ = DEFAULT_CURRENCY_CODE;
    this->amount_ = 0;
}

/**
 * Constructor for CurrencyAmount with a double amount.
 *
 * @param currency_code The currency code as a string.
 * @param amount The amount as a double.
 */
CurrencyAmount::CurrencyAmount(const string& currency_code, double amount)
    : currency_code_(currency_code), amount_(amount) {}

/**
 * Constructor for CurrencyAmount with an integer amount.
 *
 * @param currency_code The currency code as a string.
 * @param amount The amount as an integer.
 */
CurrencyAmount::CurrencyAmount(const string& currency_code, int amount)
    : currency_code_(currency_code), amount_(amount) {}

/**
  * Constructor for CurrencyAmount with integer amount and default to 'USD'.
  *
  * @param amount The amount as an int.
  */
CurrencyAmount::CurrencyAmount(int amount) {
    amount_ = amount;
    currency_code_ = "USD";
}

/**
  * Constructor for CurrencyAmount with double amount and default to 'USD'.
  *
  * @param amount The amount as a double.
  */
CurrencyAmount::CurrencyAmount(double amount) {
    amount_ = amount;
    currency_code_ = "USD";
}

/**
 * Get the currency code of the CurrencyAmount.
 *
 * @return The currency code as a string.
 */
string CurrencyAmount::getCurrencyCode() const {
    return currency_code_;
}

/**
 * Get the amount of the CurrencyAmount.
 *
 * @return The amount as a double.
 */
double CurrencyAmount::getAmount() const {
    return amount_;
}

/**
 * Set the currency code of the CurrencyAmount.
 *
 * @param currency_code The currency code as a string.
 */
void CurrencyAmount::setCurrencyCode(const string& currency_code) {
    currency_code_ = currency_code;
}

/**
 * Set the amount of the CurrencyAmount.
 *
 * @param amount The amount as a double.
 */
void CurrencyAmount::setAmount(double amount) {
    amount_ = amount;
}


/**
 * Calculate the tax amount based on the given tax rate.
 *
 * @param tax The tax rate to apply (float).
 * @return The calculated tax amount (double).
 */
double CurrencyAmount::calculateTax(float tax) {
	double _tax = ceil(this->amount_ * tax * 100 ) / 100;
	return _tax;
}

/**
 * Add tax amount to the current amount.
 *
 * @param tax The tax amount to add (double).
 */
void CurrencyAmount::addTax(double tax) {
	double _tax = (this->amount_ * tax) + .005;
	this->amount_ += _tax;
}

/**
 * Convert the CurrencyAmount object to a string representation.
 *
 * @return The string representation of the CurrencyAmount.
 */
string CurrencyAmount::to_string() const {
    // Use a stringstream to build the string representation of the currency amount
    ostringstream oss;
    oss << fixed << setprecision(2) << amount_ << " " << currency_code_;
    return oss.str();
}

/**
 * Overloaded operator for addition of CurrencyAmount objects.
 *
 * @param other The CurrencyAmount object to add (const CurrencyAmount&).
 * @return The result of adding this object with the other object (CurrencyAmount).
 */
CurrencyAmount CurrencyAmount::operator+(const CurrencyAmount& other) const {
    // Make sure the currency codes match
    if (currency_code_ != other.currency_code_) {
        throw invalid_argument("Currency codes do not match.");
    }

    // Add the amounts together and return a new CurrencyAmount object
    return CurrencyAmount(currency_code_, amount_ + other.amount_);
}

/**
 * Overloaded operator for subtraction of CurrencyAmount objects.
 *
 * @param other The CurrencyAmount object to subtract (const CurrencyAmount&).
 * @return The result of subtracting the other object from this object (CurrencyAmount).
 */
CurrencyAmount CurrencyAmount::operator-(const CurrencyAmount& other) const {
    // Make sure the currency codes match
    if (currency_code_ != other.currency_code_) {
        throw invalid_argument("Currency codes do not match.");
    }

    // Subtract the other amount from this amount and return a new CurrencyAmount object
    return CurrencyAmount(currency_code_, amount_ - other.amount_);
}

/**
 * Overloaded operator for multiplication of CurrencyAmount objects with an integer.
 *
 * @param other The integer value to multiply with (const int&).
 * @return The result of multiplying this object with the integer value (CurrencyAmount).
 */
CurrencyAmount CurrencyAmount::operator*(const int& other) const {
    return CurrencyAmount(currency_code_, amount_ * other);
}

/**
 * Check if this CurrencyAmount object is equal to another CurrencyAmount object.
 *
 * @param other The other CurrencyAmount object to compare with (const CurrencyAmount&).
 * @return True if the objects are equal, false otherwise.
 */
bool CurrencyAmount::operator==(const CurrencyAmount& other) const {
    // Two currency amounts are equal if they have the same currency code and amount
    return (currency_code_ == other.currency_code_) && (amount_ == other.amount_);
}

/**
 * Check if this CurrencyAmount object is not equal to another CurrencyAmount object.
 *
 * @param other The other CurrencyAmount object to compare with (const CurrencyAmount&).
 * @return True if the objects are not equal, false otherwise.
 */
bool CurrencyAmount::operator!=(const CurrencyAmount& other) const {
    // Two currency amounts are not equal if they do not have the same currency code or amount
    return !(*this == other);
}

/**
 * Check if this CurrencyAmount object is less than another CurrencyAmount object.
 *
 * @param other The other CurrencyAmount object to compare with (const CurrencyAmount&).
 * @return True if this object is less than the other object, false otherwise.
 */
bool CurrencyAmount::operator<(const CurrencyAmount& other) const {
    // We can only compare currency amounts with the same currency code
    if (currency_code_ != other.currency_code_) {
        throw invalid_argument("Currency codes do not match.");
    }

    // Compare the amounts
    return amount_ < other.amount_;
}

/**
 * Check if this CurrencyAmount object is less than or equal to another CurrencyAmount object.
 *
 * @param other The other CurrencyAmount object to compare with (const CurrencyAmount&).
 * @return True if this object is less than or equal to the other object, false otherwise.
 */
bool CurrencyAmount::operator<=(const CurrencyAmount& other) const {
    // We can only compare currency amounts with the same currency code
    if (currency_code_ != other.currency_code_) {
        throw invalid_argument("Currency codes do not match.");
    }

    // Compare the amounts
    return amount_ <= other.amount_;
}

/**
 * Check if this CurrencyAmount object is greater than another CurrencyAmount object.
 *
 * @param other The other CurrencyAmount object to compare with (const CurrencyAmount&).
 * @return True if this object is greater than the other object, false otherwise.
 */
bool CurrencyAmount::operator>(const CurrencyAmount& other) const {
    // We can only compare currency amounts with the same currency code
    if (currency_code_ != other.currency_code_) {
        throw invalid_argument("Currency codes do not match.");
    }

    // Compare the amounts
    return amount_ > other.amount_;
}

/**
 * Check if this CurrencyAmount object is greater than or equal to another CurrencyAmount object.
 *
 * @param other The other CurrencyAmount object to compare with (const CurrencyAmount&).
 * @return True if this object is greater than or equal to the other object, false otherwise.
 */
bool CurrencyAmount::operator>=(const CurrencyAmount& other) const {
    // We can only compare currency amounts with the same currency code
    if (currency_code_ != other.currency_code_) {
        throw invalid_argument("Currency codes do not match.");
    }

    // Compare the amounts
    return amount_ >= other.amount_;
}

/**
 * Overloaded stream insertion operator for outputting CurrencyAmount objects.
 *
 * @param os The output stream.
 * @param amount The CurrencyAmount object to output.
 * @return The output stream with the CurrencyAmount object printed.
 */
ostream& operator<<(ostream& os, const CurrencyAmount& amount) {
    os << amount.to_string();
    return os;
}

