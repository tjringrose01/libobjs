#include <iostream>
#include "cxxopts.hpp"
#include "File.hpp"

using namespace std;

int main(int argc, char** argv) {

    cxxopts::Options options("file", "Mess with files command");

    options.add_options()
        ("f,filename", "Filename", cxxopts::value<std::string>())
        ("d,debug", "Enable debugging", cxxopts::value<bool>()->default_value("false"))
        ("t,test", "Test if file exists", cxxopts::value<bool>()->default_value("false"))
        ("h,help", "Print usage")
    ;

    // Parse the arguments from the commandline
    auto result = options.parse(argc, argv);

    // Display the help message and exit
    if (result.count("help"))
    {
      cout << options.help() << endl;
      exit(0);
    }

    // Set debug flag
    bool debug = result["debug"].as<bool>();

    // Bomb out if we don't have a filename, otherwise set the variable
    string fileName = "";
    if (result.count("filename")) {
        fileName = result["filename"].as<string>();  
    } else {
        cerr << "Filename is required." << endl;
        cout << options.help() << endl;
        exit(99);
    }
      
    File file = File(fileName);

    cout << "Absolute Path: " << file.getAbsolutePath() << endl;
    cout << "Filename: " << file.getName() << endl;
    cout << "Path: " << file.getPath() << endl;
    if ( file.exists() ) {
        cout << "Exists: " << "True" << endl;
        cout << "Size: " << file.getSize() << endl;
    } else {
        cout << "Exists: " << "False" << endl;
        cout << "Size: " << "n/a" << endl;
    }

    return 0;
}
