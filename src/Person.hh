/**
 *  Person.hh - Person Class Definition - This class is responsible
 *              for defining a person. 
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

#ifndef __Person__
#define __Person__

#include <string>
#include "Address.hh"
#include "PhoneNumber.hh"
//#include "EmailAddress.hh"
//#include "SSN.hh"

using namespace std;

class Person {
private:
    /* Private Members */
    string firstName;
    string lastName;
    string middleName;

    Address address;

    PhoneNumber phoneNumber;

    // sex - 0=male; 1=female
    int sex;

    //email address

    //date birthdate

    //SSN ssn


    /* Private Methods */

public:
    /* Public Members */

    /* Public Methods */
    Person();
    Person(string firstName, string middleName, string lastName, Address address, PhoneNumber phoneNumber, int sex);
    ~Person();
    String toString();

    String getSexLabel();

    //CursedMenu& operator=(const CursedMenu& cm);
};

#endif
