/**
 *  AssetModel.hpp - AssetModel Class Definition.
 */

#ifndef LIBOBJS_ASSET_MODEL_HPP
#define LIBOBJS_ASSET_MODEL_HPP

#include <ostream>
#include <string>
#include "AssetType.hpp"

/**
 * @brief AssetModel model.
 */
class AssetModel {
private:
    std::string modelId;
    std::string manufacturer;
    std::string modelName;
    AssetType assetType;
    int defaultWarrantyMonths;

public:
    AssetModel();
    AssetModel(const std::string& modelId,
               const std::string& manufacturer,
               const std::string& modelName,
               const AssetType& assetType,
               int defaultWarrantyMonths);

    std::string getModelId() const;
    std::string getManufacturer() const;
    std::string getModelName() const;
    AssetType getAssetType() const;
    int getDefaultWarrantyMonths() const;

    void setModelId(const std::string& modelId);
    void setManufacturer(const std::string& manufacturer);
    void setModelName(const std::string& modelName);
    void setAssetType(const AssetType& assetType);
    void setDefaultWarrantyMonths(int defaultWarrantyMonths);

    std::string to_string() const;

    bool operator==(const AssetModel& other) const;
    friend std::ostream& operator<<(std::ostream& os, const AssetModel& assetModel);
};

#endif  // LIBOBJS_ASSET_MODEL_HPP
