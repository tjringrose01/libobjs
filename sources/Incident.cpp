/**
 *  Incident.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the Incident model.
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
 *  - Severity levels support triage from low to critical incident responses.
 */

#include "Incident.hpp"

/** @brief Construct a default incident record. */
Incident::Incident()
    : incidentId(""),
      assetId(""),
      reportedDate(Dt()),
      severity(IncidentSeverity::LOW),
      description(""),
      resolved(false) {}

/** @brief Construct an incident record with explicit values. */
Incident::Incident(const std::string& incidentId,
                   const std::string& assetId,
                   const Dt& reportedDate,
                   IncidentSeverity severity,
                   const std::string& description,
                   bool resolved)
    : incidentId(incidentId),
      assetId(assetId),
      reportedDate(reportedDate),
      severity(severity),
      description(description),
      resolved(resolved) {}

/** @brief Get incident identifier. */
std::string Incident::getIncidentId() const { return incidentId; }

/** @brief Get related asset identifier. */
std::string Incident::getAssetId() const { return assetId; }

/** @brief Get incident report date. */
Dt Incident::getReportedDate() const { return reportedDate; }

/** @brief Get incident severity. */
IncidentSeverity Incident::getSeverity() const { return severity; }

/** @brief Get incident description text. */
std::string Incident::getDescription() const { return description; }

/** @brief Get incident resolution state. */
bool Incident::isResolved() const { return resolved; }

/** @brief Set incident identifier. */
void Incident::setIncidentId(const std::string& incidentId) { this->incidentId = incidentId; }

/** @brief Set related asset identifier. */
void Incident::setAssetId(const std::string& assetId) { this->assetId = assetId; }

/** @brief Set incident report date. */
void Incident::setReportedDate(const Dt& reportedDate) { this->reportedDate = reportedDate; }

/** @brief Set incident severity value. */
void Incident::setSeverity(IncidentSeverity severity) { this->severity = severity; }

/** @brief Set incident description text. */
void Incident::setDescription(const std::string& description) { this->description = description; }

/** @brief Set incident resolution state. */
void Incident::setResolved(bool resolved) { this->resolved = resolved; }

/** @brief Convert incident severity enum to text. */
std::string Incident::incidentSeverityToString(IncidentSeverity severity) {
    switch (severity) {
        case IncidentSeverity::LOW:
            return "LOW";
        case IncidentSeverity::MEDIUM:
            return "MEDIUM";
        case IncidentSeverity::HIGH:
            return "HIGH";
        case IncidentSeverity::CRITICAL:
            return "CRITICAL";
        default:
            return "UNKNOWN";
    }
}

/** @brief Convert this incident record to a human-readable string. */
std::string Incident::to_string() const {
    return "incidentId=" + incidentId +
           "; assetId=" + assetId +
           "; reportedDate=" + reportedDate.to_string() +
           "; severity=" + incidentSeverityToString(severity) +
           "; description=" + description +
           "; resolved=" + (resolved ? "true" : "false");
}

/** @brief Compare two incident values. */
bool Incident::operator==(const Incident& other) const {
    return incidentId == other.incidentId &&
           assetId == other.assetId &&
           reportedDate == other.reportedDate &&
           severity == other.severity &&
           description == other.description &&
           resolved == other.resolved;
}

/** @brief Stream an incident value. */
std::ostream& operator<<(std::ostream& os, const Incident& incident) {
    os << incident.to_string();
    return os;
}
