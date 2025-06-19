#pragma once

#include "types.hpp"
#include "eathread/eathread_mutex.h"
#include "GameShared/GameClasses/Development/AssertSystem/CgsAssertManager.h"

namespace CgsSystem
{
    class IThreadClass
    {
        virtual bool UpdateThread() = 0;
        virtual void DispatchThread() = 0;
        virtual void ResourceUpdateThread(EA::Thread::Mutex* mutex) = 0;
        virtual void OnStartOfUpdateFrame() = 0;
        virtual void OnEndOfUpdateFrame() = 0;
        virtual void OnCompletionOfVsyncWait() = 0;
        virtual void RenderAssert(const CgsDev::Assert::AssertData* assertData) = 0;
    };
}
