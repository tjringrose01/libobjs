/**
 *  SSN.hh - SSN Class Definition - This class is responsible
 *           for defining a Dt.
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

#ifndef __DT__
#define __DT__

#include <string>
#include <stdexcept>

using namespace std;

typedef string String;

class Dt {
private:
    /* Private Members */
    int year;
    int month;
    int day;

    /* Private Methods */

public:
    /* Public Members */

    /* Public Methods */
    Dt();
    Dt(int year, int month, int day);
    ~Dt();

    string toString();

    void set_year(int year);
    void set_month(int month);
    void set_day(int day);

    int get_year();
    int get_month();
    int get_day();
};

#endif
