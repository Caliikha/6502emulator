#pragma once

#define LOW 0 // bit data
#define HIGH 1

using bit = bool; // 1 bit
using bit8_t = unsigned char; // 1 Byte = 8 bits
using bit16_t = unsigned short; // 2 Bytes = 16 bits
using bit32_t = bit8_t[3]; // 3 Bytes = 32 bits
using bit64_t = bit8_t[4]; // 4 Bytes = 64 bits
using bit128_t = bit8_t[5]; // 5 Bytes = 128 bits
#define mem_data bit8_t
#define INS bit8_t


#define PURE 0 // for pure virtual functions if needed
