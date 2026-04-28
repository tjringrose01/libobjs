/**
 *  AssetModel.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the AssetModel model.
 *
 *  Copyright 2026 Timothy Ringrose
 *
 *  This file is part of libobjs.
 *
 *  libobjs is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  libobjs is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with libobjs. If not, see <http://www.gnu.org/licenses/>.
 *
 *  Domain Rules:
 *  - Asset model metadata combines manufacturer details and type defaults.
 */

#include "AssetModel.hpp"

/** @brief Construct a default asset model. */
AssetModel::AssetModel()
    : modelId(""), manufacturer(""), modelName(""), assetType(AssetType()), defaultWarrantyMonths(0) {}

/** @brief Construct an asset model with explicit values. */
AssetModel::AssetModel(const std::string& modelId,
                       const std::string& manufacturer,
                       const std::string& modelName,
                       const AssetType& assetType,
                       int defaultWarrantyMonths)
    : modelId(modelId),
      manufacturer(manufacturer),
      modelName(modelName),
      assetType(assetType),
      defaultWarrantyMonths(defaultWarrantyMonths) {}

std::string AssetModel::getModelId() const { return modelId; }

std::string AssetModel::getManufacturer() const { return manufacturer; }

std::string AssetModel::getModelName() const { return modelName; }

AssetType AssetModel::getAssetType() const { return assetType; }

int AssetModel::getDefaultWarrantyMonths() const { return defaultWarrantyMonths; }

void AssetModel::setModelId(const std::string& modelId) { this->modelId = modelId; }

void AssetModel::setManufacturer(const std::string& manufacturer) { this->manufacturer = manufacturer; }

void AssetModel::setModelName(const std::string& modelName) { this->modelName = modelName; }

void AssetModel::setAssetType(const AssetType& assetType) { this->assetType = assetType; }

void AssetModel::setDefaultWarrantyMonths(int defaultWarrantyMonths) {
    this->defaultWarrantyMonths = defaultWarrantyMonths;
}

/**
 * @brief Produce a deterministic key/value snapshot of the model state.
 * @details Intended for diagnostics rather than end-user presentation.
 */
std::string AssetModel::to_string() const {
    return "modelId=" + modelId +
           "; manufacturer=" + manufacturer +
           "; modelName=" + modelName +
           "; assetType={" + assetType.to_string() + "}" +
           "; defaultWarrantyMonths=" + std::to_string(defaultWarrantyMonths);
}

/**
 * @brief Compare two model entries for strict field-by-field equality.
 */
bool AssetModel::operator==(const AssetModel& other) const {
    return modelId == other.modelId &&
           manufacturer == other.manufacturer &&
           modelName == other.modelName &&
           assetType == other.assetType &&
           defaultWarrantyMonths == other.defaultWarrantyMonths;
}

std::ostream& operator<<(std::ostream& os, const AssetModel& assetModel) {
    os << assetModel.to_string();
    return os;
}
