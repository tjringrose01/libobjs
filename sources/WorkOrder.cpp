/**
 *  WorkOrder.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the WorkOrder model.
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
 *  - Status tracks progression from open to completion/cancellation.
 */

#include "WorkOrder.hpp"

/** @brief Construct a default work order. */
WorkOrder::WorkOrder()
    : workOrderId(""),
      assetId(""),
      openedDate(Dt()),
      closedDate(Dt()),
      status(WorkOrderStatus::OPEN),
      summary(""),
      vendorId("") {}

/** @brief Construct a work order with explicit values. */
WorkOrder::WorkOrder(const std::string& workOrderId,
                     const std::string& assetId,
                     const Dt& openedDate,
                     const Dt& closedDate,
                     WorkOrderStatus status,
                     const std::string& summary,
                     const std::string& vendorId)
    : workOrderId(workOrderId),
      assetId(assetId),
      openedDate(openedDate),
      closedDate(closedDate),
      status(status),
      summary(summary),
      vendorId(vendorId) {}

/** @brief Get work order identifier. */
std::string WorkOrder::getWorkOrderId() const { return workOrderId; }

/** @brief Get related asset identifier. */
std::string WorkOrder::getAssetId() const { return assetId; }

/** @brief Get opened date. */
Dt WorkOrder::getOpenedDate() const { return openedDate; }

/** @brief Get closed date. */
Dt WorkOrder::getClosedDate() const { return closedDate; }

/** @brief Get status value. */
WorkOrderStatus WorkOrder::getStatus() const { return status; }

/** @brief Get summary text. */
std::string WorkOrder::getSummary() const { return summary; }

/** @brief Get vendor identifier. */
std::string WorkOrder::getVendorId() const { return vendorId; }

/** @brief Set work order identifier. */
void WorkOrder::setWorkOrderId(const std::string& workOrderId) { this->workOrderId = workOrderId; }

/** @brief Set related asset identifier. */
void WorkOrder::setAssetId(const std::string& assetId) { this->assetId = assetId; }

/** @brief Set opened date. */
void WorkOrder::setOpenedDate(const Dt& openedDate) { this->openedDate = openedDate; }

/** @brief Set closed date. */
void WorkOrder::setClosedDate(const Dt& closedDate) { this->closedDate = closedDate; }

/** @brief Set status value. */
void WorkOrder::setStatus(WorkOrderStatus status) { this->status = status; }

/** @brief Set summary text. */
void WorkOrder::setSummary(const std::string& summary) { this->summary = summary; }

/** @brief Set vendor identifier. */
void WorkOrder::setVendorId(const std::string& vendorId) { this->vendorId = vendorId; }

/** @brief Convert work order status enum to text. */
std::string WorkOrder::workOrderStatusToString(WorkOrderStatus status) {
    switch (status) {
        case WorkOrderStatus::OPEN:
            return "OPEN";
        case WorkOrderStatus::IN_PROGRESS:
            return "IN_PROGRESS";
        case WorkOrderStatus::COMPLETED:
            return "COMPLETED";
        case WorkOrderStatus::CANCELLED:
            return "CANCELLED";
        default:
            return "UNKNOWN";
    }
}

/** @brief Convert this work order to a human-readable string. */
std::string WorkOrder::to_string() const {
    return "workOrderId=" + workOrderId +
           "; assetId=" + assetId +
           "; openedDate=" + openedDate.to_string() +
           "; closedDate=" + closedDate.to_string() +
           "; status=" + workOrderStatusToString(status) +
           "; summary=" + summary +
           "; vendorId=" + vendorId;
}

/** @brief Compare two work order values. */
bool WorkOrder::operator==(const WorkOrder& other) const {
    return workOrderId == other.workOrderId &&
           assetId == other.assetId &&
           openedDate == other.openedDate &&
           closedDate == other.closedDate &&
           status == other.status &&
           summary == other.summary &&
           vendorId == other.vendorId;
}

/** @brief Stream a work order value. */
std::ostream& operator<<(std::ostream& os, const WorkOrder& workOrder) {
    os << workOrder.to_string();
    return os;
}
