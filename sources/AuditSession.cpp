/**
 *  AuditSession.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the AuditSession model.
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
 *  - Missing count is computed from results with found=false.
 */

#include "AuditSession.hpp"

/** @brief Construct a default audit session. */
AuditSession::AuditSession()
    : sessionId(""), startedOn(Dt()), endedOn(Dt()), locationId(""), results() {}

/** @brief Construct an audit session with explicit values. */
AuditSession::AuditSession(const std::string& sessionId,
                           const Dt& startedOn,
                           const Dt& endedOn,
                           const std::string& locationId,
                           const std::vector<AuditResult>& results)
    : sessionId(sessionId),
      startedOn(startedOn),
      endedOn(endedOn),
      locationId(locationId),
      results(results) {}

/** @brief Get session identifier. */
std::string AuditSession::getSessionId() const { return sessionId; }

/** @brief Get session start date. */
Dt AuditSession::getStartedOn() const { return startedOn; }

/** @brief Get session end date. */
Dt AuditSession::getEndedOn() const { return endedOn; }

/** @brief Get location identifier. */
std::string AuditSession::getLocationId() const { return locationId; }

/** @brief Get audit results list. */
std::vector<AuditResult> AuditSession::getResults() const { return results; }

/** @brief Set session identifier. */
void AuditSession::setSessionId(const std::string& sessionId) { this->sessionId = sessionId; }

/** @brief Set session start date. */
void AuditSession::setStartedOn(const Dt& startedOn) { this->startedOn = startedOn; }

/** @brief Set session end date. */
void AuditSession::setEndedOn(const Dt& endedOn) { this->endedOn = endedOn; }

/** @brief Set location identifier. */
void AuditSession::setLocationId(const std::string& locationId) { this->locationId = locationId; }

/** @brief Replace audit results list. */
void AuditSession::setResults(const std::vector<AuditResult>& results) { this->results = results; }

/** @brief Append one audit result entry. */
void AuditSession::addResult(const AuditResult& result) { results.push_back(result); }

/** @brief Count missing assets in this audit session. */
std::size_t AuditSession::missingCount() const {
    std::size_t count = 0;
    for (const AuditResult& result : results) {
        if (!result.isFound()) {
            ++count;
        }
    }

    return count;
}

/** @brief Convert this audit session to a human-readable string. */
std::string AuditSession::to_string() const {
    return "sessionId=" + sessionId +
           "; startedOn=" + startedOn.to_string() +
           "; endedOn=" + endedOn.to_string() +
           "; locationId=" + locationId +
           "; resultCount=" + std::to_string(results.size()) +
           "; missingCount=" + std::to_string(missingCount());
}

/** @brief Compare two audit session values. */
bool AuditSession::operator==(const AuditSession& other) const {
    return sessionId == other.sessionId &&
           startedOn == other.startedOn &&
           endedOn == other.endedOn &&
           locationId == other.locationId &&
           results == other.results;
}

/** @brief Stream an audit session value. */
std::ostream& operator<<(std::ostream& os, const AuditSession& session) {
    os << session.to_string();
    return os;
}
