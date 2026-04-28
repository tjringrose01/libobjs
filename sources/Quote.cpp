/**
 *  Quote.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the Quote model.
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
 *  - subtotal sums line totals.
 *  - total = subtotal + taxes + shipping.
 */

#include "Quote.hpp"

/** @brief Recalculate subtotal and total from line items and charges. */
void Quote::recalculateTotals() {
    subtotal = CurrencyAmount("USD", 0);
    for (const QuoteItem& item : lineItems) {
        subtotal = subtotal + item.getTotalPrice();
    }

    total = subtotal + taxes + shipping;
}

/** @brief Construct a default quote. */
Quote::Quote()
    : quoteNo(""),
      quoteDate(Dt()),
      expiryDate(Dt()),
      buyer(Company()),
      seller(Company()),
      lineItems(),
      notes(""),
      subtotal(CurrencyAmount("USD", 0)),
      taxes(CurrencyAmount("USD", 0)),
      shipping(CurrencyAmount("USD", 0)),
      total(CurrencyAmount("USD", 0)) {}

/** @brief Get quote number. */
std::string Quote::getQuoteNo() const { return quoteNo; }

/** @brief Get quote date. */
Dt Quote::getQuoteDate() const { return quoteDate; }

/** @brief Get quote expiration date. */
Dt Quote::getExpiryDate() const { return expiryDate; }

/** @brief Get buyer company. */
Company Quote::getBuyer() const { return buyer; }

/** @brief Get seller company. */
Company Quote::getSeller() const { return seller; }

/** @brief Get quote line items. */
std::vector<QuoteItem> Quote::getLineItems() const { return lineItems; }

/** @brief Get quote notes. */
std::string Quote::getNotes() const { return notes; }

/** @brief Get quote subtotal. */
CurrencyAmount Quote::getSubtotal() const { return subtotal; }

/** @brief Get quote taxes. */
CurrencyAmount Quote::getTaxes() const { return taxes; }

/** @brief Get quote shipping. */
CurrencyAmount Quote::getShipping() const { return shipping; }

/** @brief Get quote total. */
CurrencyAmount Quote::getTotal() const { return total; }

/** @brief Set quote number. */
void Quote::setQuoteNo(const std::string& quoteNo) { this->quoteNo = quoteNo; }

/** @brief Set quote date. */
void Quote::setQuoteDate(const Dt& quoteDate) { this->quoteDate = quoteDate; }

/** @brief Set quote expiration date. */
void Quote::setExpiryDate(const Dt& expiryDate) { this->expiryDate = expiryDate; }

/** @brief Set buyer company. */
void Quote::setBuyer(const Company& buyer) { this->buyer = buyer; }

/** @brief Set seller company. */
void Quote::setSeller(const Company& seller) { this->seller = seller; }

/** @brief Replace line items and recalculate totals. */
void Quote::setLineItems(const std::vector<QuoteItem>& items) {
    lineItems = items;
    recalculateTotals();
}

/** @brief Add one line item and recalculate totals. */
void Quote::addLineItem(const QuoteItem& item) {
    lineItems.push_back(item);
    recalculateTotals();
}

/** @brief Set notes text. */
void Quote::setNotes(const std::string& notes) { this->notes = notes; }

/** @brief Set taxes and recalculate total. */
void Quote::setTaxes(const CurrencyAmount& taxes) {
    this->taxes = taxes;
    recalculateTotals();
}

/** @brief Set shipping and recalculate total. */
void Quote::setShipping(const CurrencyAmount& shipping) {
    this->shipping = shipping;
    recalculateTotals();
}

/** @brief Convert this quote to a human-readable string. */
std::string Quote::to_string() const {
    return "quoteNo=" + quoteNo +
           "; quoteDate=" + quoteDate.to_string() +
           "; expiryDate=" + expiryDate.to_string() +
           "; buyer={" + buyer.to_string() + "}" +
           "; seller={" + seller.to_string() + "}" +
           "; lineItems=" + std::to_string(lineItems.size()) +
           "; subtotal=" + subtotal.to_string() +
           "; taxes=" + taxes.to_string() +
           "; shipping=" + shipping.to_string() +
           "; total=" + total.to_string() +
           "; notes=" + notes;
}

/** @brief Compare two quote values. */
bool Quote::operator==(const Quote& other) const {
    return quoteNo == other.quoteNo &&
           quoteDate == other.quoteDate &&
           expiryDate == other.expiryDate &&
           buyer == other.buyer &&
           seller == other.seller &&
           lineItems == other.lineItems &&
           notes == other.notes &&
           subtotal == other.subtotal &&
           taxes == other.taxes &&
           shipping == other.shipping &&
           total == other.total;
}

/** @brief Stream a quote value. */
std::ostream& operator<<(std::ostream& os, const Quote& quote) {
    os << quote.to_string();
    return os;
}
