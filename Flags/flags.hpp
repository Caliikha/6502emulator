#pragma once
#include "../Memory/types.h"
#include <stdlib.h>

struct Status_Flags {
    bit Carry_Flag; // False[0] True[1]
    bit Zero_Flag; // ResultZero[0] ResultNotZero[1]
    bit Interrupt_Disable; // Enable[0] Disable[1]
    bit Decimal_Mode; // False[0] True[1]
    bit Break_Command; // NoBreak[0] Break[1]
    bit Overflow_Flag; // False[0] True[1]
    bit Negative_Flag; // Positive[0] Negative[1]

    bit* status[8] = {
        &Carry_Flag,
        &Zero_Flag,
        &Interrupt_Disable,
        &Decimal_Mode,
        &Break_Command,
        NULL,
        &Overflow_Flag,
        &Negative_Flag
    };

    Status_Flags(
            bit pre_carry = 0,
            bit pre_zero = 0,
            bit pre_inter = 0,
            bit pre_dec = 0,
            bit pre_break = 0,
            bit pre_OF = 0,
            bit pre_neg = 0
            )
        :
            Carry_Flag(pre_carry),
            Zero_Flag(pre_zero),
            Interrupt_Disable(pre_inter),
            Decimal_Mode(pre_dec),
            Break_Command(pre_break),
            Overflow_Flag(pre_OF),
            Negative_Flag(pre_OF)
    {}
};
