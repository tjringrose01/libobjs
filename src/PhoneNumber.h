/**
 *  PhoneNumber.h - PhoneNumber Class Definition - This class is responsible
 *                  for defining a person. 
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

class PhoneNumber {
public:
    // Empty constructor
    PhoneNumber();

    // Constructor with default country code
    PhoneNumber(const string& areaCode, const string& prefix, const string& number, const string& countryCode = "1");

    // Getter methods
    string getCountryCode() const;
    string getAreaCode() const;
    string getPrefix() const;
    string getNumber() const;

    // Output in E.164 format
    string toE164Format() const;

    // Output in local format for the United States
    string toLocalFormat() const;

    // Output in local format for the United States
    string toString() const;

    // Check if equal to another phone number
    bool isEqualTo(const PhoneNumber& other) const;

    // Overload the equality operator (==)
    bool operator==(const PhoneNumber& other) const;

private:
    // Helper function to validate a phone number part
    void validatePart(const string& part, const string& partName) const;

    struct CountryInfo {
        string countryCode;
        string countryName;
    };

    // Known valid country codes and names
    static const unordered_map<string, CountryInfo> validCountryCodes;

    string countryCode_;
    string areaCode_;
    string prefix_;
    string number_;

    // Determine if string is all numeric characters
    bool isNumber(const string& s) const;
};

#endif // PHONENUMBER_H
