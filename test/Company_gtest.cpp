/**
 *  Company_gtest.cpp - libobjs Class Tests
 *
 *  Copyright 2024 Timothy Ringrose
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

#include <gtest/gtest.h>
#include "Company.hpp"
#include "EmailAddress.hpp"
#include "PhoneNumber.hpp"

using namespace std;

TEST(CompanyTest, CompanyInformation) {
    Company company;

    company.setCompanyName("ABC Inc.");
    company.setCompanyAddress(Address("123 Main St", "City", "State", "12345"));
    company.setCompanyPhoneNumber(PhoneNumber("1", "555", "123", "4567"));
    
    Person contactPerson("John", "Doe", "Smith", Address("456 Elm St", "Town", "State", "54321"), PhoneNumber("1", "555", "765", "4321"), 0, Dt(1990, 1, 15), SSN("123","45","6789"), EmailAddress("john.doe@example.com"));
    company.setPersonOfContact(contactPerson);

    EXPECT_EQ("ABC Inc.", company.getCompanyName());
    EXPECT_EQ("123 Main St, City, State, 12345", company.getCompanyAddress().to_string());
    EXPECT_EQ("+15551234567", company.getCompanyPhoneNumber().toE164Format());
    EXPECT_EQ("John Smith", company.getPersonOfContact().getName());
    EXPECT_EQ("+15557654321", company.getPersonOfContact().getPhoneNumber().toE164Format());
    EXPECT_EQ("john.doe@example.com", company.getPersonOfContact().getEmail().to_string());
}
