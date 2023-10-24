#include "CurrencyAmount.hh"
#include <cassert>
#include <iostream>

//using namespace std;

class CurrencyAmountTest {
public:
    void testAddition() {
        // Test addition of two currency amounts with the same currency code
        CurrencyAmount amount1("USD", 10.50);
        CurrencyAmount amount2("USD", 5.25);
        CurrencyAmount sum = amount1 + amount2;
        assert(sum.getCurrencyCode() == "USD");
        assert(sum.getAmount() == 15.75);

        // Test addition of two currency amounts with different currency codes
        CurrencyAmount amount3("EUR", 10.00);
        try {
            CurrencyAmount sum2 = amount1 + amount3;
        } catch (const std::invalid_argument& e) {
            // Make sure we get an invalid_argument exception when adding currency amounts with different codes
            assert(true);
        }
    }

    void testSubtraction() {
        // Test subtraction of two currency amounts with the same currency code
        CurrencyAmount amount1("USD", 10.50);
        CurrencyAmount amount2("USD", 5.25);
        CurrencyAmount difference = amount1 - amount2;
        assert(difference.getCurrencyCode() == "USD");
        assert(difference.getAmount() == 5.25);

        // Test subtraction of two currency amounts with different currency codes
        CurrencyAmount amount3("EUR", 10.00);
        try {
            CurrencyAmount difference2 = amount1 - amount3;
        } catch (const std::invalid_argument& e) {
            // Make sure we get an invalid_argument exception when subtracting currency amounts with different codes
            assert(true);
        }
    }

    void testEquality() {
        // Test equality of two currency amounts with the same currency code and amount
        CurrencyAmount amount1("USD", 10.50);
        CurrencyAmount amount2("USD", 10.50);
        assert(amount1 == amount2);

        // Test inequality of two currency amounts with different currency codes
        CurrencyAmount amount3("EUR", 10.50);
        assert(!(amount1 == amount3));
    }

    void testComparison() {
        // Test comparison of two currency amounts with the same currency code
        CurrencyAmount amount1("USD", 10.50);
        CurrencyAmount amount2("USD", 5.25);
        assert(amount1 > amount2);
        assert(amount1 >= amount2);
        assert(!(amount1 < amount2));
        assert(!(amount1 <= amount2));

        // Test comparison of two currency amounts with different currency codes
        CurrencyAmount amount3("EUR", 10.00);
        try {
            bool comparison = amount1 > amount3;
        } catch (const std::invalid_argument& e) {
            // Make sure we get an invalid_argument exception when comparing currency amounts with different codes
            assert(true);
        }
    }

    void testTax() {
	CurrencyAmount correctAmt("USD", 11.24);
	double correctTaxAmt = .74;
	double taxAmt = .07;
        CurrencyAmount amount1("USD", 10.50);
	std::cout << amount1.toString() << std::endl;
	assert(correctTaxAmt == amount1.getTax(.07));
	std::cout << amount1.getTax(.07) << std::endl;
	amount1.addTax(taxAmt);
	std::cout << amount1.toString() << std::endl;
	assert(amount1 == correctAmt);
    }
};

int main() {
    CurrencyAmountTest test;
    test.testAddition();
    test.testSubtraction();
    test.testEquality();
    test.testComparison();
    test.testTax();
    return 0;
}
