#pragma once
#include "../Memory/types.h"
#include "opcodes.h"

#define LDA_im      $A9 // immediate mode - 2 bytes - 2 cycles
#define LDA_ZP      $A5 // zero page - 2 bytes - 3 cycles
#define LDA_ZPX     $B5 // zero page x - 2 bytes - 4 cycles
#define LDA_abs     $AD // Absolute - 3 bytes - 4 cycles
#define LDA_absX    $BD // Absolute X - 3 bytes - 4 cycles (+1 if page crossed)
#define LDA_absY    $B9 // Absolute Y - 3 bytes - 4 cycles (+1 if page crossed)
#define LDA_inX     $A1 // Indirect X - 2 bytes - 6 cycles
#define LDA_inY     $B1 // Indirect Y - 2 bytes - 5 cycles (+1 if page crossed)
