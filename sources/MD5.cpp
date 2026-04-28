/**
 *  MD5.cpp - libobjs Class Implementation - This class is
 *             responsible for calculating MD5 hashes for file content.
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
 *  Domain Rules:
 *  - MD5 state is updated in 512-bit blocks and finalized once per digest.
 */

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include "MD5.hpp"

namespace {
inline uint32_t rotate_left(uint32_t x, uint32_t n) {
    return (x << n) | (x >> (32 - n));
}

inline uint32_t F(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) | (~x & z);
}

inline uint32_t G(uint32_t x, uint32_t y, uint32_t z) {
    return (x & z) | (y & ~z);
}

inline uint32_t H(uint32_t x, uint32_t y, uint32_t z) {
    return x ^ y ^ z;
}

inline uint32_t I(uint32_t x, uint32_t y, uint32_t z) {
    return y ^ (x | ~z);
}

inline void FF(uint32_t& a, uint32_t b, uint32_t c, uint32_t d, uint32_t x, uint32_t s, uint32_t ac) {
    a += F(b, c, d) + x + ac;
    a = rotate_left(a, s);
    a += b;
}

inline void GG(uint32_t& a, uint32_t b, uint32_t c, uint32_t d, uint32_t x, uint32_t s, uint32_t ac) {
    a += G(b, c, d) + x + ac;
    a = rotate_left(a, s);
    a += b;
}

inline void HH(uint32_t& a, uint32_t b, uint32_t c, uint32_t d, uint32_t x, uint32_t s, uint32_t ac) {
    a += H(b, c, d) + x + ac;
    a = rotate_left(a, s);
    a += b;
}

inline void II(uint32_t& a, uint32_t b, uint32_t c, uint32_t d, uint32_t x, uint32_t s, uint32_t ac) {
    a += I(b, c, d) + x + ac;
    a = rotate_left(a, s);
    a += b;
}
}  // namespace

/**
 * @brief Construct a new MD5 context with initialized state constants.
 */
MD5::MD5() : finalized(false) {
    std::memset(buffer, 0, sizeof(buffer));
    std::memset(digest, 0, sizeof(digest));
    count[0] = 0;
    count[1] = 0;
    state[0] = 0x67452301;
    state[1] = 0xefcdab89;
    state[2] = 0x98badcfe;
    state[3] = 0x10325476;
}

/**
 * @brief Process one 64-byte input block through MD5 rounds.
 *
 * @param block Input data block.
 */
void MD5::transform(const unsigned char block[64]) {
    uint32_t a = state[0];
    uint32_t b = state[1];
    uint32_t c = state[2];
    uint32_t d = state[3];
    uint32_t x[16];

    decode(block, x, 64);

    FF(a, b, c, d, x[0], 7, 0xd76aa478);
    FF(d, a, b, c, x[1], 12, 0xe8c7b756);
    FF(c, d, a, b, x[2], 17, 0x242070db);
    FF(b, c, d, a, x[3], 22, 0xc1bdceee);
    FF(a, b, c, d, x[4], 7, 0xf57c0faf);
    FF(d, a, b, c, x[5], 12, 0x4787c62a);
    FF(c, d, a, b, x[6], 17, 0xa8304613);
    FF(b, c, d, a, x[7], 22, 0xfd469501);
    FF(a, b, c, d, x[8], 7, 0x698098d8);
    FF(d, a, b, c, x[9], 12, 0x8b44f7af);
    FF(c, d, a, b, x[10], 17, 0xffff5bb1);
    FF(b, c, d, a, x[11], 22, 0x895cd7be);
    FF(a, b, c, d, x[12], 7, 0x6b901122);
    FF(d, a, b, c, x[13], 12, 0xfd987193);
    FF(c, d, a, b, x[14], 17, 0xa679438e);
    FF(b, c, d, a, x[15], 22, 0x49b40821);

    GG(a, b, c, d, x[1], 5, 0xf61e2562);
    GG(d, a, b, c, x[6], 9, 0xc040b340);
    GG(c, d, a, b, x[11], 14, 0x265e5a51);
    GG(b, c, d, a, x[0], 20, 0xe9b6c7aa);
    GG(a, b, c, d, x[5], 5, 0xd62f105d);
    GG(d, a, b, c, x[10], 9, 0x02441453);
    GG(c, d, a, b, x[15], 14, 0xd8a1e681);
    GG(b, c, d, a, x[4], 20, 0xe7d3fbc8);
    GG(a, b, c, d, x[9], 5, 0x21e1cde6);
    GG(d, a, b, c, x[14], 9, 0xc33707d6);
    GG(c, d, a, b, x[3], 14, 0xf4d50d87);
    GG(b, c, d, a, x[8], 20, 0x455a14ed);
    GG(a, b, c, d, x[13], 5, 0xa9e3e905);
    GG(d, a, b, c, x[2], 9, 0xfcefa3f8);
    GG(c, d, a, b, x[7], 14, 0x676f02d9);
    GG(b, c, d, a, x[12], 20, 0x8d2a4c8a);

    HH(a, b, c, d, x[5], 4, 0xfffa3942);
    HH(d, a, b, c, x[8], 11, 0x8771f681);
    HH(c, d, a, b, x[11], 16, 0x6d9d6122);
    HH(b, c, d, a, x[14], 23, 0xfde5380c);
    HH(a, b, c, d, x[1], 4, 0xa4beea44);
    HH(d, a, b, c, x[4], 11, 0x4bdecfa9);
    HH(c, d, a, b, x[7], 16, 0xf6bb4b60);
    HH(b, c, d, a, x[10], 23, 0xbebfbc70);
    HH(a, b, c, d, x[13], 4, 0x289b7ec6);
    HH(d, a, b, c, x[0], 11, 0xeaa127fa);
    HH(c, d, a, b, x[3], 16, 0xd4ef3085);
    HH(b, c, d, a, x[6], 23, 0x04881d05);
    HH(a, b, c, d, x[9], 4, 0xd9d4d039);
    HH(d, a, b, c, x[12], 11, 0xe6db99e5);
    HH(c, d, a, b, x[15], 16, 0x1fa27cf8);
    HH(b, c, d, a, x[2], 23, 0xc4ac5665);

    II(a, b, c, d, x[0], 6, 0xf4292244);
    II(d, a, b, c, x[7], 10, 0x432aff97);
    II(c, d, a, b, x[14], 15, 0xab9423a7);
    II(b, c, d, a, x[5], 21, 0xfc93a039);
    II(a, b, c, d, x[12], 6, 0x655b59c3);
    II(d, a, b, c, x[3], 10, 0x8f0ccc92);
    II(c, d, a, b, x[10], 15, 0xffeff47d);
    II(b, c, d, a, x[1], 21, 0x85845dd1);
    II(a, b, c, d, x[8], 6, 0x6fa87e4f);
    II(d, a, b, c, x[15], 10, 0xfe2ce6e0);
    II(c, d, a, b, x[6], 15, 0xa3014314);
    II(b, c, d, a, x[13], 21, 0x4e0811a1);
    II(a, b, c, d, x[4], 6, 0xf7537e82);
    II(d, a, b, c, x[11], 10, 0xbd3af235);
    II(c, d, a, b, x[2], 15, 0x2ad7d2bb);
    II(b, c, d, a, x[9], 21, 0xeb86d391);

    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;

    std::memset(x, 0, sizeof(x));
}

/**
 * @brief Encode 32-bit words into little-endian byte output.
 *
 * @param input Word input buffer.
 * @param output Byte output buffer.
 * @param length Number of output bytes.
 */
void MD5::encode(const uint32_t* input, unsigned char* output, size_t length) {
    for (size_t i = 0, j = 0; j < length; ++i, j += 4) {
        output[j] = static_cast<unsigned char>(input[i] & 0xff);
        output[j + 1] = static_cast<unsigned char>((input[i] >> 8) & 0xff);
        output[j + 2] = static_cast<unsigned char>((input[i] >> 16) & 0xff);
        output[j + 3] = static_cast<unsigned char>((input[i] >> 24) & 0xff);
    }
}

/**
 * @brief Decode little-endian bytes into 32-bit words.
 *
 * @param input Byte input buffer.
 * @param output Word output buffer.
 * @param length Number of input bytes.
 */
void MD5::decode(const unsigned char* input, uint32_t* output, size_t length) {
    for (size_t i = 0, j = 0; j < length; ++i, j += 4) {
        output[i] = static_cast<uint32_t>(input[j]) |
                    (static_cast<uint32_t>(input[j + 1]) << 8) |
                    (static_cast<uint32_t>(input[j + 2]) << 16) |
                    (static_cast<uint32_t>(input[j + 3]) << 24);
    }
}

/**
 * @brief Update digest state with additional raw bytes.
 *
 * @param input Input bytes.
 * @param length Number of bytes.
 */
void MD5::update(const unsigned char* input, size_t length) {
    uint32_t i = 0;
    const uint32_t index = static_cast<uint32_t>((count[0] >> 3) & 0x3F);
    const uint32_t inputBits = static_cast<uint32_t>(length << 3);

    if ((count[0] += inputBits) < inputBits) {
        count[1]++;
    }
    count[1] += static_cast<uint32_t>(length >> 29);

    const uint32_t partLen = 64 - index;
    uint32_t writeIndex = index;

    if (length >= partLen) {
        std::memcpy(&buffer[index], input, partLen);
        transform(buffer);

        for (i = partLen; i + 63 < length; i += 64) {
            transform(&input[i]);
        }
        writeIndex = 0;
    }

    std::memcpy(&buffer[writeIndex], &input[i], length - i);
}

/**
 * @brief Finalize digest state and materialize the 16-byte digest.
 */
void MD5::finalize() {
    if (finalized) {
        return;
    }

    static const unsigned char padding[64] = {0x80};
    unsigned char bits[8];

    encode(count, bits, 8);

    const uint32_t index = static_cast<uint32_t>((count[0] >> 3) & 0x3f);
    const uint32_t padLen = (index < 56) ? (56 - index) : (120 - index);
    update(padding, padLen);
    update(bits, 8);

    encode(state, digest, 16);

    std::memset(buffer, 0, sizeof(buffer));
    std::memset(count, 0, sizeof(count));
    finalized = true;
}

/**
 * @brief Calculate file MD5 hash as lowercase hexadecimal text.
 *
 * @param filename Path to the file to hash.
 * @return 32-char hex digest string, or empty when file cannot be read.
 */
std::string MD5::calculate(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return "";
    }

    MD5 md5;
    char readBuffer[1024];
    while (file) {
        file.read(readBuffer, sizeof(readBuffer));
        const std::streamsize bytesRead = file.gcount();
        if (bytesRead > 0) {
            md5.update(reinterpret_cast<const unsigned char*>(readBuffer), static_cast<size_t>(bytesRead));
        }
    }

    md5.finalize();

    std::stringstream ss;
    ss << std::hex << std::setfill('0');
    for (int i = 0; i < 16; ++i) {
        ss << std::setw(2) << static_cast<unsigned int>(md5.digest[i]);
    }

    return ss.str();
}
