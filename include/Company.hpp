/**
 *  Company.hpp - Company Class Definition - This class is responsible
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

#ifndef __COMPANY__
#define __COMPANY__

#include <string>
#include <iostream>
#include "Address.hpp"
#include "Person.hpp"
#include "PhoneNumber.hpp"

using namespace std;

/**
 * Represents a Company with essential information.
 */
class Company {
private:
    string companyName; /**< The name of the company */
    Address companyAddress; /**< The address of the company */
    PhoneNumber companyPhoneNumber; /**< The phone number of the company */
    Person poc; /**< Person of Contact for the company */

public:
    /**
     * Get the company name.
     * @return The name of the company
     */
    string getCompanyName() const;

    /**
     * Set the company name.
     * @param name The name of the company
     */
    void setCompanyName(const string& name);

    /**
     * Get the company address.
     * @return The address of the company
     */
    Address getCompanyAddress() const;

    /**
     * Set the company address.
     * @param address The address of the company
     */
    void setCompanyAddress(const Address& address);

    /**
     * Get the company phone number.
     * @return The phone number of the company
     */
    PhoneNumber getCompanyPhoneNumber() const;

    /**
     * Set the company phone number.
     * @param phoneNumber The phone number of the company
     */
    void setCompanyPhoneNumber(const PhoneNumber& phoneNumber);

    /**
     * Get the person of contact for the company.
     * @return The person of contact
     */
    Person getPersonOfContact() const;

    /**
     * Set the person of contact for the company.
     * @param person The person of contact
     */
    void setPersonOfContact(const Person& person);

    /**
     * Convert Company information to a string.
     * @return A string representation of the Company
     */
    string to_string() const;

    /**
     * Overload the equality operator to compare two Company objects.
     * @param other The Company object to compare with
     * @return True if the Company objects are equal, false otherwise
     */
    bool operator==(const Company& other) const;
};

#endif

