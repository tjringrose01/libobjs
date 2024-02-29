/**
 *  EmailAddress.cpp - libobjs Class Implementation - This class is
 *                     responsible for defining an email address.
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
 *  along with libobjs. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <string>
#include <stdexcept>
#include "EmailAddress.hpp"

using namespace std;

#define PROGRAM "libobjs"

/**
 * Default constructor for EmailAddress class.
 * Initializes name and domain to empty strings.
 */
EmailAddress::EmailAddress() {
	this->name = "";
	this->domain = "";
}

/**
 * Constructor for EmailAddress class that takes an email address.
 * Validates the email address and sets name and domain accordingly.
 *
 * @param email The email address to set.
 * @throws invalid_argument if the email is invalid.
 */
EmailAddress::EmailAddress(string email) {
	if ( email.length() > 254 )
		throw invalid_argument( "ERROR: received invalid value for email" );

	size_t atPos = email.find("@");
	if ( atPos == string::npos )
		throw invalid_argument( "ERROR: received invalid value for email" );

	set_name(email.substr(0, atPos));
	set_domain(email.substr(atPos + 1));
}

/**
 * Destructor for EmailAddress class.
 * Performs housekeeping tasks.
 */
EmailAddress::~EmailAddress() {
}

/**
 * Get the email address as a string.
 *
 * @return The email address.
 */
string EmailAddress::to_string() const {
    return(get_emailAddress());
}

/**
 * Set the name part of the email address.
 *
 * @param email The email address to extract the name from.
 * @throws invalid_argument if the email is invalid.
 */
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

/**
 * Set the domain part of the email address.
 *
 * @param email The email address to extract the domain from.
 * @throws invalid_argument if the email is invalid.
 */
void EmailAddress::set_domain(string email) {
	//Parse out domain from emailAddress
	int n = email.find("@");

	if ( n == string::npos )
		throw std::invalid_argument( "ERROR: received invalid value for email - " + email );

	if ( email.substr(n+1,email.length() - n).length() == 0 )
		throw std::invalid_argument( "ERROR: received invalid value for email - " + email );

	this->domain = email.substr(n+1,email.length() - n);
}

/**
 * Get the name part of the email address.
 *
 * @return The name part of the email address.
 */
string EmailAddress::get_name() const {
    return(this->name);
}

/**
 * Get the domain part of the email address.
 *
 * @return The domain part of the email address.
 */
string EmailAddress::get_domain() const {
    return(this->domain);
}

/**
 * Get the full email address.
 *
 * @return The full email address.
 */
string EmailAddress::get_emailAddress() const {
    return(this->name + "@" + this->domain);
}

/**
 * Check if the email address is equal to another email address.
 *
 * @param other The other email address to compare to.
 * @return bool True if the email addresses are equal, false otherwise.
 */
bool EmailAddress::IsEqualTo(const EmailAddress& other) const {
    return (this->name == other.name && this->domain == other.domain);
}

/**
 * Overload the equality operator (==) to compare two email addresses using IsEqualTo member function.
 *
 * @param other The other email address to compare to.
 * @return bool True if the email addresses are equal, false otherwise.
 */
bool EmailAddress::operator==(const EmailAddress& other) const {
	return IsEqualTo(other);
}

/**
 * Overload the stream insertion operator (<<) to output the email address using to_string().
 *
 * @param os The output stream.
 * @param email The email address to output.
 * @return ostream The output stream with the email address.
 */
ostream& operator<<(ostream& os, const EmailAddress& email) {
    os << email.to_string();
    return os;
}



