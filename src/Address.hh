/**
 *  Address.hh - Address Class Definition - This class is responsible
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

#ifndef __Address__
#define __Address__

#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

typedef string String;

class Address {
private:
    /* Private Members */
    string streetAddressLine1;
    string streetAddressLine2;
    string city;
    string state;
    string zipCode;

    /* Private Methods */

public:
    /* Public Members */

    /* Public Methods */
    Address();
    Address(string streetAddressLine1, string streetAddressLine2, string city, string state, string zipCode);
    ~Address();

    string toString();
};

#endif
