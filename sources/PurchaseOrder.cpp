/**
 *  PurchaseOrder.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the PurchaseOrder model.
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
 *  - total is derived from summed line-item extended prices.
 */

#include "PurchaseOrder.hpp"

/** @brief Recalculate purchase order total from line items. */
void PurchaseOrder::recalculateTotal() {
    total = CurrencyAmount("USD", 0);
    for (const QuoteItem& item : lineItems) {
        total = total + item.getTotalPrice();
    }
}

/** @brief Construct a default purchase order. */
PurchaseOrder::PurchaseOrder()
    : poNo(""),
      issueDate(Dt()),
      buyer(Company()),
      seller(Company()),
      lineItems(),
      total(CurrencyAmount("USD", 0)),
      notes("") {}

/** @brief Get PO number. */
std::string PurchaseOrder::getPoNo() const { return poNo; }

/** @brief Get issue date. */
Dt PurchaseOrder::getIssueDate() const { return issueDate; }

/** @brief Get buyer company. */
Company PurchaseOrder::getBuyer() const { return buyer; }

/** @brief Get seller company. */
Company PurchaseOrder::getSeller() const { return seller; }

/** @brief Get line items vector. */
std::vector<QuoteItem> PurchaseOrder::getLineItems() const { return lineItems; }

/** @brief Get computed total amount. */
CurrencyAmount PurchaseOrder::getTotal() const { return total; }

/** @brief Get notes text. */
std::string PurchaseOrder::getNotes() const { return notes; }

/** @brief Set PO number. */
void PurchaseOrder::setPoNo(const std::string& poNo) { this->poNo = poNo; }

/** @brief Set issue date. */
void PurchaseOrder::setIssueDate(const Dt& issueDate) { this->issueDate = issueDate; }

/** @brief Set buyer company. */
void PurchaseOrder::setBuyer(const Company& buyer) { this->buyer = buyer; }

/** @brief Set seller company. */
void PurchaseOrder::setSeller(const Company& seller) { this->seller = seller; }

/** @brief Replace line items and recalculate total. */
void PurchaseOrder::setLineItems(const std::vector<QuoteItem>& items) {
    lineItems = items;
    recalculateTotal();
}

/** @brief Add one line item and recalculate total. */
void PurchaseOrder::addLineItem(const QuoteItem& item) {
    lineItems.push_back(item);
    recalculateTotal();
}

/** @brief Set notes text. */
void PurchaseOrder::setNotes(const std::string& notes) { this->notes = notes; }

/** @brief Convert this purchase order to a human-readable string. */
std::string PurchaseOrder::to_string() const {
    return "poNo=" + poNo +
           "; issueDate=" + issueDate.to_string() +
           "; buyer={" + buyer.to_string() + "}" +
           "; seller={" + seller.to_string() + "}" +
           "; lineItems=" + std::to_string(lineItems.size()) +
           "; total=" + total.to_string() +
           "; notes=" + notes;
}

/** @brief Compare two purchase order values. */
bool PurchaseOrder::operator==(const PurchaseOrder& other) const {
    return poNo == other.poNo &&
           issueDate == other.issueDate &&
           buyer == other.buyer &&
           seller == other.seller &&
           lineItems == other.lineItems &&
           total == other.total &&
           notes == other.notes;
}

/** @brief Stream a purchase order value. */
std::ostream& operator<<(std::ostream& os, const PurchaseOrder& po) {
    os << po.to_string();
    return os;
}
