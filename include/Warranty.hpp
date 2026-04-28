/**
 *  Warranty.hpp - Warranty Class Definition.
 */

#ifndef LIBOBJS_WARRANTY_HPP
#define LIBOBJS_WARRANTY_HPP

#include <ostream>
#include <string>
#include "Dt.hpp"

/**
 * @brief Warranty model.
 */
class Warranty {
private:
    std::string warrantyId;
    std::string assetId;
    std::string vendorId;
    Dt startDate;
    Dt endDate;
    std::string terms;

public:
    Warranty();
    Warranty(const std::string& warrantyId,
             const std::string& assetId,
             const std::string& vendorId,
             const Dt& startDate,
             const Dt& endDate,
             const std::string& terms);

    std::string getWarrantyId() const;
    std::string getAssetId() const;
    std::string getVendorId() const;
    Dt getStartDate() const;
    Dt getEndDate() const;
    std::string getTerms() const;

    void setWarrantyId(const std::string& warrantyId);
    void setAssetId(const std::string& assetId);
    void setVendorId(const std::string& vendorId);
    void setStartDate(const Dt& startDate);
    void setEndDate(const Dt& endDate);
    void setTerms(const std::string& terms);

    bool isCoverageDate(const Dt& date) const;
    std::string to_string() const;

    bool operator==(const Warranty& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Warranty& warranty);
};

#endif  // LIBOBJS_WARRANTY_HPP
