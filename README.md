# 6502emulator
Program that emulates a 6502 processor with component level functionality

Also adding a compiler to compile a mockup-language that is supposed to emulate 6502 assembly

# How to run
You will need to compile in a standard no older than C++17 (using constexpr)

If you are using a linux terminal. Use the following command:

    g++ -std=c++17 -O3 -o run <MAINFILE> && ./run

If the terminal does not run the command, try installing or updating g++
   
    sudo apt install build-essential

If you are using a separate IDE (e.g Visual Studio). Follow these steps:

    -> Copy all files to a newly made project folder (where Main.cpp or Source.cpp resides)
    -> Check all files for possible errors with includes or preprocessor macros,
        If errors exist: ~edit accordingly to follow windows directory standard
    -> Run the program using your own main file

# Known Issues/Bugs

Comments on new language work only if `//` is entered in the beginning of the line, not anywhere

Load_Data function only takes in 8 bits, but instructions may need 16 bits which needs a more complex solution to solve
