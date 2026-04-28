/**
 *  TaxRule.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the TaxRule model.
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
 *  - Tax amount is calculated as taxable * rate.
 */

#include "TaxRule.hpp"

/** @brief Construct a default tax rule. */
TaxRule::TaxRule() : jurisdiction(""), name(""), rate(0.0), compound(false) {}

/** @brief Construct a tax rule with explicit values. */
TaxRule::TaxRule(const std::string& jurisdiction, const std::string& name, double rate, bool compound)
    : jurisdiction(jurisdiction), name(name), rate(rate), compound(compound) {}

/** @brief Get jurisdiction label. */
std::string TaxRule::getJurisdiction() const { return jurisdiction; }

/** @brief Get rule name. */
std::string TaxRule::getName() const { return name; }

/** @brief Get rule rate. */
double TaxRule::getRate() const { return rate; }

/** @brief Get compounding behavior flag. */
bool TaxRule::isCompound() const { return compound; }

/** @brief Calculate tax amount from taxable amount. */
CurrencyAmount TaxRule::calculateTax(const CurrencyAmount& taxable) const {
    return CurrencyAmount(taxable.getCurrencyCode(), taxable.getAmount() * rate);
}

/** @brief Convert this tax rule to a human-readable string. */
std::string TaxRule::to_string() const {
    return "jurisdiction=" + jurisdiction +
           "; name=" + name +
           "; rate=" + std::to_string(rate) +
           "; compound=" + (compound ? "true" : "false");
}

/** @brief Compare two tax rule values. */
bool TaxRule::operator==(const TaxRule& other) const {
    return jurisdiction == other.jurisdiction &&
           name == other.name &&
           rate == other.rate &&
           compound == other.compound;
}

/** @brief Stream a tax rule value. */
std::ostream& operator<<(std::ostream& os, const TaxRule& rule) {
    os << rule.to_string();
    return os;
}
