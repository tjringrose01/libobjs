/**
 *  InvoiceWorkflow.hpp - InvoiceWorkflow Class Definition.
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

#ifndef LIBOBJS_INVOICE_WORKFLOW_HPP
#define LIBOBJS_INVOICE_WORKFLOW_HPP

#include <ostream>
#include <string>
#include "Dt.hpp"

/**
 * Supported invoice lifecycle states.
 */
/**
 * @brief InvoiceStatus enumeration.
 */
enum class InvoiceStatus {
    DRAFT = 0,
    ISSUED = 1,
    PARTIALLY_PAID = 2,
    PAID = 3,
    OVERDUE = 4,
    VOIDED = 5
};

/**
 * Tracks and validates invoice status transitions.
 */
/**
 * @brief InvoiceWorkflow model.
 */
class InvoiceWorkflow {
private:
    std::string invoiceNo;
    InvoiceStatus status;
    Dt lastUpdated;

public:
    /**
     * Construct default workflow in DRAFT state.
     */
    InvoiceWorkflow();

    /**
     * Construct workflow for invoice number.
     *
     * @param invoiceNo Invoice number.
     */
    explicit InvoiceWorkflow(const std::string& invoiceNo);

    /**
     * Get invoice number.
     *
     * @return Invoice number.
     */
    std::string getInvoiceNo() const;

    /**
     * Get current status.
     *
     * @return Invoice status.
     */
    InvoiceStatus getStatus() const;

    /**
     * Get last updated date.
     *
     * @return Last update date.
     */
    Dt getLastUpdated() const;

    /**
     * Validate whether transition is permitted.
     *
     * @param nextStatus Desired next status.
     * @return True if transition is allowed.
     */
    bool canTransitionTo(InvoiceStatus nextStatus) const;

    /**
     * Transition workflow to a new status.
     *
     * @param nextStatus Desired next status.
     * @param onDate Transition date.
     */
    void transitionTo(InvoiceStatus nextStatus, const Dt& onDate);

    /**
     * Convert status enum to text.
     *
     * @param status Invoice status.
     * @return Status label.
     */
    static std::string invoiceStatusToString(InvoiceStatus status);

    /**
     * Convert workflow to text.
     *
     * @return String representation.
     */
    std::string to_string() const;

    /**
     * Compare workflows.
     *
     * @param other Other workflow.
     * @return True when fields match.
     */
    bool operator==(const InvoiceWorkflow& other) const;

    /**
     * Stream workflow.
     *
     * @param os Output stream.
     * @param workflow Workflow object.
     * @return Output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const InvoiceWorkflow& workflow);
};

#endif  // LIBOBJS_INVOICE_WORKFLOW_HPP
