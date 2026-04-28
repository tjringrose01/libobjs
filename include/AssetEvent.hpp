/**
 *  AssetEvent.hpp - AssetEvent Class Definition.
 */

#ifndef LIBOBJS_ASSET_EVENT_HPP
#define LIBOBJS_ASSET_EVENT_HPP

#include <ostream>
#include <string>
#include "Dt.hpp"

/**
 * @brief AssetEventType enumeration.
 */
enum class AssetEventType {
    CREATED = 0,
    MOVED = 1,
    ASSIGNED = 2,
    RETURNED = 3,
    MAINTENANCE = 4,
    RETIRED = 5,
    DISPOSED = 6
};

/**
 * @brief AssetEvent model.
 */
class AssetEvent {
private:
    std::string eventId;
    std::string assetId;
    AssetEventType eventType;
    Dt eventDate;
    std::string actorId;
    std::string details;

public:
    AssetEvent();
    AssetEvent(const std::string& eventId,
               const std::string& assetId,
               AssetEventType eventType,
               const Dt& eventDate,
               const std::string& actorId,
               const std::string& details);

    std::string getEventId() const;
    std::string getAssetId() const;
    AssetEventType getEventType() const;
    Dt getEventDate() const;
    std::string getActorId() const;
    std::string getDetails() const;

    void setEventId(const std::string& eventId);
    void setAssetId(const std::string& assetId);
    void setEventType(AssetEventType eventType);
    void setEventDate(const Dt& eventDate);
    void setActorId(const std::string& actorId);
    void setDetails(const std::string& details);

    static std::string assetEventTypeToString(AssetEventType eventType);
    std::string to_string() const;

    bool operator==(const AssetEvent& other) const;
    friend std::ostream& operator<<(std::ostream& os, const AssetEvent& event);
};

#endif  // LIBOBJS_ASSET_EVENT_HPP
