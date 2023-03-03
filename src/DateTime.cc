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

/**
 * Human-readable time	Seconds
 * 1 hour		3600 seconds
 * 1 day		86400 seconds
 * 1 week		604800 seconds
 * 1 month (30.44 days)	2629743 seconds
 * 1 year (365.24 days)	31556926 seconds
 */

#define SEC_IN_MIN   60
#define SEC_IN_HOUR  3600
#define SEC_IN_DAY   86400
#define SEC_IN_WEEK  604800
#define SEC_IN_MONTH 2629743
#define SEC_IN_YEAR  31556926

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

int DateTime::getDay() {
    int day = getEpoch() % SEC_IN_MONTH;
    day = day / SEC_IN_DAY;
    return(day);
}

int DateTime::getHour() {
    int hour = getEpoch() % SEC_IN_DAY;

    cout << "Debug (hour): " << hour << endl;
    //hour = hour / SEC_IN_HOUR;

    return(hour);
}

int DateTime::getMinute() {
    int minute = getEpoch() % SEC_IN_HOUR / SEC_IN_MIN;
    return(minute);
}

int DateTime::getSecond() {
    return( getEpoch() % SEC_IN_MIN );
}

/**
 * epochmonth = ((current year number - 1970 - 1) * 12) + current month number
 */
int DateTime::getMonth() {
    int month = getEpoch() % SEC_IN_YEAR;

    month = month / SEC_IN_MONTH;

    month += 1;

    return(month);
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

    cout << "Year:   " << getYear() << endl;

    cout << "Month:  " << getMonth() << endl;

    cout << "Day:    " << getDay() << endl;

    cout << "Hour:   " << getHour() << endl;

    cout << "Minute: " << getMinute() << endl;

    cout << "Second: " << getSecond() << endl;

    return(retString);
}
