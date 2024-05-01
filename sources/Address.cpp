/**
 *  Address.cc - libobjs Class Implementation - This class is
 *               responsible for defining an address.
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

#include <string>
#include <iostream>
#include "Address.hpp"

using namespace std;

#define PROGRAM "libobjs"

/**
 * Constructor for Address class that initializes the address with provided information.
 *
 * @param streetAddressLine1 The first line of the street address (string).
 * @param streetAddressLine2 The second line of the street address (string).
 * @param city The city of the address (string).
 * @param state The state of the address (string).
 * @param zipCode The ZIP code of the address (string).
 */
Address::Address(string streetAddressLine1, string streetAddressLine2, string city, string state, string zipCode) {
    this->streetAddressLine1 = streetAddressLine1;
    this->streetAddressLine2 = streetAddressLine2;
    this->city = city;
    this->state = state;
    this->zipCode = zipCode;
}

/**
 * Constructor for Address class that initializes the address with provided information.
 *
 * @param streetAddressLine1 The first line of the street address (string).
 * @param city The city of the address (string).
 * @param state The state of the address (string).
 * @param zipCode The ZIP code of the address (string).
 */
Address::Address(string streetAddressLine1, string city, string state, string zipCode) {
    this->streetAddressLine1 = streetAddressLine1;
    this->streetAddressLine2 = "";
    this->city = city;
    this->state = state;
    this->zipCode = zipCode;
}

/**
 * Default constructor for Address class.
 */
Address::Address() = default;

/**
 * Destructor for the Address class.
 */
Address::~Address() {
}

/**
 * Convert the address object to a string representation.
 *
 * @return A string representing the address.
 */
string Address::to_string() const {

    string retString = "";

    retString += this->streetAddressLine1;
    retString += ", ";

    if (this->streetAddressLine2.length() > 0) {
        retString += this->streetAddressLine2;
        retString += ", ";
    }

    retString += this->city;
    retString += ", ";
    retString += this->state;
    retString += ", ";
    retString += this->zipCode;
    
    return(retString);
}

/**
 * Set the first line of the street address.
 *
 * @param streetAddressLine1 The first line of the street address (string).
 */
void Address::set_streetAddressLine1(string streetAddressLine1) {
    this->streetAddressLine1 = streetAddressLine1;
}

/**
 * Set the second line of the street address.
 *
 * @param streetAddressLine2 The second line of the street address (string).
 */
void Address::set_streetAddressLine2(string streetAddressLine2) {
    this->streetAddressLine2 = streetAddressLine2;
}

/**
 * Set the city of the address.
 *
 * @param city The city of the address (string).
 */
void Address::set_city(string city) {
    this->city = city;
}

/**
 * Set the state of the address.
 *
 * @param state The state of the address (string).
 */
void Address::set_state(string state) {
    this->state = state;
}

/**
 * Set the ZIP code of the address.
 *
 * @param zipCode The ZIP code of the address (string).
 */
void Address::set_zipCode(string zipCode) {
    this->zipCode = zipCode;
}

/**
 * Get the first line of the street address.
 *
 * @return The first line of the street address (string).
 */
string Address::get_streetAddressLine1() const {
    return(this->streetAddressLine1);
}

/**
 * Get the second line of the street address.
 *
 * @return The second line of the street address (string).
 */
string Address::get_streetAddressLine2() const {
    return(this->streetAddressLine2);
}

/**
 * Get the city of the address.
 *
 * @return The city of the address (string).
 */
string Address::get_city() const {
    return(this->city);
}

/**
 * Get the state of the address.
 *
 * @return The state of the address (string).
 */
string Address::get_state() const {
    return(this->state);
}

/**
 * Get the ZIP code of the address.
 *
 * @return The ZIP code of the address (string).
 */
string Address::get_zipCode() const {
    return(this->zipCode);
}

/**
 * Check if this Address is equal to another Address.
 *
 * @param other The other Address to compare to.
 * @return bool True if the Addresses are equal, false otherwise.
 */
bool Address::isEqualTo(const Address& other) const {
    return (this->streetAddressLine1 == other.streetAddressLine1 &&
            this->streetAddressLine2 == other.streetAddressLine2 &&
            this->city == other.city &&
            this->state == other.state &&
            this->zipCode == other.zipCode);
}

/**
 * Overload the equality operator (==) to check if two Address objects are equal.
 *
 * @param other The other Address object to compare to.
 * @return bool True if the Address objects are equal, false otherwise.
 */
bool Address::operator==(const Address& other) const {
    return isEqualTo(other);
}

/**
 * Overload the stream insertion operator (<<) to output the address in a formatted manner using the to_string() method.
 *
 * @param os The output stream.
 * @param address The address to output.
 * @return ostream The output stream with the address in a formatted manner.
 */
ostream& operator<<(ostream& os, const Address& address) {
    os << address.to_string();
    return os;
}


