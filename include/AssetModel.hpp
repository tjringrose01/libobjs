/**
 *  AssetModel.hpp - AssetModel Class Definition.
 */

#ifndef LIBOBJS_ASSET_MODEL_HPP
#define LIBOBJS_ASSET_MODEL_HPP

#include <ostream>
#include <string>
#include "AssetType.hpp"

/**
 * @brief Asset model catalog entry.
 * @details Captures manufacturer/model identity, type metadata, and default warranty policy.
 */
class AssetModel {
private:
    std::string modelId;
    std::string manufacturer;
    std::string modelName;
    AssetType assetType;
    int defaultWarrantyMonths;

public:
    /**
     * @brief Creates an empty model entry.
     * @details Warranty default is `0` months.
     */
    AssetModel();

    /**
     * @brief Creates a model entry from explicit values.
     * @param modelId Stable identifier for the catalog entry.
     * @param manufacturer Manufacturer name.
     * @param modelName Product/model name.
     * @param assetType Type metadata associated with this model.
     * @param defaultWarrantyMonths Default warranty duration in months.
     * @note `defaultWarrantyMonths` is stored directly; callers should keep it non-negative.
     */
    AssetModel(const std::string& modelId,
               const std::string& manufacturer,
               const std::string& modelName,
               const AssetType& assetType,
               int defaultWarrantyMonths);

    /**
     * @brief Returns model catalog identifier.
     * @return Stored `modelId` value.
     */
    std::string getModelId() const;

    /**
     * @brief Returns manufacturer name.
     * @return Stored `manufacturer` value.
     */
    std::string getManufacturer() const;

    /**
     * @brief Returns model/product name.
     * @return Stored `modelName` value.
     */
    std::string getModelName() const;

    /**
     * @brief Returns associated type metadata.
     * @return Copy of stored `assetType`.
     */
    AssetType getAssetType() const;

    /**
     * @brief Returns the default warranty period.
     * @return Warranty duration in months.
     */
    int getDefaultWarrantyMonths() const;

    /**
     * @brief Replaces model catalog identifier.
     * @param modelId New model identifier.
     */
    void setModelId(const std::string& modelId);

    /**
     * @brief Replaces manufacturer name.
     * @param manufacturer New manufacturer text.
     */
    void setManufacturer(const std::string& manufacturer);

    /**
     * @brief Replaces model/product name.
     * @param modelName New model name text.
     */
    void setModelName(const std::string& modelName);

    /**
     * @brief Replaces type metadata.
     * @param assetType New type value.
     */
    void setAssetType(const AssetType& assetType);

    /**
     * @brief Replaces default warranty period.
     * @param defaultWarrantyMonths New warranty duration in months.
     * @note No min/max clamping is performed.
     */
    void setDefaultWarrantyMonths(int defaultWarrantyMonths);

    /**
     * @brief Builds a diagnostic string with all stored fields.
     * @return Semicolon-delimited key/value string intended for logs and debugging.
     */
    std::string to_string() const;

    /**
     * @brief Compares two model entries for strict value equality.
     * @param other Value to compare against.
     * @return `true` only when every stored field matches.
     */
    bool operator==(const AssetModel& other) const;
    friend std::ostream& operator<<(std::ostream& os, const AssetModel& assetModel);
};

#endif  // LIBOBJS_ASSET_MODEL_HPP
