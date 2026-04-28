/**
 *  DisposalRecord.hpp - DisposalRecord Class Definition.
 */

#ifndef LIBOBJS_DISPOSAL_RECORD_HPP
#define LIBOBJS_DISPOSAL_RECORD_HPP

#include <ostream>
#include <string>
#include "Dt.hpp"

/**
 * @brief DisposalRecord model.
 */
class DisposalRecord {
private:
    std::string disposalId;
    std::string assetId;
    Dt disposalDate;
    std::string method;
    std::string approvedBy;
    std::string notes;

public:
    DisposalRecord();
    DisposalRecord(const std::string& disposalId,
                   const std::string& assetId,
                   const Dt& disposalDate,
                   const std::string& method,
                   const std::string& approvedBy,
                   const std::string& notes);

    std::string getDisposalId() const;
    std::string getAssetId() const;
    Dt getDisposalDate() const;
    std::string getMethod() const;
    std::string getApprovedBy() const;
    std::string getNotes() const;

    void setDisposalId(const std::string& disposalId);
    void setAssetId(const std::string& assetId);
    void setDisposalDate(const Dt& disposalDate);
    void setMethod(const std::string& method);
    void setApprovedBy(const std::string& approvedBy);
    void setNotes(const std::string& notes);

    std::string to_string() const;

    bool operator==(const DisposalRecord& other) const;
    friend std::ostream& operator<<(std::ostream& os, const DisposalRecord& disposal);
};

#endif  // LIBOBJS_DISPOSAL_RECORD_HPP
