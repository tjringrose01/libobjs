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
#define EPOCH_YEAR 1970

DateTime::DateTime() {
    this->epoch_ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

DateTime::~DateTime() {
}

unsigned long DateTime::getEpoch_ms() {
    return(this->epoch_ms);
}

unsigned long DateTime::getEpoch() {
    return(this->epoch_ms / 1000);
}

/**
 * epochmonth = ((current year number - 1970 - 1) * 12) + current month number
 */
int DateTime::getMonth() {
    ( ( getYear() - 1970 - 1 ) * 12 ) 


    return(0);
}

/**
 * seconds / 60 / 60 / 24 / 365 + 1970
 */
int DateTime::getYear() {
    int year = EPOCH_YEAR + getEpoch() / 60 / 60 / 24 / 365 ;
    return(year);
}

/**
 * Method to try and show te object in string form.
 */
string DateTime::toString() {
    string retString = "";

    retString += "";

    cout << getEpoch_ms() << " milliseconds since the Epoch\n";
    cout << getEpoch() << " seconds since the Epoch\n";

    cout << "Year: " << getYear() << endl;

    cout << "Month: " << getMonth() << endl;

    return(retString);
}
