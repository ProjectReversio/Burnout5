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
        void Clear();

        const bool IsBitSet(u32 num) const;
        void SetBit(u32 num);
        void UnSetBit(u32 num);
        T GetBit(u32 num) const;
        void SetBitTo(u32 num, bool value);
        bool IsZero() const;
        bool IsFull() const;
        bool IsFullUpTo(u32 num) const;

        T& GetFlags();
    };
}
