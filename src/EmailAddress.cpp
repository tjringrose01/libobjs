/**
 *  EmailAddress.cc - libobjs Class Implementation - This class is
 *                   responsible for defining a phone number.
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
#include <stdexcept>
#include "EmailAddress.h"

using namespace std;

#define PROGRAM "libobjs"

EmailAddress::EmailAddress() {
	this->name = "";
	this->domain = "";
}

EmailAddress::EmailAddress(string email) {
	if ( email.length() > 254 )
		throw invalid_argument( "ERROR: received invalid value for email" );

	if ( email.find("@") == string::npos )
		throw invalid_argument( "ERROR: received invalid value for email" );

	set_name(email);
	set_domain(email);
}

/**
 * Housekeeping
 */
EmailAddress::~EmailAddress() {
}

/**
PhoneNumber& PhoneNumber::operator=(const PhoneNumber& address) {
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

string EmailAddress::toString() {

    string retString = "";

    retString = get_emailAddress();
    
    return(retString);
}

void EmailAddress::set_name(string email) {
	//Parse out name from emailAddress
	int n = email.find("@");

	if ( n == string::npos )
		throw std::invalid_argument( "ERROR: received invalid value for email" );

	if ( email.substr(0,n).length() == 0 )
		throw std::invalid_argument( "ERROR: received invalid value for email" );

	this->name = email.substr(0,n);

	//cout << this->name << endl;
}

void EmailAddress::set_domain(string email) {
	//Parse out domain from emailAddress
	int n = email.find("@");

	if ( n == string::npos )
		throw std::invalid_argument( "ERROR: received invalid value for email" );

	if ( email.substr(n+1,email.length() - n).length() == 0 )
		throw std::invalid_argument( "ERROR: received invalid value for email" );

	this->domain = email.substr(n+1,email.length() - n);
}

string EmailAddress::get_name() {
    return(this->name);
}

string EmailAddress::get_domain() {
    return(this->domain);
}

string EmailAddress::get_emailAddress() {
    return(this->name + "@" + this->domain);
}
