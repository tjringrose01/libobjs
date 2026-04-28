/**
 *  MaintenancePlan.hpp - MaintenancePlan Class Definition.
 */

#ifndef LIBOBJS_MAINTENANCE_PLAN_HPP
#define LIBOBJS_MAINTENANCE_PLAN_HPP

#include <ostream>
#include <string>
#include "Dt.hpp"

/**
 * @brief MaintenancePlan model.
 */
class MaintenancePlan {
private:
    std::string planId;
    std::string assetId;
    int frequencyDays;
    Dt nextDueDate;
    std::string vendorId;
    std::string instructions;

public:
    MaintenancePlan();
    MaintenancePlan(const std::string& planId,
                    const std::string& assetId,
                    int frequencyDays,
                    const Dt& nextDueDate,
                    const std::string& vendorId,
                    const std::string& instructions);

    std::string getPlanId() const;
    std::string getAssetId() const;
    int getFrequencyDays() const;
    Dt getNextDueDate() const;
    std::string getVendorId() const;
    std::string getInstructions() const;

    void setPlanId(const std::string& planId);
    void setAssetId(const std::string& assetId);
    void setFrequencyDays(int frequencyDays);
    void setNextDueDate(const Dt& nextDueDate);
    void setVendorId(const std::string& vendorId);
    void setInstructions(const std::string& instructions);

    bool isDueOn(const Dt& date) const;
    std::string to_string() const;

    bool operator==(const MaintenancePlan& other) const;
    friend std::ostream& operator<<(std::ostream& os, const MaintenancePlan& plan);
};

#endif  // LIBOBJS_MAINTENANCE_PLAN_HPP
