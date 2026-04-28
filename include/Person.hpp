/**
 *  Person.hpp - Person Class Definition - This class is responsible
 *               for defining a person. 
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

#ifndef LIBOBJS_PERSON_HPP
#define LIBOBJS_PERSON_HPP

#include "Address.hpp"
#include "Dt.hpp"
#include "EmailAddress.hpp"
#include "PhoneNumber.hpp"
#include "SSN.hpp"
#include <ostream>
#include <string>
/**
 * @brief Person model.
 */

class Person {
private:
  std::string firstName;
  std::string lastName;
  std::string middleName;
  Address address;
  PhoneNumber phoneNumber;
  // sex: 0 = male, 1 = female
  int sex;
  Dt birthdate;
  SSN ssn;
  EmailAddress email;

public:
  /**
   * Default constructor for Person.
   */
  Person();

  /**
   * Constructor for Person with provided information.
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
  Person(const std::string& firstName, const std::string& middleName, const std::string& lastName,
         const Address& address, const PhoneNumber& phoneNumber, int sex, const Dt& birthdate,
         const SSN& ssn, const EmailAddress& email);

  /**
   * Destructor for Person.
   */
  ~Person();

  /**
   * Convert Person information to a string.
   *
   * @return A string representation of the Person.
   */
  std::string to_string() const;

  /**
   * Get the full name of the person.
   *
   * @return The full name of the person.
   */
  std::string getName() const;

  /**
   * Get the label corresponding to the sex of the person.
   *
   * @return A string representing the sex label (Male, Female, or Unknown).
   */
  std::string getSexLabel() const;

  /**
   * Get the email address of the person.
   *
   * @return The email address of the person.
   */
  EmailAddress getEmail() const;

  /**
   * Get the phone number of the person.
   *
   * @return The phone number of the person.
   */
  PhoneNumber getPhoneNumber() const;

  /**
   * Overload the equality operator (==) to check if two Person objects are equal.
   *
   * @param other The other Person object to compare to.
   * @return bool True if the Person objects are equal, false otherwise.
   */
  bool operator==(const Person& other) const;

  /**
   * Overload the stream insertion operator (<<) to output the Person object using to_string().
   *
   * @param os The output stream.
   * @param person The Person object to output.
   * @return ostream The output stream with the Person object.
   */
  friend std::ostream& operator<<(std::ostream& os, const Person& person);
};

#endif // LIBOBJS_PERSON_HPP
