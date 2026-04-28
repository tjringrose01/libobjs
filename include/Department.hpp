/**
 *  Department.hpp - Department Class Definition.
 */

#ifndef LIBOBJS_DEPARTMENT_HPP
#define LIBOBJS_DEPARTMENT_HPP

#include <ostream>
#include <string>

/**
 * @brief Department model.
 */
class Department {
private:
    std::string departmentId;
    std::string name;
    std::string costCenter;
    std::string managerId;

public:
    Department();
    Department(const std::string& departmentId,
               const std::string& name,
               const std::string& costCenter,
               const std::string& managerId);

    std::string getDepartmentId() const;
    std::string getName() const;
    std::string getCostCenter() const;
    std::string getManagerId() const;

    void setDepartmentId(const std::string& departmentId);
    void setName(const std::string& name);
    void setCostCenter(const std::string& costCenter);
    void setManagerId(const std::string& managerId);

    std::string to_string() const;

    bool operator==(const Department& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Department& department);
};

#endif  // LIBOBJS_DEPARTMENT_HPP
