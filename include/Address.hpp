/**
 *  Address.hpp - Address Class Definition - This class is responsible
 *                for defining a person. 
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

#ifndef __ADDRESS__
#define __ADDRESS__

#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

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

    void set_streetAddressLine1(string streetAddressLine1);
    void set_streetAddressLine2(string streetAddressLine2);
    void set_city(string city);
    void set_state(string state);
    void set_zipCode(string zipCode);

    string get_streetAddressLine1();
    string get_streetAddressLine2();
    string get_city();
    string get_state();
    string get_zipCode();
    
    //Address operator=(const Address address);
};

#endif // __ADDRESS__
