#pragma once 
#include <iostream>
#include <exception>
#include "types.h"
#include <cstdint>
#include <initializer_list>

template <const uint32_t Capacity_Limit = 1024*64> // standard 65kB of memory
struct RAM {
    bit8_t Memory[Capacity_Limit];

    RAM() {
        for (uint32_t i = 0; i < Capacity_Limit; i++) {
            Memory[i] = 0x00;
        }
    }

    RAM(const bit8_t& def_set_value) {
        for (uint32_t i = 0; i < Capacity_Limit; i++) {
            Memory[i] = def_set_value;
        }
    }

    template <typename type = bit8_t>
    RAM(const std::initializer_list<type>& pre_set) {
        for (int i = 0; i < pre_set.size(); i++) {
            Memory[i] = *(pre_set.begin() + i);
        }
    }

    bit8_t& operator[](const uint32_t& index) {
        return this->Memory[index];
    }
};
