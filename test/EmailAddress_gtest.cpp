/**
 *  EmailAddress_gtest.cpp - libobjs Class Tests
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
#include "EmailAddress.hpp"

using namespace std;

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
