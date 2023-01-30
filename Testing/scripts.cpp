#include <iostream>
#include <fstream>

int main()
{
    system("git add 6502_CPU/ Flags/ Instructions/ Memory/ Registers/ main.cpp");
    system("git status");
//    std::ofstream outputfile("./Instructions/opcodes.h");
//
//    char chars[16] = {
//        '0', '1', '2', '3', '4', '5', '6', '7', '8', 
//        '9', 'A', 'B', 'C', 'D', 'E', 'F'
//    };
//
//    
//    for (int i = 0; i < 16; i++){
//        for (int j = 0; j < 16; j++){
//            outputfile << "#define $" << chars[i] << chars[j] << " 0x" << chars[i] << chars[j] << '\n';
//        }
//    }
//
//    outputfile.close();
}
