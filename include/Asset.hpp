/**
 *  Asset.hpp - Asset Class Definition.
 */

#ifndef LIBOBJS_ASSET_HPP
#define LIBOBJS_ASSET_HPP

#include <ostream>
#include <string>
#include "AssetModel.hpp"
#include "Department.hpp"
#include "Location.hpp"

/**
 * @brief AssetStatus enumeration.
 */
enum class AssetStatus {
    IN_STOCK = 0,
    ASSIGNED = 1,
    IN_REPAIR = 2,
    RETIRED = 3,
    DISPOSED = 4
};

/**
 * @brief Asset model.
 */
class Asset {
private:
    std::string assetId;
    std::string assetTag;
    std::string serialNumber;
    AssetModel model;
    AssetStatus status;
    Location location;
    Department owningDepartment;
    std::string custodianId;

public:
    Asset();
    Asset(const std::string& assetId,
          const std::string& assetTag,
          const std::string& serialNumber,
          const AssetModel& model,
          AssetStatus status,
          const Location& location,
          const Department& owningDepartment,
          const std::string& custodianId);

    std::string getAssetId() const;
    std::string getAssetTag() const;
    std::string getSerialNumber() const;
    AssetModel getModel() const;
    AssetStatus getStatus() const;
    Location getLocation() const;
    Department getOwningDepartment() const;
    std::string getCustodianId() const;

    void setAssetId(const std::string& assetId);
    void setAssetTag(const std::string& assetTag);
    void setSerialNumber(const std::string& serialNumber);
    void setModel(const AssetModel& model);
    void setStatus(AssetStatus status);
    void setLocation(const Location& location);
    void setOwningDepartment(const Department& owningDepartment);
    void setCustodianId(const std::string& custodianId);

    static std::string assetStatusToString(AssetStatus status);
    std::string to_string() const;

    bool operator==(const Asset& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Asset& asset);
};

#endif  // LIBOBJS_ASSET_HPP
