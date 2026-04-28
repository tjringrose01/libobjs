/**
 *  Money.hpp - Money Class Definition.
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

#ifndef LIBOBJS_MONEY_HPP
#define LIBOBJS_MONEY_HPP

#include <cstdint>
#include <ostream>
#include <string>

/**
 * Value object for currency in minor units to avoid floating-point drift.
 */
/**
 * @brief Money model.
 */
class Money {
private:
    std::string currencyCode;
    std::int64_t minorUnits;

public:
    /**
     * Construct default money as 0 USD.
     */
    Money();

    /**
     * Construct money.
     *
     * @param currencyCode ISO currency code.
     * @param minorUnits Minor units (cents for USD).
     */
    Money(const std::string& currencyCode, std::int64_t minorUnits);

    /**
     * Build money from decimal amount.
     *
     * @param currencyCode ISO currency code.
     * @param decimalAmount Decimal amount.
     * @return Money value.
     */
    static Money fromDouble(const std::string& currencyCode, double decimalAmount);

    /**
     * Get currency code.
     *
     * @return Currency code.
     */
    std::string getCurrencyCode() const;

    /**
     * Get minor units.
     *
     * @return Minor unit amount.
     */
    std::int64_t getMinorUnits() const;

    /**
     * Convert to decimal amount.
     *
     * @return Decimal value.
     */
    double toDouble() const;

    /**
     * Convert money to text.
     *
     * @return String representation.
     */
    std::string to_string() const;

    /**
     * Add two money values.
     *
     * @param other Other money value.
     * @return Sum.
     */
    Money operator+(const Money& other) const;

    /**
     * Subtract two money values.
     *
     * @param other Other money value.
     * @return Difference.
     */
    Money operator-(const Money& other) const;

    /**
     * Compare equality.
     *
     * @param other Other money value.
     * @return True if equal.
     */
    bool operator==(const Money& other) const;

    /**
     * Compare less-than.
     *
     * @param other Other money value.
     * @return True if less-than.
     */
    bool operator<(const Money& other) const;

    /**
     * Compare greater-than.
     *
     * @param other Other money value.
     * @return True if greater-than.
     */
    bool operator>(const Money& other) const;

    /**
     * Stream money.
     *
     * @param os Output stream.
     * @param money Money value.
     * @return Output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Money& money);
};

#endif  // LIBOBJS_MONEY_HPP
