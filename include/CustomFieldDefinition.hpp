/**
 *  CustomFieldDefinition.hpp - CustomFieldDefinition Class Definition.
 */

#ifndef LIBOBJS_CUSTOM_FIELD_DEFINITION_HPP
#define LIBOBJS_CUSTOM_FIELD_DEFINITION_HPP

#include <ostream>
#include <string>

/**
 * @brief CustomFieldType enumeration.
 */
enum class CustomFieldType {
    TEXT = 0,
    NUMBER = 1,
    DATE = 2,
    BOOLEAN = 3
};

/**
 * @brief CustomFieldDefinition model.
 */
class CustomFieldDefinition {
private:
    std::string definitionId;
    std::string entityType;
    std::string fieldName;
    CustomFieldType fieldType;
    bool required;

public:
    CustomFieldDefinition();
    CustomFieldDefinition(const std::string& definitionId,
                          const std::string& entityType,
                          const std::string& fieldName,
                          CustomFieldType fieldType,
                          bool required);

    std::string getDefinitionId() const;
    std::string getEntityType() const;
    std::string getFieldName() const;
    CustomFieldType getFieldType() const;
    bool isRequired() const;

    void setDefinitionId(const std::string& definitionId);
    void setEntityType(const std::string& entityType);
    void setFieldName(const std::string& fieldName);
    void setFieldType(CustomFieldType fieldType);
    void setRequired(bool required);

    static std::string customFieldTypeToString(CustomFieldType fieldType);
    std::string to_string() const;

    bool operator==(const CustomFieldDefinition& other) const;
    friend std::ostream& operator<<(std::ostream& os, const CustomFieldDefinition& definition);
};

#endif  // LIBOBJS_CUSTOM_FIELD_DEFINITION_HPP
