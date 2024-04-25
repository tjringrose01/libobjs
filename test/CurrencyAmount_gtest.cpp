/**
 *  CurrencyAmount_gtest.cpp - libobjs Class Tests
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
#include "CurrencyAmount.hpp"

using namespace std;

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
