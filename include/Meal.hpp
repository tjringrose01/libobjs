#ifndef MEAL_HPP
#define MEAL_HPP

#include <string>
#include <vector>
#include <iostream>

using namespace std;

/**
 * @brief Represents a meal with a name, description, and list of ingredients.
 */
class Meal {
private:
    string name; /**< The name of the meal. */
    string description; /**< The description of the meal. */
    vector<string> ingredients; /**< The list of ingredients for the meal. */

public:
    /**
     * @brief Default constructor.
     */
    Meal() = default;

    /**
     * @brief Parameterized constructor.
     * @param name The name of the meal.
     * @param description The description of the meal.
     * @param ingredients The list of ingredients for the meal.
     */
    Meal(string name, string description, const vector<string>& ingredients);

    /**
     * @brief Get the name of the meal.
     * @return The name of the meal.
     */
    string getName() const;

    /**
     * @brief Set the name of the meal.
     * @param name The new name of the meal.
     */
    void setName(const string& name);

    /**
     * @brief Get the description of the meal.
     * @return The description of the meal.
     */
    string getDescription() const;

    /**
     * @brief Set the description of the meal.
     * @param description The new description of the meal.
     */
    void setDescription(const string& description);

    /**
     * @brief Get the list of ingredients for the meal.
     * @return The list of ingredients for the meal.
     */
    const vector<string>& getIngredients() const;

    /**
     * @brief Set the list of ingredients for the meal.
     * @param ingredients The new list of ingredients for the meal.
     */
    void setIngredients(const vector<string>& ingredients);

    /**
     * @brief Add an ingredient to the list of ingredients for the meal.
     * @param ingredient The ingredient to add.
     */
    void addIngredient(const string& ingredient);

    /**
     * @brief Get a string representation of the meal.
     * @return A string representation of the meal.
     */
    string toString() const;
};

/**
 * @brief Overload of the output stream operator for printing a meal.
 * @param os The output stream.
 * @param meal The meal to print.
 * @return The output stream.
 */
ostream& operator<<(ostream& os, const Meal& meal);

#endif /* MEAL_HPP */