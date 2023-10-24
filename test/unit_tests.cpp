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
#include "../src/PhoneNumber.h"

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


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
