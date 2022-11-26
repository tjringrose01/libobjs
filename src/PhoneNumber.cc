/**
 *  PhoneNumber.cc - libobjs Class Implementation - This class is
 *                   responsible for defining a phone number.
 *
 *  Copyright 2022 Timothy Ringrose
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

#include <string>
#include "PhoneNumber.hh"

using namespace std;

typedef string String;

#define PROGRAM "libobjs"

PhoneNumber::PhoneNumber(string countryCode, string areaCode, string telephonePrefix, string lineNumber) {
    this->countryCode = countryCode;
    this->areaCode = areaCode;
    this->telephonePrefix = telephonePrefix;
    this->lineNumber = lineNumber;
}

PhoneNumber::PhoneNumber() {
    this->countryCode = "";
    this->areaCode = "";
    this->telephonePrefix = "";
    this->lineNumber = "";
}

/**
 * Housekeeping
 */
PhoneNumber::~PhoneNumber() {
}

/**
PhoneNumber& PhoneNumber::operator=(const PhoneNumber& address) {
    if (this != &address) // make sure not same object
    {
        //menuName = cm.menuName;
        //menuTitle = cm.menuTitle;
        //foreMenuColor = cm.foreMenuColor;
        //backMenuColor = cm.backMenuColor;
        //debugFlag = cm.debugFlag;

        //menuItems.clear();
        //for (int x=0; x < cm.menuItems.size(); x++)
        //{
            //menuItems.push_back(cm.menuItems.at(x));
        //}
    }
    return *this;    // Return ref for multiple assignment
}
*/

string PhoneNumber::toString() {

    string retString = "";

    retString += this->countryCode;
    retString += " (";
    retString += this->areaCode;
    retString += ") ";
    retString += this->telephonePrefix;
    retString += "-";
    retString += this->lineNumber;
    
    return(retString);
}

void PhoneNumber::set_countryCode(string countryCode) {
    this->countryCode = countryCode;
}

void PhoneNumber::set_areaCode(string areaCode) {
    this->areaCode = areaCode;
}

void PhoneNumber::set_telephonePrefix(string telephonePrefix) {
    this->telephonePrefix = telephonePrefix;
}

void PhoneNumber::set_lineNumber(string lineNumber) {
    this->lineNumber = lineNumber;
}

string PhoneNumber::get_countryCode() {
    return(this->countryCode);
}

string PhoneNumber::get_areaCode() {
    return(this->areaCode);
}

string PhoneNumber::get_telephonePrefix() {
    return(this->telephonePrefix);
}

string PhoneNumber::get_lineNumber() {
    return(this->lineNumber);
}
