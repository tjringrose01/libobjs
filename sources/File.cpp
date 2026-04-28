/**
 *  File.cpp - libobjs Class Implementation - This class is
 *             responsible for defining and parsing filesystem file metadata.
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
 *  - Path parsing supports both Unix and Windows-style separators.
 *  - Hidden file detection follows Unix dotfile conventions.
 */

#include <string>
#include <fstream>
#include <cctype>
#include "File.hpp"
#include "MD5.hpp"

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
    if (path.empty()) {
        return name;
    }

    // Check for trailing slash
    if (path.back() == '/' || path.back() == '\\') {
        return path + name;
    }

    // Preserve Windows-style separators if the path uses backslashes only.
    if (path.find('\\') != std::string::npos && path.find('/') == std::string::npos) {
        return path + "\\" + name;
    }

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
    if (!in.good()) {
        return 0;
    }

    const std::streampos endPos = in.tellg();
    if (endPos < 0) {
        return 0;
    }

    return static_cast<size_t>(endPos);
}

/**
 * Get the MD5 hash of the file.
 * 
 * @return The MD5 hash of the file.
 */
string File::getMD5() const {
    MD5 md5;
    string md5_hash = md5.calculate(getAbsolutePath());
    
    return md5_hash;
}

/**
 * Check whether the file path is absolute.
 *
 * @return True when the absolute path is absolute, false otherwise.
 */
bool File::isAbsolutePath() const {
    const string absolutePath = getAbsolutePath();

    if (absolutePath.empty()) {
        return false;
    }

    if (absolutePath[0] == '/' || absolutePath[0] == '\\') {
        return true;
    }

    // Windows-style absolute path, such as C:\temp\file.txt
    if (absolutePath.length() > 2 &&
        std::isalpha(static_cast<unsigned char>(absolutePath[0])) &&
        absolutePath[1] == ':' &&
        (absolutePath[2] == '\\' || absolutePath[2] == '/')) {
        return true;
    }

    return false;
}

/**
 * Check whether the file has an extension.
 *
 * @return True when the file name has an extension, false otherwise.
 */
bool File::hasExtension() const {
    return !getExtension().empty();
}

/**
 * Get the file extension without the dot.
 *
 * @return The extension string, or empty when no extension exists.
 */
string File::getExtension() const {
    if (name.empty()) {
        return "";
    }

    const size_t dotPos = name.find_last_of('.');
    if (dotPos == std::string::npos || dotPos == 0 || dotPos == name.length() - 1) {
        return "";
    }

    return name.substr(dotPos + 1);
}

/**
 * Get the file stem (name without extension).
 *
 * @return The stem portion of the file name.
 */
string File::getStem() const {
    if (name.empty()) {
        return "";
    }

    if (name == "." || name == "..") {
        return name;
    }

    const size_t dotPos = name.find_last_of('.');
    if (dotPos == std::string::npos || dotPos == 0) {
        return name;
    }

    return name.substr(0, dotPos);
}

/**
 * Check whether the file is a hidden Unix-style file.
 *
 * @return True when the filename starts with a dot.
 */
bool File::isHidden() const {
    if (name == "." || name == "..") {
        return false;
    }

    return name.length() > 1 && name[0] == '.';
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
        // If the path is "/" or "\", else drop the trailing slash
        if ( fileName.substr(0, separatorPos + 1).length() == 1 ) {
            path = fileName.substr(0, separatorPos + 1);
        } else {
            path = fileName.substr(0, separatorPos); // Include the separator in the path
        }
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
