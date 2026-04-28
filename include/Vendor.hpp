/**
 *  Vendor.hpp - Vendor Class Definition.
 */

#ifndef LIBOBJS_VENDOR_HPP
#define LIBOBJS_VENDOR_HPP

#include <ostream>
#include <string>

/**
 * @brief Vendor model.
 */
class Vendor {
private:
    std::string vendorId;
    std::string name;
    std::string contactName;
    std::string contactEmail;
    std::string contactPhone;

public:
    Vendor();
    Vendor(const std::string& vendorId,
           const std::string& name,
           const std::string& contactName,
           const std::string& contactEmail,
           const std::string& contactPhone);

    std::string getVendorId() const;
    std::string getName() const;
    std::string getContactName() const;
    std::string getContactEmail() const;
    std::string getContactPhone() const;

    void setVendorId(const std::string& vendorId);
    void setName(const std::string& name);
    void setContactName(const std::string& contactName);
    void setContactEmail(const std::string& contactEmail);
    void setContactPhone(const std::string& contactPhone);

    std::string to_string() const;

    bool operator==(const Vendor& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Vendor& vendor);
};

#endif  // LIBOBJS_VENDOR_HPP
