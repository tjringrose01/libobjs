/**
 *  CurrencyAmount.h - Currency Class Definition - This class is responsible
 *                      for defining a currency amount.
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

class CurrencyAmount {
public:
    // Constructor that takes in the currency code and amount
    CurrencyAmount(const std::string& currency_code, double amount);

    // Getter functions for the currency code and amount
    std::string getCurrencyCode() const;
    double getAmount() const;

    // Setter functions for the currency code and amount
    void setCurrencyCode(const std::string& currency_code);
    void setAmount(double amount);

    // Adds Tax to the CurrencyAmount
    void addTax(double tax);

    // Return Tax amount from the CurrencyAmount
    double getTax(double tax);

    // Function to convert the currency amount to a string
    std::string toString() const;

    // Overloaded operators for addition and subtraction
    CurrencyAmount operator+(const CurrencyAmount& other) const;
    CurrencyAmount operator-(const CurrencyAmount& other) const;

    // Overloaded comparison operators
    bool operator==(const CurrencyAmount& other) const;
    bool operator!=(const CurrencyAmount& other) const;
    bool operator<(const CurrencyAmount& other) const;
    bool operator<=(const CurrencyAmount& other) const;
    bool operator>(const CurrencyAmount& other) const;
    bool operator>=(const CurrencyAmount& other) const;

private:
    // Member variables for the currency code and amount
    std::string currency_code_;
    double amount_;
};

#endif
