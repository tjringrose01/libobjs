/**
 *  Department.hpp - Department Class Definition.
 */

#ifndef LIBOBJS_DEPARTMENT_HPP
#define LIBOBJS_DEPARTMENT_HPP

#include <ostream>
#include <string>

/**
 * @brief Department ownership descriptor.
 * @details Associates assets to organizational ownership and cost tracking metadata.
 */
class Department {
private:
    std::string departmentId;
    std::string name;
    std::string costCenter;
    std::string managerId;

public:
    /**
     * @brief Creates an empty department value.
     */
    Department();

    /**
     * @brief Creates a department from explicit values.
     * @param departmentId Stable department identifier.
     * @param name Department display name.
     * @param costCenter Financial cost center code.
     * @param managerId Optional manager identifier.
     */
    Department(const std::string& departmentId,
               const std::string& name,
               const std::string& costCenter,
               const std::string& managerId);

    /**
     * @brief Returns department identifier.
     * @return Stored `departmentId` value.
     */
    std::string getDepartmentId() const;

    /**
     * @brief Returns department display name.
     * @return Stored `name` value.
     */
    std::string getName() const;

    /**
     * @brief Returns cost center code.
     * @return Stored `costCenter` value.
     */
    std::string getCostCenter() const;

    /**
     * @brief Returns manager identifier.
     * @return Stored `managerId` value; empty indicates no manager mapping.
     */
    std::string getManagerId() const;

    /**
     * @brief Replaces department identifier.
     * @param departmentId New department ID.
     */
    void setDepartmentId(const std::string& departmentId);

    /**
     * @brief Replaces department display name.
     * @param name New department name.
     */
    void setName(const std::string& name);

    /**
     * @brief Replaces cost center code.
     * @param costCenter New cost center text.
     */
    void setCostCenter(const std::string& costCenter);

    /**
     * @brief Replaces manager identifier.
     * @param managerId New manager ID; empty indicates no manager mapping.
     */
    void setManagerId(const std::string& managerId);

    /**
     * @brief Builds a diagnostic string with all stored fields.
     * @return Semicolon-delimited key/value string intended for logs and debugging.
     */
    std::string to_string() const;

    /**
     * @brief Compares two departments for strict value equality.
     * @param other Value to compare against.
     * @return `true` only when all stored fields match.
     */
    bool operator==(const Department& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Department& department);
};

#endif  // LIBOBJS_DEPARTMENT_HPP
