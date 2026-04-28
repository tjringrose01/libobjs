/**
 * @file file.cpp
 * @brief Source/header documentation for file.cpp.
 */

#include <iostream>
#include <string>
#include "cxxopts.hpp"
#include "File.hpp"

using namespace std;

namespace {
void printUsage() {
    cout << "File Class CLI\n\n";
    cout << "Usage:\n";
    cout << "  file [options] <filename>\n\n";
    cout << "Input:\n";
    cout << "  <filename>                  Required; maps to File(filename)\n";
    cout << "  -f, --filename <filename>   Optional alias for positional filename\n\n";
    cout << "Output selectors:\n";
    cout << "  If no output selector is provided, --all is used.\n";
    cout << "  --all                       Show all File function outputs\n";
    cout << "  --get-name                  Show getName()\n";
    cout << "  --get-path                  Show getPath()\n";
    cout << "  --get-absolute-path         Show getAbsolutePath()\n";
    cout << "  --exists                    Show exists()\n";
    cout << "  --get-size                  Show getSize()\n";
    cout << "  --get-md5                   Show getMD5()\n";
    cout << "  --is-absolute-path          Show isAbsolutePath()\n";
    cout << "  --has-extension             Show hasExtension()\n";
    cout << "  --get-extension             Show getExtension()\n";
    cout << "  --get-stem                  Show getStem()\n";
    cout << "  --is-hidden                 Show isHidden()\n\n";
    cout << "General:\n";
    cout << "  -h, --help                  Print this help page\n\n";
    cout << "Examples:\n";
    cout << "  file /tmp/data.txt --exists --get-size --get-md5\n";
    cout << "  file report.csv --get-name --get-path --get-absolute-path\n";
    cout << "  file .env --is-hidden --has-extension\n";
    cout << "  file archive.tar.gz --get-stem --get-extension\n";
}
} // namespace

int main(int argc, char** argv) {

    cxxopts::Options options("file", "Inspect File class behavior");

    options.add_options("Input")
        ("f,filename", "Single input path (uses File(filename))", cxxopts::value<std::string>())
    ;

    options.add_options("Output")
        ("all", "Show all File function outputs")
        ("get-name", "Show getName()")
        ("get-path", "Show getPath()")
        ("get-absolute-path", "Show getAbsolutePath()")
        ("exists", "Show exists()")
        ("get-size", "Show getSize()")
        ("get-md5", "Show getMD5()")
        ("is-absolute-path", "Show isAbsolutePath()")
        ("has-extension", "Show hasExtension()")
        ("get-extension", "Show getExtension()")
        ("get-stem", "Show getStem()")
        ("is-hidden", "Show isHidden()")
    ;

    options.add_options("General")
        ("h,help", "Print usage")
    ;
    options.parse_positional({"filename"});

    cxxopts::ParseResult result;
    try {
        result = options.parse(argc, argv);
    } catch (const std::exception& ex) {
        cerr << "Argument error: " << ex.what() << endl << endl;
        printUsage();
        return 99;
    }

    // Display the help message and exit
    if (result.count("help"))
    {
        printUsage();
        return 0;
    }

    if (result.count("filename") == 0) {
        cerr << "A filename is required." << endl;
        cerr << endl;
        printUsage();
        return 99;
    }

    File file(result["filename"].as<string>());

    bool showName = result.count("get-name") > 0;
    bool showPath = result.count("get-path") > 0;
    bool showAbsolutePath = result.count("get-absolute-path") > 0;
    bool showExists = result.count("exists") > 0;
    bool showSize = result.count("get-size") > 0;
    bool showMd5 = result.count("get-md5") > 0;
    bool showIsAbsolutePath = result.count("is-absolute-path") > 0;
    bool showHasExtension = result.count("has-extension") > 0;
    bool showExtension = result.count("get-extension") > 0;
    bool showStem = result.count("get-stem") > 0;
    bool showIsHidden = result.count("is-hidden") > 0;

    bool showAll = result.count("all") > 0;
    const bool noOutputSelector = !showAll &&
                                  !showName &&
                                  !showPath &&
                                  !showAbsolutePath &&
                                  !showExists &&
                                  !showSize &&
                                  !showMd5 &&
                                  !showIsAbsolutePath &&
                                  !showHasExtension &&
                                  !showExtension &&
                                  !showStem &&
                                  !showIsHidden;
    if (noOutputSelector) {
        showAll = true;
    }

    if (showAll || showAbsolutePath) {
        cout << "getAbsolutePath: " << file.getAbsolutePath() << endl;
    }

    if (showAll || showName) {
        cout << "getName: " << file.getName() << endl;
    }

    if (showAll || showPath) {
        cout << "getPath: " << file.getPath() << endl;
    }

    if (showAll || showExists) {
        cout << "exists: " << (file.exists() ? "true" : "false") << endl;
    }

    if (showAll || showSize) {
        cout << "getSize: " << file.getSize() << endl;
    }

    if (showAll || showMd5) {
        const string md5 = file.getMD5();
        cout << "getMD5: " << (md5.empty() ? "n/a" : md5) << endl;
    }

    if (showAll || showIsAbsolutePath) {
        cout << "isAbsolutePath: " << (file.isAbsolutePath() ? "true" : "false") << endl;
    }

    if (showAll || showHasExtension) {
        cout << "hasExtension: " << (file.hasExtension() ? "true" : "false") << endl;
    }

    if (showAll || showExtension) {
        cout << "getExtension: " << file.getExtension() << endl;
    }

    if (showAll || showStem) {
        cout << "getStem: " << file.getStem() << endl;
    }

    if (showAll || showIsHidden) {
        cout << "isHidden: " << (file.isHidden() ? "true" : "false") << endl;
    }

    return 0;
}
