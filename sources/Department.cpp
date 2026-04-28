/**
 *  Department.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the Department model.
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
 *  - Department ownership links assets to reporting/cost-center boundaries.
 */

#include "Department.hpp"

/** @brief Construct a default department. */
Department::Department() : departmentId(""), name(""), costCenter(""), managerId("") {}

/** @brief Construct a department with explicit values. */
Department::Department(const std::string& departmentId,
                       const std::string& name,
                       const std::string& costCenter,
                       const std::string& managerId)
    : departmentId(departmentId), name(name), costCenter(costCenter), managerId(managerId) {}

std::string Department::getDepartmentId() const { return departmentId; }

std::string Department::getName() const { return name; }

std::string Department::getCostCenter() const { return costCenter; }

std::string Department::getManagerId() const { return managerId; }

void Department::setDepartmentId(const std::string& departmentId) { this->departmentId = departmentId; }

void Department::setName(const std::string& name) { this->name = name; }

void Department::setCostCenter(const std::string& costCenter) { this->costCenter = costCenter; }

void Department::setManagerId(const std::string& managerId) { this->managerId = managerId; }

/**
 * @brief Produce a deterministic key/value snapshot of the department state.
 * @details Intended for diagnostics rather than end-user presentation.
 */
std::string Department::to_string() const {
    return "departmentId=" + departmentId +
           "; name=" + name +
           "; costCenter=" + costCenter +
           "; managerId=" + managerId;
}

/**
 * @brief Compare two departments for strict field-by-field equality.
 */
bool Department::operator==(const Department& other) const {
    return departmentId == other.departmentId &&
           name == other.name &&
           costCenter == other.costCenter &&
           managerId == other.managerId;
}

std::ostream& operator<<(std::ostream& os, const Department& department) {
    os << department.to_string();
    return os;
}
