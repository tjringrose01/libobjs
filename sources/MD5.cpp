#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstring>
#include "MD5.hpp"

MD5::MD5() {
    buffer[0] = NULL;
    digest[0] = NULL;
    finalized = false;
    count[0] = count[1] = 0;
    state[0] = 0x67452301;
    state[1] = 0xefcdab89;
    state[2] = 0x98badcfe;
    state[3] = 0x10325476;
}

void MD5::transform(const unsigned char block[64]) {
    uint32_t a = state[0], b = state[1], c = state[2], d = state[3], x[16];

    decode(block, x, 64);

    // Round 1
    for (int i = 0; i < 16; ++i) {
        uint32_t f = (b & c) | ((~b) & d);
        uint32_t g = i;
        uint32_t temp = d;
        d = c;
        c = b;
        b = b + ((a + f + 0x5A827999 + x[g]) << 7);
        a = temp;
    }

    // Round 2
    for (int i = 0; i < 16; ++i) {
        uint32_t f = (d & b) | ((~d) & c);
        uint32_t g = (5 * i + 1) % 16;
        uint32_t temp = d;
        d = c;
        c = b;
        b = b + ((a + f + 0x5A827999 + x[g]) << 12);
        a = temp;
    }

    // Round 3
    for (int i = 0; i < 16; ++i) {
        uint32_t f = b ^ c ^ d;
        uint32_t g = (3 * i + 5) % 16;
        uint32_t temp = d;
        d = c;
        c = b;
        b = b + ((a + f + 0x5A827999 + x[g]) << 17);
        a = temp;
    }

    // Round 4
    for (int i = 0; i < 16; ++i) {
        uint32_t f = c ^ (b | (~d));
        uint32_t g = (7 * i) % 16;
        uint32_t temp = d;
        d = c;
        c = b;
        b = b + ((a + f + 0x5A827999 + x[g]) << 22);
        a = temp;
    }

    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;

    // Zeroize sensitive information.
    memset(x, 0, sizeof(x));
}

void MD5::encode(const uint32_t* input, unsigned char* output, size_t length) {
    for (size_t i = 0, j = 0; j < length; ++i, j += 4) {
        output[j] = static_cast<unsigned char>(input[i] & 0xff);
        output[j + 1] = static_cast<unsigned char>((input[i] >> 8) & 0xff);
        output[j + 2] = static_cast<unsigned char>((input[i] >> 16) & 0xff);
        output[j + 3] = static_cast<unsigned char>((input[i] >> 24) & 0xff);
    }
}

void MD5::decode(const unsigned char* input, uint32_t* output, size_t length) {
    for (size_t i = 0, j = 0; j < length; ++i, j += 4) {
        output[i] = (static_cast<uint32_t>(input[j])) |
                    (static_cast<uint32_t>(input[j + 1]) << 8) |
                    (static_cast<uint32_t>(input[j + 2]) << 16) |
                    (static_cast<uint32_t>(input[j + 3]) << 24);
    }
}

void MD5::update(const unsigned char* input, size_t length) {
    uint32_t i, index, partLen;

    // Compute number of bytes mod 64
    index = static_cast<uint32_t>((count[0] >> 3) & 0x3F);

    // Update number of bits
    if ((count[0] += static_cast<uint32_t>(length << 3)) < (static_cast<uint32_t>(length << 3))) {
        count[1]++;
    }

    count[1] += static_cast<uint32_t>(length >> 29);

    partLen = 64 - index;

    // Transform as many times as possible
    if (length >= partLen) {
        memcpy(&buffer[index], input, partLen);
        transform(buffer);

        for (i = partLen; i + 63 < length; i += 64) {
            transform(&input[i]);
        }

        index = 0;
    } else {
        i = 0;
    }

    // Buffer remaining input
    memcpy(&buffer[index], &input[i], length - i);
}

void MD5::finalize() {
    unsigned char bits[8];
    uint32_t index, padLen;

    // Save number of bits
    encode(count, bits, 8);

    // Pad out to 56 mod 64
    index = static_cast<uint32_t>((count[0] >> 3) & 0x3f);
    padLen = (index < 56) ? (56 - index) : (120 - index);
    update(reinterpret_cast<const unsigned char*>("\x80"), 1);
    while (padLen--) {
        update(reinterpret_cast<const unsigned char*>("\x00"), 1);
    }

    // Append length (before padding)
    update(bits, 8);

    // Store state in digest
    encode(state, digest, 16);

    // Zeroize sensitive information
    memset(buffer, 0, sizeof(buffer));
    memset(count, 0, sizeof(count));

    finalized = true;
}

std::string MD5::calculate(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return "";
    }

    MD5 md5;
    unsigned char buffer[64];
    while (file.read(reinterpret_cast<char*>(buffer), sizeof(buffer))) {
        md5.update(buffer, file.gcount());
    }

    md5.finalize();

    std::stringstream ss;
    for (int i = 0; i < 16; ++i) {
        ss << std::hex << std::setfill('0') << std::setw(2) << (int)md5.digest[i];
    }

    return ss.str();
}