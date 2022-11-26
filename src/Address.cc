/**
 *  Address.cc - libobjs Class Implementation - This class is
 *               responsible for defining an address.
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
#include <iostream>
#include "Address.hh"

using namespace std;
typedef string String;

#define PROGRAM "libobjs"

Address::Address(string streetAddressLine1, string streetAddressLine2, string city, string state, string zipCode) {
    this->streetAddressLine1 = streetAddressLine1;
    this->streetAddressLine2 = streetAddressLine2;
    this->city = city;
    this->state = state;
    this->zipCode = zipCode;
}

Address::Address() {
    this->streetAddressLine1 = "";
    this->streetAddressLine2 = "";
    this->city = "";
    this->state = "";
    this->zipCode = "";
}

/**
 * Housekeeping
 */
Address::~Address() {
}

string Address::toString() {

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

void Address::set_streetAddressLine1(string streetAddressLine1) {
    this->streetAddressLine1 = streetAddressLine1;
}

void Address::set_streetAddressLine2(string streetAddressLine2) {
    this->streetAddressLine2 = streetAddressLine2;
}

void Address::set_city(string city) {
    this->city = city;
}

void Address::set_state(string state) {
    this->state = state;
}

void Address::set_zipCode(string zipCode) {
    this->zipCode = zipCode;
}

string Address::get_streetAddressLine1() {
    return(this->streetAddressLine1);
}

string Address::get_streetAddressLine2() {
    return(this->streetAddressLine2);
}

string Address::get_city() {
    return(this->city);
}

string Address::get_state() {
    return(this->state);
}

string Address::get_zipCode() {
    return(this->zipCode);
}

/*
Address Address::operator=(const Address address) {
    //if (this != address) // make sure not same object
    //{
        Address tmp = Address(address.streetAddressLine1, address.streetAddressLine2, address.city, address.state, address.zipCode);
    //}
    //return this;    // Return ref for multiple assignment
    return(tmp);
}
*/
