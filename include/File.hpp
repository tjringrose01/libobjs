#ifndef FILE_HPP
#define FILE_HPP

#include <string>
#include "MD5.hpp"

using namespace std;

/**
 * Represents a file with its name, path, and size.
 */
class File {
public:
    /**
     * Constructor for creating a File object.
     * 
     * @param name The name of the file.
     * @param path The path where the file is located.
     */
    File(const std::string& name, const std::string& path);

    /**
     * Constructor for creating a File object.
     * 
     * @param name The absolute name of the file.
     */
    File(const std::string& name);

    /**
     * Get the name of the file.
     * 
     * @return The name of the file.
     */
    std::string getName() const;

    /**
     * Get the path of the file.
     * 
     * @return The path of the file.
     */
    std::string getPath() const;

    /**
     * Get the path of the file.
     * 
     * @return The absolute path of the file.
     */
    std::string getAbsolutePath() const;

    /**
     * Get the size of the file.
     * 
     * @return The size of the file.
     */
    size_t getSize() const;

    /**
     * Check if the file exists.
     * 
     * @return True if the file exists, false otherwise.
     */
    bool exists() const;

    /**
     * Get the MD5 hash of the file.
     * 
     * @return The MD5 hash of the file.
     */
    string getMD5() const;

private:
    std::string name; /**< The name of the file. */
    std::string path; /**< The path of the file. */
    
    /**
     * Get the path from the absolute path of the file.
     * 
     * @return The path extracted from the absolute path.
     */
    string getPathFromAbsolutePath(string fileName);

    /**
     * Get the name from the absolute path of the file.
     * 
     * @return The name extracted from the absolute path.
     */
    string getNameFromAbsolutePath(string fileName);
};


#endif // FILE_HPP