/**
 *  AssetType.hpp - AssetType Class Definition.
 */

#ifndef LIBOBJS_ASSET_TYPE_HPP
#define LIBOBJS_ASSET_TYPE_HPP

#include <ostream>
#include <string>

/**
 * @brief AssetType model.
 */
class AssetType {
private:
    std::string typeId;
    std::string name;
    std::string description;
    bool depreciable;

public:
    AssetType();
    AssetType(const std::string& typeId,
              const std::string& name,
              const std::string& description,
              bool depreciable);

    std::string getTypeId() const;
    std::string getName() const;
    std::string getDescription() const;
    bool isDepreciable() const;

    void setTypeId(const std::string& typeId);
    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setDepreciable(bool depreciable);

    std::string to_string() const;

    bool operator==(const AssetType& other) const;
    friend std::ostream& operator<<(std::ostream& os, const AssetType& assetType);
};

#endif  // LIBOBJS_ASSET_TYPE_HPP
