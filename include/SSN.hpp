/**
 *  SSN.hpp - SSN Class Definition - This class is responsible
 *            for defining a Social Security Number. 
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

class SSN {
private:
    /* Private Members */
    /**
     * The area number of the SSN.
     */
    string areaNo;
    
    /**
     * The group number of the SSN.
     */
    string groupNo;
    
    /**
     * The serial number of the SSN.
     */
    string serialNo;

    /* Private Methods */

public:
    /* Public Members */

    /* Public Methods */
    /**
     * Default constructor for SSN.
     */
    SSN();

    /**
     * Constructor for SSN with specified area number, group number, and serial number.
     *
     * @param areaNo The area number of the SSN.
     * @param groupNo The group number of the SSN.
     * @param serialNo The serial number of the SSN.
     */
    SSN(string areaNo, string groupNo, string serialNo);

    /**
     * Destructor for SSN.
     */
    ~SSN();

    /**
     * Convert the SSN to a string representation.
     *
     * @return A string representing the SSN.
     */
    string to_string() const;

    /**
     * Set the area number of the SSN.
     *
     * @param areaNo The area number to set.
     */
    void set_areaNo(string areaNo);

    /**
     * Set the group number of the SSN.
     *
     * @param groupNo The group number to set.
     */
    void set_groupNo(string groupNo);

    /**
     * Set the serial number of the SSN.
     *
     * @param serialNo The serial number to set.
     */
    void set_serialNo(string serialNo);

    /**
     * Get the area number of the SSN.
     *
     * @return The area number of the SSN.
     */
    string get_areaNo() const;

    /**
     * Get the group number of the SSN.
     *
     * @return The group number of the SSN.
     */
    string get_groupNo() const;

    /**
     * Get the serial number of the SSN.
     *
     * @return The serial number of the SSN.
     */
    string get_serialNo() const;

    /**
     * Check if the SSN is equal to another SSN.
     *
     * @param other The other SSN to compare to.
     * @return bool True if the SSNs are equal, false otherwise.
     */
    bool IsEqualTo(const SSN& other) const;

    /**
     * Overload the equality operator (==) to compare two SSNs using IsEqualTo member function.
     *
     * @param other The other SSN to compare to.
     * @return bool True if the SSNs are equal, false otherwise.
     */
    bool operator==(const SSN& other) const;

    /**
     * Overload the stream insertion operator (<<) to output the SSN using to_string().
     *
     * @param os The output stream.
     * @param ssn The SSN object to output.
     * @return ostream The output stream with the SSN.
     */
    friend ostream& operator<<(ostream& os, const SSN& ssn);
};

#endif
