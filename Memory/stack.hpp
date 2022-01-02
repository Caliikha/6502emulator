#pragma once
#include <cstdint>
#include "../Memory/types.h"
#include "../Memory/ROM.hpp"

template <const uint16_t Size = 256> // default stack size of 256 Bytes
struct Stack {
    bit16_t Stack_Pointer;
    constexpr static const bit16_t StackLimit = 0xFFFF - Size;

    Stack(const bit16_t& pre_set = 0xFFFF) : Stack_Pointer(pre_set) {}
};
