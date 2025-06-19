#pragma once
#include "BrnGameModuleIO.h"
#include "GameShared/GameClasses/Module/CgsModuleSingleBufferedTemplate.h"
#include "GameShared/GameClasses/System/Threads/CgsThreadLayout.h"

namespace BrnGame
{
    class BrnGameModule : public CgsModule::ModuleSingleBufferedTemplate<BrnGame::BrnGameModuleIO::InputBuffer, BrnGame::BrnGameModuleIO::OutputBuffer>, public CgsSystem::IThreadClass
    {
    public:
        explicit BrnGameModule();
        ~BrnGameModule() override;

        bool UpdateThread() override;
        void DispatchThread() override;
        void ResourceUpdateThread(EA::Thread::Mutex *mutex) override;
        void OnStartOfUpdateFrame() override;
        void OnEndOfUpdateFrame() override;
        void OnCompletionOfVsyncWait() override;
        void RenderAssert(const CgsDev::Assert::AssertData *assertData) override;


        bool HasGameTerminated() const { return mbHasGameTerminated; }

    private:
        bool mbHasGameTerminated = false;

    };
}
