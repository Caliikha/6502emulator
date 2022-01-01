#pragma once 
#include <iostream>
#include <exception>
#include "types.h"
#include <cstdint>

template <const uint32_t Capacity_Limit = 1024*64> // standard 65kB of memory
struct RAM {
    constexpr const static uint32_t Max_Capacity = Capacity_Limit;
    bit8_t Memory[Capacity_Limit];

    RAM() {
        for (uint32_t i = 0; i < Max_Capacity; i++){
            Memory[i] = 0x00;
        }
    }

    RAM(const bit8_t& def_set_value) {
        for (uint32_t i = 0; i < Max_Capacity; i++){
            Memory[i] = def_set_value;
        }
    }

    RAM(const bit8_t* pre_set) {
        try {
            bool test = pre_set[Max_Capacity - 1] == 1;
        } catch(std::exception e) {
            std::cout << e.what() << '\n';
        }
        for (uint32_t i = 0; i < Max_Capacity; i++){
            Memory[i] = pre_set[i];
        }
    }
};
