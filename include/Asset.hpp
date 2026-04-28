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
 * @brief Lifecycle state for an asset record.
 * @details Values progress from inventory through assignment and eventual retirement/disposal.
 */
enum class AssetStatus {
    IN_STOCK = 0,
    ASSIGNED = 1,
    IN_REPAIR = 2,
    RETIRED = 3,
    DISPOSED = 4
};

/**
 * @brief Inventory asset value object.
 * @details Stores identity, model, lifecycle, and ownership/location fields.
 * Validation and formatting constraints are not enforced by this class.
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
    /**
     * @brief Creates an empty asset with default nested values.
     * @details Default status is `AssetStatus::IN_STOCK`.
     */
    Asset();

    /**
     * @brief Creates an asset from explicit field values.
     * @param assetId Stable record identifier used by external systems.
     * @param assetTag Human-facing inventory tag.
     * @param serialNumber Manufacturer serial number.
     * @param model Asset model metadata.
     * @param status Current lifecycle status.
     * @param location Current physical/logical location.
     * @param owningDepartment Department responsible for ownership/cost center.
     * @param custodianId Person or account currently responsible for custody.
     * @note Inputs are stored as provided; no normalization or validation is performed.
     */
    Asset(const std::string& assetId,
          const std::string& assetTag,
          const std::string& serialNumber,
          const AssetModel& model,
          AssetStatus status,
          const Location& location,
          const Department& owningDepartment,
          const std::string& custodianId);

    /**
     * @brief Returns the asset record identifier.
     * @return Stored `assetId` value.
     */
    std::string getAssetId() const;

    /**
     * @brief Returns the inventory tag displayed to operators.
     * @return Stored `assetTag` value.
     */
    std::string getAssetTag() const;

    /**
     * @brief Returns the manufacturer serial number.
     * @return Stored `serialNumber` value.
     */
    std::string getSerialNumber() const;

    /**
     * @brief Returns model metadata associated with this asset.
     * @return Copy of the stored `model` object.
     */
    AssetModel getModel() const;

    /**
     * @brief Returns the current lifecycle status.
     * @return Stored `status` enumeration value.
     */
    AssetStatus getStatus() const;

    /**
     * @brief Returns current location metadata.
     * @return Copy of the stored `location` object.
     */
    Location getLocation() const;

    /**
     * @brief Returns ownership metadata.
     * @return Copy of the stored `owningDepartment` object.
     */
    Department getOwningDepartment() const;

    /**
     * @brief Returns the current custodian identifier.
     * @return Stored `custodianId` value. Empty means unassigned custody.
     */
    std::string getCustodianId() const;

    /**
     * @brief Replaces the asset record identifier.
     * @param assetId New external record identifier.
     * @note No format or uniqueness checks are performed.
     */
    void setAssetId(const std::string& assetId);

    /**
     * @brief Replaces the inventory tag.
     * @param assetTag New operator-facing tag.
     * @note No format or uniqueness checks are performed.
     */
    void setAssetTag(const std::string& assetTag);

    /**
     * @brief Replaces the serial number.
     * @param serialNumber New manufacturer serial number.
     * @note No format checks are performed.
     */
    void setSerialNumber(const std::string& serialNumber);

    /**
     * @brief Replaces model metadata.
     * @param model New model value.
     */
    void setModel(const AssetModel& model);

    /**
     * @brief Replaces lifecycle status.
     * @param status New lifecycle state.
     */
    void setStatus(AssetStatus status);

    /**
     * @brief Replaces location metadata.
     * @param location New location value.
     */
    void setLocation(const Location& location);

    /**
     * @brief Replaces owning department metadata.
     * @param owningDepartment New department value.
     */
    void setOwningDepartment(const Department& owningDepartment);

    /**
     * @brief Replaces custodian identifier.
     * @param custodianId New custodian reference. Empty means no assignee.
     * @note No existence or format checks are performed.
     */
    void setCustodianId(const std::string& custodianId);

    /**
     * @brief Converts a lifecycle status enum value into its stable token.
     * @param status Status value to convert.
     * @return One of `IN_STOCK`, `ASSIGNED`, `IN_REPAIR`, `RETIRED`, `DISPOSED`,
     * or `UNKNOWN` when the input is outside defined enumerators.
     */
    static std::string assetStatusToString(AssetStatus status);

    /**
     * @brief Builds a diagnostic string with all stored fields.
     * @return Semicolon-delimited key/value string intended for logs and debugging.
     */
    std::string to_string() const;

    /**
     * @brief Compares two assets for strict value equality.
     * @param other Value to compare against.
     * @return `true` only if every stored field matches, including nested objects.
     * @details This is a full state comparison, not a business-identity comparison.
     */
    bool operator==(const Asset& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Asset& asset);
};

#endif  // LIBOBJS_ASSET_HPP
