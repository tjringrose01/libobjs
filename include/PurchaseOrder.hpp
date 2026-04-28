/**
 *  PurchaseOrder.hpp - PurchaseOrder Class Definition.
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

#ifndef LIBOBJS_PURCHASE_ORDER_HPP
#define LIBOBJS_PURCHASE_ORDER_HPP

#include <ostream>
#include <string>
#include <vector>
#include "Company.hpp"
#include "CurrencyAmount.hpp"
#include "Dt.hpp"
#include "QuoteItem.hpp"

/**
 * Represents a purchase order with line items and parties.
 */
/**
 * @brief PurchaseOrder model.
 */
class PurchaseOrder {
private:
    std::string poNo;
    Dt issueDate;
    Company buyer;
    Company seller;
    std::vector<QuoteItem> lineItems;
    CurrencyAmount total;
    std::string notes;

    void recalculateTotal();

public:
    /**
     * Construct default purchase order.
     */
    PurchaseOrder();

    /**
     * Get PO number.
     *
     * @return PO number.
     */
    std::string getPoNo() const;

    /**
     * Get issue date.
     *
     * @return Issue date.
     */
    Dt getIssueDate() const;

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
     * @return Line item vector.
     */
    std::vector<QuoteItem> getLineItems() const;

    /**
     * Get total amount.
     *
     * @return Total.
     */
    CurrencyAmount getTotal() const;

    /**
     * Get notes.
     *
     * @return Notes.
     */
    std::string getNotes() const;

    /**
     * Set PO number.
     *
     * @param poNo PO number.
     */
    void setPoNo(const std::string& poNo);

    /**
     * Set issue date.
     *
     * @param issueDate Issue date.
     */
    void setIssueDate(const Dt& issueDate);

    /**
     * Set buyer company.
     *
     * @param buyer Buyer.
     */
    void setBuyer(const Company& buyer);

    /**
     * Set seller company.
     *
     * @param seller Seller.
     */
    void setSeller(const Company& seller);

    /**
     * Replace line items and recalculate total.
     *
     * @param items Line items.
     */
    void setLineItems(const std::vector<QuoteItem>& items);

    /**
     * Add one line item and recalculate total.
     *
     * @param item Line item.
     */
    void addLineItem(const QuoteItem& item);

    /**
     * Set notes.
     *
     * @param notes Notes text.
     */
    void setNotes(const std::string& notes);

    /**
     * Convert purchase order to text.
     *
     * @return String representation.
     */
    std::string to_string() const;

    /**
     * Compare purchase orders.
     *
     * @param other Other PO.
     * @return True when fields match.
     */
    bool operator==(const PurchaseOrder& other) const;

    /**
     * Stream purchase order.
     *
     * @param os Output stream.
     * @param po Purchase order.
     * @return Output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const PurchaseOrder& po);
};

#endif  // LIBOBJS_PURCHASE_ORDER_HPP
