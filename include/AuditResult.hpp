/**
 *  AuditResult.hpp - AuditResult Class Definition.
 */

#ifndef LIBOBJS_AUDIT_RESULT_HPP
#define LIBOBJS_AUDIT_RESULT_HPP

#include <ostream>
#include <string>
#include "Dt.hpp"

/**
 * @brief AuditResult model.
 */
class AuditResult {
private:
    std::string resultId;
    std::string assetId;
    bool found;
    std::string conditionNotes;
    std::string auditorId;
    Dt auditDate;

public:
    AuditResult();
    AuditResult(const std::string& resultId,
                const std::string& assetId,
                bool found,
                const std::string& conditionNotes,
                const std::string& auditorId,
                const Dt& auditDate);

    std::string getResultId() const;
    std::string getAssetId() const;
    bool isFound() const;
    std::string getConditionNotes() const;
    std::string getAuditorId() const;
    Dt getAuditDate() const;

    void setResultId(const std::string& resultId);
    void setAssetId(const std::string& assetId);
    void setFound(bool found);
    void setConditionNotes(const std::string& conditionNotes);
    void setAuditorId(const std::string& auditorId);
    void setAuditDate(const Dt& auditDate);

    std::string to_string() const;

    bool operator==(const AuditResult& other) const;
    friend std::ostream& operator<<(std::ostream& os, const AuditResult& result);
};

#endif  // LIBOBJS_AUDIT_RESULT_HPP
