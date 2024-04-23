/**
 *  Invoice.cpp - Invoice Class Implementation - This class is responsible
 *                    for defining an Invoice. 
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
 *  along with libobjs.  If not, see <http://www.gnu.org/licenses/>.
 * 
 *  Itemized List of Products/Services: This section details the products or services provided, including a description, quantity, unit price, and total price for each item. It may also include any applicable taxes or discounts.
 * 
 */

#include "Invoice.hpp"
#include "Dt.hpp"
#include "Company.hpp"
#include "CurrencyAmount.hpp"
#include <vector>

using namespace std;

Invoice::Invoice() {
    this->invoiceDate = Dt();
    this->dueDate = Dt();
    this->lineItems = vector<InvoiceItem>();
    this->buyer = Company();
    this->seller;
    this->terms = "";
    this->invoiceNo = "";
    this->poNo = "";
    this->notes = "";
    this->subtotal = CurrencyAmount(0);
    this->taxes = CurrencyAmount(0);
    this->shipping = CurrencyAmount(0);
    this->total = CurrencyAmount(0);
}

// Getters
/**
 * Get the invoice date.
 * @return The invoice date.
 */
Dt Invoice::getInvoiceDate() const { return invoiceDate; }

/**
 * Get the due date of the invoice.
 * @return The due date of the invoice.
 */
Dt Invoice::getDueDate() const { return dueDate; }

/**
 * Get the line items of the invoice.
 * @return The line items of the invoice.
 */
vector<InvoiceItem> Invoice::getLineItems() const { return lineItems; }

/**
 * Get the buyer company of the invoice.
 * @return The buyer company of the invoice.
 */
Company Invoice::getBuyer() const { return buyer; }

/**
 * Get the seller company of the invoice.
 * @return The seller company of the invoice.
 */
Company Invoice::getSeller() const { return seller; }

/**
 * Get the terms related to payment.
 * @return The terms related to payment.
 */
string Invoice::getTerms() const { return terms; }

/**
 * Get the invoice number.
 * @return The invoice number.
 */
string Invoice::getInvoiceNo() const { return invoiceNo; }

/**
 * Get the purchase order number related to the invoice.
 * @return The purchase order number related to the invoice.
 */
string Invoice::getPoNo() const { return poNo; }

/**
 * Get additional notes or instructions.
 * @return Additional notes or instructions.
 */
string Invoice::getNotes() const { return notes; }

/**
 * Get the subtotal amount.
 * @return The subtotal amount.
 */
CurrencyAmount Invoice::getSubtotal() const { return subtotal; }

/**
 * Get the taxes amount.
 * @return The taxes amount.
 */
CurrencyAmount Invoice::getTaxes() const { return taxes; }

/**
 * Get the shipping amount.
 * @return The shipping amount.
 */
CurrencyAmount Invoice::getShipping() const { return shipping; }

/**
 * Get the total amount to be paid.
 * @return The total amount to be paid.
 */
CurrencyAmount Invoice::getTotal() const { return total; }

// Setters
/**
 * Set the invoice date.
 * @param date The invoice date to set.
 */
void Invoice::setInvoiceDate(Dt date) { invoiceDate = date; }

/**
 * Set the due date of the invoice.
 * @param date The due date of the invoice to set.
 */
void Invoice::setDueDate(Dt date) { dueDate = date; }

/**
 * Set the line items of the invoice.
 * @param items The line items to set.
 */
void Invoice::setLineItems(vector<InvoiceItem> items) { lineItems = items; }

/**
 * Set the buyer company of the invoice.
 * @param company The buyer company to set.
 */
void Invoice::setBuyer(Company company) { buyer = company; }

/**
 * Set the seller company of the invoice.
 * @param company The seller company to set.
 */
void Invoice::setSeller(Company company) { seller = company; }

/**
 * Set the terms related to payment.
 * @param terms The terms related to payment to set.
 */
void Invoice::setTerms(string terms) { this->terms = terms; }

/**
 * Set the invoice number.
 * @param invoiceNo The invoice number to set.
 */
void Invoice::setInvoiceNo(string invoiceNo) { this->invoiceNo = invoiceNo; }

/**
 * Set the purchase order number related to the invoice.
 * @param poNo The purchase order number to set.
 */
void Invoice::setPoNo(string poNo) { this->poNo = poNo; }

/**
 * Set additional notes or instructions.
 * @param notes The additional notes or instructions to set.
 */
void Invoice::setNotes(string notes) { this->notes = notes; }

/**
 * Set the subtotal amount.
 * @param amount The subtotal amount to set.
 */
void Invoice::setSubtotal(CurrencyAmount amount) { subtotal = amount; }

/**
 * Set the taxes amount.
 * @param amount The taxes amount to set.
 */
void Invoice::setTaxes(CurrencyAmount amount) { taxes = amount; }

/**
 * Set the shipping amount.
 * @param amount The shipping amount to set.
 */
void Invoice::setShipping(CurrencyAmount amount) { shipping = amount; }

/**
 * Set the total amount to be paid.
 * @param amount The total amount to be paid to set.
 */
void Invoice::setTotal(CurrencyAmount amount) { total = amount; }
