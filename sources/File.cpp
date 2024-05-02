#include <string>
#include <fstream>
#include "File.hpp"

using namespace std;

/**
 * Constructor for creating a File object.
 * 
 * @param name The name of the file.
 * @param path The path where the file is located.
 */
File::File(const std::string& name, const std::string& path) : name(name), path(path) {}

/**
 * Constructor for creating a File object.
 * 
 * @param name The absolute name of the file.
 */
File::File(const std::string& name) {
    // Determin filename
    this->name = getNameFromAbsolutePath(name);

    // Determine path
    this->path = getPathFromAbsolutePath(name);
}

/**
 * Get the name of the file.
 * 
 * @return The name of the file.
 */
std::string File::getName() const {
    return name;
}

/**
 * Get the path of the file.
 * 
 * @return The path of the file.
 */
std::string File::getPath() const {
    return path;
}

/**
 * Get the path of the file.
 * 
 * @return The absolute path of the file.
 */
std::string File::getAbsolutePath() const {
    return path + "/" + name;
}

/**
 * Check if the file exists.
 * 
 * @return True if the file exists, false otherwise.
 */
bool File::exists() const {
    // Implement this
    // Check if the file exists
    // Return true if the file exists, false otherwise
    // For now, return false as a placeholder
    ifstream f(getAbsolutePath().c_str());
    return f.good();
}

/**
 * Get the size of the file.
 * 
 * @return The size of the file.
 */
size_t File::getSize() const {
    ifstream in(getAbsolutePath(), ifstream::ate | ifstream::binary);
    return in.tellg();
}

/**
 * Get the path from the absolute path of the file.
 * 
 * @return The path extracted from the absolute path.
 */
std::string File::getPathFromAbsolutePath(string fileName) {
    // Actually implement this
    // Extract path from the absolute path
    // For example:
    // If the absolute path is "/home/user/documents/file.txt"
    // The extracted path should be "/home/user/documents"
    string path = "";

    size_t separatorPos = fileName.find_last_of("/\\");
    if (separatorPos != std::string::npos) {
        // Extract the path and filename
        path = fileName.substr(0, separatorPos); // Include the separator in the path
    } else {
        // No path separator found, consider the entire string as the filename
        path = "";
    }
    return path;
}

/**
 * Get the name from the absolute path of the file.
 * 
 * @return The name extracted from the absolute path.
 */
std::string File::getNameFromAbsolutePath(string fileName) {
    // Implement a function to perform this
    // Extract name from the absolute path
    // For example:
    // If the absolute path is "/home/user/documents/file.txt"
    // The extracted name should be "file.txt"
    string name = "";

    size_t separatorPos = fileName.find_last_of("/\\");
    if (separatorPos != std::string::npos) {
        // Extract the path and filename
        name = fileName.substr(separatorPos + 1);
    } else {
        // No path separator found, consider the entire string as the filename
        name = fileName;
    }
    return name; // Placeholder, replace with actual implementation
}

