/**
 *  Dt.cc - libobjs Class Implementation - This class is
 *           responsible for defining a Dt.
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
 *  along with libobjs. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <string>
#include "Dt.hh"

using namespace std;

#define PROGRAM "libobjs"

#define MIN_YEAR 1
#define MAX_YEAR 9999

#define MIN_MONTH 1
#define MAX_MONTH 12

#define MIN_DAY 1
#define MAX_DAY 31

Dt::Dt(int year, int month, int day) {
    set_year(year);
    set_month(month);
    set_day(day);
}

Dt::Dt() {
    this->year = 1900;
    this->month = 1;
    this->day = 1;
}

/**
 * Housekeeping
 */
Dt::~Dt() {
}

string Dt::toString() {

    string retString = "";

    if (this->month < 10) retString += "0";
    retString += std::to_string(this->month);

    retString += "/";

    if (this->day < 10) retString += "0";
    retString += std::to_string(this->day);

    retString += "/";

    retString += std::to_string(this->year);
    
    return(retString);
}

void Dt::set_year(int year) {
    bool isValid = false;

    if (year >= MIN_YEAR && year <= MAX_YEAR)
        isValid = true;

    if ( isValid )
        this->year = year;
    else
        throw std::invalid_argument( "ERROR: received invalid value for year" );
}

void Dt::set_month(int month) {
    bool isValid = false;

    if (month >= MIN_MONTH && month <= MAX_MONTH)
        isValid = true;

    if ( isValid )
        this->month = month;
    else
        throw std::invalid_argument( "ERROR: received invalid value for month" );
}

void Dt::set_day(int day) {
    bool isValid = false;

    if ( this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12) {
	if ( day >= 1 && day <= 31 )
		isValid = true;
    }

    if ( this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11) {
	if ( day >= 1 && day <= 30 )
		isValid = true;
    }

    if ( this->month == 2 ) {
	    if ( year % 4 == 0 )
		    if ( year % 100 == 0 && year % 400 != 0 ) {
			    // 28 days
		    	if ( day >= 1 && day <= 28 )
				isValid = true;
		    } else {
			    // 29 days
		    	if ( day >= 1 && day <= 29 )
				isValid = true;
		    }
    }


    if ( isValid )
        this->day = day;
    else
        throw std::invalid_argument( "ERROR: received invalid value for day" );
}

int Dt::get_year() {
    return(this->year);
}

int Dt::get_month() {
    return(this->month);
}

int Dt::get_day() {
    return(this->day);
}
