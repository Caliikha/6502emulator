#pragma once 
#include <iostream>
#include <exception>
#include "types.h"
#include <cstdint>
#include <initializer_list>

template <const uint32_t Capacity_Limit = 1024*64> // standard 65kB of memory
struct ROM {
    bit8_t Memory[Capacity_Limit];

    ROM() {
        for (uint32_t i = 0; i < Capacity_Limit; i++){
            Memory[i] = 0x00;
        }
    }

    ROM(const bit8_t& def_set_value) {
        for (uint32_t i = 0; i < Capacity_Limit; i++){
            Memory[i] = def_set_value;
        }
    }

    template <typename type = bit8_t>
    ROM(const std::initializer_list<type>& pre_set) {
        std::copy(pre_set.begin(), pre_set.end(), Memory);
    }
};
