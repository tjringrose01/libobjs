/**
 *  AuditResult.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the AuditResult model.
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
 *  - Each result captures one found/missing determination from an audit run.
 */

#include "AuditResult.hpp"

/** @brief Construct a default audit result. */
AuditResult::AuditResult()
    : resultId(""),
      assetId(""),
      found(false),
      conditionNotes(""),
      auditorId(""),
      auditDate(Dt()) {}

/** @brief Construct an audit result with explicit values. */
AuditResult::AuditResult(const std::string& resultId,
                         const std::string& assetId,
                         bool found,
                         const std::string& conditionNotes,
                         const std::string& auditorId,
                         const Dt& auditDate)
    : resultId(resultId),
      assetId(assetId),
      found(found),
      conditionNotes(conditionNotes),
      auditorId(auditorId),
      auditDate(auditDate) {}

/** @brief Get result identifier. */
std::string AuditResult::getResultId() const { return resultId; }

/** @brief Get related asset identifier. */
std::string AuditResult::getAssetId() const { return assetId; }

/** @brief Get whether the asset was found. */
bool AuditResult::isFound() const { return found; }

/** @brief Get condition notes. */
std::string AuditResult::getConditionNotes() const { return conditionNotes; }

/** @brief Get auditor identifier. */
std::string AuditResult::getAuditorId() const { return auditorId; }

/** @brief Get audit date. */
Dt AuditResult::getAuditDate() const { return auditDate; }

/** @brief Set result identifier. */
void AuditResult::setResultId(const std::string& resultId) { this->resultId = resultId; }

/** @brief Set related asset identifier. */
void AuditResult::setAssetId(const std::string& assetId) { this->assetId = assetId; }

/** @brief Set found flag. */
void AuditResult::setFound(bool found) { this->found = found; }

/** @brief Set condition notes. */
void AuditResult::setConditionNotes(const std::string& conditionNotes) { this->conditionNotes = conditionNotes; }

/** @brief Set auditor identifier. */
void AuditResult::setAuditorId(const std::string& auditorId) { this->auditorId = auditorId; }

/** @brief Set audit date. */
void AuditResult::setAuditDate(const Dt& auditDate) { this->auditDate = auditDate; }

/** @brief Convert this audit result to a human-readable string. */
std::string AuditResult::to_string() const {
    return "resultId=" + resultId +
           "; assetId=" + assetId +
           "; found=" + (found ? "true" : "false") +
           "; conditionNotes=" + conditionNotes +
           "; auditorId=" + auditorId +
           "; auditDate=" + auditDate.to_string();
}

/** @brief Compare two audit result values. */
bool AuditResult::operator==(const AuditResult& other) const {
    return resultId == other.resultId &&
           assetId == other.assetId &&
           found == other.found &&
           conditionNotes == other.conditionNotes &&
           auditorId == other.auditorId &&
           auditDate == other.auditDate;
}

/** @brief Stream an audit result value. */
std::ostream& operator<<(std::ostream& os, const AuditResult& result) {
    os << result.to_string();
    return os;
}
