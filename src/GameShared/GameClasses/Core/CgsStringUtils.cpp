#include "CgsStringUtils.h"

#include <cstdarg>
#include <cstring>
#include <stdio.h>

// TODO: Why are there 2 identical functions?

void CgsCore::SPrintf(char* buffer, u32 len, const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    auto result = _vsnprintf(buffer, len, fmt, args);
    if (result == len || result < 0)
    {
        // If the result is equal to len, it means the string was truncated.
        // If result is negative, it indicates an error occurred.
        buffer[len - 1] = '\0'; // Ensure null termination
    }
    va_end(args);
}

void CgsCore::SnPrintf(char* buffer, u32 len, const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    auto result = _vsnprintf(buffer, len, fmt, args);
    if (result == len || result < 0)
    {
        // If the result is equal to len, it means the string was truncated.
        // If result is negative, it indicates an error occurred.
        buffer[len - 1] = '\0'; // Ensure null termination
    }
    va_end(args);
}

void CgsCore::StrCpy(char* dest, u32 len, const char* src)
{
    // TODO: Implement CgsCore::StrCpy
}

void CgsCore::StrCat(char* dest, u32 len, const char* src)
{
    // TODO: Implement CgsCore::StrCat
}