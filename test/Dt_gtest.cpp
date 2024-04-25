/**
 *  Dt_gtest.cpp - libobjs Class Tests
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
#include "Dt.hpp"

using namespace std;

// Test for default constructor
TEST(DtTest, DefaulConstructor) {
    Dt dt1;
    Dt dt2(1900, 1, 1);

    EXPECT_EQ("01/01/1900", dt1.to_string());
    EXPECT_EQ(dt1.to_string(), dt2.to_string());

    // Check equality
    EXPECT_TRUE(dt1 == dt2);
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
