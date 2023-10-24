#include "Dt.hh"
#include <cassert>
#include <iostream>

//using namespace std;

class dates {
public:
    void test1() {
        // Test addition of two currency amounts with the same currency code
	
        Dt date;
	for (int year = 2000; year < 2023; ++year) {
		for (int month = 1; month <= 12; ++month) {
			for (int day = 1; day <= 31; ++day) {

				try {
        				date = Dt(year,month,day);
					cout << date.toString() << endl;
				} catch (const invalid_argument& e) {
				}

			}
		}

	}

	/*
        // Test addition of two currency amounts with different currency codes
        CurrencyAmount amount3("EUR", 10.00);
        try {
            CurrencyAmount sum2 = amount1 + amount3;
        } catch (const std::invalid_argument& e) {
            // Make sure we get an invalid_argument exception when adding currency amounts with different codes
            assert(true);
        }
	*/
    }
};

int main() {
    dates test;
    test.test1();
    return 0;
}
