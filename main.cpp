#include <iostream>
#include "./6502_CPU/cpu.hpp"
#include "./Instructions/opcodes.h"

int main()
{
    const int ram_size = 4;
    const int stack_size = ram_size*256/(64*1024);
    ROM<4> memory = ROM<ram_size>{
        0x41, 0xA0, 0x21, 0x32
    };
    Stack<stack_size> stack;
    CPU<4> _6502 = CPU<4>(memory, stack);
    std::cout << _6502.Load_Opcode() << '\n';
    std::cout << _6502.Load_Opcode() << '\n';
    std::cout << _6502.Load_Opcode() << '\n';
    std::cout << _6502.Load_Opcode() << '\n';
}
