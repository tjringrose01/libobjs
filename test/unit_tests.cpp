/**
 *  unit_tests.cc - libobjs Class Tests
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

#include <gtest/gtest.h>
#include "PhoneNumber.hpp"
#include "Dt.hpp"
#include "EmailAddress.hpp"
#include "CurrencyAmount.hpp"
#include "Company.hpp"

using namespace std;

// Test for creating and formatting phone numbers
TEST(PhoneNumberTest, Formatting) {
    PhoneNumber number1("1", "555", "123", "4567");
    PhoneNumber number2("1", "555", "123", "4567");
    PhoneNumber number3("1", "555", "234", "5678");

    EXPECT_EQ("+15551234567", number1.toE164Format());
    EXPECT_EQ("(555) 123-4567", number1.toLocalFormat());

    // Check equality
    EXPECT_TRUE(number1 == number2);
    EXPECT_FALSE(number1 == number3);
}


// Test for invalid phone numbers
TEST(PhoneNumberTest, InvalidPhoneNumber) {
    // Invalid country code
    EXPECT_THROW(PhoneNumber("123", "555", "123", "4567"), invalid_argument);

    // Invalid part (empty area code)
    EXPECT_THROW(PhoneNumber("1", "", "123", "4567"), invalid_argument);

    // Invalid part (non-numeric prefix)
    EXPECT_THROW(PhoneNumber("1", "555", "12a", "4567"), invalid_argument);
}

// Test for creating and formatting
TEST(DtTest, Formatting) {
    Dt dt1(2023, 12, 31);
    Dt dt2(2023, 12, 31);
    Dt dt3(2023, 1, 1);

    EXPECT_EQ("12/31/2023", dt1.to_string());
    EXPECT_EQ("12/31/2023", dt2.to_string());
    EXPECT_EQ("01/01/2023", dt3.to_string());

    // Check equality
    EXPECT_TRUE(dt1 == dt2);
    EXPECT_FALSE(dt1 == dt3);
}

// Test for invalid dates
TEST(DtTest, InvalidDate) {
    // Invalid year
    EXPECT_THROW(Dt(-1,1,1), invalid_argument);
    EXPECT_THROW(Dt(10000,1,1), invalid_argument);
    EXPECT_THROW(Dt(1900,2,29), invalid_argument);

    // Invalid month
    EXPECT_THROW(Dt(2023,-1,1), invalid_argument);
    EXPECT_THROW(Dt(2023,13,1), invalid_argument);
    
    // Invalid day
    EXPECT_THROW(Dt(2023,1,-1), invalid_argument);
    EXPECT_THROW(Dt(2023,2,28), invalid_argument);
    EXPECT_THROW(Dt(2023,3,32), invalid_argument);
    EXPECT_THROW(Dt(2023,4,31), invalid_argument);
    EXPECT_THROW(Dt(2023,5,32), invalid_argument);
    EXPECT_THROW(Dt(2023,6,31), invalid_argument);
    EXPECT_THROW(Dt(2023,7,32), invalid_argument);
    EXPECT_THROW(Dt(2023,8,32), invalid_argument);
    EXPECT_THROW(Dt(2023,9,31), invalid_argument);
    EXPECT_THROW(Dt(2023,10,32), invalid_argument);
    EXPECT_THROW(Dt(2023,11,31), invalid_argument);
    EXPECT_THROW(Dt(2023,12,32), invalid_argument);


}

// Test for EmailAddress class
TEST(EmailAddressTest, ValidEmail) {
    EmailAddress email1("test@example.com");
    EmailAddress email2("john.doe@example.com");
    EmailAddress email3("john.doe@example.com");

    EXPECT_EQ("test", email1.get_name());
    EXPECT_EQ("example.com", email1.get_domain());
    EXPECT_EQ("john.doe", email2.get_name());
    EXPECT_EQ("example.com", email2.get_domain());

    EXPECT_TRUE(email2 == email3);
    EXPECT_FALSE(email1 == email2);
}

TEST(EmailAddressTest, InvalidEmail) {
    EXPECT_THROW(EmailAddress("invalid_email"), invalid_argument);
    EXPECT_THROW(EmailAddress("missing@domain"), invalid_argument);
}

TEST(EmailAddressTest, SpecialCases) {
    // "@" at the beginning
    EXPECT_THROW(EmailAddress("@invalid.com"), invalid_argument);

    // "@" at the end
    EXPECT_THROW(EmailAddress("invalid@"), invalid_argument);

    // Empty name
    EXPECT_THROW(EmailAddress("@example.com"), invalid_argument);

    // Empty domain
    EXPECT_THROW(EmailAddress("test@"), invalid_argument);
}

// Test for CurrencyAmount class
TEST(CurrencyAmountTest, DoubleAmountComparison) {
    CurrencyAmount amount1("USD", 10.5);
    CurrencyAmount amount2("USD", 20.75);
    CurrencyAmount amount3("USD", 10.5);

    EXPECT_TRUE(amount2 > amount1);
    EXPECT_TRUE(amount2 >= amount1);
    EXPECT_FALSE(amount1 > amount2);
    EXPECT_FALSE(amount1 >= amount2);
    EXPECT_TRUE(amount1 >= amount3);
    EXPECT_TRUE(amount1 == amount3);
}

TEST(CurrencyAmountTest, IntegerAmountComparison) {
    CurrencyAmount amount1("EUR", 100);
    CurrencyAmount amount2("EUR", 200);
    CurrencyAmount amount3("EUR", 100);

    EXPECT_TRUE(amount2 > amount1);
    EXPECT_TRUE(amount2 >= amount1);
    EXPECT_FALSE(amount1 > amount2);
    EXPECT_FALSE(amount1 >= amount2);
    EXPECT_TRUE(amount1 >= amount3);
    EXPECT_TRUE(amount1 == amount3);
}

TEST(CurrencyAmountTest, OutputOperator) {
    CurrencyAmount amount("GBP", 50);

    stringstream ss;
    ss << amount;

    EXPECT_EQ("50.00 GBP", ss.str());
}

TEST(CompanyTest, CompanyInformation) {
    Company company;

    company.setCompanyName("ABC Inc.");
    company.setCompanyAddress(Address("123 Main St", "City", "State", "12345"));
    company.setCompanyPhoneNumber(PhoneNumber("1", "555", "1234567"));
    
    Person contactPerson("John", "Doe", "Smith", Address("456 Elm St", "Town", "State", "54321"), PhoneNumber("1", "555", "7654321"), 0, Dt(1990, 1, 15), SSN("123-45-6789"), EmailAddress("john.doe@example.com"));
    company.setPersonOfContact(contactPerson);

    EXPECT_EQ("ABC Inc.", company.getCompanyName());
    EXPECT_EQ("123 Main St, City, State, 12345", company.getCompanyAddress().to_string());
    EXPECT_EQ("+15551234567", company.getCompanyPhoneNumber().toE164Format());
    EXPECT_EQ("John Smith", company.getPersonOfContact().getName());
    EXPECT_EQ("+15557654321", company.getPersonOfContact().getPhoneNumber().toE164Format());
    EXPECT_EQ("john.doe@example.com", company.getPersonOfContact().getEmail().to_string());
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
