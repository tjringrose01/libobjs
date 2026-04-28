/**
 *  Money.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the Money model.
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
 *  - Amounts are stored in minor units to avoid floating-point drift.
 *  - Arithmetic requires matching currency codes.
 */

#include "Money.hpp"

#include <cmath>
#include <iomanip>
#include <sstream>
#include <stdexcept>

/** @brief Construct default USD zero money value. */
Money::Money() : currencyCode("USD"), minorUnits(0) {}

/** @brief Construct money with explicit currency and minor units. */
Money::Money(const std::string& currencyCode, std::int64_t minorUnits)
    : currencyCode(currencyCode), minorUnits(minorUnits) {}

/** @brief Build money from decimal value using bankers-safe rounding. */
Money Money::fromDouble(const std::string& currencyCode, double decimalAmount) {
    return Money(currencyCode, static_cast<std::int64_t>(std::llround(decimalAmount * 100.0)));
}

/** @brief Get currency code. */
std::string Money::getCurrencyCode() const { return currencyCode; }

/** @brief Get minor-unit amount. */
std::int64_t Money::getMinorUnits() const { return minorUnits; }

/** @brief Convert minor-unit amount to decimal representation. */
double Money::toDouble() const { return static_cast<double>(minorUnits) / 100.0; }

/** @brief Convert this money value to a human-readable string. */
std::string Money::to_string() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << toDouble() << " " << currencyCode;
    return oss.str();
}

/** @brief Add two money values with matching currencies. */
Money Money::operator+(const Money& other) const {
    if (currencyCode != other.currencyCode) {
        throw std::invalid_argument("ERROR: currency mismatch in Money::operator+");
    }
    return Money(currencyCode, minorUnits + other.minorUnits);
}

/** @brief Subtract two money values with matching currencies. */
Money Money::operator-(const Money& other) const {
    if (currencyCode != other.currencyCode) {
        throw std::invalid_argument("ERROR: currency mismatch in Money::operator-");
    }
    return Money(currencyCode, minorUnits - other.minorUnits);
}

/** @brief Compare equality of two money values. */
bool Money::operator==(const Money& other) const {
    return currencyCode == other.currencyCode && minorUnits == other.minorUnits;
}

/** @brief Compare less-than of two money values. */
bool Money::operator<(const Money& other) const {
    if (currencyCode != other.currencyCode) {
        throw std::invalid_argument("ERROR: currency mismatch in Money::operator<");
    }
    return minorUnits < other.minorUnits;
}

/** @brief Compare greater-than of two money values. */
bool Money::operator>(const Money& other) const {
    if (currencyCode != other.currencyCode) {
        throw std::invalid_argument("ERROR: currency mismatch in Money::operator>");
    }
    return minorUnits > other.minorUnits;
}

/** @brief Stream a money value. */
std::ostream& operator<<(std::ostream& os, const Money& money) {
    os << money.to_string();
    return os;
}
