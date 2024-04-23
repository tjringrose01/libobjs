/**
 *  InvoiceItem.hpp - InvoiceItem Class Definition - This class is responsible
 *                    for defining an InvoiceItem. 
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
 *  Itemized List of Products/Services: This section details the products or services provided, including a description, quantity, unit price, and total price for each item. It may also include any applicable taxes or discounts.
 * 
 **/

#ifndef __INVOICEITEM__
#define __INVOICEITEM__

#include <string>
#include "CurrencyAmount.hpp"

using namespace std;

/**
 * Represents an item in an invoice.
 */
class InvoiceItem {
private:
    /* Private Members */
    string description; /**< The description of the item. */
    int quantity; /**< The quantity of the item. */
    CurrencyAmount unitPrice; /**< The unit price of the item. */
    CurrencyAmount totalPrice; /**< The total price of the item. */

public:
    /**
     * Default constructor initializing all members to default values.
     */
    InvoiceItem();

    /**
     * Parameterized constructor to set the item details.
     * @param desc The description of the item.
     * @param quant The quantity of the item.
     * @param price The unit price of the item.
     */
    InvoiceItem(string desc, int quant, CurrencyAmount price);

    // Getters
    /**
     * Get the description of the item.
     * @return The description of the item.
     */
    string getDescription() const;

    /**
     * Get the quantity of the item.
     * @return The quantity of the item.
     */
    int getQuantity() const;

    /**
     * Get the unit price of the item.
     * @return The unit price of the item.
     */
    CurrencyAmount getUnitPrice() const;

    /**
     * Get the total price of the item.
     * @return The total price of the item.
     */
    CurrencyAmount getTotalPrice() const;

    // Setters
    /**
     * Set the description of the item.
     * @param desc The description of the item.
     */
    void setDescription(string desc);

    /**
     * Set the quantity of the item.
     * @param quant The quantity of the item.
     */
    void setQuantity(int quant);

    /**
     * Set the unit price of the item and update the total price.
     * @param price The unit price of the item.
     */
    void setUnitPrice(CurrencyAmount price);
};

#endif












//Itemized List of Products/Services: This section details the products or services provided, including a description, quantity, unit price, and total price for each item. It may also include any applicable taxes or discounts.
