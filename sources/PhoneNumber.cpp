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

#include "PhoneNumber.hpp"
#include <sstream>

using namespace std;

// Initialize the map of valid country codes and names
const unordered_map<string, PhoneNumber::CountryInfo> PhoneNumber::validCountryCodes = {
    { "1",  { "1",     "United States" } },
    { "44", { "44",    "United Kingdom" } },
    { "49", { "49",    "Germany" } },
    { "33", { "33",    "France" } },
    { "81", { "81",    "Japan" } },
    { "86", { "86",    "China" } },
    { "91", { "91",    "India" } },
    { "7",  { "7",     "Russia" } },
    { "55", { "55",    "Brazil" } },
    // Add more country codes and names here
};

/**
 * Default constructor for PhoneNumber with default country code.
 */
PhoneNumber::PhoneNumber() = default;

/**
 * Constructor for PhoneNumber with country code.
 * 
 * @param countryCode The country code of the phone number.
 * @param areaCode The area code of the phone number.
 * @param prefix The prefix of the phone number.
 * @param number The number of the phone number.
 */
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


/**
 * Get the country code of the phone number.
 *
 * @return string The country code.
 */
string PhoneNumber::getCountryCode() const {
    return countryCode_;
}

/**
 * Get the area code of the phone number.
 *
 * @return string The area code.
 */
string PhoneNumber::getAreaCode() const {
    return areaCode_;
}

/**
 * Get the prefix of the phone number.
 *
 * @return string The prefix.
 */
string PhoneNumber::getPrefix() const {
    return prefix_;
}

/**
 * Get the number of the phone number.
 *
 * @return string The number.
 */
string PhoneNumber::getNumber() const {
    return number_;
}

/**
 * Get the phone number in E.164 format.
 *
 * @return string The phone number in E.164 format.
 */
string PhoneNumber::toE164Format() const {
    return "+" + countryCode_ + areaCode_ + prefix_ + number_;
}


/**
 * Get the phone number in local format.
 * If the country code is "1" (United States), the format will be (XXX) YYY-ZZZZ.
 * For other countries, the format will default to E.164 format.
 *
 * @return string The phone number in local format.
 */
string PhoneNumber::toLocalFormat() const {
    if (countryCode_ == "1") {
        // Format for the United States (local format)
        return "(" + areaCode_ + ") " + prefix_ + "-" + number_;
    } else {
        // Format for other countries (E.164 format)
        return toE164Format();
    }
}

/**
 * Convert the phone number to a string representation.
 *
 * @return string The phone number as a string.
 */
string PhoneNumber::to_string() const {
    return toLocalFormat();
}



/**
 * Check if this phone number is equal to another phone number.
 *
 * @param other The other phone number to compare to.
 * @return bool True if the phone numbers are equal, false otherwise.
 */
bool PhoneNumber::isEqualTo(const PhoneNumber& other) const {
    return (countryCode_ == other.countryCode_ &&
            areaCode_ == other.areaCode_ &&
            prefix_ == other.prefix_ &&
            number_ == other.number_);
}

/**
 * Overload the equality operator (==).
 *
 * @param other The other phone number to compare to.
 * @return bool True if the phone numbers are equal, false otherwise.
 */
bool PhoneNumber::operator==(const PhoneNumber& other) const {
    return isEqualTo(other);
}

/**
 * Helper function to validate a phone number part.
 *
 * @param part The part of the phone number to validate.
 * @param partName The name of the part being validated.
 */
void PhoneNumber::validatePart(const string& part, const string& partName) const {
    // Throw an exception if the part is empty
    if (part.empty()) {
        throw invalid_argument(partName + " is empty.");
    }

    // Throw an exception if the part is not numeric
    if (!isNumber(part)) {
        throw invalid_argument(partName + " is not numeric.");
    }
}

/**
 * Check if the given string consists of all numeric characters.
 *
 * @param s The string to check.
 * @return bool True if the string is all numeric, false otherwise.
 */
bool PhoneNumber::isNumber(const string& s) const {
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

/**
 * Overload the stream insertion operator (<<) to output the phone number in E.164 format.
 *
 * @param os The output stream.
 * @param phoneNumber The phone number to output.
 * @return ostream The output stream with the phone number in E.164 format.
 */
ostream& operator<<(ostream& os, const PhoneNumber& phoneNumber) {
    os << "+" << phoneNumber.toLocalFormat();
    return os;
}

