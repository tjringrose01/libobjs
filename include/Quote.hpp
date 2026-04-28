/**
 *  Quote.hpp - Quote Class Definition.
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

#ifndef LIBOBJS_QUOTE_HPP
#define LIBOBJS_QUOTE_HPP

#include <ostream>
#include <string>
#include <vector>
#include "Company.hpp"
#include "CurrencyAmount.hpp"
#include "Dt.hpp"
#include "QuoteItem.hpp"

/**
 * Represents a customer quote before conversion to invoice.
 */
/**
 * @brief Quote model.
 */
class Quote {
private:
    std::string quoteNo;
    Dt quoteDate;
    Dt expiryDate;
    Company buyer;
    Company seller;
    std::vector<QuoteItem> lineItems;
    std::string notes;
    CurrencyAmount subtotal;
    CurrencyAmount taxes;
    CurrencyAmount shipping;
    CurrencyAmount total;

    void recalculateTotals();

public:
    /**
     * Construct a default quote.
     */
    Quote();

    /**
     * Get quote number.
     *
     * @return Quote number.
     */
    std::string getQuoteNo() const;

    /**
     * Get quote date.
     *
     * @return Quote date.
     */
    Dt getQuoteDate() const;

    /**
     * Get quote expiration date.
     *
     * @return Expiration date.
     */
    Dt getExpiryDate() const;

    /**
     * Get buyer.
     *
     * @return Buyer company.
     */
    Company getBuyer() const;

    /**
     * Get seller.
     *
     * @return Seller company.
     */
    Company getSeller() const;

    /**
     * Get line items.
     *
     * @return Vector of quote items.
     */
    std::vector<QuoteItem> getLineItems() const;

    /**
     * Get notes.
     *
     * @return Notes.
     */
    std::string getNotes() const;

    /**
     * Get subtotal.
     *
     * @return Subtotal amount.
     */
    CurrencyAmount getSubtotal() const;

    /**
     * Get taxes.
     *
     * @return Tax amount.
     */
    CurrencyAmount getTaxes() const;

    /**
     * Get shipping.
     *
     * @return Shipping amount.
     */
    CurrencyAmount getShipping() const;

    /**
     * Get total.
     *
     * @return Total amount.
     */
    CurrencyAmount getTotal() const;

    /**
     * Set quote number.
     *
     * @param quoteNo Quote number.
     */
    void setQuoteNo(const std::string& quoteNo);

    /**
     * Set quote date.
     *
     * @param quoteDate Quote date.
     */
    void setQuoteDate(const Dt& quoteDate);

    /**
     * Set expiration date.
     *
     * @param expiryDate Expiration date.
     */
    void setExpiryDate(const Dt& expiryDate);

    /**
     * Set buyer.
     *
     * @param buyer Buyer company.
     */
    void setBuyer(const Company& buyer);

    /**
     * Set seller.
     *
     * @param seller Seller company.
     */
    void setSeller(const Company& seller);

    /**
     * Replace line items and recalculate totals.
     *
     * @param items Quote line items.
     */
    void setLineItems(const std::vector<QuoteItem>& items);

    /**
     * Add one line item and recalculate totals.
     *
     * @param item Quote item.
     */
    void addLineItem(const QuoteItem& item);

    /**
     * Set notes.
     *
     * @param notes Notes text.
     */
    void setNotes(const std::string& notes);

    /**
     * Set taxes and recalculate total.
     *
     * @param taxes Tax amount.
     */
    void setTaxes(const CurrencyAmount& taxes);

    /**
     * Set shipping and recalculate total.
     *
     * @param shipping Shipping amount.
     */
    void setShipping(const CurrencyAmount& shipping);

    /**
     * Convert quote to text.
     *
     * @return String representation.
     */
    std::string to_string() const;

    /**
     * Compare quotes.
     *
     * @param other Other quote.
     * @return True when fields match.
     */
    bool operator==(const Quote& other) const;

    /**
     * Stream quote.
     *
     * @param os Output stream.
     * @param quote Quote object.
     * @return Output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Quote& quote);
};

#endif  // LIBOBJS_QUOTE_HPP
