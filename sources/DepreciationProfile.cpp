/**
 *  DepreciationProfile.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the DepreciationProfile model.
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
 *  - Monthly rate represents percentage depreciation allocation per month.
 */

#include "DepreciationProfile.hpp"

/** @brief Construct a default depreciation profile. */
DepreciationProfile::DepreciationProfile()
    : profileId(""), method(DepreciationMethod::STRAIGHT_LINE), usefulLifeMonths(0), salvagePercent(0.0) {}

/** @brief Construct a depreciation profile with explicit values. */
DepreciationProfile::DepreciationProfile(const std::string& profileId,
                                         DepreciationMethod method,
                                         int usefulLifeMonths,
                                         double salvagePercent)
    : profileId(profileId),
      method(method),
      usefulLifeMonths(usefulLifeMonths),
      salvagePercent(salvagePercent) {}

/** @brief Get profile identifier. */
std::string DepreciationProfile::getProfileId() const { return profileId; }

/** @brief Get depreciation method. */
DepreciationMethod DepreciationProfile::getMethod() const { return method; }

/** @brief Get useful life in months. */
int DepreciationProfile::getUsefulLifeMonths() const { return usefulLifeMonths; }

/** @brief Get salvage percentage. */
double DepreciationProfile::getSalvagePercent() const { return salvagePercent; }

/** @brief Set profile identifier. */
void DepreciationProfile::setProfileId(const std::string& profileId) { this->profileId = profileId; }

/** @brief Set depreciation method. */
void DepreciationProfile::setMethod(DepreciationMethod method) { this->method = method; }

/** @brief Set useful life in months. */
void DepreciationProfile::setUsefulLifeMonths(int usefulLifeMonths) {
    this->usefulLifeMonths = usefulLifeMonths;
}

/** @brief Set salvage percentage. */
void DepreciationProfile::setSalvagePercent(double salvagePercent) { this->salvagePercent = salvagePercent; }

/** @brief Compute monthly depreciation rate percentage. */
double DepreciationProfile::monthlyRate() const {
    if (usefulLifeMonths <= 0) {
        return 0.0;
    }

    const double basePercent = 100.0 - salvagePercent;
    switch (method) {
        case DepreciationMethod::STRAIGHT_LINE:
            return basePercent / static_cast<double>(usefulLifeMonths);
        case DepreciationMethod::DECLINING_BALANCE:
            return (basePercent / static_cast<double>(usefulLifeMonths)) * 1.5;
        case DepreciationMethod::UNITS_OF_PRODUCTION:
            return basePercent / static_cast<double>(usefulLifeMonths);
        default:
            return 0.0;
    }
}

/** @brief Convert depreciation method enum to text. */
std::string DepreciationProfile::depreciationMethodToString(DepreciationMethod method) {
    switch (method) {
        case DepreciationMethod::STRAIGHT_LINE:
            return "STRAIGHT_LINE";
        case DepreciationMethod::DECLINING_BALANCE:
            return "DECLINING_BALANCE";
        case DepreciationMethod::UNITS_OF_PRODUCTION:
            return "UNITS_OF_PRODUCTION";
        default:
            return "UNKNOWN";
    }
}

/** @brief Convert this depreciation profile to a human-readable string. */
std::string DepreciationProfile::to_string() const {
    return "profileId=" + profileId +
           "; method=" + depreciationMethodToString(method) +
           "; usefulLifeMonths=" + std::to_string(usefulLifeMonths) +
           "; salvagePercent=" + std::to_string(salvagePercent);
}

/** @brief Compare two depreciation profile values. */
bool DepreciationProfile::operator==(const DepreciationProfile& other) const {
    return profileId == other.profileId &&
           method == other.method &&
           usefulLifeMonths == other.usefulLifeMonths &&
           salvagePercent == other.salvagePercent;
}

/** @brief Stream a depreciation profile value. */
std::ostream& operator<<(std::ostream& os, const DepreciationProfile& profile) {
    os << profile.to_string();
    return os;
}
