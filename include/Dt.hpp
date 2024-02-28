/**
 *  Dt.hpp - Dt Class Definition - This class is responsible
 *           for defining a Date.
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

#ifndef __DT__
#define __DT__

#include <string>
#include <stdexcept>

using namespace std;

typedef string String;

/**
 * The Dt class represents a date with year, month, and day.
 * It provides methods to set and get the year, month, and day, 
 * convert the date to a string, compare two dates, and get the day of the week.
 */
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

    /**
     * Default constructor for the Dt class.
     * It is called when a new date object is created without any parameters.
     */
    Dt();

    /**
     * Constructor for the Dt class that takes year, month, and day as parameters.
     * It is called when a new date object is created with specified year, month, and day.
     *
     * @param year An integer representing the year to be set.
     * @param month An integer representing the month to be set.
     * @param day An integer representing the day to be set.
     */
    Dt(const int& year, const int& month, const int& day);

    /**
     * Destructor for the Dt class.
     * It is called when a date object is destroyed or goes out of scope.
     */
    ~Dt();

    /**
     * Converts a date object into a string in the format MM/DD/YYYY.
     *
     * @return A string representing the date.
     */
    string toString();

    /**
     * Sets the year of a date object.
     * The year must be within a valid range.
     *
     * @param year An integer representing the year to be set.
     */
    void set_year(int year);

    /**
     * Sets the month of a date object.
     * The month must be within a valid range.
     *
     * @param month An integer representing the month to be set.
     */
    void set_month(int month);

    /**
     * Sets the day of a date object.
     * The day must be within a valid range depending on the month and whether the year is a leap year.
     *
     * @param day An integer representing the day to be set.
     */
    void set_day(int day);

    /**
     * Gets the year of a date object.
     *
     * @return An integer representing the year of the date object.
     */
    int get_year();

    /**
     * Gets the month of a date object.
     *
     * @return An integer representing the month of the date object.
     */
    int get_month();

    /**
     * Gets the day of a date object.
     *
     * @return An integer representing the day of the date object.
     */
    int get_day();

    /**
     * Overloads the equality operator to compare two date objects.
     *
     * @param other A reference to another date object to be compared with.
     * @return A boolean value indicating whether the current date object is equal to the other date object.
     */
    bool operator==(const Dt& other) const;

    /**
     * Compares if the current date object is equal to another date object.
     *
     * @param other A reference to another date object to be compared with.
     * @return A boolean value indicating whether the current date object is equal to the other date object.
     */
    bool isEqualTo(const Dt& other) const;

    /**
     * Gets the day of the week for the date.
     *
     * @return A string representing the day of the week.
     */
    std::string getDayOfWeek() const;
};

#endif
