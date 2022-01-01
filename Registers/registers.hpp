#pragma once
#include "../Memory/types.h"

struct Registers {
    bit8_t Accumulator;
    bit8_t IRX;
    bit8_t IRY;

    Registers(bit8_t A = 0x00, bit8_t X = 0x00, bit8_t Y = 0x00) : Accumulator(A), IRX(X), IRY(Y) {}
};
