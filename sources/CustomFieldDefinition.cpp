/**
 *  CustomFieldDefinition.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the CustomFieldDefinition model.
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
 *  - Field definitions constrain allowed value types for entity extensions.
 */

#include "CustomFieldDefinition.hpp"

/** @brief Construct a default custom field definition. */
CustomFieldDefinition::CustomFieldDefinition()
    : definitionId(""), entityType(""), fieldName(""), fieldType(CustomFieldType::TEXT), required(false) {}

/** @brief Construct a custom field definition with explicit values. */
CustomFieldDefinition::CustomFieldDefinition(const std::string& definitionId,
                                             const std::string& entityType,
                                             const std::string& fieldName,
                                             CustomFieldType fieldType,
                                             bool required)
    : definitionId(definitionId),
      entityType(entityType),
      fieldName(fieldName),
      fieldType(fieldType),
      required(required) {}

/** @brief Get definition identifier. */
std::string CustomFieldDefinition::getDefinitionId() const { return definitionId; }

/** @brief Get entity type label. */
std::string CustomFieldDefinition::getEntityType() const { return entityType; }

/** @brief Get field name. */
std::string CustomFieldDefinition::getFieldName() const { return fieldName; }

/** @brief Get field type. */
CustomFieldType CustomFieldDefinition::getFieldType() const { return fieldType; }

/** @brief Get whether value is required. */
bool CustomFieldDefinition::isRequired() const { return required; }

/** @brief Set definition identifier. */
void CustomFieldDefinition::setDefinitionId(const std::string& definitionId) { this->definitionId = definitionId; }

/** @brief Set entity type label. */
void CustomFieldDefinition::setEntityType(const std::string& entityType) { this->entityType = entityType; }

/** @brief Set field name. */
void CustomFieldDefinition::setFieldName(const std::string& fieldName) { this->fieldName = fieldName; }

/** @brief Set field type. */
void CustomFieldDefinition::setFieldType(CustomFieldType fieldType) { this->fieldType = fieldType; }

/** @brief Set required flag. */
void CustomFieldDefinition::setRequired(bool required) { this->required = required; }

/** @brief Convert custom field type enum to text. */
std::string CustomFieldDefinition::customFieldTypeToString(CustomFieldType fieldType) {
    switch (fieldType) {
        case CustomFieldType::TEXT:
            return "TEXT";
        case CustomFieldType::NUMBER:
            return "NUMBER";
        case CustomFieldType::DATE:
            return "DATE";
        case CustomFieldType::BOOLEAN:
            return "BOOLEAN";
        default:
            return "UNKNOWN";
    }
}

/** @brief Convert this custom field definition to a human-readable string. */
std::string CustomFieldDefinition::to_string() const {
    return "definitionId=" + definitionId +
           "; entityType=" + entityType +
           "; fieldName=" + fieldName +
           "; fieldType=" + customFieldTypeToString(fieldType) +
           "; required=" + (required ? "true" : "false");
}

/** @brief Compare two custom field definition values. */
bool CustomFieldDefinition::operator==(const CustomFieldDefinition& other) const {
    return definitionId == other.definitionId &&
           entityType == other.entityType &&
           fieldName == other.fieldName &&
           fieldType == other.fieldType &&
           required == other.required;
}

/** @brief Stream a custom field definition value. */
std::ostream& operator<<(std::ostream& os, const CustomFieldDefinition& definition) {
    os << definition.to_string();
    return os;
}
