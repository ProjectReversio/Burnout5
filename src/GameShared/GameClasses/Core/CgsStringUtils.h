#pragma once
#include "types.hpp"

namespace CgsCore
{

    extern void SPrintf(char* buffer, u32 len, const char* fmt, ...);
    extern void SnPrintf(char* buffer, u32 len, const char* fmt, ...);
    extern void StrCpy(char* dest, u32 len, const char* src);
    extern void StrCat(char* dest, u32 len, const char* src);

}
