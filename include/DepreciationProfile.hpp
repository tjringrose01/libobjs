/**
 *  DepreciationProfile.hpp - DepreciationProfile Class Definition.
 */

#ifndef LIBOBJS_DEPRECIATION_PROFILE_HPP
#define LIBOBJS_DEPRECIATION_PROFILE_HPP

#include <ostream>
#include <string>

/**
 * @brief DepreciationMethod enumeration.
 */
enum class DepreciationMethod {
    STRAIGHT_LINE = 0,
    DECLINING_BALANCE = 1,
    UNITS_OF_PRODUCTION = 2
};

/**
 * @brief DepreciationProfile model.
 */
class DepreciationProfile {
private:
    std::string profileId;
    DepreciationMethod method;
    int usefulLifeMonths;
    double salvagePercent;

public:
    DepreciationProfile();
    DepreciationProfile(const std::string& profileId,
                        DepreciationMethod method,
                        int usefulLifeMonths,
                        double salvagePercent);

    std::string getProfileId() const;
    DepreciationMethod getMethod() const;
    int getUsefulLifeMonths() const;
    double getSalvagePercent() const;

    void setProfileId(const std::string& profileId);
    void setMethod(DepreciationMethod method);
    void setUsefulLifeMonths(int usefulLifeMonths);
    void setSalvagePercent(double salvagePercent);

    double monthlyRate() const;
    static std::string depreciationMethodToString(DepreciationMethod method);
    std::string to_string() const;

    bool operator==(const DepreciationProfile& other) const;
    friend std::ostream& operator<<(std::ostream& os, const DepreciationProfile& profile);
};

#endif  // LIBOBJS_DEPRECIATION_PROFILE_HPP
