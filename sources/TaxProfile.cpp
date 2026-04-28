/**
 *  TaxProfile.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the TaxProfile model.
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
 *  - Compound tax rules apply on taxable amount plus tax accumulated so far.
 */

#include "TaxProfile.hpp"

/** @brief Construct a default tax profile. */
TaxProfile::TaxProfile() : profileName(""), rules() {}

/** @brief Construct a named tax profile. */
TaxProfile::TaxProfile(const std::string& profileName) : profileName(profileName), rules() {}

/** @brief Get profile name. */
std::string TaxProfile::getProfileName() const { return profileName; }

/** @brief Set profile name. */
void TaxProfile::setProfileName(const std::string& profileName) { this->profileName = profileName; }

/** @brief Get tax rules. */
std::vector<TaxRule> TaxProfile::getRules() const { return rules; }

/** @brief Add one tax rule. */
void TaxProfile::addRule(const TaxRule& rule) { rules.push_back(rule); }

/** @brief Replace tax rule collection. */
void TaxProfile::setRules(const std::vector<TaxRule>& rules) { this->rules = rules; }

/** @brief Calculate total tax from all configured rules. */
CurrencyAmount TaxProfile::calculateTotalTax(const CurrencyAmount& taxable) const {
    CurrencyAmount totalTax(taxable.getCurrencyCode(), 0);

    for (const TaxRule& rule : rules) {
        CurrencyAmount base = taxable;
        if (rule.isCompound()) {
            base = taxable + totalTax;
        }

        totalTax = totalTax + rule.calculateTax(base);
    }

    return totalTax;
}

/** @brief Return taxable amount plus calculated tax. */
CurrencyAmount TaxProfile::applyToNet(const CurrencyAmount& taxable) const {
    return taxable + calculateTotalTax(taxable);
}

/** @brief Convert this tax profile to a human-readable string. */
std::string TaxProfile::to_string() const {
    return "profileName=" + profileName +
           "; ruleCount=" + std::to_string(rules.size());
}

/** @brief Compare two tax profile values. */
bool TaxProfile::operator==(const TaxProfile& other) const {
    return profileName == other.profileName && rules == other.rules;
}

/** @brief Stream a tax profile value. */
std::ostream& operator<<(std::ostream& os, const TaxProfile& profile) {
    os << profile.to_string();
    return os;
}
