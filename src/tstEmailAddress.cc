#include <string>
#include <fstream>
#include <stdexcept>

#include "EmailAddress.hh"

using namespace std;

int main(int argc, char** argv) {

	string infile = "tstEmailAddress.sample";
	ifstream file(infile);

	string address = "";

	if (file.is_open()) {
    		std::string line;
    		while (std::getline(file, line)) {
        		// using printf() in all tests for consistency
        		//printf("%s", line.c_str());

			address = "";
			address = line;
			
			try {
				EmailAddress email(address);
				printf("%-64s %s\r\n", email.toString().c_str(),"[Good]");
			} catch (exception& exc) {
				printf("%-64s %s\r\n", address.c_str(),"[Bad]");
			}
    		}
    	file.close();

	} else {
		cerr << "ERROR: Unable to open " << infile << endl;
	}

	return 0;
}
