#include <iostream>
#include "./6502_CPU/cpu.hpp"
#include "./Instructions/opcodes.h"
#include "./Instructions/instructions.hpp"

int main()
{
    const int ram_size = 64*1024;
    const int stack_size = ram_size*256/(64*1024); // = 256
    RAM<ram_size>memory = {
        LDA_ZP, 0x03,
        0x00, 0x50
    };
    RAM<ram_size> rom_2 = {
        LDA_im, 0x05,
        0x04, 0x06
    };
    Stack<stack_size> stack;

    CPU<ram_size, stack_size> _6502(rom_2, stack);
    _6502.Run();
    CPU<ram_size, stack_size>(memory, stack).Run();
}
