/**
 *  InspectionRecord.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the InspectionRecord model.
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
 *  - Inspection results capture pass/fail/attention outcomes for audit history.
 */

#include "InspectionRecord.hpp"

/** @brief Construct a default inspection record. */
InspectionRecord::InspectionRecord()
    : inspectionId(""),
      assetId(""),
      inspectionDate(Dt()),
      inspectorId(""),
      result(InspectionResult::PASSED),
      notes("") {}

/** @brief Construct an inspection record with explicit values. */
InspectionRecord::InspectionRecord(const std::string& inspectionId,
                                   const std::string& assetId,
                                   const Dt& inspectionDate,
                                   const std::string& inspectorId,
                                   InspectionResult result,
                                   const std::string& notes)
    : inspectionId(inspectionId),
      assetId(assetId),
      inspectionDate(inspectionDate),
      inspectorId(inspectorId),
      result(result),
      notes(notes) {}

/** @brief Get inspection identifier. */
std::string InspectionRecord::getInspectionId() const { return inspectionId; }

/** @brief Get related asset identifier. */
std::string InspectionRecord::getAssetId() const { return assetId; }

/** @brief Get inspection date. */
Dt InspectionRecord::getInspectionDate() const { return inspectionDate; }

/** @brief Get inspector identifier. */
std::string InspectionRecord::getInspectorId() const { return inspectorId; }

/** @brief Get inspection result value. */
InspectionResult InspectionRecord::getResult() const { return result; }

/** @brief Get inspection notes. */
std::string InspectionRecord::getNotes() const { return notes; }

/** @brief Set inspection identifier. */
void InspectionRecord::setInspectionId(const std::string& inspectionId) { this->inspectionId = inspectionId; }

/** @brief Set related asset identifier. */
void InspectionRecord::setAssetId(const std::string& assetId) { this->assetId = assetId; }

/** @brief Set inspection date. */
void InspectionRecord::setInspectionDate(const Dt& inspectionDate) { this->inspectionDate = inspectionDate; }

/** @brief Set inspector identifier. */
void InspectionRecord::setInspectorId(const std::string& inspectorId) { this->inspectorId = inspectorId; }

/** @brief Set inspection result value. */
void InspectionRecord::setResult(InspectionResult result) { this->result = result; }

/** @brief Set inspection notes. */
void InspectionRecord::setNotes(const std::string& notes) { this->notes = notes; }

/** @brief Convert inspection result enum to text. */
std::string InspectionRecord::inspectionResultToString(InspectionResult result) {
    switch (result) {
        case InspectionResult::PASSED:
            return "PASSED";
        case InspectionResult::FAILED:
            return "FAILED";
        case InspectionResult::NEEDS_ATTENTION:
            return "NEEDS_ATTENTION";
        default:
            return "UNKNOWN";
    }
}

/** @brief Convert this inspection record to a human-readable string. */
std::string InspectionRecord::to_string() const {
    return "inspectionId=" + inspectionId +
           "; assetId=" + assetId +
           "; inspectionDate=" + inspectionDate.to_string() +
           "; inspectorId=" + inspectorId +
           "; result=" + inspectionResultToString(result) +
           "; notes=" + notes;
}

/** @brief Compare two inspection record values. */
bool InspectionRecord::operator==(const InspectionRecord& other) const {
    return inspectionId == other.inspectionId &&
           assetId == other.assetId &&
           inspectionDate == other.inspectionDate &&
           inspectorId == other.inspectorId &&
           result == other.result &&
           notes == other.notes;
}

/** @brief Stream an inspection record value. */
std::ostream& operator<<(std::ostream& os, const InspectionRecord& inspection) {
    os << inspection.to_string();
    return os;
}
