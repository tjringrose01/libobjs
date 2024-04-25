#include "User.hpp"

User::User() {}

User::User(const std::string& username, const std::string& password, const std::string& email)
    : username(username), password(password), email(email) {}

const std::string& User::getUsername() const {
    return username;
}

void User::setUsername(const std::string& username) {
    this->username = username;
}

const std::string& User::getPassword() const {
    return password;
}

void User::setPassword(const std::string& password) {
    this->password = password;
}

const std::string& User::getEmail() const {
    return email;
}

void User::setEmail(const std::string& email) {
    this->email = email;
}