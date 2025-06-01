#pragma once

namespace CgsDev
{
    namespace Assert
    {
        // TODO: Asserts
    }
}

// TODO: Uncomment when asserts are implemented
/*
#define CGS_ASSERT(condition, msg) \
    if (!(condition)) { \
        CgsDev::StrStream lStrStream(CgsCore::gacDebugPrintStringBuffer, CgsCore::KI_DEBUGMAXVARGSSTRINGLENGTH); \
        lStrStream << #msg; \
        { \
            CgsDev::Assert::PrintStringed(__FILE__, __LINE__, lStrStream.GetBuffer()); \
            __debugbreak(); \
        } \
    }
*/

#define CGS_ASSERT(condition, msg)
