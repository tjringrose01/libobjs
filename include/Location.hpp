/**
 *  Location.hpp - Location Class Definition.
 */

#ifndef LIBOBJS_LOCATION_HPP
#define LIBOBJS_LOCATION_HPP

#include <ostream>
#include <string>

/**
 * @brief Location model.
 */
class Location {
private:
    std::string locationId;
    std::string name;
    std::string parentLocationId;
    std::string address;

public:
    Location();
    Location(const std::string& locationId,
             const std::string& name,
             const std::string& parentLocationId,
             const std::string& address);

    std::string getLocationId() const;
    std::string getName() const;
    std::string getParentLocationId() const;
    std::string getAddress() const;

    void setLocationId(const std::string& locationId);
    void setName(const std::string& name);
    void setParentLocationId(const std::string& parentLocationId);
    void setAddress(const std::string& address);

    std::string to_string() const;

    bool operator==(const Location& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Location& location);
};

#endif  // LIBOBJS_LOCATION_HPP
