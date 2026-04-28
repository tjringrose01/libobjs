/**
 *  Location.hpp - Location Class Definition.
 */

#ifndef LIBOBJS_LOCATION_HPP
#define LIBOBJS_LOCATION_HPP

#include <ostream>
#include <string>

/**
 * @brief Physical or logical location descriptor.
 * @details Supports parent-child hierarchy through `parentLocationId`.
 */
class Location {
private:
    std::string locationId;
    std::string name;
    std::string parentLocationId;
    std::string address;

public:
    /**
     * @brief Creates an empty location value.
     */
    Location();

    /**
     * @brief Creates a location from explicit values.
     * @param locationId Stable location identifier.
     * @param name Human-facing location name.
     * @param parentLocationId Optional parent location identifier for hierarchy.
     * @param address Free-form address text.
     * @note Empty `parentLocationId` indicates a root location.
     */
    Location(const std::string& locationId,
             const std::string& name,
             const std::string& parentLocationId,
             const std::string& address);

    /**
     * @brief Returns location identifier.
     * @return Stored `locationId` value.
     */
    std::string getLocationId() const;

    /**
     * @brief Returns location display name.
     * @return Stored `name` value.
     */
    std::string getName() const;

    /**
     * @brief Returns parent location identifier.
     * @return Stored `parentLocationId` value; empty means no parent.
     */
    std::string getParentLocationId() const;

    /**
     * @brief Returns address text.
     * @return Stored `address` value.
     */
    std::string getAddress() const;

    /**
     * @brief Replaces location identifier.
     * @param locationId New location ID.
     */
    void setLocationId(const std::string& locationId);

    /**
     * @brief Replaces location display name.
     * @param name New name text.
     */
    void setName(const std::string& name);

    /**
     * @brief Replaces parent location identifier.
     * @param parentLocationId New parent ID; empty removes the parent relationship.
     */
    void setParentLocationId(const std::string& parentLocationId);

    /**
     * @brief Replaces address text.
     * @param address New address value.
     */
    void setAddress(const std::string& address);

    /**
     * @brief Builds a diagnostic string with all stored fields.
     * @return Semicolon-delimited key/value string intended for logs and debugging.
     */
    std::string to_string() const;

    /**
     * @brief Compares two locations for strict value equality.
     * @param other Value to compare against.
     * @return `true` only when all stored fields match.
     */
    bool operator==(const Location& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Location& location);
};

#endif  // LIBOBJS_LOCATION_HPP
