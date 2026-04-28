/**
 *  Person.cpp - Person Class Implementation - This class is
 *               responsible for reading in the configuration file and
 *               storing it's informtion within it's class members
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

#include "Person.hpp"

/**
 * Default constructor for the Person class.
 */
Person::Person() = default;

/**
 * Constructor for the Person class that initializes the object with provided information.
 *
 * @param firstName The first name of the person (string).
 * @param middleName The middle name of the person (string).
 * @param lastName The last name of the person (string).
 * @param address The address of the person (Address).
 * @param phoneNumber The phone number of the person (PhoneNumber).
 * @param sex The gender of the person (int).
 * @param birthdate The birthdate of the person (Dt).
 * @param ssn The social security number of the person (SSN).
 * @param email The email address of the person (EmailAddress).
 */
Person::Person(const std::string& firstName, const std::string& middleName,
               const std::string& lastName, const Address& address, const PhoneNumber& phoneNumber,
               int sex, const Dt& birthdate, const SSN& ssn, const EmailAddress& email)
    : firstName(firstName), lastName(lastName), middleName(middleName), address(address),
      phoneNumber(phoneNumber), sex(sex), birthdate(birthdate), ssn(ssn), email(email) {}

/**
 * Destructor for the Person class.
 */
Person::~Person() = default;

/**
 * Method to convert the object into a string representation.
 *
 * @return A string representing the object in a formatted manner.
 */
std::string Person::to_string() const {
    std::string retString = "";

    retString += firstName;
    retString += " ";
    retString += middleName;
    retString += " ";
    retString += lastName;
    retString += "; ";
    retString += getSexLabel();
    retString += "; ";
    retString += ssn.to_string();
    retString += "; ";
    retString += address.to_string();
    retString += "; ";
    retString += phoneNumber.to_string();
    retString += "; ";
    retString += birthdate.to_string();
    retString += "; ";
    retString += email.to_string();

    return retString;
}

/**
 * This method returns the label corresponding to the sex of the person.
 *
 * @return A string representing the sex label (Male, Female, or Unknown).
 */
std::string Person::getSexLabel() const {
    std::string label = "Unknown";
    switch (sex) {
    case 0:
        label = "Male";
        break;

    case 1:
        label = "Female";
        break;
    }

    return label;
}

/**
 * Get the full name of the person.
 *
 * @return The full name of the person.
 */
std::string Person::getName() const {
    return firstName + " " + lastName;
}

/**
 * Get the email address of the person.
 *
 * @return The email address of the person.
 */
EmailAddress Person::getEmail() const {
    return email;
}

/**
 * Get the phone number of the person.
 *
 * @return The phone number of the person.
 */
PhoneNumber Person::getPhoneNumber() const {
    return phoneNumber;
}

/**
 * Overload the equality operator (==) to check if two Person objects are equal.
 *
 * @param other The other Person object to compare to.
 * @return bool True if the Person objects are equal, false otherwise.
 */
bool Person::operator==(const Person& other) const {
    return (firstName == other.firstName && middleName == other.middleName &&
            lastName == other.lastName && address == other.address &&
            phoneNumber == other.phoneNumber && sex == other.sex && birthdate == other.birthdate &&
            ssn == other.ssn && email == other.email);
}

/**
 * Overload the stream insertion operator (<<) to output the Person object using to_string().
 *
 * @param os The output stream.
 * @param person The Person object to output.
 * @return ostream The output stream with the Person object.
 */
std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << person.to_string();
    return os;
}
