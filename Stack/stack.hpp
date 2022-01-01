#pragma once
#include "../Memory/types.h"

struct Stacks {
    bit8_t Stack[256]; // located betwee $0100 and $01FF
    bit8_t* Stackptr;

    Stacks() : Stackptr(Stack) {}
};
