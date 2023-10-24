#include <iostream>
#include <string>
#include "CurrencyAmount.h"

using namespace std;

int main(int argc, char* argv[]) {
    // Check for command line arguments
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <currency code> <amount>" << endl;
        return 1;
    }

    // Parse command line arguments
    string currencyCode = argv[1];
    double amount = stod(argv[2]);

    // Create a CurrencyAmount object
    CurrencyAmount amountObj(currencyCode, amount);

    // Handle command line options
    for (int i = 3; i < argc; i++) {
        string option = argv[i];

        // Check for addition option
        if (option == "-add") {
            // Parse additional arguments
            if (i + 2 >= argc) {
                cerr << "Error: insufficient arguments for addition option" << endl;
                return 1;
            }

            string addCurrencyCode = argv[i+1];
            double addAmount = stod(argv[i+2]);

            // Create a CurrencyAmount object to add to the original object
            CurrencyAmount addAmountObj(addCurrencyCode, addAmount);
            amountObj = amountObj + addAmountObj;

            // Update the index to skip the additional arguments
            i += 2;
        }

        // Check for subtraction option
        else if (option == "-sub") {
            // Parse additional arguments
            if (i + 2 >= argc) {
                cerr << "Error: insufficient arguments for subtraction option" << endl;
                return 1;
            }

            string subCurrencyCode = argv[i+1];
            double subAmount = stod(argv[i+2]);

            // Create a CurrencyAmount object to subtract from the original object
            CurrencyAmount subAmountObj(subCurrencyCode, subAmount);
            amountObj = amountObj - subAmountObj;

            // Update the index to skip the additional arguments
            i += 2;
        }

        // Check for comparison option
        else if (option == "-cmp") {
            // Parse additional arguments
            if (i + 2 >= argc) {
                cerr << "Error: insufficient arguments for comparison option" << endl;
                return 1;
            }

            string cmpCurrencyCode = argv[i+1];
            double cmpAmount = stod(argv[i+2]);

            // Create a CurrencyAmount object to compare to the original object
            CurrencyAmount cmpAmountObj(cmpCurrencyCode, cmpAmount);

            // Compare the two objects
            if (amountObj == cmpAmountObj) {
                cout << "The two amounts are equal" << endl;
            } else if (amountObj > cmpAmountObj) {
                cout << "The original amount is greater than the comparison amount" << endl;
            } else {
                cout << "The original amount is less than the comparison amount" << endl;
            }

            // Update the index to skip the additional arguments
            i += 2;
        }

        // Invalid option
        else {
            cerr << "Error: invalid option \"" << option << "\"" << endl;
            return 1;
        }
    }

    // Print the final amount
    cout << "Final amount: " << amountObj.getAmount() << " " << amountObj.getCurrencyCode() << endl;

    return 0;
}
