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

    mem_data& Load_Data() { // loading byte at current position
        return this->Memory[Program_Counter++];
    }
    
    mem_data& Load_Data_At(const bit8_t& address) { // loading byte at defined position
        return this->Memory[address];
    }

    bit16_t& Load_Address(const bit16_t& address) { // loading 2 bytes at defined position further in memory (stack)
        return (this->Memory[address + 1] << 8) + this->Memory[address]; // little endian format
    }

    bit8_t& Load_Opcode() { // loading byte at current position meant to be opcode
        return Load_Data();
    }

    void Print_Data(const char* instruction_name) {
        static uint32_t line_num = 0;
        printf("%d\t\t%X\t%X\t\t%s\t\t%X\t%X\t%X\t%X\t%X\n",
                line_num++,                     // Line
                                                // Address
                this->Memory[Program_Counter],  // Hex
                this->Memory[Program_Counter+1],// Code
                                                // Label
                instruction_name,               // Instruction
                this->Accumulator,              // ACC
                this->IRX,                      // IRX
                this->IRY,                      // IRY
                this->Program_Counter,          // PC
                this->Stack_Pointer             // SP
                );
    }

    void Run() {
        printf("Line\tAddress\tHex\tCode\tLabel\tInstruction\tACC\tIRX\tIRY\tPC\tSP\n");
        while (Program_Counter < (Memory_Size - Stack_Size)) {
            switch (Load_Opcode()) { // first byte read is the opcode instruction
                case LDA_im:
                {
                    Registers::Accumulator = Load_Data();
                    Status_Flags::Zero_Flag = (Registers::Accumulator == 0);
                    Status_Flags::Negative_Flag = (Registers::Accumulator >= 0b10000000);
                    Clock_Cycles += 2;
                    this->Print_Data("LDA_im");
                    break;
                }
                case LDA_ZP:
                {
                    Registers::Accumulator = Load_Data_At(Load_Data());
                    Status_Flags::Zero_Flag = (Registers::Accumulator == 0);
                    Status_Flags::Negative_Flag = (Registers::Accumulator >= 0b10000000);
                    Clock_Cycles += 3;
                    this->Print_Data("LDA_ZP");
                    break;
                }
                case LDA_ZPX:
                {
                    Registers::Accumulator = Load_Data_At(Load_Data() + Registers::IRX);
                    Status_Flags::Zero_Flag = (Registers::Accumulator == 0);
                    Status_Flags::Negative_Flag = (Registers::Accumulator >= 0b10000000);
                    Clock_Cycles += 4;
                    this->Print_Data("LDA_ZPX");
                    break;
                }
                default:
                {
                }
            }
        }
        printf("\n");
    }
};
