/**
 *  Invoice_gtest.cpp - libobjs Class Tests
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
#include "CurrencyAmount.hpp"
#include "Dt.hpp"
#include "Invoice.hpp"
#include "InvoiceItem.hpp"
#include "PhoneNumber.hpp"

using namespace std;

/**
 * Tests for Invoice Class Tests for Invoice Class Tests for Invoice Class Tests for Invoice Class
 * Tests for Invoice Class Tests for Invoice Class Tests for Invoice Class Tests for Invoice Class
 * Tests for Invoice Class Tests for Invoice Class Tests for Invoice Class Tests for Invoice Class
*/
TEST(InvoiceTest, DefaultConstructor) {
    Invoice invoice;

    EXPECT_EQ(Dt(), invoice.getInvoiceDate());
    EXPECT_EQ(Dt(), invoice.getDueDate());
    //EXPECT_EQ(vector<InvoiceItem>(), invoice.getLineItems());
    EXPECT_EQ(Company(), invoice.getBuyer());
    EXPECT_EQ(Company(), invoice.getSeller());
    EXPECT_EQ("", invoice.getTerms());
    EXPECT_EQ("", invoice.getInvoiceNo());
    EXPECT_EQ("", invoice.getPoNo());
    EXPECT_EQ("", invoice.getNotes());
    EXPECT_EQ(CurrencyAmount(0), invoice.getSubtotal());
    EXPECT_EQ(CurrencyAmount(0), invoice.getTaxes());
    EXPECT_EQ(CurrencyAmount(0), invoice.getShipping());
    EXPECT_EQ(CurrencyAmount(0), invoice.getTotal());
}

/*
// Test for setSeller method
TEST(InvoiceTest, SetSeller) {
    Company company;
    Invoice invoice;

    company.setCompanyName("Seller Inc.");
    invoice.setSeller(company);

    EXPECT_EQ("Seller Inc.", invoice.getSeller().getCompanyName());
}

// Test for setTerms method
TEST(InvoiceTest, SetTerms) {
    Invoice invoice;

    invoice.setTerms("Net 30");

    EXPECT_EQ("Net 30", invoice.getTerms());
}

// Test for setInvoiceNo method
TEST(InvoiceTest, SetInvoiceNo) {
    Invoice invoice;

    invoice.setInvoiceNo("INV-001");

    EXPECT_EQ("INV-001", invoice.getInvoiceNo());
}

// Test for setPoNo method
TEST(InvoiceTest, SetPoNo) {
    Invoice invoice;

    invoice.setPoNo("PO-123");

    EXPECT_EQ("PO-123", invoice.getPoNo());
}

// Test for setNotes method
TEST(InvoiceTest, SetNotes) {
    Invoice invoice;

    invoice.setNotes("Please pay within 15 days.");

    EXPECT_EQ("Please pay within 15 days.", invoice.getNotes());
}

// Test for setSubtotal method
TEST(InvoiceTest, SetSubtotal) {
    Invoice invoice;
    CurrencyAmount amount("USD", 100.50);

    invoice.setSubtotal(amount);

    EXPECT_EQ(amount, invoice.getSubtotal());
}

// Test for setTaxes method
TEST(InvoiceTest, SetTaxes) {
    Invoice invoice;
    CurrencyAmount amount("USD", 10.25);

    invoice.setTaxes(amount);

    EXPECT_EQ(amount, invoice.getTaxes());
}

// Test for setShipping method
TEST(InvoiceTest, SetShipping) {
    Invoice invoice;
    CurrencyAmount amount("USD", 5.75);

    invoice.setShipping(amount);

    EXPECT_EQ(amount, invoice.getShipping());
}

// Test for setTotal method
TEST(InvoiceTest, SetTotal) {
    Invoice invoice;
    CurrencyAmount amount("USD", 120.50);

    invoice.setTotal(amount);

    EXPECT_EQ(amount, invoice.getTotal());
}
*/
