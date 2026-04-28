/**
 *  AuditSession.hpp - AuditSession Class Definition.
 */

#ifndef LIBOBJS_AUDIT_SESSION_HPP
#define LIBOBJS_AUDIT_SESSION_HPP

#include <ostream>
#include <string>
#include <vector>
#include "AuditResult.hpp"
#include "Dt.hpp"

/**
 * @brief AuditSession model.
 */
class AuditSession {
private:
    std::string sessionId;
    Dt startedOn;
    Dt endedOn;
    std::string locationId;
    std::vector<AuditResult> results;

public:
    AuditSession();
    AuditSession(const std::string& sessionId,
                 const Dt& startedOn,
                 const Dt& endedOn,
                 const std::string& locationId,
                 const std::vector<AuditResult>& results);

    std::string getSessionId() const;
    Dt getStartedOn() const;
    Dt getEndedOn() const;
    std::string getLocationId() const;
    std::vector<AuditResult> getResults() const;

    void setSessionId(const std::string& sessionId);
    void setStartedOn(const Dt& startedOn);
    void setEndedOn(const Dt& endedOn);
    void setLocationId(const std::string& locationId);
    void setResults(const std::vector<AuditResult>& results);
    void addResult(const AuditResult& result);

    std::size_t missingCount() const;
    std::string to_string() const;

    bool operator==(const AuditSession& other) const;
    friend std::ostream& operator<<(std::ostream& os, const AuditSession& session);
};

#endif  // LIBOBJS_AUDIT_SESSION_HPP
