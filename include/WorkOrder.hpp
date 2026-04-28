/**
 *  WorkOrder.hpp - WorkOrder Class Definition.
 */

#ifndef LIBOBJS_WORK_ORDER_HPP
#define LIBOBJS_WORK_ORDER_HPP

#include <ostream>
#include <string>
#include "Dt.hpp"

/**
 * @brief WorkOrderStatus enumeration.
 */
enum class WorkOrderStatus {
    OPEN = 0,
    IN_PROGRESS = 1,
    COMPLETED = 2,
    CANCELLED = 3
};

/**
 * @brief WorkOrder model.
 */
class WorkOrder {
private:
    std::string workOrderId;
    std::string assetId;
    Dt openedDate;
    Dt closedDate;
    WorkOrderStatus status;
    std::string summary;
    std::string vendorId;

public:
    WorkOrder();
    WorkOrder(const std::string& workOrderId,
              const std::string& assetId,
              const Dt& openedDate,
              const Dt& closedDate,
              WorkOrderStatus status,
              const std::string& summary,
              const std::string& vendorId);

    std::string getWorkOrderId() const;
    std::string getAssetId() const;
    Dt getOpenedDate() const;
    Dt getClosedDate() const;
    WorkOrderStatus getStatus() const;
    std::string getSummary() const;
    std::string getVendorId() const;

    void setWorkOrderId(const std::string& workOrderId);
    void setAssetId(const std::string& assetId);
    void setOpenedDate(const Dt& openedDate);
    void setClosedDate(const Dt& closedDate);
    void setStatus(WorkOrderStatus status);
    void setSummary(const std::string& summary);
    void setVendorId(const std::string& vendorId);

    static std::string workOrderStatusToString(WorkOrderStatus status);
    std::string to_string() const;

    bool operator==(const WorkOrder& other) const;
    friend std::ostream& operator<<(std::ostream& os, const WorkOrder& workOrder);
};

#endif  // LIBOBJS_WORK_ORDER_HPP
