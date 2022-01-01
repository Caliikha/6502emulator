#pragma once
#include "../Memory/types.h"

struct Registers {
    bit8_t Accumulator;
    bit8_t IRX;
    bit8_t IRY;

    Registers(bit8_t A, bit8_t X, bit8_t Y) : Accumulator(A), IRX(X), IRY(Y) {}
};
