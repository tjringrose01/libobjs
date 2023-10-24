/**
 *  SSN.h - SSN Class Definition - This class is responsible
 *           for defining a Social Security Number. 
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

#ifndef __SSN__
#define __SSN__

#include <string>

using namespace std;

typedef string String;

class SSN {
private:
    /* Private Members */
    string areaNo;
    string groupNo;
    string serialNo;

    /* Private Methods */

public:
    /* Public Members */

    /* Public Methods */
    SSN();
    SSN(string areaNo, string groupNo, string serialNo);
    ~SSN();

    string toString();

    void set_areaNo(string areaNo);
    void set_groupNo(string groupNo);
    void set_serialNo(string serialNo);

    string get_areaNo();
    string get_groupNo();
    string get_serialNo();
};

#endif
