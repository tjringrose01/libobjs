/**
 *  Person.cc - Person Class Implementation - This class is
 *              responsible for reading in the configuration file and
 *              storing it's informtion within it's class members
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
 *  along with libobjs.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <string>
#include "Person.hh"
#include "Dt.hh"

using namespace std;
typedef string String;

#define PROGRAM "libobjs"

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
 * Method to try and show te object in string form.
 */
String Person::toString() {
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
    retString += address.toString();
    retString += "; ";
    retString += phoneNumber.toString();
    retString += "; ";
    retString += birthdate.toString();
    retString += "; ";
    retString += email.toString();

    return(retString);
}

String Person::getSexLabel() {
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
