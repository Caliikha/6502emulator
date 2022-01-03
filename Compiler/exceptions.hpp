#include <iostream>
#include "../Memory/types.h"

namespace Exceptions{ 
    class Except {
    protected:
        const char* err_message = "[ERROR] ";
    public:
        
        Except(const char* input = "Exception Occured") {
            static_cast<std::string>(err_message) += input += '\n';
        }

        inline constexpr const char* what() {
            return err_message;
        }
    };

    class No_File_Located : public Except {
    public:
        No_File_Located(const char* input = "No_File_Located\n") {
            static_cast<std::string>(err_message) += input += '\n';
        }

        inline const char* what() {
            return err_message;
        }
    };

    class No_End : public Except {
    public:
        No_End(const char* input = ".<end> not located in file\n") {
            static_cast<std::string>(err_message) += input += '\n';
        }

        inline const char* what() {
            return err_message;
        }
    };
}
