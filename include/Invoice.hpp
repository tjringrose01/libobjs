/**
 *  EmailAddress.hpp - EmailAddress Class Definition - This class is responsible
 *                     for defining a person. 
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
 * Header: This includes the word "Invoice" prominently displayed, along with a unique invoice number, issue date, and payment due date. The header also includes the seller's contact information (name, address, phone number, email) and the buyer's contact information (if different).

Invoice Date: The date when the invoice was issued.

Payment Due Date: The date by which the payment should be made.

Itemized List of Products/Services: This section details the products or services provided, including a description, quantity, unit price, and total price for each item. It may also include any applicable taxes or discounts.

Subtotal: The total cost before any taxes or discounts are applied.

Taxes: Any applicable taxes (such as sales tax or VAT) are listed here, along with the amount.

Total Amount Due: The final amount to be paid, including taxes and any discounts.

Payment Terms: Any specific terms related to payment, such as accepted payment methods or late payment fees.

Terms and Conditions: Any additional terms and conditions related to the sale, such as return policies or warranties.

Seller's Information: The seller's contact information, including name, address, phone number, and email.

Buyer's Information: The buyer's contact information, if different from the seller's.

Invoice Number: A unique identifier for the invoice, which helps in tracking and referencing the invoice in the future.

PO Number: If the invoice is related to a purchase order (PO), the PO number may be included for reference.

Notes: Any additional information relevant to the invoice, such as special instructions or terms.
 */

#ifndef __INVOICE__
#define __INVOICE__

#include <string>
#include <vector>
#include "Dt.hpp"
#include "InvoiceItem.hpp"
#include "Company.hpp"
#include "CurrencyAmount.hpp"

using namespace std;

class Invoice {
    /* Private Members */
    private:

    /**
     * Invoice date.
     */
    Dt invoiceDate;

    /**
     * Due date for payment.
     */
    Dt dueDate;

    /**
     * List of line items on the invoice.
     */
    vector<InvoiceItem> lineItems;

    /**
     * Information about the buyer.
     */
    Company buyer;

    /**
     * Information about the seller.
     */
    Company seller;

    /**
     * Terms related to payment.
     */
    string terms;

    /**
     * Unique identifier for the invoice.
     */
    string invoiceNo;

    /**
     * Purchase order number related to the invoice.
     */
    string poNo;

    /**
     * Additional notes or instructions.
     */
    string notes;

    /**
     * Subtotal amount.
     */
    CurrencyAmount subtotal;

    /**
     * Taxes amount.
     */
    CurrencyAmount taxes;

    /**
     * Shipping amount.
     */
    CurrencyAmount shipping;

    /**
     * Total amount to be paid.
     */
    CurrencyAmount total;

    /* Public Members */
    public:
    
    /**
     * Default constructor initializing all members to default values.
     */
    Invoice();

    // Getters
    /**
     * Get the invoice date.
     * @return The invoice date.
     */
    Dt getInvoiceDate() const;

    /**
     * Get the due date of the invoice.
     * @return The due date of the invoice.
     */
    Dt getDueDate() const;

    /**
     * Get the line items of the invoice.
     * @return The line items of the invoice.
     */
    vector<InvoiceItem> getLineItems() const;

    /**
     * Get the buyer company of the invoice.
     * @return The buyer company of the invoice.
     */
    Company getBuyer() const;

    /**
     * Get the seller company of the invoice.
     * @return The seller company of the invoice.
     */
    Company getSeller() const;

    /**
     * Get the terms related to payment.
     * @return The terms related to payment.
     */
    string getTerms() const;

    /**
     * Get the invoice number.
     * @return The invoice number.
     */
    string getInvoiceNo() const;

    /**
     * Get the purchase order number related to the invoice.
     * @return The purchase order number related to the invoice.
     */
    string getPoNo() const;

    /**
     * Get additional notes or instructions.
     * @return Additional notes or instructions.
     */
    string getNotes() const;

    /**
     * Get the subtotal amount.
     * @return The subtotal amount.
     */
    CurrencyAmount getSubtotal() const;

    /**
     * Get the taxes amount.
     * @return The taxes amount.
     */
    CurrencyAmount getTaxes() const;

    /**
     * Get the shipping amount.
     * @return The shipping amount.
     */
    CurrencyAmount getShipping() const;

    /**
     * Get the total amount to be paid.
     * @return The total amount to be paid.
     */
    CurrencyAmount getTotal() const;

    // Setters
    /**
     * Set the invoice date.
     * @param date The invoice date to set.
     */
    void setInvoiceDate(Dt date);

    /**
     * Set the due date of the invoice.
     * @param date The due date of the invoice to set.
     */
    void setDueDate(Dt date);

    /**
     * Set the line items of the invoice.
     * @param items The line items to set.
     */
    void setLineItems(vector<InvoiceItem> items);

    /**
     * Set the buyer company of the invoice.
     * @param company The buyer company to set.
     */
    void setBuyer(Company company);

    /**
     * Set the seller company of the invoice.
     * @param company The seller company to set.
     */
    void setSeller(Company company);

    /**
     * Set the terms related to payment.
     * @param terms The terms related to payment to set.
     */
    void setTerms(string terms);

    /**
     * Set the invoice number.
     * @param invoiceNo The invoice number to set.
     */
    void setInvoiceNo(string invoiceNo);

    /**
     * Set the purchase order number related to the invoice.
     * @param poNo The purchase order number to set.
     */
    void setPoNo(string poNo);

    /**
     * Set additional notes or instructions.
     * @param notes The additional notes or instructions to set.
     */
    void setNotes(string notes);

    /**
     * Set the subtotal amount.
     * @param amount The subtotal amount to set.
     */
    void setSubtotal(CurrencyAmount amount);

    /**
     * Set the taxes amount.
     * @param amount The taxes amount to set.
     */
    void setTaxes(CurrencyAmount amount);

    /**
     * Set the shipping amount.
     * @param amount The shipping amount to set.
     */
    void setShipping(CurrencyAmount amount);

    /**
     * Set the total amount to be paid.
     * @param amount The total amount to be paid to set.
     */
    void setTotal(CurrencyAmount amount);
};

#endif // __INVOICE__