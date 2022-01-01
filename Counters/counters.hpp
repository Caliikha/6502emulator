#pragma once
#include "../Memory/types.h"

struct Counters {
    bit16_t Program_Counter;

    Counters(bit16_t pre_set = 0x0000) : Program_Counter(pre_set) {}
};
