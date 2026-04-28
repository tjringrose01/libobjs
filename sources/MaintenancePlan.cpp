/**
 *  MaintenancePlan.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the MaintenancePlan model.
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
 *  - A plan is due when the current date is on or after the next due date.
 */

#include "MaintenancePlan.hpp"

/**
 * @brief Return true when lhs date is earlier than rhs date.
 */
static bool dt_less_than(const Dt& lhs, const Dt& rhs) {
    if (lhs.get_year() != rhs.get_year()) {
        return lhs.get_year() < rhs.get_year();
    }
    if (lhs.get_month() != rhs.get_month()) {
        return lhs.get_month() < rhs.get_month();
    }
    return lhs.get_day() < rhs.get_day();
}

/** @brief Construct a default maintenance plan. */
MaintenancePlan::MaintenancePlan()
    : planId(""), assetId(""), frequencyDays(0), nextDueDate(Dt()), vendorId(""), instructions("") {}

/** @brief Construct a maintenance plan with explicit values. */
MaintenancePlan::MaintenancePlan(const std::string& planId,
                                 const std::string& assetId,
                                 int frequencyDays,
                                 const Dt& nextDueDate,
                                 const std::string& vendorId,
                                 const std::string& instructions)
    : planId(planId),
      assetId(assetId),
      frequencyDays(frequencyDays),
      nextDueDate(nextDueDate),
      vendorId(vendorId),
      instructions(instructions) {}

/** @brief Get the maintenance plan identifier. */
std::string MaintenancePlan::getPlanId() const { return planId; }

/** @brief Get the related asset identifier. */
std::string MaintenancePlan::getAssetId() const { return assetId; }

/** @brief Get the plan frequency in days. */
int MaintenancePlan::getFrequencyDays() const { return frequencyDays; }

/** @brief Get the next due date. */
Dt MaintenancePlan::getNextDueDate() const { return nextDueDate; }

/** @brief Get the vendor identifier. */
std::string MaintenancePlan::getVendorId() const { return vendorId; }

/** @brief Get maintenance instructions text. */
std::string MaintenancePlan::getInstructions() const { return instructions; }

/** @brief Set the maintenance plan identifier. */
void MaintenancePlan::setPlanId(const std::string& planId) { this->planId = planId; }

/** @brief Set the related asset identifier. */
void MaintenancePlan::setAssetId(const std::string& assetId) { this->assetId = assetId; }

/** @brief Set frequency in days. */
void MaintenancePlan::setFrequencyDays(int frequencyDays) { this->frequencyDays = frequencyDays; }

/** @brief Set next due date. */
void MaintenancePlan::setNextDueDate(const Dt& nextDueDate) { this->nextDueDate = nextDueDate; }

/** @brief Set vendor identifier. */
void MaintenancePlan::setVendorId(const std::string& vendorId) { this->vendorId = vendorId; }

/** @brief Set instructions text. */
void MaintenancePlan::setInstructions(const std::string& instructions) { this->instructions = instructions; }

/** @brief Return true when the plan is due on the given date. */
bool MaintenancePlan::isDueOn(const Dt& date) const {
    return !dt_less_than(date, nextDueDate);
}

/** @brief Convert this maintenance plan to a human-readable string. */
std::string MaintenancePlan::to_string() const {
    return "planId=" + planId +
           "; assetId=" + assetId +
           "; frequencyDays=" + std::to_string(frequencyDays) +
           "; nextDueDate=" + nextDueDate.to_string() +
           "; vendorId=" + vendorId +
           "; instructions=" + instructions;
}

/** @brief Compare two maintenance plan values. */
bool MaintenancePlan::operator==(const MaintenancePlan& other) const {
    return planId == other.planId &&
           assetId == other.assetId &&
           frequencyDays == other.frequencyDays &&
           nextDueDate == other.nextDueDate &&
           vendorId == other.vendorId &&
           instructions == other.instructions;
}

/** @brief Stream a maintenance plan value. */
std::ostream& operator<<(std::ostream& os, const MaintenancePlan& plan) {
    os << plan.to_string();
    return os;
}
