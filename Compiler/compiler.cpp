#include <iostream>
#include <fstream>
#include "../6502_CPU/cpu.hpp"
#include "./exceptions.hpp"

void Parser(const int& argc, char** argv) throw() {
    static unsigned int lines_read = 0;
    std::ifstream inputfile;
    std::ofstream outputfile;
    if (argc > 1) {
        if (static_cast<std::string>(argv[1]).find(".zep") != std::string::npos) {
            inputfile = std::ifstream(argv[1]);
            outputfile = std::ofstream("ASSM_6502.cpp");
            outputfile << "#include <iostream>\n";
            outputfile << "#include \"../6502_CPU/cpu.hpp\"\n";
            outputfile << "#include <iomanip>\n\n";
            outputfile << "#define end ;PC++;\n";
            outputfile << "#define EXE memory[PC]=\n";
            outputfile << "#define next ;PC++;memory[PC]=\n\n";
            outputfile << "int main() {\n";
        }
        else {
            throw Exceptions::No_File_Located();
        }
        while (!inputfile.eof()) {
            std::string current_line;
            int RAM_size;
            int STACK_size;
            getline(inputfile, current_line); lines_read++;
            switch (current_line[0]){
                case '@':
                {
                    if (current_line.substr(0,4) == "@set"){
                        if (current_line.substr(4, 12) == " RAM-size = "){
                            std::string temp_str;
                            inputfile.seekg(lines_read);
                            inputfile >> temp_str;
                            inputfile >> temp_str;
                            inputfile >> temp_str;
                            inputfile >> temp_str;
                            RAM_size = stoi(temp_str);
                            outputfile << "\tRAM<" << RAM_size << "> memory;\n";
                        }
                        else if (current_line.substr(4,14) == " STACK-size = "){
                            std::string temp_str;
                            inputfile.seekg(18, std::ios::seekdir());
                            inputfile >> temp_str;
                            inputfile >> temp_str;
                            inputfile >> temp_str;
                            inputfile >> temp_str;
                            STACK_size = stoi(temp_str);
                            outputfile << "\tStack<" << STACK_size << "> stack;\n";
                        }
                    }
                    break;
                }
                case '.':
                {
                    if (current_line.substr(0,8) == ".<start>") {
                        //inputfile.seekg(lines_read);
                        outputfile << "\tint PC = 0x00;\n";
                        std::string Loaded_Byte;
                        inputfile >> Loaded_Byte;
                        while (Loaded_Byte[0] != '.'){
                            outputfile << "\tEXE " << Loaded_Byte.substr(0, Loaded_Byte.size()-1) << " next ";
                            inputfile >> Loaded_Byte;
                            outputfile << Loaded_Byte.substr(0, Loaded_Byte.size()-1) << " end\n";
                            inputfile >> Loaded_Byte;
                            lines_read++;
                        }
                        outputfile << "\tCPU<" << RAM_size << ", " << STACK_size << ">(memory, stack).Run();\n";
                        outputfile << '}';
                    }
                    else if (current_line.substr(0,6) == ".<end>") {
                        outputfile << '}';
                    }
                    break;
                }
            }
        }
    }
    else {
        throw Exceptions::No_File_Located();
    }
}

int main(int argc, char** argv)
{
    try {
        Parser(argc, argv);
    }
    catch (Exceptions::No_File_Located error) {
        printf("%s", error.what());
    }
    system("g++ -O3 -o run ASSM_6502.cpp && ./run && rm run && rm ASSM_6502.cpp");
}
