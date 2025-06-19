#pragma once

#include "types.hpp"
#include "cmn/rw/core/base/ostypes.h"

namespace CgsModule
{
    class BaseVariableEventQueue
    {
    protected:
        bool mbIsConstructed;

        // TODO: Implement BaseVariableEventQueue Methods
    };

    template<size_t T, size_t N>
    class VariableEventQueue : public BaseVariableEventQueue
    {
    protected:
        RwChar macData[T];

        s32 miBufferWritePos;
        s32 miLength;
        s32 miFirstEventOffset;

    public:
        // TODO: Implement VariableEventQueue Methods
    };
}
