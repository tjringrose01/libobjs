/**
 *  Asset.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the Asset model.
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
 *  - Asset status identifies lifecycle stage from stocking to disposal.
 */

#include "Asset.hpp"

/** @brief Construct a default asset value. */
Asset::Asset()
    : assetId(""),
      assetTag(""),
      serialNumber(""),
      model(AssetModel()),
      status(AssetStatus::IN_STOCK),
      location(Location()),
      owningDepartment(Department()),
      custodianId("") {}

/** @brief Construct an asset value with explicit fields. */
Asset::Asset(const std::string& assetId,
             const std::string& assetTag,
             const std::string& serialNumber,
             const AssetModel& model,
             AssetStatus status,
             const Location& location,
             const Department& owningDepartment,
             const std::string& custodianId)
    : assetId(assetId),
      assetTag(assetTag),
      serialNumber(serialNumber),
      model(model),
      status(status),
      location(location),
      owningDepartment(owningDepartment),
      custodianId(custodianId) {}

/** @brief Get the asset identifier. */
std::string Asset::getAssetId() const { return assetId; }

/** @brief Get the asset tag. */
std::string Asset::getAssetTag() const { return assetTag; }

/** @brief Get the serial number. */
std::string Asset::getSerialNumber() const { return serialNumber; }

/** @brief Get the model metadata. */
AssetModel Asset::getModel() const { return model; }

/** @brief Get the current asset status. */
AssetStatus Asset::getStatus() const { return status; }

/** @brief Get the location data. */
Location Asset::getLocation() const { return location; }

/** @brief Get the owning department data. */
Department Asset::getOwningDepartment() const { return owningDepartment; }

/** @brief Get the custodian identifier. */
std::string Asset::getCustodianId() const { return custodianId; }

/** @brief Set the asset identifier. */
void Asset::setAssetId(const std::string& assetId) { this->assetId = assetId; }

/** @brief Set the asset tag. */
void Asset::setAssetTag(const std::string& assetTag) { this->assetTag = assetTag; }

/** @brief Set the serial number. */
void Asset::setSerialNumber(const std::string& serialNumber) { this->serialNumber = serialNumber; }

/** @brief Set the model metadata. */
void Asset::setModel(const AssetModel& model) { this->model = model; }

/** @brief Set the lifecycle status. */
void Asset::setStatus(AssetStatus status) { this->status = status; }

/** @brief Set the current location. */
void Asset::setLocation(const Location& location) { this->location = location; }

/** @brief Set the owning department. */
void Asset::setOwningDepartment(const Department& owningDepartment) {
    this->owningDepartment = owningDepartment;
}

/** @brief Set the custodian identifier. */
void Asset::setCustodianId(const std::string& custodianId) { this->custodianId = custodianId; }

/** @brief Convert an asset status enum value to text. */
std::string Asset::assetStatusToString(AssetStatus status) {
    switch (status) {
        case AssetStatus::IN_STOCK:
            return "IN_STOCK";
        case AssetStatus::ASSIGNED:
            return "ASSIGNED";
        case AssetStatus::IN_REPAIR:
            return "IN_REPAIR";
        case AssetStatus::RETIRED:
            return "RETIRED";
        case AssetStatus::DISPOSED:
            return "DISPOSED";
        default:
            return "UNKNOWN";
    }
}

/** @brief Convert this asset to a human-readable string. */
std::string Asset::to_string() const {
    return "assetId=" + assetId +
           "; assetTag=" + assetTag +
           "; serialNumber=" + serialNumber +
           "; model={" + model.to_string() + "}" +
           "; status=" + assetStatusToString(status) +
           "; location={" + location.to_string() + "}" +
           "; owningDepartment={" + owningDepartment.to_string() + "}" +
           "; custodianId=" + custodianId;
}

/** @brief Compare two asset values. */
bool Asset::operator==(const Asset& other) const {
    return assetId == other.assetId &&
           assetTag == other.assetTag &&
           serialNumber == other.serialNumber &&
           model == other.model &&
           status == other.status &&
           location == other.location &&
           owningDepartment == other.owningDepartment &&
           custodianId == other.custodianId;
}

/** @brief Stream an asset value. */
std::ostream& operator<<(std::ostream& os, const Asset& asset) {
    os << asset.to_string();
    return os;
}
