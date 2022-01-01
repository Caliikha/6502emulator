#pragma once
#include "../Memory/types.h"
#include "../Memory/RAM.hpp"
#include "../Memory/counters.hpp"
#include "../Flags/flags.hpp"
#include "../Registers/registers.hpp"
#include "../Memory/stack.hpp"


class CPU : public Counters, public Stacks<256>, public Registers, public Status_Flags, public RAM<65535> {
public:
    CPU(
        Stacks pre_stack = 0xFFFF
      , Registers pre_reg = Registers{0x00,0x00,0x00}
      , Status_Flags pre_flag = Status_Flags{LOW,LOW,LOW,LOW,LOW,LOW,LOW}
      , RAM<65535> mem = RAM<65535>() // default set to 64kB of ram
      , Counters pre_counter = 0x0000
      ) : Stacks(pre_stack)
        , Registers(pre_reg)
        , Status_Flags(pre_flag)
        , RAM(mem)
        , Counters(pre_counter)
    {}

    mem_data& Load_Data() {
        return this->RAM::Memory[Program_Counter];
    }
};
