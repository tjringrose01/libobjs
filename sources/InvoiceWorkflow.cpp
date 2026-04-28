/**
 *  InvoiceWorkflow.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the InvoiceWorkflow model.
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
 *  - Transition rules enforce a linear invoice lifecycle.
 */

#include "InvoiceWorkflow.hpp"

#include <stdexcept>

/** @brief Construct a default invoice workflow in draft state. */
InvoiceWorkflow::InvoiceWorkflow() : invoiceNo(""), status(InvoiceStatus::DRAFT), lastUpdated(Dt()) {}

/** @brief Construct a workflow for a specific invoice number. */
InvoiceWorkflow::InvoiceWorkflow(const std::string& invoiceNo)
    : invoiceNo(invoiceNo), status(InvoiceStatus::DRAFT), lastUpdated(Dt()) {}

/** @brief Get invoice number. */
std::string InvoiceWorkflow::getInvoiceNo() const { return invoiceNo; }

/** @brief Get current workflow status. */
InvoiceStatus InvoiceWorkflow::getStatus() const { return status; }

/** @brief Get last updated date. */
Dt InvoiceWorkflow::getLastUpdated() const { return lastUpdated; }

/** @brief Return true when transition from current state is allowed. */
bool InvoiceWorkflow::canTransitionTo(InvoiceStatus nextStatus) const {
    switch (status) {
        case InvoiceStatus::DRAFT:
            return nextStatus == InvoiceStatus::ISSUED || nextStatus == InvoiceStatus::VOIDED;
        case InvoiceStatus::ISSUED:
            return nextStatus == InvoiceStatus::PARTIALLY_PAID ||
                   nextStatus == InvoiceStatus::PAID ||
                   nextStatus == InvoiceStatus::OVERDUE ||
                   nextStatus == InvoiceStatus::VOIDED;
        case InvoiceStatus::PARTIALLY_PAID:
            return nextStatus == InvoiceStatus::PAID || nextStatus == InvoiceStatus::OVERDUE;
        case InvoiceStatus::OVERDUE:
            return nextStatus == InvoiceStatus::PARTIALLY_PAID || nextStatus == InvoiceStatus::PAID;
        case InvoiceStatus::PAID:
            return false;
        case InvoiceStatus::VOIDED:
            return false;
        default:
            return false;
    }
}

/** @brief Transition workflow status if the requested move is valid. */
void InvoiceWorkflow::transitionTo(InvoiceStatus nextStatus, const Dt& onDate) {
    if (!canTransitionTo(nextStatus)) {
        throw std::invalid_argument("ERROR: invalid invoice status transition");
    }

    status = nextStatus;
    lastUpdated = onDate;
}

/** @brief Convert invoice status enum to text. */
std::string InvoiceWorkflow::invoiceStatusToString(InvoiceStatus status) {
    switch (status) {
        case InvoiceStatus::DRAFT:
            return "DRAFT";
        case InvoiceStatus::ISSUED:
            return "ISSUED";
        case InvoiceStatus::PARTIALLY_PAID:
            return "PARTIALLY_PAID";
        case InvoiceStatus::PAID:
            return "PAID";
        case InvoiceStatus::OVERDUE:
            return "OVERDUE";
        case InvoiceStatus::VOIDED:
            return "VOIDED";
        default:
            return "UNKNOWN";
    }
}

/** @brief Convert this invoice workflow to a human-readable string. */
std::string InvoiceWorkflow::to_string() const {
    return "invoiceNo=" + invoiceNo +
           "; status=" + invoiceStatusToString(status) +
           "; lastUpdated=" + lastUpdated.to_string();
}

/** @brief Compare two invoice workflow values. */
bool InvoiceWorkflow::operator==(const InvoiceWorkflow& other) const {
    return invoiceNo == other.invoiceNo && status == other.status && lastUpdated == other.lastUpdated;
}

/** @brief Stream an invoice workflow value. */
std::ostream& operator<<(std::ostream& os, const InvoiceWorkflow& workflow) {
    os << workflow.to_string();
    return os;
}
