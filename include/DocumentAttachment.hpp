/**
 *  DocumentAttachment.hpp - DocumentAttachment Class Definition.
 */

#ifndef LIBOBJS_DOCUMENT_ATTACHMENT_HPP
#define LIBOBJS_DOCUMENT_ATTACHMENT_HPP

#include <ostream>
#include <string>
#include "Dt.hpp"

/**
 * @brief DocumentAttachment model.
 */
class DocumentAttachment {
private:
    std::string attachmentId;
    std::string entityType;
    std::string entityId;
    std::string filePath;
    std::string fileHash;
    Dt uploadedDate;

public:
    DocumentAttachment();
    DocumentAttachment(const std::string& attachmentId,
                       const std::string& entityType,
                       const std::string& entityId,
                       const std::string& filePath,
                       const std::string& fileHash,
                       const Dt& uploadedDate);

    std::string getAttachmentId() const;
    std::string getEntityType() const;
    std::string getEntityId() const;
    std::string getFilePath() const;
    std::string getFileHash() const;
    Dt getUploadedDate() const;

    void setAttachmentId(const std::string& attachmentId);
    void setEntityType(const std::string& entityType);
    void setEntityId(const std::string& entityId);
    void setFilePath(const std::string& filePath);
    void setFileHash(const std::string& fileHash);
    void setUploadedDate(const Dt& uploadedDate);

    std::string to_string() const;

    bool operator==(const DocumentAttachment& other) const;
    friend std::ostream& operator<<(std::ostream& os, const DocumentAttachment& attachment);
};

#endif  // LIBOBJS_DOCUMENT_ATTACHMENT_HPP
