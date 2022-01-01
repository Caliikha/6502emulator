#include <iostream>
#include "./6502_CPU/cpu.hpp"

int main()
{
    CPU _6502;
    std::cout << _6502.Program_Counter << '\n';
}
