#ifdef WIN32
#include <Windows.h>
#endif

#include <GameShared/GameClasses/System/CgsHardwareInit.h>

#include "GameSource/Game/BrnGameModule.h"
#include "GameSource/Game/BrnGameModuleIO.h"
#include "pc/gcm/renderengine/device.h"

BrnGame::BrnGameModule* gpBurnoutGame;

void LoadConfig()
{
    // TODO: Implement LoadConfig
}

void SaveConfig()
{
    // TODO: Implement SaveConfig
}

void EnginePrepare()
{
    // TODO: Implement EnginePrepare

    renderengine::Device::Start();

    // TODO: Implement EnginePrepare

    // TODO: Memory stuff
    // TODO: Construct BrnGame::BrnGameModule with memory resource
    /*if (memResource)
        gpBurnoutGame = new BrnGame::BrnGameModule(memResource);
    else
        gpBurnoutGame = nullptr;*/

    // TEMP: For now, just create a new instance without memory resource
    gpBurnoutGame = new BrnGame::BrnGameModule();

    // TODO: Implement EnginePrepare

    gpBurnoutGame->Construct();

    // TODO: Implement EnginePrepare

    while (!gpBurnoutGame->Prepare())
    {
        if (gpBurnoutGame->HasGameTerminated())
            break;

        CgsSystem::HardwareInit::UpdateHardware();
    }
}

void EngineUpdate()
{
    while (!gpBurnoutGame->HasGameTerminated())
    {
        CgsSystem::HardwareInit::UpdateHardware();

        // TODO: Implement EngineUpdate
    }
}

void EngineRelease()
{
    SaveConfig();
    // TODO: Implement EngineRelease

    while (!gpBurnoutGame->Release())
    {
        CgsSystem::HardwareInit::UpdateHardware();
    }
}

void GameRelease()
{
    CgsSystem::HardwareInit::ReleaseHardware();

    // TODO: Implement GameRelease
}

#ifdef WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
    if (!CgsSystem::HardwareInit::IsAlreadyRunning())
    {
        renderengine::Device::Initialize();
        LoadConfig();

        // TODO: these values are probably supposed to be set in global space or just used directly where needed
        //lpSubKey = "SOFTWARE\\EA Games\\Burnout(TM) Paradise The Ultimate Box\\";
        //lpValueName = "locale";

        CgsSystem::HardwareInit::InitializeHardware(lpCmdLine);

        EnginePrepare();
        EngineUpdate();
        EngineRelease();
        GameRelease();

    }
    return 0;
}
#endif