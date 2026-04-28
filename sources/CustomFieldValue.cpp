/**
 *  CustomFieldValue.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the CustomFieldValue model.
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
 *  - Values reference a custom field definition and target entity.
 */

#include "CustomFieldValue.hpp"

/** @brief Construct a default custom field value. */
CustomFieldValue::CustomFieldValue()
    : definitionId(""), entityId(""), value(""), lastUpdated(Dt()) {}

/** @brief Construct a custom field value with explicit values. */
CustomFieldValue::CustomFieldValue(const std::string& definitionId,
                                   const std::string& entityId,
                                   const std::string& value,
                                   const Dt& lastUpdated)
    : definitionId(definitionId), entityId(entityId), value(value), lastUpdated(lastUpdated) {}

/** @brief Get definition identifier. */
std::string CustomFieldValue::getDefinitionId() const { return definitionId; }

/** @brief Get target entity identifier. */
std::string CustomFieldValue::getEntityId() const { return entityId; }

/** @brief Get stored value text. */
std::string CustomFieldValue::getValue() const { return value; }

/** @brief Get last-updated date. */
Dt CustomFieldValue::getLastUpdated() const { return lastUpdated; }

/** @brief Set definition identifier. */
void CustomFieldValue::setDefinitionId(const std::string& definitionId) { this->definitionId = definitionId; }

/** @brief Set target entity identifier. */
void CustomFieldValue::setEntityId(const std::string& entityId) { this->entityId = entityId; }

/** @brief Set stored value text. */
void CustomFieldValue::setValue(const std::string& value) { this->value = value; }

/** @brief Set last-updated date. */
void CustomFieldValue::setLastUpdated(const Dt& lastUpdated) { this->lastUpdated = lastUpdated; }

/** @brief Convert this custom field value to a human-readable string. */
std::string CustomFieldValue::to_string() const {
    return "definitionId=" + definitionId +
           "; entityId=" + entityId +
           "; value=" + value +
           "; lastUpdated=" + lastUpdated.to_string();
}

/** @brief Compare two custom field value records. */
bool CustomFieldValue::operator==(const CustomFieldValue& other) const {
    return definitionId == other.definitionId &&
           entityId == other.entityId &&
           value == other.value &&
           lastUpdated == other.lastUpdated;
}

/** @brief Stream a custom field value record. */
std::ostream& operator<<(std::ostream& os, const CustomFieldValue& fieldValue) {
    os << fieldValue.to_string();
    return os;
}
