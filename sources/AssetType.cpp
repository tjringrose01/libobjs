/**
 *  AssetType.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the AssetType model.
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
 *  - Asset types identify equipment families and whether depreciation applies.
 */

#include "AssetType.hpp"

/** @brief Construct a default asset type. */
AssetType::AssetType() : typeId(""), name(""), description(""), depreciable(false) {}

/** @brief Construct an asset type with explicit values. */
AssetType::AssetType(const std::string& typeId,
                     const std::string& name,
                     const std::string& description,
                     bool depreciable)
    : typeId(typeId), name(name), description(description), depreciable(depreciable) {}

/** @brief Get the asset type identifier. */
std::string AssetType::getTypeId() const { return typeId; }

/** @brief Get the asset type name. */
std::string AssetType::getName() const { return name; }

/** @brief Get the asset type description. */
std::string AssetType::getDescription() const { return description; }

/** @brief Return whether the type is depreciable. */
bool AssetType::isDepreciable() const { return depreciable; }

/** @brief Set the asset type identifier. */
void AssetType::setTypeId(const std::string& typeId) { this->typeId = typeId; }

/** @brief Set the asset type name. */
void AssetType::setName(const std::string& name) { this->name = name; }

/** @brief Set the asset type description. */
void AssetType::setDescription(const std::string& description) { this->description = description; }

/** @brief Set whether the type is depreciable. */
void AssetType::setDepreciable(bool depreciable) { this->depreciable = depreciable; }

/** @brief Convert this asset type to a human-readable string. */
std::string AssetType::to_string() const {
    return "typeId=" + typeId +
           "; name=" + name +
           "; description=" + description +
           "; depreciable=" + (depreciable ? "true" : "false");
}

/** @brief Compare two asset type values. */
bool AssetType::operator==(const AssetType& other) const {
    return typeId == other.typeId &&
           name == other.name &&
           description == other.description &&
           depreciable == other.depreciable;
}

/** @brief Stream an asset type value. */
std::ostream& operator<<(std::ostream& os, const AssetType& assetType) {
    os << assetType.to_string();
    return os;
}
