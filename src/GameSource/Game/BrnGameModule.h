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
        ~BrnGameModule();

    private:

    };
}
