/**
 *  HDD.hh - HDD Class Definition - This class is responsible
 *              for defining a Hard Disk Drive. 
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

#ifndef __HDD__
#define __HDD__

#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

typedef string String;

class HDD {
private:
    /* Private Members */
    string manufacturer;
    string model;
    string serialNo;
    string type;
    string interface;

    /* Private Methods */

public:
    /* Public Members */

    /* Public Methods */
    HDD();
    ~HDD();

    string toString();

    //Address operator=(const Address address);
};

#endif
