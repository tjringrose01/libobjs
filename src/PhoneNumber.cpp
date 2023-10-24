/**
 *  PhoneNumber.cpp - libobjs Class Implementation - This class is
 *                    responsible for defining a phone number.
 *
 *  Copyright 2023 Timothy Ringrose
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
 */

// PhoneNumber.cpp (Implementation File)

#include "PhoneNumber.h"
#include <sstream>

using namespace std;

// Initialize the map of valid country codes and names
const unordered_map<string, PhoneNumber::CountryInfo> PhoneNumber::validCountryCodes = {
    { "1", { "1", "United States" } },
    { "44", { "44", "United Kingdom" } },
    { "49", { "49", "Germany" } },
    { "33", { "33", "France" } },
    // Add more country codes and names here
};

// Constructor with default country code
PhoneNumber::PhoneNumber() = default;

// Constructor with default country code
PhoneNumber::PhoneNumber(const string& countryCode, const string& areaCode, const string& prefix, const string& number) {
    validatePart(countryCode, "Country Code");
    if (validCountryCodes.find(countryCode) == validCountryCodes.end()) {
        throw invalid_argument("Invalid country code.");
    }

    validatePart(areaCode, "Area Code");
    validatePart(prefix, "Prefix");
    validatePart(number, "Number");

    countryCode_ = countryCode;
    areaCode_ = areaCode;
    prefix_ = prefix;
    number_ = number;
}

// Getter methods
string PhoneNumber::getCountryCode() const {
    return countryCode_;
}

string PhoneNumber::getAreaCode() const {
    return areaCode_;
}

string PhoneNumber::getPrefix() const {
    return prefix_;
}

string PhoneNumber::getNumber() const {
    return number_;
}

// Output in E.164 format
string PhoneNumber::toE164Format() const {
    return "+" + countryCode_ + areaCode_ + prefix_ + number_;
}

// Output in local format for the United States
string PhoneNumber::toLocalFormat() const {
    if (countryCode_ == "1") {
        // Format for the United States (local format)
        return "(" + areaCode_ + ") " + prefix_ + "-" + number_;
    } else {
        // Format for other countries (E.164 format)
        return toE164Format();
    }
}

// Output in local format for the United States
string PhoneNumber::toString() const {
    return toLocalFormat();
}

// Check if equal to another phone number
bool PhoneNumber::isEqualTo(const PhoneNumber& other) const {
    return (countryCode_ == other.countryCode_ &&
            areaCode_ == other.areaCode_ &&
            prefix_ == other.prefix_ &&
            number_ == other.number_);
}

// Overload the equality operator (==)
bool PhoneNumber::operator==(const PhoneNumber& other) const {
    return isEqualTo(other);
}

// Helper function to validate a phone number part
void PhoneNumber::validatePart(const string& part, const string& partName) const {
    // Throw an exception if we are empty
    if ( part.empty() ) {
        throw invalid_argument(partName + " is empty.");
    }

    // Throw an exception if we are not numeric
    if ( ! isNumber(part) ) {
        throw invalid_argument(partName + " is not numeric.");
    }
}

// Determine if string is all numeric characters
bool PhoneNumber::isNumber(const string& s) const {
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
