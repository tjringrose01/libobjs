/**
 *  Person.cpp - Person Class Implementation - This class is
 *               responsible for reading in the configuration file and
 *               storing it's informtion within it's class members
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
#include "Person.hpp"
#include "Dt.hpp"

using namespace std;

#define PROGRAM "libobjs"

/**
 * Constructor for the Person class that initializes the object with provided information.
 *
 * @param firstName The first name of the person (string).
 * @param middleName The middle name of the person (string).
 * @param lastName The last name of the person (string).
 * @param address The address of the person (Address).
 * @param phoneNumber The phone number of the person (PhoneNumber).
 * @param sex The gender of the person (int).
 * @param birthdate The birthdate of the person (Dt).
 * @param ssn The social security number of the person (SSN).
 * @param email The email address of the person (EmailAddress).
 */
Person::Person(string firstName, string middleName, string lastName, Address address, PhoneNumber phoneNumber, int sex, Dt birthdate, SSN ssn, EmailAddress email) {
    this->firstName = firstName;
    this->middleName = middleName;
    this->lastName = lastName;
    this->address = address;
    this->phoneNumber = phoneNumber;
    this->sex = sex;
    this->birthdate = birthdate;
    this->ssn = ssn;
    this->email = email;
}
Person::~Person() {
}

/**
 * Method to convert the object into a string representation.
 *
 * @return A string representing the object in a formatted manner.
 */
string Person::toString() {
    string retString = "";

    retString += firstName;
    retString += " ";
    retString += middleName;
    retString += " ";
    retString += lastName;
    retString += "; ";
    retString += getSexLabel();
    retString += "; ";
    retString += ssn.toString();
    retString += "; ";
    retString += address.to_string();
    retString += "; ";
    retString += phoneNumber.to_string();
    retString += "; ";
    retString += birthdate.to_string();
    retString += "; ";
    retString += email.toString();

    return(retString);
}

/**
 * This method returns the label corresponding to the sex of the person.
 *
 * @return A string representing the sex label (Male, Female, or Unknown).
 */
string Person::getSexLabel() {
    string label = "Unknown";
    switch (this->sex) {
        case 0:
            label = "Male";
            break;
        
        case 1:
            label = "Female";
            break;

    }

    return(label);
}

/*
CursedMenu& CursedMenu::operator=(const CursedMenu& cm) {
    if (this != &cm) // make sure not same object
    {
        menuName = cm.menuName;
        menuTitle = cm.menuTitle;
        foreMenuColor = cm.foreMenuColor;
        backMenuColor = cm.backMenuColor;
        debugFlag = cm.debugFlag;

        menuItems.clear();
        for (int x=0; x < cm.menuItems.size(); x++)
        {
            menuItems.push_back(cm.menuItems.at(x));
        }
    }
    return *this;    // Return ref for multiple assignment
}
*/
