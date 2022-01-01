#pragma once
#include <stdlib.h>
#include "types.h"
#include "RAM.hpp"

struct Counters {
    bit16_t Program_Counter;

    Counters(const bit16_t& pre_set = 0x0000) : Program_Counter(pre_set) {}
};
