/**
 *  DisposalRecord.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the DisposalRecord model.
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
 *  - Disposal record captures approval and method for retired assets.
 */

#include "DisposalRecord.hpp"

/** @brief Construct a default disposal record. */
DisposalRecord::DisposalRecord()
    : disposalId(""), assetId(""), disposalDate(Dt()), method(""), approvedBy(""), notes("") {}

/** @brief Construct a disposal record with explicit values. */
DisposalRecord::DisposalRecord(const std::string& disposalId,
                               const std::string& assetId,
                               const Dt& disposalDate,
                               const std::string& method,
                               const std::string& approvedBy,
                               const std::string& notes)
    : disposalId(disposalId),
      assetId(assetId),
      disposalDate(disposalDate),
      method(method),
      approvedBy(approvedBy),
      notes(notes) {}

/** @brief Get disposal identifier. */
std::string DisposalRecord::getDisposalId() const { return disposalId; }

/** @brief Get related asset identifier. */
std::string DisposalRecord::getAssetId() const { return assetId; }

/** @brief Get disposal date. */
Dt DisposalRecord::getDisposalDate() const { return disposalDate; }

/** @brief Get disposal method text. */
std::string DisposalRecord::getMethod() const { return method; }

/** @brief Get approver identifier. */
std::string DisposalRecord::getApprovedBy() const { return approvedBy; }

/** @brief Get disposal notes text. */
std::string DisposalRecord::getNotes() const { return notes; }

/** @brief Set disposal identifier. */
void DisposalRecord::setDisposalId(const std::string& disposalId) { this->disposalId = disposalId; }

/** @brief Set related asset identifier. */
void DisposalRecord::setAssetId(const std::string& assetId) { this->assetId = assetId; }

/** @brief Set disposal date. */
void DisposalRecord::setDisposalDate(const Dt& disposalDate) { this->disposalDate = disposalDate; }

/** @brief Set disposal method text. */
void DisposalRecord::setMethod(const std::string& method) { this->method = method; }

/** @brief Set approver identifier. */
void DisposalRecord::setApprovedBy(const std::string& approvedBy) { this->approvedBy = approvedBy; }

/** @brief Set disposal notes text. */
void DisposalRecord::setNotes(const std::string& notes) { this->notes = notes; }

/** @brief Convert this disposal record to a human-readable string. */
std::string DisposalRecord::to_string() const {
    return "disposalId=" + disposalId +
           "; assetId=" + assetId +
           "; disposalDate=" + disposalDate.to_string() +
           "; method=" + method +
           "; approvedBy=" + approvedBy +
           "; notes=" + notes;
}

/** @brief Compare two disposal record values. */
bool DisposalRecord::operator==(const DisposalRecord& other) const {
    return disposalId == other.disposalId &&
           assetId == other.assetId &&
           disposalDate == other.disposalDate &&
           method == other.method &&
           approvedBy == other.approvedBy &&
           notes == other.notes;
}

/** @brief Stream a disposal record value. */
std::ostream& operator<<(std::ostream& os, const DisposalRecord& disposal) {
    os << disposal.to_string();
    return os;
}
