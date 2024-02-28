/**
 *  EmailAddress.hpp - EmailAddress Class Definition - This class is responsible
 *                     for defining a person. 
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

#ifndef __EmailAddress
#define __EmailAddress

#include <stdlib.h>
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

class EmailAddress {
private:
    /* Private Members */
    /**
     * The name part of the email address.
     */
    string name;
    
    /**
     * The domain part of the email address.
     */
    string domain;

    /* Private Methods */
    /**
     * Set the name part of the email address.
     *
     * @param email The email address to extract the name from.
     * @throws invalid_argument if the email is invalid.
     */
    void set_name(string email);

    /**
     * Set the domain part of the email address.
     *
     * @param email The email address to extract the domain from.
     * @throws invalid_argument if the email is invalid.
     */
    void set_domain(string email);

public:
    /* Public Members */

    /* Public Methods */
    /**
     * Constructor for EmailAddress class that takes an email address.
     * Validates the email address and sets name and domain accordingly.
     *
     * @param email The email address to set.
     * @throws invalid_argument if the email is invalid.
     */
    EmailAddress(string email);

    /**
     * Default constructor for EmailAddress class.
     * Initializes name and domain to empty strings.
     */
    EmailAddress();

    /**
     * Destructor for EmailAddress class.
     * Performs housekeeping tasks.
     */
    ~EmailAddress();

    /**
     * Get the email address as a string.
     *
     * @return The email address.
     */
    string to_string() const;

    /**
     * Set the email address.
     *
     * @param email The email address to set.
     */
    void set_emailAddress(string email);

    /**
     * Get the name part of the email address.
     *
     * @return The name part of the email address.
     */
    string get_name() const;

    /**
     * Get the domain part of the email address.
     *
     * @return The domain part of the email address.
     */
    string get_domain() const;

    /**
     * Get the full email address.
     *
     * @return The full email address.
     */
    string get_emailAddress() const;
    
    /**
     * Check if the email address is equal to another email address.
     *
     * @param other The other email address to compare to.
     * @return bool True if the email addresses are equal, false otherwise.
     */
    bool IsEqualTo(const EmailAddress& other) const;

    /**
     * Overload the equality operator (==) to compare two email addresses using IsEqualTo member function.
     *
     * @param other The other email address to compare to.
     * @return bool True if the email addresses are equal, false otherwise.
     */
    bool operator==(const EmailAddress& other) const;

    /**
     * Overload the stream insertion operator (<<) to output the email address.
     *
     * @param os The output stream.
     * @param email The email address to output.
     * @return ostream The output stream with the email address.
     */
    friend ostream& operator<<(ostream& os, const EmailAddress& email);
};

#endif
