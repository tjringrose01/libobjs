/**
 *  QuoteItem.hpp - QuoteItem Class Definition.
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
 *  along with libobjs.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef LIBOBJS_QUOTE_ITEM_HPP
#define LIBOBJS_QUOTE_ITEM_HPP

#include <ostream>
#include <string>
#include "CurrencyAmount.hpp"

/**
 * Represents a single line item on a quote.
 */
/**
 * @brief QuoteItem model.
 */
class QuoteItem {
private:
    std::string description;
    int quantity;
    CurrencyAmount unitPrice;
    CurrencyAmount totalPrice;

public:
    /**
     * Construct a default quote item.
     */
    QuoteItem();

    /**
     * Construct a quote item.
     *
     * @param description Item description.
     * @param quantity Quantity to quote.
     * @param unitPrice Unit price for the item.
     */
    QuoteItem(const std::string& description, int quantity, const CurrencyAmount& unitPrice);

    /**
     * Get item description.
     *
     * @return Description text.
     */
    std::string getDescription() const;

    /**
     * Get quantity.
     *
     * @return Quantity.
     */
    int getQuantity() const;

    /**
     * Get unit price.
     *
     * @return Unit price.
     */
    CurrencyAmount getUnitPrice() const;

    /**
     * Get total price.
     *
     * @return Extended price.
     */
    CurrencyAmount getTotalPrice() const;

    /**
     * Set description.
     *
     * @param description Description text.
     */
    void setDescription(const std::string& description);

    /**
     * Set quantity and recompute total.
     *
     * @param quantity Quantity.
     */
    void setQuantity(int quantity);

    /**
     * Set unit price and recompute total.
     *
     * @param unitPrice Unit price.
     */
    void setUnitPrice(const CurrencyAmount& unitPrice);

    /**
     * Convert quote item to text.
     *
     * @return String representation.
     */
    std::string to_string() const;

    /**
     * Compare quote items.
     *
     * @param other Other quote item.
     * @return True when all fields match.
     */
    bool operator==(const QuoteItem& other) const;

    /**
     * Stream quote item.
     *
     * @param os Output stream.
     * @param item Quote item.
     * @return Output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const QuoteItem& item);
};

#endif  // LIBOBJS_QUOTE_ITEM_HPP
