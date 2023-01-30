#include <iostream>
#include "../6502_CPU/cpu.hpp"
#include <fstream>
#include <iomanip>

#define end ;PC++;
#define EXE memory[PC]=
#define next ;PC++;memory[PC]=

int main()
{
    std::ofstream outputfile("./Testing/analysis.txt");
    const int ram_size = 64*1024;
    const int stack_size = ram_size*256/(64*1024); // = 256

    RAM<ram_size>memory = {
//        LDA_ZP, 0x03,
//        LDA_im, 0x50,
//        LDA_ZPX, 0x03
    };

    int PC = 0x00;
    EXE LDA_ZP next $20 end
    EXE LDA_im next $41 end

    //memory[0x2020] = LDA_ZP; memory[0x2021] = 0x20;
    //memory[0x2022] = 0x23; memory[0x2023] = 0x41;

    Stack<stack_size> stack;

    CPU<ram_size, stack_size> _6502(memory, stack);
    _6502.Run();
    for (int i = 0; i < (ram_size - 1); i+=2){
        outputfile << std::setbase(16) << memory.Memory[i] << '\t' << memory.Memory[i+1] << '\n';
        //printf("%x\t%x\n", memory.Memory[i], memory.Memory[i+1]);
    }
    outputfile.close();

    //    CPU<ram_size, stack_size> _6502(rom_2, stack);
    //    _6502.Run();
    //    RAM<ram_size> rom_2 = {
    //        LDA_im, 0x05,
    //        0x04, 0x06
    //    };
}
