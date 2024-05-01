#include "Meal.hpp"
#include <sstream>

using namespace std;

/**
 * @brief Constructor for the Meal class.
 * @param name The name of the meal.
 * @param description The description of the meal.
 * @param ingredients The list of ingredients for the meal.
 */
Meal::Meal(string name, string description, const vector<string>& ingredients)
    : name(name), description(description), ingredients(ingredients) {}

/**
 * @brief Get the name of the meal.
 * @return The name of the meal.
 */
string Meal::getName() const {
    return name;
}

/**
 * @brief Set the name of the meal.
 * @param name The new name of the meal.
 */
void Meal::setName(const string& name) {
    this->name = name;
}

/**
 * @brief Get the description of the meal.
 * @return The description of the meal.
 */
string Meal::getDescription() const {
    return description;
}

/**
 * @brief Set the description of the meal.
 * @param description The new description of the meal.
 */
void Meal::setDescription(const string& description) {
    this->description = description;
}

/**
 * @brief Get the list of ingredients for the meal.
 * @return The list of ingredients for the meal.
 */
const vector<string>& Meal::getIngredients() const {
    return ingredients;
}

/**
 * @brief Set the list of ingredients for the meal.
 * @param ingredients The new list of ingredients for the meal.
 */
void Meal::setIngredients(const vector<string>& ingredients) {
    this->ingredients = ingredients;
}

/**
 * @brief Add an ingredient to the list of ingredients for the meal.
 * @param ingredient The ingredient to add.
 */
void Meal::addIngredient(const string& ingredient) {
    ingredients.push_back(ingredient);
}

/**
 * @brief Get a string representation of the meal.
 * @return A string representation of the meal.
 */
string Meal::toString() const {
    stringstream ss;
    ss << "Meal: " << name << "\n";
    ss << "Description: " << description << "\n";
    ss << "Ingredients:\n";
    for (const auto& ingredient : ingredients) {
        ss << "- " << ingredient << "\n";
    }
    return ss.str();
}

/**
 * @brief Overload of the output stream operator for printing a meal.
 * @param os The output stream.
 * @param meal The meal to print.
 * @return The output stream.
 */
ostream& operator<<(ostream& os, const Meal& meal) {
    os << meal.toString();
    return os;
}