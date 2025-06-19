#pragma once

#include "types.hpp"
#include "GameShared/GameClasses/Containers/CgsFlagSet.h"

namespace CgsModule
{
    class IOBuffer
    {
        typedef CgsContainers::FlagSet<s8> FlagSet8;

    private:
        FlagSet8 mxStatusFlags;

    public:
        void Construct();
        void Destruct();
        void LockForWrite();
        void UnlockForWrite();
        void LockForRead() const;
        void UnlockForRead() const;

        // TODO: Implement these operator overloads if needed
        //void* operator new(size_t);
        //void operator delete(void* ptr);
        //void* operator new(size_t, void* ptr);
        //void operator delete(void* ptr, void* place);

    protected:
        bool IsBufferLockedForReading() const;
        bool IsBufferLockedForWriting() const;
        bool IsBufferLocked() const;
    };
}
