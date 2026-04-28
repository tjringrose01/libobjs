/**
 *  Incident.hpp - Incident Class Definition.
 */

#ifndef LIBOBJS_INCIDENT_HPP
#define LIBOBJS_INCIDENT_HPP

#include <ostream>
#include <string>
#include "Dt.hpp"

/**
 * @brief IncidentSeverity enumeration.
 */
enum class IncidentSeverity {
    LOW = 0,
    MEDIUM = 1,
    HIGH = 2,
    CRITICAL = 3
};

/**
 * @brief Incident model.
 */
class Incident {
private:
    std::string incidentId;
    std::string assetId;
    Dt reportedDate;
    IncidentSeverity severity;
    std::string description;
    bool resolved;

public:
    Incident();
    Incident(const std::string& incidentId,
             const std::string& assetId,
             const Dt& reportedDate,
             IncidentSeverity severity,
             const std::string& description,
             bool resolved);

    std::string getIncidentId() const;
    std::string getAssetId() const;
    Dt getReportedDate() const;
    IncidentSeverity getSeverity() const;
    std::string getDescription() const;
    bool isResolved() const;

    void setIncidentId(const std::string& incidentId);
    void setAssetId(const std::string& assetId);
    void setReportedDate(const Dt& reportedDate);
    void setSeverity(IncidentSeverity severity);
    void setDescription(const std::string& description);
    void setResolved(bool resolved);

    static std::string incidentSeverityToString(IncidentSeverity severity);
    std::string to_string() const;

    bool operator==(const Incident& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Incident& incident);
};

#endif  // LIBOBJS_INCIDENT_HPP
