#ifndef USER_H
#define USER_H

#include <string>

/**
 * @brief Represents a user account with a username, password, and email.
 */
class User {
public:
    /**
     * @brief Constructs an empty User object.
     */
    User();

    /**
     * @brief Constructs a User object with the given username, password, and email.
     * 
     * @param username The username of the user.
     * @param password The password of the user.
     * @param email The email address of the user.
     */
    User(const std::string& username, const std::string& password, const std::string& email);
    
    /**
     * @brief Gets the username of the user.
     * 
     * @return The username.
     */
    const std::string& getUsername() const;
    
    /**
     * @brief Sets the username of the user.
     * 
     * @param username The new username.
     */
    void setUsername(const std::string& username);
    
    /**
     * @brief Gets the password of the user.
     * 
     * @return The password.
     */
    const std::string& getPassword() const;
    
    /**
     * @brief Sets the password of the user.
     * 
     * @param password The new password.
     */
    void setPassword(const std::string& password);
    
    /**
     * @brief Gets the email address of the user.
     * 
     * @return The email address.
     */
    const std::string& getEmail() const;
    
    /**
     * @brief Sets the email address of the user.
     * 
     * @param email The new email address.
     */
    void setEmail(const std::string& email);

private:
    std::string username; /**< The username of the user. */
    std::string password; /**< The password of the user. */
    std::string email; /**< The email address of the user. */
};

#endif // USER_H