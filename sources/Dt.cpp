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
#include "Dt.hpp"

using namespace std;

#define PROGRAM "libobjs"

#define MIN_YEAR 1
#define MAX_YEAR 9999

#define MIN_MONTH 1
#define MAX_MONTH 12

#define MIN_DAY 1
#define MAX_DAY 31

/**
 * This is a constructor for the Dt class that takes year, month, and day as parameters.
 * It is called when a new date object is created with specified year, month, and day.
 *
 * @param year An integer representing the year to be set.
 * @param month An integer representing the month to be set.
 * @param day An integer representing the day to be set.
 */
Dt::Dt(const int& year, const int& month, const int& day) {
    set_year(year);
    set_month(month);
    set_day(day);
}

/**
 * This is the default constructor for the Dt class.
 * It is called when a new date object is created without any parameters.
 * Currently, it does not perform any specific initialization tasks.
 */
Dt::Dt() = default;

/**
 * This is the destructor for the Dt class.
 * It is called when a date object is destroyed or goes out of scope.
 * Currently, it does not perform any specific cleanup tasks.
 */
Dt::~Dt() {
}

/**
 * This method is used to convert a date object into a string.
 * The resulting string is in the format MM/DD/YYYY.
 *
 * @return A string representing the date. If the month or day is less than 10, 
 * they are padded with a leading zero to ensure a consistent string length.
 */
string Dt::toString() {
    // Initialize an empty string
    string retString = "";

    // If the month is less than 10, add a leading zero
    if (this->month < 10) retString += "0";
    
    // Add the month to the string
    retString += to_string(this->month);

    // Add a slash to separate month and day
    retString += "/";

    // If the day is less than 10, add a leading zero
    if (this->day < 10) retString += "0";

    // Add the day to the string
    retString += to_string(this->day);

    // Add a slash to separate day and year
    retString += "/";

    // If the year is less than 10, add a leading zero
    if (this->year < 10) retString += "0";

    // If the year is less than 100, add a leading zero
    if (this->year < 100) retString += "0";

    // If the year is less than 1000, add a leading zero
    if (this->year < 1000) retString += "0";

    // Add the year to the string
    retString += std::to_string(this->year);

    // Return the final date string in the format MM/DD/YYYY
    return(retString);
}

/**
 * This method is used to set the year of a date object.
 * The year must be within a valid range defined by MIN_YEAR and MAX_YEAR.
 *
 * @param year An integer representing the year to be set.
 * @throws std::invalid_argument If the provided year is not within the valid range.
 */
void Dt::set_year(int year) {
    
    // Initialize a boolean to check if the year is valid
    bool isValid = false;

    // If the year is within the valid range, set isValid to true
    if (year >= MIN_YEAR && year <= MAX_YEAR)
        isValid = true;

    // If the year is valid, set the year or else thow an exception
    if ( isValid )
        this->year = year;
    else
        throw std::invalid_argument( "ERROR: received invalid value for year" );

    // All done
    return;
}

/**
 * This method is used to set the month of a date object.
 * The month must be within a valid range defined by MIN_MONTH and MAX_MONTH.
 *
 * @param month An integer representing the month to be set.
 * @throws std::invalid_argument If the provided month is not within the valid range.
 */
void Dt::set_month(int month) {
    
    // Initialize a boolean to check if the month is valid
    bool isValid = false;

    // If the month is within the valid range, set isValid to true
    if (month >= MIN_MONTH && month <= MAX_MONTH)
        isValid = true;

    // If the month is valid, set the year or else thow an exception
    if ( isValid )
        this->month = month;
    else
        throw std::invalid_argument( "ERROR: received invalid value for month" );
}

/**
 * This method is used to set the day of a date object.
 * The day must be within a valid range depending on the month and whether the year is a leap year.
 *
 * @param day An integer representing the day to be set.
 * @throws std::invalid_argument If the provided day is not within the valid range.
 */
void Dt::set_day(int day) {
    
    // Initialize a boolean to check if the day is valid
    bool isValid = false;

    // If the month has 31 days and the day is within the valid range, set isValid to true
    if ( this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12) {
	if ( day >= 1 && day <= 31 )
		isValid = true;
    }

    // If the month has 30 days and the day is within the valid range, set isValid to true
    if ( this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11) {
	if ( day >= 1 && day <= 30 )
		isValid = true;
    }

    // If the month is February, check if the year is a leap year to determine the valid range for the day
    if ( this->month == 2 ) {
	    if ( year % 4 == 0 )
		    if ( year % 100 == 0 && year % 400 != 0 ) {
                        // If the year is not a leap year, the valid range for the day is 1-28
		    	if ( day >= 1 && day <= 28 )
				isValid = true;
		    } else {
                        // If the year is a leap year, the valid range for the day is 1-29
		    	if ( day >= 1 && day <= 29 )
				isValid = true;
		    }
    }

    // If the day is valid, set the day or else throw an exception
    if ( isValid )
        this->day = day;
    else
        throw std::invalid_argument( "ERROR: received invalid value for day" );

    // All done
    return;
}

/**
 * This method is used to get the year of a date object.
 *
 * @return An integer representing the year of the date object.
 */
int Dt::get_year() {
    return(this->year);
}

/**
 * This method is used to get the month of a date object.
 *
 * @return An integer representing the month of the date object.
 */
int Dt::get_month() {
    return(this->month);
}

/**
 * This method is used to get the day of a date object.
 *
 * @return An integer representing the day of the date object.
 */
int Dt::get_day() {
    return(this->day);
}

/**
 * This method is used to compare if the current date object is equal to another date object.
 *
 * @param other A reference to another date object to be compared with.
 * @return A boolean value indicating whether the current date object is equal to the other date object.
 *         Returns true if the year, month, and day of both date objects are the same, otherwise returns false.
 */
bool Dt::isEqualTo(const Dt& other) const {
    return (year == other.year &&
            month == other.month &&
            day == other.day);
}

/**
 * This method overloads the equality operator to compare two date objects.
 *
 * @param other A reference to another date object to be compared with.
 * @return A boolean value indicating whether the current date object is equal to the other date object.
 *         It calls the isEqualTo method to compare the year, month, and day of both date objects.
 */
bool Dt::operator==(const Dt& other) const {
    return isEqualTo(other);
}

/**
 * Gets the day of the week for the date.
 *
 * @return A string representing the day of the week.
 */
string Dt::getDayOfWeek() const {
    // Array with weekday names
    std::string week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    // Adjust month number for algorithm
    int adjustedMonth = this->month;
    int adjustedYear = this->year;
    if (month < 3) {
        adjustedMonth += 12;
        adjustedYear--;
    }

    // Tomohiko Sakamoto's Algorithm
    int h = (this->day + 2*adjustedMonth + 3*(adjustedMonth+1)/5 + adjustedYear + adjustedYear/4 - adjustedYear/100 + adjustedYear/400) % 7;

    // Return the name of the weekday
    return week[h];
}

