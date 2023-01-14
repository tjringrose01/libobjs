/**
 *  DateTime.hh - DateTime Class Definition - This class is responsible
 *              for defining a date and time. 
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

#ifndef __DateTime__
#define __DateTime__

#include <string>
#include <iostream>

using namespace std;

class DateTime {
private:
    /* Private Members */
    uint64_t epoch;

    /* Private Methods */

public:
    /* Public Members */

    /* Public Methods */
    int getMonth();
    int getYear();
    DateTime();
    ~DateTime();
    string toString();
};

#endif
