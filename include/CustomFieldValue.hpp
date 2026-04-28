/**
 *  CustomFieldValue.hpp - CustomFieldValue Class Definition.
 */

#ifndef LIBOBJS_CUSTOM_FIELD_VALUE_HPP
#define LIBOBJS_CUSTOM_FIELD_VALUE_HPP

#include <ostream>
#include <string>
#include "Dt.hpp"

/**
 * @brief CustomFieldValue model.
 */
class CustomFieldValue {
private:
    std::string definitionId;
    std::string entityId;
    std::string value;
    Dt lastUpdated;

public:
    CustomFieldValue();
    CustomFieldValue(const std::string& definitionId,
                     const std::string& entityId,
                     const std::string& value,
                     const Dt& lastUpdated);

    std::string getDefinitionId() const;
    std::string getEntityId() const;
    std::string getValue() const;
    Dt getLastUpdated() const;

    void setDefinitionId(const std::string& definitionId);
    void setEntityId(const std::string& entityId);
    void setValue(const std::string& value);
    void setLastUpdated(const Dt& lastUpdated);

    std::string to_string() const;

    bool operator==(const CustomFieldValue& other) const;
    friend std::ostream& operator<<(std::ostream& os, const CustomFieldValue& fieldValue);
};

#endif  // LIBOBJS_CUSTOM_FIELD_VALUE_HPP
