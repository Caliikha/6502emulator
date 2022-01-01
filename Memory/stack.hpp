#pragma once
#include <cstdint>
#include "../Memory/types.h"
#include "../Memory/RAM.hpp"

template <const uint16_t Size = 256> // default stack size of 256 Bytes
struct Stacks {
    bit16_t Stack_Pointer;
    constexpr static const bit16_t StackLimit = 0xFFFF - Size;

    Stacks(const bit16_t& pre_set = 0xFFFF) : Stack_Pointer(pre_set) {}
};
