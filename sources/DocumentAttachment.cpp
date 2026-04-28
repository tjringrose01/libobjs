/**
 *  DocumentAttachment.cpp - libobjs Class Implementation - This class is
 *             responsible for implementing the DocumentAttachment model.
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
 *  - Hash and file path link metadata to external document storage.
 */

#include "DocumentAttachment.hpp"

/** @brief Construct a default document attachment record. */
DocumentAttachment::DocumentAttachment()
    : attachmentId(""),
      entityType(""),
      entityId(""),
      filePath(""),
      fileHash(""),
      uploadedDate(Dt()) {}

/** @brief Construct a document attachment record with explicit values. */
DocumentAttachment::DocumentAttachment(const std::string& attachmentId,
                                       const std::string& entityType,
                                       const std::string& entityId,
                                       const std::string& filePath,
                                       const std::string& fileHash,
                                       const Dt& uploadedDate)
    : attachmentId(attachmentId),
      entityType(entityType),
      entityId(entityId),
      filePath(filePath),
      fileHash(fileHash),
      uploadedDate(uploadedDate) {}

/** @brief Get attachment identifier. */
std::string DocumentAttachment::getAttachmentId() const { return attachmentId; }

/** @brief Get attached entity type. */
std::string DocumentAttachment::getEntityType() const { return entityType; }

/** @brief Get attached entity identifier. */
std::string DocumentAttachment::getEntityId() const { return entityId; }

/** @brief Get file path. */
std::string DocumentAttachment::getFilePath() const { return filePath; }

/** @brief Get file hash. */
std::string DocumentAttachment::getFileHash() const { return fileHash; }

/** @brief Get uploaded date. */
Dt DocumentAttachment::getUploadedDate() const { return uploadedDate; }

/** @brief Set attachment identifier. */
void DocumentAttachment::setAttachmentId(const std::string& attachmentId) { this->attachmentId = attachmentId; }

/** @brief Set attached entity type. */
void DocumentAttachment::setEntityType(const std::string& entityType) { this->entityType = entityType; }

/** @brief Set attached entity identifier. */
void DocumentAttachment::setEntityId(const std::string& entityId) { this->entityId = entityId; }

/** @brief Set file path. */
void DocumentAttachment::setFilePath(const std::string& filePath) { this->filePath = filePath; }

/** @brief Set file hash. */
void DocumentAttachment::setFileHash(const std::string& fileHash) { this->fileHash = fileHash; }

/** @brief Set uploaded date. */
void DocumentAttachment::setUploadedDate(const Dt& uploadedDate) { this->uploadedDate = uploadedDate; }

/** @brief Convert this document attachment to a human-readable string. */
std::string DocumentAttachment::to_string() const {
    return "attachmentId=" + attachmentId +
           "; entityType=" + entityType +
           "; entityId=" + entityId +
           "; filePath=" + filePath +
           "; fileHash=" + fileHash +
           "; uploadedDate=" + uploadedDate.to_string();
}

/** @brief Compare two document attachment values. */
bool DocumentAttachment::operator==(const DocumentAttachment& other) const {
    return attachmentId == other.attachmentId &&
           entityType == other.entityType &&
           entityId == other.entityId &&
           filePath == other.filePath &&
           fileHash == other.fileHash &&
           uploadedDate == other.uploadedDate;
}

/** @brief Stream a document attachment value. */
std::ostream& operator<<(std::ostream& os, const DocumentAttachment& attachment) {
    os << attachment.to_string();
    return os;
}
