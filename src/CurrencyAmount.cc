#include "CurrencyAmount.hh"
#include <sstream>
#include <iomanip>

CurrencyAmount::CurrencyAmount(const std::string& currency_code, double amount)
    : currency_code_(currency_code), amount_(amount) {}

std::string CurrencyAmount::getCurrencyCode() const {
    return currency_code_;
}

double CurrencyAmount::getAmount() const {
    return amount_;
}

void CurrencyAmount::setCurrencyCode(const std::string& currency_code) {
    currency_code_ = currency_code;
}

void CurrencyAmount::setAmount(double amount) {
    amount_ = amount;
}

std::string CurrencyAmount::toString() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << amount_ << " " << currency_code_;
    return oss.str();
}

CurrencyAmount CurrencyAmount::operator+(const CurrencyAmount& other) const {
    // Make sure the currency codes match
    if (currency_code_ != other.currency_code_) {
        throw std::invalid_argument("Currency codes do not match.");
    }

    // Add the amounts together and return a new CurrencyAmount object
    return CurrencyAmount(currency_code_, amount_ + other.amount_);
}

CurrencyAmount CurrencyAmount::operator-(const CurrencyAmount& other) const {
    // Make sure the currency codes match
    if (currency_code_ != other.currency_code_) {
        throw std::invalid_argument("Currency codes do not match.");
    }

    // Subtract the other amount from this amount and return a new CurrencyAmount object
    return CurrencyAmount(currency_code_, amount_ - other.amount_);
}

bool CurrencyAmount::operator==(const CurrencyAmount& other) const {
    // Two currency amounts are equal if they have the same currency code and amount
    return (currency_code_ == other.currency_code_) && (amount_ == other.amount_);
}

bool CurrencyAmount::operator!=(const CurrencyAmount& other) const {
    // Two currency amounts are not equal if they do not have the same currency code or amount
    return !(*this == other);
}

/*bool CurrencyAmount::operator<(const CurrencyAmount& other) const {
    // We can only compare currency amounts with the same currency code
    if (currency_code_ !=
*/
