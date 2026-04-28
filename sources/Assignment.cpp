/**
 *  Assignment.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the Assignment model.
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
 *  - Assignment state records who had custody and when.
 */

#include "Assignment.hpp"

/** @brief Construct a default assignment value. */
Assignment::Assignment()
    : assignmentId(""),
      assetId(""),
      assigneeId(""),
      startDate(Dt()),
      endDate(Dt()),
      conditionOut(""),
      conditionIn(""),
      active(false) {}

/** @brief Construct an assignment value with explicit fields. */
Assignment::Assignment(const std::string& assignmentId,
                       const std::string& assetId,
                       const std::string& assigneeId,
                       const Dt& startDate,
                       const Dt& endDate,
                       const std::string& conditionOut,
                       const std::string& conditionIn,
                       bool active)
    : assignmentId(assignmentId),
      assetId(assetId),
      assigneeId(assigneeId),
      startDate(startDate),
      endDate(endDate),
      conditionOut(conditionOut),
      conditionIn(conditionIn),
      active(active) {}

/** @brief Get the assignment identifier. */
std::string Assignment::getAssignmentId() const { return assignmentId; }

/** @brief Get the related asset identifier. */
std::string Assignment::getAssetId() const { return assetId; }

/** @brief Get the assignee identifier. */
std::string Assignment::getAssigneeId() const { return assigneeId; }

/** @brief Get assignment start date. */
Dt Assignment::getStartDate() const { return startDate; }

/** @brief Get assignment end date. */
Dt Assignment::getEndDate() const { return endDate; }

/** @brief Get check-out condition notes. */
std::string Assignment::getConditionOut() const { return conditionOut; }

/** @brief Get check-in condition notes. */
std::string Assignment::getConditionIn() const { return conditionIn; }

/** @brief Get whether assignment is currently active. */
bool Assignment::isActive() const { return active; }

/** @brief Set assignment identifier. */
void Assignment::setAssignmentId(const std::string& assignmentId) { this->assignmentId = assignmentId; }

/** @brief Set related asset identifier. */
void Assignment::setAssetId(const std::string& assetId) { this->assetId = assetId; }

/** @brief Set assignee identifier. */
void Assignment::setAssigneeId(const std::string& assigneeId) { this->assigneeId = assigneeId; }

/** @brief Set assignment start date. */
void Assignment::setStartDate(const Dt& startDate) { this->startDate = startDate; }

/** @brief Set assignment end date. */
void Assignment::setEndDate(const Dt& endDate) { this->endDate = endDate; }

/** @brief Set check-out condition notes. */
void Assignment::setConditionOut(const std::string& conditionOut) { this->conditionOut = conditionOut; }

/** @brief Set check-in condition notes. */
void Assignment::setConditionIn(const std::string& conditionIn) { this->conditionIn = conditionIn; }

/** @brief Set active flag for assignment. */
void Assignment::setActive(bool active) { this->active = active; }

/** @brief Convert this assignment to a human-readable string. */
std::string Assignment::to_string() const {
    return "assignmentId=" + assignmentId +
           "; assetId=" + assetId +
           "; assigneeId=" + assigneeId +
           "; startDate=" + startDate.to_string() +
           "; endDate=" + endDate.to_string() +
           "; conditionOut=" + conditionOut +
           "; conditionIn=" + conditionIn +
           "; active=" + (active ? "true" : "false");
}

/** @brief Compare two assignment values. */
bool Assignment::operator==(const Assignment& other) const {
    return assignmentId == other.assignmentId &&
           assetId == other.assetId &&
           assigneeId == other.assigneeId &&
           startDate == other.startDate &&
           endDate == other.endDate &&
           conditionOut == other.conditionOut &&
           conditionIn == other.conditionIn &&
           active == other.active;
}

/** @brief Stream an assignment value. */
std::ostream& operator<<(std::ostream& os, const Assignment& assignment) {
    os << assignment.to_string();
    return os;
}
