#include <iostream>
#include "./6502_CPU/cpu.hpp"
#include "./Instructions/opcodes.h"

int main()
{
    RAM<4> memory = RAM<4>{
        0x41, 0xA0, 0x21, 0x32
    };
    Stack<1> stack;
    CPU<4,1> _6502 = CPU<4,1>(memory, stack);
    std::cout << _6502.Load_Opcode() << '\n';
    std::cout << _6502.Load_Opcode() << '\n';
    std::cout << _6502.Load_Opcode() << '\n';
    std::cout << _6502.Load_Opcode() << '\n';
}
