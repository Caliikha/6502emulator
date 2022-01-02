#pragma once
#include "../Memory/types.h"
#include "../Flags/flags.hpp"
#include "../Instructions/instructions.hpp"
#include "../Instructions/opcodes.h"
#include "../Memory/counters.hpp"
#include "../Memory/RAM.hpp"
#include "../Memory/stack.hpp"
#include "../Registers/registers.hpp"


template <
const uint32_t Memory_Size = 64*1024, // Memory Size first input
const uint16_t Stack_Size = (256/(64*1024))*Memory_Size // Stack Size second input
>
class CPU 
    : public RAM<Memory_Size>,  // default 64kB of memory for the 6502
      public Stack<Stack_Size>, // default 256 Bytes for the stack
      public Counters,
      public Registers,
      public Status_Flags,
      public Instructions
{
protected:
    uint32_t Clock_Cycles; // set to same type as RAM max cap
public:
    CPU(
        const RAM<Memory_Size>& mem = RAM<Stack_Size>(static_cast<bit8_t>(0x00))
      , const Stack<Stack_Size>& pre_stack = Stack<Stack_Size>(0xFFFF)
      , const Counters& pre_counter = static_cast<bit8_t>(0x0000)
      , const Registers& pre_reg = Registers{0x00,0x00,0x00}
      , const Status_Flags& pre_flag = Status_Flags{LOW,LOW,LOW,LOW,LOW,LOW,LOW}
      ) 
        : 
          RAM<Memory_Size>(mem),
          Stack<Stack_Size>(pre_stack),
          Counters(pre_counter),
          Registers(pre_reg),
          Status_Flags(pre_flag)
    {
        Clock_Cycles = 0;
    }

    mem_data& Load_Data() {
        return this->Memory[Program_Counter++];
    }
    
    mem_data& Load_Data_At(const bit8_t& address) {
        return this->Memory[address];
    }

    bit8_t& Load_Opcode() {
        return Load_Data();
    }

    void Run() {
        for (int i = 0; i < Memory_Size; i++){
            switch (Load_Opcode()) { // first byte read is the opcode instruction
                case LDA_im:
                {
                    Registers::Accumulator = Load_Data();
                    Status_Flags::Zero_Flag = (Registers::Accumulator == 0);
                    Status_Flags::Negative_Flag = (Registers::Accumulator >= 0b10000000);
                    Clock_Cycles += 2;
                    break;
                }
                case LDA_ZP:
                {
                    Registers::Accumulator = Load_Data_At(Load_Data());
                    Status_Flags::Zero_Flag = (Registers::Accumulator == 0);
                    Status_Flags::Negative_Flag = (Registers::Accumulator >= 0b10000000);
                    Clock_Cycles += 3;
                    break;
                }
                case LDA_ZPX:
                {
                    Registers::Accumulator = Load_Data_At(Load_Data() + Registers::IRX);
                    Status_Flags::Zero_Flag = (Registers::Accumulator == 0);
                    Status_Flags::Negative_Flag = (Registers::Accumulator >= 0b10000000);
                    Clock_Cycles += 4;
                    break;
                }
                default:
                {
                }
            }
        }
    }
};
