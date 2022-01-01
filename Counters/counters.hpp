#pragma once
#include "../Memory/types.h"

struct Counters {
    bit16_t Program_Counter;

    Counters(bit16_t pre_set) : Program_Counter(pre_set) {}
};
