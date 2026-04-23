/**
 *  File_gtest.cpp - libobjs File Class Tests
 *
 *  Copyright 2026 Timothy Ringrose
 *
 *  This file is part of libobjs.
 *
 *  libobjs is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  libobjs is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with libobjs. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <gtest/gtest.h>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <vector>
#include "File.hpp"

using namespace std;

class CerrSilencer {
public:
    CerrSilencer() : original(std::cerr.rdbuf(sink.rdbuf())) {}
    ~CerrSilencer() {
        std::cerr.rdbuf(original);
    }

private:
    std::ostringstream sink;
    std::streambuf* original;
};

class FileTest : public ::testing::Test {
protected:
    std::string tempDir;
    std::vector<std::string> filesToDelete;
    std::vector<std::string> dirsToDelete;

    void SetUp() override {
        char templatePath[] = "/tmp/libobjs_file_gtest_XXXXXX";
        char* createdDir = mkdtemp(templatePath);
        ASSERT_NE(createdDir, nullptr);
        tempDir = createdDir;
    }

    void TearDown() override {
        for (const string& filePath : filesToDelete) {
            std::remove(filePath.c_str());
        }

        for (auto dirIt = dirsToDelete.rbegin(); dirIt != dirsToDelete.rend(); ++dirIt) {
            rmdir(dirIt->c_str());
        }

        if (!tempDir.empty()) {
            rmdir(tempDir.c_str());
        }
    }

    std::string makePath(const std::string& fileName) const {
        return tempDir + "/" + fileName;
    }

    void createDir(const std::string& dirPath) {
        ASSERT_EQ(mkdir(dirPath.c_str(), 0700), 0);
        dirsToDelete.push_back(dirPath);
    }

    void writeFile(const std::string& filePath, const std::string& content) {
        std::ofstream out(filePath, std::ios::binary);
        ASSERT_TRUE(out.is_open());
        out.write(content.data(), static_cast<std::streamsize>(content.size()));
        out.close();
        filesToDelete.push_back(filePath);
    }
};

TEST_F(FileTest, OneArgConstructorParsesPathsAcrossManyIterations) {
    struct ConstructorCase {
        std::string input;
        std::string expectedName;
        std::string expectedPath;
        std::string expectedAbsolutePath;
        bool isAbsolute;
    };

    const std::vector<ConstructorCase> cases = {
        {"alpha.txt", "alpha.txt", "", "alpha.txt", false},
        {"/tmp/alpha.txt", "alpha.txt", "/tmp", "/tmp/alpha.txt", true},
        {"/alpha.txt", "alpha.txt", "/", "/alpha.txt", true},
        {"dir/sub/alpha.txt", "alpha.txt", "dir/sub", "dir/sub/alpha.txt", false},
        {"dir\\sub\\alpha.txt", "alpha.txt", "dir\\sub", "dir\\sub\\alpha.txt", false},
        {".hidden", ".hidden", "", ".hidden", false},
        {"trailing.", "trailing.", "", "trailing.", false}
    };

    for (int iter = 0; iter < 200; ++iter) {
        for (const auto& scenario : cases) {
            File file(scenario.input);
            EXPECT_EQ(file.getName(), scenario.expectedName);
            EXPECT_EQ(file.getPath(), scenario.expectedPath);
            EXPECT_EQ(file.getAbsolutePath(), scenario.expectedAbsolutePath);
            EXPECT_EQ(file.isAbsolutePath(), scenario.isAbsolute);
        }
    }
}

TEST_F(FileTest, TwoArgConstructorBuildsAbsolutePathsAcrossManyIterations) {
    struct ConstructorCase {
        std::string name;
        std::string path;
        std::string expectedAbsolutePath;
        bool isAbsolute;
    };

    const std::vector<ConstructorCase> cases = {
        {"f.txt", "", "f.txt", false},
        {"f.txt", "/", "/f.txt", true},
        {"f.txt", "/tmp", "/tmp/f.txt", true},
        {"f.txt", "/tmp/", "/tmp/f.txt", true},
        {"f.txt", "relative/path", "relative/path/f.txt", false},
        {"f.txt", "C:\\temp", "C:\\temp\\f.txt", true},
        {"f.txt", "C:\\temp\\", "C:\\temp\\f.txt", true}
    };

    for (int iter = 0; iter < 200; ++iter) {
        for (const auto& scenario : cases) {
            File file(scenario.name, scenario.path);
            EXPECT_EQ(file.getName(), scenario.name);
            EXPECT_EQ(file.getPath(), scenario.path);
            EXPECT_EQ(file.getAbsolutePath(), scenario.expectedAbsolutePath);
            EXPECT_EQ(file.isAbsolutePath(), scenario.isAbsolute);
        }
    }
}

TEST_F(FileTest, ExistingFilesSizeAndMd5AreStableAcrossManyIterations) {
    struct HashCase {
        std::string content;
        std::string expectedMd5;
    };

    const std::vector<HashCase> hashCases = {
        {"", "d41d8cd98f00b204e9800998ecf8427e"},
        {"a", "0cc175b9c0f1b6a831c399e269772661"},
        {"abc", "900150983cd24fb0d6963f7d28e17f72"},
        {"hello\n", "b1946ac92492d2347c6235b4d2611184"}
    };

    for (int iter = 0; iter < 125; ++iter) {
        for (size_t index = 0; index < hashCases.size(); ++index) {
            const std::string filePath = makePath("hash_" + std::to_string(iter) + "_" + std::to_string(index) + ".txt");
            writeFile(filePath, hashCases[index].content);

            File file(filePath);
            EXPECT_TRUE(file.exists());
            EXPECT_EQ(file.getSize(), hashCases[index].content.size());
            EXPECT_EQ(file.getMD5(), hashCases[index].expectedMd5);
        }
    }
}

TEST_F(FileTest, MissingFilesReturnSafeValuesAcrossManyIterations) {
    CerrSilencer silenceErrors;

    for (int iter = 0; iter < 500; ++iter) {
        const std::string missingPath = makePath("missing_" + std::to_string(iter) + ".txt");
        File missingFile(missingPath);

        EXPECT_FALSE(missingFile.exists());
        EXPECT_EQ(missingFile.getSize(), 0u);
        EXPECT_EQ(missingFile.getMD5(), "");

        EXPECT_NO_THROW({
            (void)missingFile.getAbsolutePath();
            (void)missingFile.getName();
            (void)missingFile.getPath();
            (void)missingFile.getStem();
            (void)missingFile.getExtension();
            (void)missingFile.hasExtension();
            (void)missingFile.isHidden();
            (void)missingFile.isAbsolutePath();
        });
    }
}

TEST_F(FileTest, ExtensionStemAndHiddenRulesCoverEdgeCases) {
    struct NameCase {
        std::string input;
        std::string expectedExtension;
        std::string expectedStem;
        bool expectedHasExtension;
        bool expectedIsHidden;
    };

    const std::vector<NameCase> nameCases = {
        {"alpha.txt", "txt", "alpha", true, false},
        {"archive.tar.gz", "gz", "archive.tar", true, false},
        {"no_extension", "", "no_extension", false, false},
        {"trailing.", "", "trailing", false, false},
        {".bashrc", "", ".bashrc", false, true},
        {".hidden.txt", "txt", ".hidden", true, true},
        {".", "", ".", false, false},
        {"..", "", "..", false, false}
    };

    for (int iter = 0; iter < 300; ++iter) {
        for (const auto& scenario : nameCases) {
            File file(scenario.input);
            EXPECT_EQ(file.getExtension(), scenario.expectedExtension);
            EXPECT_EQ(file.getStem(), scenario.expectedStem);
            EXPECT_EQ(file.hasExtension(), scenario.expectedHasExtension);
            EXPECT_EQ(file.isHidden(), scenario.expectedIsHidden);
        }
    }
}

TEST_F(FileTest, DirectoryAndPathEdgeCasesDoNotThrowAcrossManyIterations) {
    CerrSilencer silenceErrors;

    const std::string nestedDir = makePath("nested");
    createDir(nestedDir);

    const std::string nestedFilePath = nestedDir + "/inside.txt";
    writeFile(nestedFilePath, "inside");

    std::vector<std::string> oneArgInputs = {
        "",
        ".",
        "..",
        "/",
        "//",
        "name",
        ".hidden",
        "file.txt",
        "file.",
        "path/with/slash.txt",
        "path\\with\\backslash.txt",
        "name with spaces.log",
        nestedFilePath,
        "////leading/slashes.txt",
        "C:\\windows\\style\\name.bin"
    };

    std::vector<std::string> twoArgNames = {
        "",
        ".",
        "..",
        "name",
        ".hidden",
        "file.txt",
        "trailing."
    };

    std::vector<std::string> twoArgPaths = {
        "",
        "/",
        "/tmp",
        "/tmp/",
        "relative",
        "relative/sub",
        "C:\\temp",
        "C:\\temp\\"
    };

    for (int iter = 0; iter < 250; ++iter) {
        for (const std::string& oneArg : oneArgInputs) {
            File file(oneArg);
            EXPECT_NO_THROW({
                (void)file.getAbsolutePath();
                (void)file.getName();
                (void)file.getPath();
                (void)file.exists();
                (void)file.getSize();
                (void)file.getMD5();
                (void)file.isAbsolutePath();
                (void)file.hasExtension();
                (void)file.getExtension();
                (void)file.getStem();
                (void)file.isHidden();
            });
        }

        for (const std::string& name : twoArgNames) {
            for (const std::string& path : twoArgPaths) {
                File file(name, path);
                EXPECT_NO_THROW({
                    (void)file.getAbsolutePath();
                    (void)file.getName();
                    (void)file.getPath();
                    (void)file.exists();
                    (void)file.getSize();
                    (void)file.getMD5();
                    (void)file.isAbsolutePath();
                    (void)file.hasExtension();
                    (void)file.getExtension();
                    (void)file.getStem();
                    (void)file.isHidden();
                });
            }
        }
    }
}
