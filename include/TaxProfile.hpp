/**
 *  TaxProfile.hpp - TaxProfile Class Definition.
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

#ifndef LIBOBJS_TAX_PROFILE_HPP
#define LIBOBJS_TAX_PROFILE_HPP

#include <ostream>
#include <string>
#include <vector>
#include "CurrencyAmount.hpp"
#include "TaxRule.hpp"

/**
 * Represents a set of tax rules to apply for a transaction.
 */
/**
 * @brief TaxProfile model.
 */
class TaxProfile {
private:
    std::string profileName;
    std::vector<TaxRule> rules;

public:
    /**
     * Construct a default tax profile.
     */
    TaxProfile();

    /**
     * Construct a named tax profile.
     *
     * @param profileName Profile name.
     */
    explicit TaxProfile(const std::string& profileName);

    /**
     * Get profile name.
     *
     * @return Profile name.
     */
    std::string getProfileName() const;

    /**
     * Set profile name.
     *
     * @param profileName Profile name.
     */
    void setProfileName(const std::string& profileName);

    /**
     * Get tax rules.
     *
     * @return Rules vector.
     */
    std::vector<TaxRule> getRules() const;

    /**
     * Add a tax rule.
     *
     * @param rule Tax rule.
     */
    void addRule(const TaxRule& rule);

    /**
     * Set all tax rules.
     *
     * @param rules Rules vector.
     */
    void setRules(const std::vector<TaxRule>& rules);

    /**
     * Calculate total tax from all rules.
     *
     * @param taxable Taxable amount.
     * @return Total tax amount.
     */
    CurrencyAmount calculateTotalTax(const CurrencyAmount& taxable) const;

    /**
     * Calculate gross amount (taxable + total tax).
     *
     * @param taxable Taxable amount.
     * @return Gross amount including tax.
     */
    CurrencyAmount applyToNet(const CurrencyAmount& taxable) const;

    /**
     * Convert profile to text.
     *
     * @return String representation.
     */
    std::string to_string() const;

    /**
     * Compare tax profiles.
     *
     * @param other Other profile.
     * @return True when fields match.
     */
    bool operator==(const TaxProfile& other) const;

    /**
     * Stream tax profile.
     *
     * @param os Output stream.
     * @param profile Tax profile.
     * @return Output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const TaxProfile& profile);
};

#endif  // LIBOBJS_TAX_PROFILE_HPP
