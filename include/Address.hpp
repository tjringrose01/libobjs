/**
 *  Address.hpp - Address Class Definition - This class is responsible
 *                for defining a person. 
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

#ifndef __ADDRESS__
#define __ADDRESS__

#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

/**
 * Represents an address with street information, city, state, and ZIP code.
 */
class Address {
private:
    /* Private Members */
    string streetAddressLine1;
    string streetAddressLine2;
    string city;
    string state;
    string zipCode;

    /* Private Methods */

public:
    /* Public Members */

    /* Public Methods */
    /**
     * Default constructor for Address class.
     */
    Address();

    /**
     * Constructor for Address class that initializes the address with provided information.
     *
     * @param streetAddressLine1 The first line of the street address (string).
     * @param streetAddressLine2 The second line of the street address (string).
     * @param city The city of the address (string).
     * @param state The state of the address (string).
     * @param zipCode The ZIP code of the address (string).
     */
    Address(string streetAddressLine1, string streetAddressLine2, string city, string state, string zipCode);

    /**
     * Constructor for Address class that initializes the address with provided information.
     *
     * @param streetAddressLine1 The first line of the street address (string).
     * @param city The city of the address (string).
     * @param state The state of the address (string).
     * @param zipCode The ZIP code of the address (string).
     */
    Address(string streetAddressLine1, string city, string state, string zipCode);

    /**
     * Destructor for the Address class.
     */
    ~Address();

    /**
     * Convert the address object to a string representation.
     *
     * @return A string representing the address.
     */
    string to_string() const;

    /**
     * Set the first line of the street address.
     *
     * @param streetAddressLine1 The first line of the street address (string).
     */
    void set_streetAddressLine1(string streetAddressLine1);

    /**
     * Set the second line of the street address.
     *
     * @param streetAddressLine2 The second line of the street address (string).
     */
    void set_streetAddressLine2(string streetAddressLine2);

    /**
     * Set the city of the address.
     *
     * @param city The city of the address (string).
     */
    void set_city(string city);

    /**
     * Set the state of the address.
     *
     * @param state The state of the address (string).
     */
    void set_state(string state);

    /**
     * Set the ZIP code of the address.
     *
     * @param zipCode The ZIP code of the address (string).
     */
    void set_zipCode(string zipCode);

    /**
     * Get the first line of the street address.
     *
     * @return The first line of the street address (string).
     */
    string get_streetAddressLine1() const;

    /**
     * Get the second line of the street address.
     *
     * @return The second line of the street address (string).
     */
    string get_streetAddressLine2() const;

    /**
     * Get the city of the address.
     *
     * @return The city of the address (string).
     */
    string get_city() const;

    /**
     * Get the state of the address.
     *
     * @return The state of the address (string).
     */
    string get_state() const;

    /**
     * Get the ZIP code of the address.
     *
     * @return The ZIP code of the address (string).
     */
    string get_zipCode() const;
    
    /**
     * Check if this Address is equal to another Address.
     *
     * @param other The other Address to compare to.
     * @return bool True if the Addresses are equal, false otherwise.
     */
    bool isEqualTo(const Address& other) const;

    /**
     * Overload the equality operator (==) to check if two Address objects are equal.
     *
     * @param other The other Address object to compare to.
     * @return bool True if the Address objects are equal, false otherwise.
     */
    bool operator==(const Address& other) const;
    
    /**
     * Overload the stream insertion operator (<<) to output the address in a formatted manner.
     *
     * @param os The output stream.
     * @param address The address to output.
     * @return ostream The output stream with the address in a formatted manner.
     */
    friend ostream& operator<<(ostream& os, const Address& address);
};

#endif // __ADDRESS__
