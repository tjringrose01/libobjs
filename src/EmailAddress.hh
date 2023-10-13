/**
 *  EmailAddress.hh - EmailAddress Class Definition - This class is responsible
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

#ifndef __EmailAddress
#define __EmailAddress

#include <stdlib.h>
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

class EmailAddress {
private:
    /* Private Members */
    string name;
    string domain;

    /* Private Methods */
    void set_name(string email);
    void set_domain(string email);

public:
    /* Public Members */

    /* Public Methods */
    EmailAddress(string email);
    EmailAddress();
    ~EmailAddress();

    string toString();

    void set_emailAddress(string email);

    string get_name();
    string get_domain();
    string get_emailAddress();
    
};

#endif
