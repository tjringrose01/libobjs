/**
 *  Warranty.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the Warranty model.
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
 *  - Warranty coverage applies when date is between start and end inclusive.
 */

#include "Warranty.hpp"

/**
 * @brief Return true when lhs date is earlier than rhs date.
 */
static bool dt_less_than(const Dt& lhs, const Dt& rhs) {
    if (lhs.get_year() != rhs.get_year()) {
        return lhs.get_year() < rhs.get_year();
    }
    if (lhs.get_month() != rhs.get_month()) {
        return lhs.get_month() < rhs.get_month();
    }
    return lhs.get_day() < rhs.get_day();
}

/** @brief Construct a default warranty. */
Warranty::Warranty()
    : warrantyId(""), assetId(""), vendorId(""), startDate(Dt()), endDate(Dt()), terms("") {}

/** @brief Construct a warranty with explicit values. */
Warranty::Warranty(const std::string& warrantyId,
                   const std::string& assetId,
                   const std::string& vendorId,
                   const Dt& startDate,
                   const Dt& endDate,
                   const std::string& terms)
    : warrantyId(warrantyId),
      assetId(assetId),
      vendorId(vendorId),
      startDate(startDate),
      endDate(endDate),
      terms(terms) {}

/** @brief Get the warranty identifier. */
std::string Warranty::getWarrantyId() const { return warrantyId; }

/** @brief Get the related asset identifier. */
std::string Warranty::getAssetId() const { return assetId; }

/** @brief Get the related vendor identifier. */
std::string Warranty::getVendorId() const { return vendorId; }

/** @brief Get the warranty start date. */
Dt Warranty::getStartDate() const { return startDate; }

/** @brief Get the warranty end date. */
Dt Warranty::getEndDate() const { return endDate; }

/** @brief Get warranty terms text. */
std::string Warranty::getTerms() const { return terms; }

/** @brief Set the warranty identifier. */
void Warranty::setWarrantyId(const std::string& warrantyId) { this->warrantyId = warrantyId; }

/** @brief Set the related asset identifier. */
void Warranty::setAssetId(const std::string& assetId) { this->assetId = assetId; }

/** @brief Set the related vendor identifier. */
void Warranty::setVendorId(const std::string& vendorId) { this->vendorId = vendorId; }

/** @brief Set the warranty start date. */
void Warranty::setStartDate(const Dt& startDate) { this->startDate = startDate; }

/** @brief Set the warranty end date. */
void Warranty::setEndDate(const Dt& endDate) { this->endDate = endDate; }

/** @brief Set warranty terms text. */
void Warranty::setTerms(const std::string& terms) { this->terms = terms; }

/** @brief Return true when the given date is covered by this warranty. */
bool Warranty::isCoverageDate(const Dt& date) const {
    return !dt_less_than(date, startDate) && !dt_less_than(endDate, date);
}

/** @brief Convert this warranty to a human-readable string. */
std::string Warranty::to_string() const {
    return "warrantyId=" + warrantyId +
           "; assetId=" + assetId +
           "; vendorId=" + vendorId +
           "; startDate=" + startDate.to_string() +
           "; endDate=" + endDate.to_string() +
           "; terms=" + terms;
}

/** @brief Compare two warranty values. */
bool Warranty::operator==(const Warranty& other) const {
    return warrantyId == other.warrantyId &&
           assetId == other.assetId &&
           vendorId == other.vendorId &&
           startDate == other.startDate &&
           endDate == other.endDate &&
           terms == other.terms;
}

/** @brief Stream a warranty value. */
std::ostream& operator<<(std::ostream& os, const Warranty& warranty) {
    os << warranty.to_string();
    return os;
}
