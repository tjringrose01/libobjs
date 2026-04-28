/**
 *  QuoteItem.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the QuoteItem model.
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
 *  Domain Rules:
 *  - totalPrice is derived from quantity * unitPrice.
 */

#include "QuoteItem.hpp"

/** @brief Construct a default quote line item. */
QuoteItem::QuoteItem()
    : description(""), quantity(0), unitPrice(CurrencyAmount(0)), totalPrice(CurrencyAmount(0)) {}

/** @brief Construct a quote line item with explicit values. */
QuoteItem::QuoteItem(const std::string& description, int quantity, const CurrencyAmount& unitPrice)
    : description(description), quantity(quantity), unitPrice(unitPrice), totalPrice(unitPrice * quantity) {}

/** @brief Get line item description. */
std::string QuoteItem::getDescription() const { return description; }

/** @brief Get line item quantity. */
int QuoteItem::getQuantity() const { return quantity; }

/** @brief Get unit price amount. */
CurrencyAmount QuoteItem::getUnitPrice() const { return unitPrice; }

/** @brief Get line total amount. */
CurrencyAmount QuoteItem::getTotalPrice() const { return totalPrice; }

/** @brief Set line description. */
void QuoteItem::setDescription(const std::string& description) { this->description = description; }

/** @brief Set quantity and recalculate total price. */
void QuoteItem::setQuantity(int quantity) {
    this->quantity = quantity;
    totalPrice = unitPrice * quantity;
}

/** @brief Set unit price and recalculate total price. */
void QuoteItem::setUnitPrice(const CurrencyAmount& unitPrice) {
    this->unitPrice = unitPrice;
    totalPrice = unitPrice * quantity;
}

/** @brief Convert this quote item to a human-readable string. */
std::string QuoteItem::to_string() const {
    return "description=" + description +
           "; quantity=" + std::to_string(quantity) +
           "; unitPrice=" + unitPrice.to_string() +
           "; totalPrice=" + totalPrice.to_string();
}

/** @brief Compare two quote item values. */
bool QuoteItem::operator==(const QuoteItem& other) const {
    return description == other.description &&
           quantity == other.quantity &&
           unitPrice == other.unitPrice &&
           totalPrice == other.totalPrice;
}

/** @brief Stream a quote item value. */
std::ostream& operator<<(std::ostream& os, const QuoteItem& item) {
    os << item.to_string();
    return os;
}
