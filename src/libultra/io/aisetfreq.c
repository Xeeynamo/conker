#include <rcp.h>
// #include "../os/osint.h"

#pragma GLOBAL_ASM("asm/nonmatchings/libultra/io/aisetfreq/osAiSetFrequency.s")
// NON-MATCHING: looks like -g / -O1 but not quite
// s32 osAiSetFrequency(u32 frequency)
// {
//     register u32 dacRate;
//     register u8 bitRate;
//     register f32 f;
//     f = osViClock / (float)frequency + .5f;
//     dacRate = f;
//     if (dacRate < AI_MIN_DAC_RATE)
//         return -1;
//     bitRate = dacRate / 66;
//     if (bitRate > AI_MAX_BIT_RATE)
//         bitRate = AI_MAX_BIT_RATE;
//     IO_WRITE(AI_DACRATE_REG, dacRate - 1);
//     IO_WRITE(AI_BITRATE_REG, bitRate - 1);
//     IO_WRITE(AI_CONTROL_REG, AI_CONTROL_DMA_ON);
//     return osViClock / (s32)dacRate;
// }
