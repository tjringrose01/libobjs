#include "User.hpp"
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>

/**
 * @brief Default constructor for User class.
 */
User::User() {}

/**
 * @brief Constructor for User class with username, password, and email.
 * 
 * @param username The username of the user.
 * @param password The password of the user.
 * @param email The email address of the user.
 */
User::User(const std::string& username, const std::string& password, const std::string& email)
    : username(username), passwordHash(sha256(password)), email(email) {}

/**
 * @brief Get the username of the user.
 * 
 * @return The username.
 */
const std::string& User::getUsername() const {
    return username;
}

/**
 * @brief Set the username of the user.
 * 
 * @param username The new username.
 */
void User::setUsername(const std::string& username) {
    this->username = username;
}

/**
 * @brief Get the hashed password of the user.
 * 
 * @return The hashed password.
 */
const std::string& User::getPasswordHash() const {
    return passwordHash;
}

/**
 * @brief Set the password of the user.
 * 
 * @param password The new password.
 */
void User::setPassword(const std::string& password) {
    passwordHash = sha256(password);
}

/**
 * @brief Get the email address of the user.
 * 
 * @return The email address.
 */
const std::string& User::getEmail() const {
    return email;
}

/**
 * @brief Set the email address of the user.
 * 
 * @param email The new email address.
 */
void User::setEmail(const std::string& email) {
    this->email = email;
}

/**
 * @brief Check if the given password matches the user's password.
 * 
 * @param password The password to check.
 * @return True if the passwords match, false otherwise.
 */
bool User::checkPassword(const std::string& password) const {
    return passwordHash == sha256(password);
}

/**
 * @brief Compute the SHA-256 hash of a string.
 * 
 * @param str The string to hash.
 * @return The SHA-256 hash as a hexadecimal string.
 */
std::string User::sha256(const std::string& str) const {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.length());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}