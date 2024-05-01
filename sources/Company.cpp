/**
 *  Company.cpp - Company Class Implementation - This class is responsible
 *                for defining a company. 
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

#include <string>
#include <iostream>
#include "Address.hpp"
#include "Person.hpp"
#include "PhoneNumber.hpp"
#include "Company.hpp"

using namespace std;

/**
 * Get the company name.
 * @return The name of the company
 */
string Company::getCompanyName() const { return companyName; }

/**
 * Set the company name.
 * @param name The name of the company
 */
void Company::setCompanyName(const string& name) { companyName = name; }

/**
 * Get the company address.
 * @return The address of the company
 */
Address Company::getCompanyAddress() const { return companyAddress; }

/**
 * Set the company address.
 * @param address The address of the company
 */
void Company::setCompanyAddress(const Address& address) { companyAddress = address; }

/**
 * Get the company phone number.
 * @return The phone number of the company
 */
PhoneNumber Company::getCompanyPhoneNumber() const { return companyPhoneNumber; }

/**
 * Set the company phone number.
 * @param phoneNumber The phone number of the company
 */
void Company::setCompanyPhoneNumber(const PhoneNumber& phoneNumber) { companyPhoneNumber = phoneNumber; }

/**
 * Get the person of contact for the company.
 * @return The person of contact
 */
Person Company::getPersonOfContact() const { return poc; }

/**
 * Set the person of contact for the company.
 * @param person The person of contact
 */
void Company::setPersonOfContact(const Person& person) { poc = person; }

/**
 * Convert Company information to a string.
 * @return A string representation of the Company
 */
string Company::to_string() const {
    string companyInfo = "Company Name: " + companyName + "\n";
    companyInfo += "Company Address: " + companyAddress.to_string() + "\n";
    companyInfo += "Company Phone Number: " + companyPhoneNumber.toE164Format() + "\n";
    companyInfo += "Person of Contact: " + poc.getName() + "\n";
    companyInfo += "Contact Phone Number: " + poc.getPhoneNumber().toE164Format() + "\n";
    companyInfo += "Contact Email Address: " + poc.getEmail().to_string() + "\n";

    return companyInfo;
}

/**
     * Overload the equality operator to compare two Company objects.
     * @param other The Company object to compare with
     * @return True if the Company objects are equal, false otherwise
     */
    bool Company::operator==(const Company& other) const {
        return companyName == other.getCompanyName() &&
               companyAddress == other.getCompanyAddress() &&
               companyPhoneNumber == other.getCompanyPhoneNumber() &&
               other.getPersonOfContact() == poc;
    }
