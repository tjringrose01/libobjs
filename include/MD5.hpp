#ifndef __MD5__
#define __MD5__

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdint>

using namespace std;

class MD5 {
private:
    uint32_t state[4];
    uint32_t count[2];
    unsigned char buffer[64];
    unsigned char digest[16];
    bool finalized;

    void transform(const unsigned char block[64]);
    void encode(const uint32_t* input, unsigned char* output, size_t length);
    void decode(const unsigned char* input, uint32_t* output, size_t length);

public:
    MD5();
    string calculate(const string& filename);
    void update(const unsigned char* input, size_t length);
    void finalize();
};

/*
int main() {
    string filename = "path_to_your_file.txt";
    MD5 md5;
    string md5_hash = md5.calculate(filename);
    if (!md5_hash.empty()) {
        cout << "MD5 Hash: " << md5_hash << endl;
    }
    return 0;
}
*/

#endif /* MD5 */