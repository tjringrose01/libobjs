/**
 *  Location.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the Location model.
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
 *  - A location may reference a parent location to model hierarchy.
 */

#include "Location.hpp"

/** @brief Construct a default location. */
Location::Location() : locationId(""), name(""), parentLocationId(""), address("") {}

/** @brief Construct a location with explicit values. */
Location::Location(const std::string& locationId,
                   const std::string& name,
                   const std::string& parentLocationId,
                   const std::string& address)
    : locationId(locationId), name(name), parentLocationId(parentLocationId), address(address) {}

std::string Location::getLocationId() const { return locationId; }

std::string Location::getName() const { return name; }

std::string Location::getParentLocationId() const { return parentLocationId; }

std::string Location::getAddress() const { return address; }

void Location::setLocationId(const std::string& locationId) { this->locationId = locationId; }

void Location::setName(const std::string& name) { this->name = name; }

void Location::setParentLocationId(const std::string& parentLocationId) {
    this->parentLocationId = parentLocationId;
}

void Location::setAddress(const std::string& address) { this->address = address; }

/**
 * @brief Produce a deterministic key/value snapshot of the location state.
 * @details Intended for diagnostics rather than end-user presentation.
 */
std::string Location::to_string() const {
    return "locationId=" + locationId +
           "; name=" + name +
           "; parentLocationId=" + parentLocationId +
           "; address=" + address;
}

/**
 * @brief Compare two locations for strict field-by-field equality.
 */
bool Location::operator==(const Location& other) const {
    return locationId == other.locationId &&
           name == other.name &&
           parentLocationId == other.parentLocationId &&
           address == other.address;
}

std::ostream& operator<<(std::ostream& os, const Location& location) {
    os << location.to_string();
    return os;
}
