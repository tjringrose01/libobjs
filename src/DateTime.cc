/**
 *  DateTime.cc - DateTime Class Implementation - This class is
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
#include <chrono>
#include "DateTime.hh"

using namespace std;
using namespace std::chrono;

#define PROGRAM "libobjs"

DateTime::DateTime() {
    this->epoch = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

DateTime::~DateTime() {
}

int DateTime::getMonth() {
    return(0);
}

int DateTime::getYear() {
    uint64_t year = epoch / 1000 / 60 / 60 / 24 ;
    return(year);
}

/**
 * Method to try and show te object in string form.
 */
string DateTime::toString() {
    string retString = "";

    retString += "";

    cout << epoch << " milliseconds since the Epoch\n";

    cout << "Year: " << getYear() << endl;

    return(retString);
}
