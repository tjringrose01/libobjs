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

/**
Address& Address::operator=(const Address& address) {
    if (this != &address) // make sure not same object
    {
        //menuName = cm.menuName;
        //menuTitle = cm.menuTitle;
        //foreMenuColor = cm.foreMenuColor;
        //backMenuColor = cm.backMenuColor;
        //debugFlag = cm.debugFlag;

        //menuItems.clear();
        //for (int x=0; x < cm.menuItems.size(); x++)
        //{
            //menuItems.push_back(cm.menuItems.at(x));
        //}
    }
    return *this;    // Return ref for multiple assignment
}
*/



string Address::toString() {

    string retString = "";

    retString += "; LINE1 = ";
    retString += this->streetAddressLine1;
    retString += "; LINE2 = ";
    retString += this->streetAddressLine2;
    retString += "; CITY = ";
    retString += this->city;
    retString += "; STATE = ";
    retString += this->state;
    retString += "; ZIP = ";
    retString += this->zipCode;
    
    return(retString);
}
