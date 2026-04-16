/**
 *  PhoneNumber_gtest.cpp - libobjs Class Tests
 *
 *  Copyright 2026 Timothy Ringrose
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
#include <sstream>
#include <random>
#include <chrono>

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


// Additional tests for edge cases, stream operator, and more invalid inputs
TEST(PhoneNumberTest, StreamOperatorAndNonUSFormatting) {
    PhoneNumber usNum("1", "555", "123", "4567");
    PhoneNumber ukNum("44", "20", "7946", "0000");

    // operator<< prepends a '+' to toLocalFormat()
    std::stringstream ss;
    ss << usNum;
    EXPECT_EQ("+15551234567", ss.str());

    ss.str(""); ss.clear();
    ss << ukNum;
    // Note: current implementation will produce a double-plus for non-US
    EXPECT_EQ("+442079460000", ss.str());
}

TEST(PhoneNumberTest, MoreInvalidInputs) {
    // Leading plus in parts should be rejected
    EXPECT_THROW(PhoneNumber("+1", "555", "123", "4567"), invalid_argument);
    EXPECT_THROW(PhoneNumber("1", "+555", "123", "4567"), invalid_argument);

    // Whitespace in parts is invalid
    EXPECT_THROW(PhoneNumber("1", " 555", "123", "4567"), invalid_argument);
    EXPECT_THROW(PhoneNumber("1", "555", "12 3", "4567"), invalid_argument);
}

TEST(PhoneNumberTest, DefaultConstructorAndLongNumbers) {
    // Default constructed phone number currently yields a single '+'
    PhoneNumber def;
    EXPECT_EQ("+", def.toE164Format());
    EXPECT_EQ("+", def.toLocalFormat());

    // Very long numeric parts are accepted (no explicit limits)
    std::string longArea(20, '1');
    std::string longPrefix(20, '2');
    std::string longNumber(20, '3');
    PhoneNumber longNum("1", longArea, longPrefix, longNumber);
    EXPECT_EQ("+1" + longArea + longPrefix + longNumber, longNum.toE164Format());
}

TEST(PhoneNumberTest, InequalityDifferentCountry) {
    PhoneNumber a("1", "555", "123", "4567");
    PhoneNumber b("44", "555", "123", "4567");
    EXPECT_FALSE(a == b);
}


TEST(PhoneNumberTest, RandomizedValidAndInvalidInputs) {
    // This test performs many randomized iterations to catch edge cases.
    const int ITER = 200000; // number of randomized cases for each category (x1000)

    std::vector<std::string> allowedCountries = {"1","44","49","33","81","86","91","7","55"};

    auto now = std::chrono::steady_clock::now().time_since_epoch().count();
    std::mt19937 rng(static_cast<unsigned int>(now));
    std::uniform_int_distribution<int> lenDist(1, 12);
    std::uniform_int_distribution<int> countryDist(0, static_cast<int>(allowedCountries.size()-1));
    std::uniform_int_distribution<int> charDist(0, 9);

    auto genNumeric = [&](int len) {
        std::string s; s.reserve(len);
        for (int i = 0; i < len; ++i) s.push_back(static_cast<char>('0' + (rng() % 10)));
        return s;
    };

    // Randomized valid inputs
    for (int i = 0; i < ITER; ++i) {
        std::string country = allowedCountries[countryDist(rng)];
        int aLen = 2 + (rng() % 4); // 2-5
        int pLen = 2 + (rng() % 4); // 2-5
        int nLen = 3 + (rng() % 8); // 3-10
        std::string area = genNumeric(aLen);
        std::string prefix = genNumeric(pLen);
        std::string number = genNumeric(nLen);

        PhoneNumber pn(country, area, prefix, number);
        // E.164 should be +country + area + prefix + number
        EXPECT_EQ("+" + country + area + prefix + number, pn.toE164Format());
        // toLocalFormat for country "1" should use US format (parentheses)
        if (country == "1") {
            // basic sanity: contains area and prefix and number characters
            std::string local = pn.toLocalFormat();
            EXPECT_NE(std::string::npos, local.find(area));
            EXPECT_NE(std::string::npos, local.find(prefix));
            EXPECT_NE(std::string::npos, local.find(number.substr(0, std::min<int>(3, (int)number.size()))));
        } else {
            // Non-US returns E.164
            EXPECT_EQ(pn.toLocalFormat(), pn.toE164Format());
        }
    }

    // Randomized invalid inputs
    std::uniform_int_distribution<int> invalidType(0,8);
    for (int i = 0; i < ITER; ++i) {
        int t = invalidType(rng);
        std::string country, area, prefix, number;

        switch (t) {
            case 0: // invalid country (numeric but not allowed)
                country = std::to_string(100 + (rng() % 900));
                area = genNumeric(3);
                prefix = genNumeric(3);
                number = genNumeric(4);
                EXPECT_THROW(PhoneNumber(country, area, prefix, number), std::invalid_argument);
                break;
            case 1: // non-numeric in area
                country = allowedCountries[countryDist(rng)];
                area = genNumeric(2) + "a" + genNumeric(1);
                prefix = genNumeric(3);
                number = genNumeric(4);
                EXPECT_THROW(PhoneNumber(country, area, prefix, number), std::invalid_argument);
                break;
            case 2: // leading plus sign
                country = "+" + allowedCountries[countryDist(rng)];
                area = genNumeric(3);
                prefix = genNumeric(3);
                number = genNumeric(4);
                EXPECT_THROW(PhoneNumber(country, area, prefix, number), std::invalid_argument);
                break;
            case 3: // whitespace in parts
                country = allowedCountries[countryDist(rng)];
                area = " " + genNumeric(2);
                prefix = genNumeric(3);
                number = genNumeric(4);
                EXPECT_THROW(PhoneNumber(country, area, prefix, number), std::invalid_argument);
                break;
            case 4: // empty parts
                country = allowedCountries[countryDist(rng)];
                area = "";
                prefix = genNumeric(3);
                number = genNumeric(4);
                EXPECT_THROW(PhoneNumber(country, area, prefix, number), std::invalid_argument);
                break;
            case 5: // non-numeric in prefix
                country = allowedCountries[countryDist(rng)];
                area = genNumeric(3);
                prefix = genNumeric(2) + "x" + genNumeric(1);
                number = genNumeric(4);
                EXPECT_THROW(PhoneNumber(country, area, prefix, number), std::invalid_argument);
                break;
            case 6: // non-numeric in number
                country = allowedCountries[countryDist(rng)];
                area = genNumeric(3);
                prefix = genNumeric(3);
                number = genNumeric(2) + "-" + genNumeric(2);
                EXPECT_THROW(PhoneNumber(country, area, prefix, number), std::invalid_argument);
                break;
            case 7: // extremely long country code
                country = std::string(64, '9');
                area = genNumeric(3);
                prefix = genNumeric(3);
                number = genNumeric(4);
                EXPECT_THROW(PhoneNumber(country, area, prefix, number), std::invalid_argument);
                break;
            case 8: // empty or zero country
                country = (rng() % 2) ? std::string("") : std::string("0");
                area = genNumeric(3);
                prefix = genNumeric(3);
                number = genNumeric(4);
                EXPECT_THROW(PhoneNumber(country, area, prefix, number), std::invalid_argument);
                break;
        }
    }
}


// Check operator<< produces E.164 (single leading '+') — this will expose current double-plus bug
TEST(PhoneNumberTest, StreamOperatorShouldMatchE164) {
    const int ITER2 = 1000;
    auto now2 = std::chrono::steady_clock::now().time_since_epoch().count();
    std::mt19937 rng2(static_cast<unsigned int>(now2 ^ 0xabcdef));
    std::vector<std::string> allowedCountries = {"1","44","49","33","81","86","91","7","55"};
    std::uniform_int_distribution<int> countryDist2(0, static_cast<int>(allowedCountries.size()-1));

    auto genNumeric2 = [&](int len) {
        std::string s; s.reserve(len);
        for (int i = 0; i < len; ++i) s.push_back(static_cast<char>('0' + (rng2() % 10)));
        return s;
    };

    for (int i = 0; i < ITER2; ++i) {
        std::string country = allowedCountries[countryDist2(rng2)];
        std::string area = genNumeric2(3);
        std::string prefix = genNumeric2(3);
        std::string number = genNumeric2(4);

        PhoneNumber pn(country, area, prefix, number);
        std::stringstream ss;
        ss << pn;
        // Expect the stream output to equal E.164 (single '+') — if implementation is wrong, this will fail
        EXPECT_EQ(pn.toE164Format(), ss.str());
    }
}
