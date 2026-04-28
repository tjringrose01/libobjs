/**
 *  Assignment.hpp - Assignment Class Definition.
 */

#ifndef LIBOBJS_ASSIGNMENT_HPP
#define LIBOBJS_ASSIGNMENT_HPP

#include <ostream>
#include <string>
#include "Dt.hpp"

/**
 * @brief Assignment model.
 */
class Assignment {
private:
    std::string assignmentId;
    std::string assetId;
    std::string assigneeId;
    Dt startDate;
    Dt endDate;
    std::string conditionOut;
    std::string conditionIn;
    bool active;

public:
    Assignment();
    Assignment(const std::string& assignmentId,
               const std::string& assetId,
               const std::string& assigneeId,
               const Dt& startDate,
               const Dt& endDate,
               const std::string& conditionOut,
               const std::string& conditionIn,
               bool active);

    std::string getAssignmentId() const;
    std::string getAssetId() const;
    std::string getAssigneeId() const;
    Dt getStartDate() const;
    Dt getEndDate() const;
    std::string getConditionOut() const;
    std::string getConditionIn() const;
    bool isActive() const;

    void setAssignmentId(const std::string& assignmentId);
    void setAssetId(const std::string& assetId);
    void setAssigneeId(const std::string& assigneeId);
    void setStartDate(const Dt& startDate);
    void setEndDate(const Dt& endDate);
    void setConditionOut(const std::string& conditionOut);
    void setConditionIn(const std::string& conditionIn);
    void setActive(bool active);

    std::string to_string() const;

    bool operator==(const Assignment& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Assignment& assignment);
};

#endif  // LIBOBJS_ASSIGNMENT_HPP
