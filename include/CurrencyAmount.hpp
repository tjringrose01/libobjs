/**
 *  CurrencyAmount.hpp - Currency Class Definition - This class is responsible
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

#ifndef CURRENCY_AMOUNT_H
#define CURRENCY_AMOUNT_H

#include <string>

using namespace std;

class CurrencyAmount {
public:
    /**
     * Constructor for CurrencyAmount.
     *
     * @param currency_code The currency code as a string.
     * @param amount The amount as a double.
     */
    CurrencyAmount(const string& currency_code, double amount);

    /**
     * Constructor for CurrencyAmount with integer amount.
     *
     * @param currency_code The currency code as a string.
     * @param amount The amount as an integer.
     */
    CurrencyAmount(const string& currency_code, int amount);

    /**
     * Get the currency code of the CurrencyAmount.
     *
     * @return The currency code as a string.
     */
    string getCurrencyCode() const;

    /**
     * Get the amount of the CurrencyAmount.
     *
     * @return The amount as a double.
     */
    double getAmount() const;

    /**
     * Set the currency code of the CurrencyAmount.
     *
     * @param currency_code The currency code as a string.
     */
    void setCurrencyCode(const string& currency_code);

    /**
     * Set the amount of the CurrencyAmount.
     *
     * @param amount The amount as a double.
     */
    void setAmount(double amount);

    /**
     * Add tax to the CurrencyAmount.
     *
     * @param tax The tax amount to add.
     */
    void addTax(double tax);

    /**
     * Get the tax amount from the CurrencyAmount.
     *
     * @param tax The tax amount to calculate.
     * @return The calculated tax amount.
     */
    double calculateTax(float tax);

    /**
     * Convert the currency amount to a string representation.
     *
     * @return The currency amount as a string.
     */
    string to_string() const;

    /**
     * Overloaded operator for addition of CurrencyAmount objects.
     *
     * @param other The CurrencyAmount object to add.
     * @return The result of adding this object with the other object.
     */
    CurrencyAmount operator+(const CurrencyAmount& other) const;

    /**
     * Overloaded operator for subtraction of CurrencyAmount objects.
     *
     * @param other The CurrencyAmount object to subtract.
     * @return The result of subtracting the other object from this object.
     */
    CurrencyAmount operator-(const CurrencyAmount& other) const;

    // Overloaded comparison operators
    /**
     * Overloaded equality operator for comparing CurrencyAmount objects.
     *
     * @param other The CurrencyAmount object to compare with.
     * @return True if the objects are equal, false otherwise.
     */
    bool operator==(const CurrencyAmount& other) const;

    /**
     * Overloaded inequality operator for comparing CurrencyAmount objects.
     *
     * @param other The CurrencyAmount object to compare with.
     * @return True if the objects are not equal, false otherwise.
     */
    bool operator!=(const CurrencyAmount& other) const;

    /**
     * Overloaded less than operator for comparing CurrencyAmount objects.
     *
     * @param other The CurrencyAmount object to compare with.
     * @return True if this object is less than the other object, false otherwise.
     */
    bool operator<(const CurrencyAmount& other) const;

    /**
     * Overloaded less than or equal to operator for comparing CurrencyAmount objects.
     *
     * @param other The CurrencyAmount object to compare with.
     * @return True if this object is less than or equal to the other object, false otherwise.
     */
    bool operator<=(const CurrencyAmount& other) const;

    /**
     * Overloaded greater than operator for comparing CurrencyAmount objects.
     *
     * @param other The CurrencyAmount object to compare with.
     * @return True if this object is greater than the other object, false otherwise.
     */
    bool operator>(const CurrencyAmount& other) const;

    /**
     * Overloaded greater than or equal to operator for comparing CurrencyAmount objects.
     *
     * @param other The CurrencyAmount object to compare with.
     * @return True if this object is greater than or equal to the other object, false otherwise.
     */
    bool operator>=(const CurrencyAmount& other) const;

    /**
     * Overloaded stream insertion operator for outputting CurrencyAmount objects.
     *
     * @param os The output stream.
     * @param amount The CurrencyAmount object to output.
     * @return The output stream with the CurrencyAmount object printed.
     */
    friend ostream& operator<<(ostream& os, const CurrencyAmount& amount);

private:
    // Member variables for the currency code and amount
    string currency_code_;
    double amount_;
};

#endif