#pragma once

#include "types.hpp"

namespace CgsContainers
{
    template <typename T>
    class FlagSet
    {
    protected:
        T muFlags;

    public:
        // TODO: All function implementations are guessed as they were inlined in the decompile
        void Clear() { muFlags = 0; }

        const bool IsBitSet(u32 num) const { return (muFlags & num) != 0; }
        void SetBit(u32 num) { muFlags |= num; }
        void UnSetBit(u32 num) { muFlags &= ~num; }
        T GetBit(u32 num) const { return (muFlags & num); }
        void SetBitTo(u32 num, bool value) { if (value) SetBit(num); else UnSetBit(num); }
        bool IsZero() const { return muFlags == 0; }
        bool IsFull() const { return muFlags == ~T(0); }
        bool IsFullUpTo(u32 num) const { return (muFlags & num) == num; }

        T& GetFlags() { return muFlags; }
    };
}
