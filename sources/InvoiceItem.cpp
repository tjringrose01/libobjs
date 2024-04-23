/**
 *  InvoiceItem.cpp - InvoiceItem Class Implementation - This class is responsible
 *                    for defining an InvoiceItem. 
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
 **/

#include "InvoiceItem.hpp"

using namespace std;

/**
 * Default constructor initializing all members to default values.
 */
InvoiceItem::InvoiceItem() : description(""), quantity(0), unitPrice(0.0), totalPrice(0.0) {}

/**
 * Parameterized constructor to set the item details.
 * @param desc The description of the item.
 * @param quant The quantity of the item.
 * @param price The unit price of the item.
 */
InvoiceItem::InvoiceItem(string desc, int quant, CurrencyAmount price) {
    this->description = desc;
    this->quantity = quant;
    this->unitPrice = price;
    this->totalPrice = price * quant;
}

// Getters
/**
 * Get the description of the item.
 * @return The description of the item.
 */
string InvoiceItem::getDescription() const { return description; }

/**
 * Get the quantity of the item.
 * @return The quantity of the item.
 */
int InvoiceItem::getQuantity() const { return quantity; }

/**
 * Get the unit price of the item.
 * @return The unit price of the item.
 */
CurrencyAmount InvoiceItem::getUnitPrice() const { return unitPrice; }

/**
 * Get the total price of the item.
 * @return The total price of the item.
 */
CurrencyAmount InvoiceItem::getTotalPrice() const { return totalPrice; }

// Setters
/**
 * Set the description of the item.
 * @param desc The description of the item.
 */
void InvoiceItem::setDescription(string desc) { description = desc; }

/**
 * Set the quantity of the item.
 * @param quant The quantity of the item.
 */
void InvoiceItem::setQuantity(int quant) { quantity = quant; }

/**
 * Set the unit price of the item and update the total price.
 * @param price The unit price of the item.
 */
void InvoiceItem::setUnitPrice(CurrencyAmount price) {
    unitPrice = price;
    totalPrice = price * quantity;
}