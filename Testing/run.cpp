#include <iostream>

int main(int argc, char **argv)
{
    bool debug_enable = false;
    if (argc > 1) {
        for (int i = 1; i < argc; i++){
            if (static_cast<std::string>(argv[i]) == "debug"){
                debug_enable = true;
            }
        }
        for (int i = 1; i < argc; i++){
            if (static_cast<std::string>(argv[i]).find("main") != std::string::npos && debug_enable == false){
                switch (argv[i][0]){
                    case 'o':
                    case 'O':
                        system("g++ -std=c++17 -o run ./main.cpp && ./run && rm run");
                        break;
                    case 't':
                    case 'T':
                        system("g++ -std=c++17 -o run ./Testing/testmain.cpp && ./run && rm run");
                        break;
                    default:
                        std::cerr << "Command-line argument list must include: [Omain] - [Tmain]\nAnd command-line argument list must include: {empty} - [debug]" << std::endl;
                }
            }
            else if (static_cast<std::string>(argv[i]).find("main") != std::string::npos && debug_enable == true){
                switch (argv[i][0]){
                    case 'o':
                    case 'O':
                        system("g++ -std=c++17 -g -o run ./main.cpp && gdb run && rm run");
                        break;
                    case 't':
                    case 'T':
                        system("g++ -std=c++17 -g -o run ./Testing/testmain.cpp && gdb run && rm run");
                        break;
                    default:
                        std::cerr << "Command-line argument list must include: [Omain] - [Tmain]\nAnd command-line argument list must include: {empty} - [debug]" << std::endl;
                }
            }
        }
    }
}
