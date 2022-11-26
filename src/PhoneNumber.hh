/**
 *  PhoneNumber.hh - PhoneNumber Class Definition - This class is responsible
 *                   for defining a person. 
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

#ifndef __PhoneNumber__
#define __PhoneNumber__

#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

typedef string String;

class PhoneNumber {
private:
    /* Private Members */
    string countryCode;
    string areaCode;
    string telephonePrefix;
    string lineNumber;

    /* Private Methods */

public:
    /* Public Members */

    /* Public Methods */
    PhoneNumber();
    PhoneNumber(string countryCode, string areaCode, string telephonePrefix, string lineNumber);
    ~PhoneNumber();

    string toString();

    void set_countryCode(string countryCode);
    void set_areaCode(string areaCode);
    void set_telephonePrefix(string telephonePrefix);
    void set_lineNumber(string lineNumber);

    string get_countryCode();
    string get_areaCode();
    string get_telephonePrefix();
    string get_lineNumber();
    
};

#endif
