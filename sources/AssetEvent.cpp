/**
 *  AssetEvent.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the AssetEvent model.
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
 *  - Events provide an immutable-style audit trail for asset lifecycle actions.
 */

#include "AssetEvent.hpp"

/** @brief Construct a default asset event. */
AssetEvent::AssetEvent()
    : eventId(""),
      assetId(""),
      eventType(AssetEventType::CREATED),
      eventDate(Dt()),
      actorId(""),
      details("") {}

/** @brief Construct an asset event with explicit values. */
AssetEvent::AssetEvent(const std::string& eventId,
                       const std::string& assetId,
                       AssetEventType eventType,
                       const Dt& eventDate,
                       const std::string& actorId,
                       const std::string& details)
    : eventId(eventId),
      assetId(assetId),
      eventType(eventType),
      eventDate(eventDate),
      actorId(actorId),
      details(details) {}

/** @brief Get the event identifier. */
std::string AssetEvent::getEventId() const { return eventId; }

/** @brief Get the related asset identifier. */
std::string AssetEvent::getAssetId() const { return assetId; }

/** @brief Get the event type. */
AssetEventType AssetEvent::getEventType() const { return eventType; }

/** @brief Get the event date. */
Dt AssetEvent::getEventDate() const { return eventDate; }

/** @brief Get the actor identifier. */
std::string AssetEvent::getActorId() const { return actorId; }

/** @brief Get detail text for the event. */
std::string AssetEvent::getDetails() const { return details; }

/** @brief Set the event identifier. */
void AssetEvent::setEventId(const std::string& eventId) { this->eventId = eventId; }

/** @brief Set the related asset identifier. */
void AssetEvent::setAssetId(const std::string& assetId) { this->assetId = assetId; }

/** @brief Set the event type. */
void AssetEvent::setEventType(AssetEventType eventType) { this->eventType = eventType; }

/** @brief Set the event date. */
void AssetEvent::setEventDate(const Dt& eventDate) { this->eventDate = eventDate; }

/** @brief Set the actor identifier. */
void AssetEvent::setActorId(const std::string& actorId) { this->actorId = actorId; }

/** @brief Set detail text for the event. */
void AssetEvent::setDetails(const std::string& details) { this->details = details; }

/** @brief Convert an event type enum value to text. */
std::string AssetEvent::assetEventTypeToString(AssetEventType eventType) {
    switch (eventType) {
        case AssetEventType::CREATED:
            return "CREATED";
        case AssetEventType::MOVED:
            return "MOVED";
        case AssetEventType::ASSIGNED:
            return "ASSIGNED";
        case AssetEventType::RETURNED:
            return "RETURNED";
        case AssetEventType::MAINTENANCE:
            return "MAINTENANCE";
        case AssetEventType::RETIRED:
            return "RETIRED";
        case AssetEventType::DISPOSED:
            return "DISPOSED";
        default:
            return "UNKNOWN";
    }
}

/** @brief Convert this asset event to a human-readable string. */
std::string AssetEvent::to_string() const {
    return "eventId=" + eventId +
           "; assetId=" + assetId +
           "; eventType=" + assetEventTypeToString(eventType) +
           "; eventDate=" + eventDate.to_string() +
           "; actorId=" + actorId +
           "; details=" + details;
}

/** @brief Compare two asset event values. */
bool AssetEvent::operator==(const AssetEvent& other) const {
    return eventId == other.eventId &&
           assetId == other.assetId &&
           eventType == other.eventType &&
           eventDate == other.eventDate &&
           actorId == other.actorId &&
           details == other.details;
}

/** @brief Stream an asset event value. */
std::ostream& operator<<(std::ostream& os, const AssetEvent& event) {
    os << event.to_string();
    return os;
}
