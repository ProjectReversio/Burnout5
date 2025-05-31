#pragma once

#include <cstdint>

#include <GameShared/GameClasses/Containers/CgsFlagSet.h>
#include "CgsDataStructure.h"
#include <eathread/eathread_rwmutex.h>

namespace CgsModule
{
    class DataBuffer
    {
        EA::Thread::RWMutex mMutex;
        DataStructure* mpDataStructure;

        typedef CgsContainers::FlagSet<std::int8_t> FlagSet8;
        FlagSet8 mxStatusFlags;

        bool mbMultiThreaded;

    public:
        void Construct();
        void Prepare();
        void Release();
        void Destruct();
        void SetDataStructure(DataStructure* pDataStructure);
        DataStructure* GetDataStructure() const;

        void SetMultiThreaded(bool isMultiThreaded);

        void LockForWrite();
        void UnlockForWrite();
        void LockForRead();
        void UnlockForRead();

        bool IsBufferLocked();
    };
}
