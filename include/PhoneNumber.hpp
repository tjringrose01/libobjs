/**
 *  PhoneNumber.h - PhoneNumber Class Definition - This class is responsible
 *                  for defining a Phone Number. 
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
 *  along with libobjs.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

// PhoneNumber.h (Header File)

#ifndef PHONENUMBER_H
#define PHONENUMBER_H

#include <string>
#include <stdexcept>
#include <unordered_map>

using namespace std;

/**
 * PhoneNumber class represents a phone number with country code, area code, prefix, and number.
 */
class PhoneNumber {
public:
    /**
     * Default constructor for PhoneNumber.
     */
    PhoneNumber();

    /**
     * Constructor for PhoneNumber with default country code.
     * 
     * @param countryCode The country code of the phone number.
     * @param areaCode The area code of the phone number.
     * @param prefix The prefix of the phone number.
     * @param number The number of the phone number.
     */
    PhoneNumber(const string& countryCode, const string& areaCode, const string& prefix, const string& number);

    /**
     * Get the country code of the phone number.
     *
     * @return string The country code.
     */
    string getCountryCode() const;

    /**
     * Get the area code of the phone number.
     *
     * @return string The area code.
     */
    string getAreaCode() const;

    /**
     * Get the prefix of the phone number.
     *
     * @return string The prefix.
     */
    string getPrefix() const;

    /**
     * Get the number of the phone number.
     *
     * @return string The number.
     */
    string getNumber() const;

    /**
     * Get the phone number in E.164 format.
     *
     * @return string The phone number in E.164 format.
     */
    string toE164Format() const;

    /**
     * Get the phone number in local format for the United States.
     *
     * @return string The phone number in local format.
     */
    string toLocalFormat() const;

    /**
     * Convert the phone number to a string representation.
     *
     * @return string The phone number as a string.
     */
    string to_string() const;

    /**
     * Check if this phone number is equal to another phone number.
     *
     * @param other The other phone number to compare to.
     * @return bool True if the phone numbers are equal, false otherwise.
     */
    bool isEqualTo(const PhoneNumber& other) const;

    /**
     * Overload the equality operator (==).
     *
     * @param other The other phone number to compare to.
     * @return bool True if the phone numbers are equal, false otherwise.
     */
    bool operator==(const PhoneNumber& other) const;

private:
    /**
     * Helper function to validate a phone number part.
     *
     * @param part The part of the phone number to validate.
     * @param partName The name of the part being validated.
     */
    void validatePart(const string& part, const string& partName) const;

    /**
     * Struct to hold country code and country name information.
     */
    struct CountryInfo {
        string countryCode;
        string countryName;
    };

    /**
     * Map of valid country codes and names.
     */
    static const unordered_map<string, CountryInfo> validCountryCodes;

    string countryCode_;
    string areaCode_;
    string prefix_;
    string number_;

    /**
     * Check if the given string consists of all numeric characters.
     *
     * @param s The string to check.
     * @return bool True if the string is all numeric, false otherwise.
     */
    bool isNumber(const string& s) const;

    /**
     * Overload the stream insertion operator (<<) to output the phone number in E.164 format.
     *
     * @param os The output stream.
     * @param phoneNumber The phone number to output.
     * @return ostream The output stream with the phone number in E.164 format.
     */
    friend ostream& operator<<(ostream& os, const PhoneNumber& phoneNumber);
};

#endif // PHONENUMBER_H
