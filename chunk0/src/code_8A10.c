#include <ultra64.h>

#include "variables.h"


void func_85008A10(void) {
    D_80088720 = func_85083E90(1);
    D_80088724.x = 0.0f;
    D_80088724.y = 0.0f;
    D_80088724.z = 0.0f;
    D_80088730 = func_85083E90(1);
}

// is this a loop?
#pragma GLOBAL_ASM("asm/nonmatchings/code_8A10/func_85008A60.s")
