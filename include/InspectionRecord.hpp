/**
 *  InspectionRecord.hpp - InspectionRecord Class Definition.
 */

#ifndef LIBOBJS_INSPECTION_RECORD_HPP
#define LIBOBJS_INSPECTION_RECORD_HPP

#include <ostream>
#include <string>
#include "Dt.hpp"

/**
 * @brief InspectionResult enumeration.
 */
enum class InspectionResult {
    PASSED = 0,
    FAILED = 1,
    NEEDS_ATTENTION = 2
};

/**
 * @brief InspectionRecord model.
 */
class InspectionRecord {
private:
    std::string inspectionId;
    std::string assetId;
    Dt inspectionDate;
    std::string inspectorId;
    InspectionResult result;
    std::string notes;

public:
    InspectionRecord();
    InspectionRecord(const std::string& inspectionId,
                     const std::string& assetId,
                     const Dt& inspectionDate,
                     const std::string& inspectorId,
                     InspectionResult result,
                     const std::string& notes);

    std::string getInspectionId() const;
    std::string getAssetId() const;
    Dt getInspectionDate() const;
    std::string getInspectorId() const;
    InspectionResult getResult() const;
    std::string getNotes() const;

    void setInspectionId(const std::string& inspectionId);
    void setAssetId(const std::string& assetId);
    void setInspectionDate(const Dt& inspectionDate);
    void setInspectorId(const std::string& inspectorId);
    void setResult(InspectionResult result);
    void setNotes(const std::string& notes);

    static std::string inspectionResultToString(InspectionResult result);
    std::string to_string() const;

    bool operator==(const InspectionRecord& other) const;
    friend std::ostream& operator<<(std::ostream& os, const InspectionRecord& inspection);
};

#endif  // LIBOBJS_INSPECTION_RECORD_HPP
