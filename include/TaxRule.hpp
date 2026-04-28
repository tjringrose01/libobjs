/**
 *  TaxRule.hpp - TaxRule Class Definition.
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

#ifndef LIBOBJS_TAX_RULE_HPP
#define LIBOBJS_TAX_RULE_HPP

#include <ostream>
#include <string>
#include "CurrencyAmount.hpp"

/**
 * Represents one tax rule for a jurisdiction and rate.
 */
/**
 * @brief TaxRule model.
 */
class TaxRule {
private:
    std::string jurisdiction;
    std::string name;
    double rate;
    bool compound;

public:
    /**
     * Construct a default tax rule.
     */
    TaxRule();

    /**
     * Construct a tax rule.
     *
     * @param jurisdiction Tax jurisdiction.
     * @param name Rule name.
     * @param rate Tax rate (for example 0.07 for 7%).
     * @param compound Whether tax compounds on prior taxes.
     */
    TaxRule(const std::string& jurisdiction, const std::string& name, double rate, bool compound);

    /**
     * Get jurisdiction.
     *
     * @return Jurisdiction label.
     */
    std::string getJurisdiction() const;

    /**
     * Get rule name.
     *
     * @return Rule name.
     */
    std::string getName() const;

    /**
     * Get rate.
     *
     * @return Tax rate.
     */
    double getRate() const;

    /**
     * Get compounding behavior.
     *
     * @return True when tax is compound.
     */
    bool isCompound() const;

    /**
     * Calculate tax for a taxable amount.
     *
     * @param taxable Taxable amount.
     * @return Tax amount.
     */
    CurrencyAmount calculateTax(const CurrencyAmount& taxable) const;

    /**
     * Convert rule to text.
     *
     * @return String representation.
     */
    std::string to_string() const;

    /**
     * Compare tax rules.
     *
     * @param other Other tax rule.
     * @return True when fields match.
     */
    bool operator==(const TaxRule& other) const;

    /**
     * Stream tax rule.
     *
     * @param os Output stream.
     * @param rule Tax rule.
     * @return Output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const TaxRule& rule);
};

#endif  // LIBOBJS_TAX_RULE_HPP
