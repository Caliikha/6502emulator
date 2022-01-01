#pragma once
#include "../Memory/types.h"
#include "../Memory/RAM.hpp"
#include "../Counters/counters.hpp"
#include "../Flags/flags.hpp"
#include "../Registers/registers.hpp"
#include "../Stack/stack.hpp"


class CPU : public Counters, public Stacks, public Registers, public Status_Flags, public RAM<65535> {
public:
    CPU(Counters pre_counter = 0x0000
      , Stacks pre_stack = Stacks{}
      , Registers pre_reg = Registers{0x00,0x00,0x00}
      , Status_Flags pre_flag = Status_Flags{LOW,LOW,LOW,LOW,LOW,LOW,LOW}
      , RAM<65535> mem = RAM<65535>() // default set to 64kB of ram
      ) : Counters(pre_counter)
        , Stacks(pre_stack)
        , Registers(pre_reg)
        , Status_Flags(pre_flag)
        , RAM(mem)
    {}
};
