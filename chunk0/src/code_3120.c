#include <ultra64.h>

#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/code_3120/func_85003120.s")
#pragma GLOBAL_ASM("asm/nonmatchings/code_3120/func_850031EC.s")
#pragma GLOBAL_ASM("asm/nonmatchings/code_3120/func_850034B4.s")
#pragma GLOBAL_ASM("asm/nonmatchings/code_3120/func_85003570.s")
// NON-MATCHING: miles away!
// void func_85003570(void) {
//     s32 temp_s4;
//     u8 *temp_v0;
//     s32 phi_s0;
//     s32 phi_s0_2;
//     s32 phi_s1;
//     // s16 *phi_s3;
//     // s16 *phi_s2;
//     u32 i;
//
//     u8 a;
//     u8 b;
//     u8 c;
//     u8 d;
//
//     temp_s4 = func_80003C40(0x10, 1, 2, 0);
//     phi_s0 = 1718240; // 0x001A37E0;
//     // phi_s3 = &D_800B87A0;
//     // phi_s2 = D_80091D20;
//
//     for (i = 0; i < 15524; i +=2)
//     {
//         if ((phi_s0 & 1) != 0) {
//             phi_s0_2 = phi_s0 - 1;
//             phi_s1 = 1;
//         } else {
//             phi_s0_2 = phi_s0;
//             phi_s1 = 0;
//         }
//         func_80004514(phi_s0_2, temp_s4, 0x10, 1);
//
//         temp_v0 = phi_s1 + temp_s4;
//
//         a = *(temp_v0 + 0);
//         b = *(temp_v0 + 1);
//         c = *(temp_v0 + 2);
//         d = *(temp_v0 + 3);
//
//         D_800B87A0[i] = (a << 24 ) + (b << 16) + (c << 8) + d;
//
//         phi_s0 = &D_80091D20[i]; //phi_s0_2 +
//     }
//     func_80004074(temp_s4);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/code_3120/func_85003668.s")

void func_850038A0(void) {
    func_85001A08();
    func_85001BC8(0, &D_800DBE2A, &D_800DBE2C);
    func_85001BC8(1, 0, 0);
    func_85001CEC(2);
    func_8510F800(0);
    func_850025FC();
    D_800DBE62 = (u8)1;
}

// some kind of cache?
s32 func_8500390C(s32 arg0) {
    struct105 *phi_v0;
    s32 phi_v1;

    if (arg0 == D_800B0E58) {
        return 0;
    }
    if (arg0 == D_800B0E5C) {
        return 1;
    }
    phi_v0 = D_800B0E60;
    phi_v1 = 2;

    do
    {
        if (arg0 == phi_v0->unk0) {
            return phi_v1;
        }
        if (arg0 == phi_v0->unk4) {
            return phi_v1 + 1;
        }
        if (arg0 == phi_v0->unk8) {
            return phi_v1 + 2;
        }
        if (arg0 == phi_v0->unkC) {
            return phi_v1 + 3;
        }
        phi_v0++;
        phi_v1 += 4;
    } while (phi_v1 != 7762);

    return -1;
}

void func_850039B0(s32 arg0) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/code_3120/func_850039BC.s")
// NON-MATCHING: uses v0 not v1
// void func_850039BC(s32 arg0) {
//     D_800DBE5C = arg0;
//     if (arg0) {
//         D_800DBE5C = arg0 + 8;
//     }
// }
