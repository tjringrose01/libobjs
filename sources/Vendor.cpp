/**
 *  Vendor.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the Vendor model.
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
 *  - Vendor identity data is shared by maintenance and warranty records.
 */

#include "Vendor.hpp"

/** @brief Construct a default vendor. */
Vendor::Vendor() : vendorId(""), name(""), contactName(""), contactEmail(""), contactPhone("") {}

/** @brief Construct a vendor with explicit values. */
Vendor::Vendor(const std::string& vendorId,
               const std::string& name,
               const std::string& contactName,
               const std::string& contactEmail,
               const std::string& contactPhone)
    : vendorId(vendorId),
      name(name),
      contactName(contactName),
      contactEmail(contactEmail),
      contactPhone(contactPhone) {}

/** @brief Get the vendor identifier. */
std::string Vendor::getVendorId() const { return vendorId; }

/** @brief Get the vendor name. */
std::string Vendor::getName() const { return name; }

/** @brief Get the vendor contact name. */
std::string Vendor::getContactName() const { return contactName; }

/** @brief Get the vendor contact email. */
std::string Vendor::getContactEmail() const { return contactEmail; }

/** @brief Get the vendor contact phone. */
std::string Vendor::getContactPhone() const { return contactPhone; }

/** @brief Set the vendor identifier. */
void Vendor::setVendorId(const std::string& vendorId) { this->vendorId = vendorId; }

/** @brief Set the vendor name. */
void Vendor::setName(const std::string& name) { this->name = name; }

/** @brief Set the vendor contact name. */
void Vendor::setContactName(const std::string& contactName) { this->contactName = contactName; }

/** @brief Set the vendor contact email. */
void Vendor::setContactEmail(const std::string& contactEmail) { this->contactEmail = contactEmail; }

/** @brief Set the vendor contact phone. */
void Vendor::setContactPhone(const std::string& contactPhone) { this->contactPhone = contactPhone; }

/** @brief Convert this vendor to a human-readable string. */
std::string Vendor::to_string() const {
    return "vendorId=" + vendorId +
           "; name=" + name +
           "; contactName=" + contactName +
           "; contactEmail=" + contactEmail +
           "; contactPhone=" + contactPhone;
}

/** @brief Compare two vendor values. */
bool Vendor::operator==(const Vendor& other) const {
    return vendorId == other.vendorId &&
           name == other.name &&
           contactName == other.contactName &&
           contactEmail == other.contactEmail &&
           contactPhone == other.contactPhone;
}

/** @brief Stream a vendor value. */
std::ostream& operator<<(std::ostream& os, const Vendor& vendor) {
    os << vendor.to_string();
    return os;
}
