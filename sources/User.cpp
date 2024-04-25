#include "User.hpp"

/**
 * @brief Default constructor for User.
 */
User::User() {}

/**
 * @brief Constructor for User with username, password, and email.
 * 
 * @param username The username of the user.
 * @param password The password of the user.
 * @param email The email address of the user.
 */
User::User(const std::string& username, const std::string& password, const std::string& email)
    : username(username), password(password), email(email) {}

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
 * @brief Get the password of the user.
 * 
 * @return The password.
 */
const std::string& User::getPassword() const {
    return password;
}

/**
 * @brief Set the password of the user.
 * 
 * @param password The new password.
 */
void User::setPassword(const std::string& password) {
    this->password = password;
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