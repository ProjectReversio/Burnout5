#ifdef WIN32
#include <Windows.h>
#endif

#include <GameShared/GameClasses/System/CgsHardwareInit.h>

#include "pc/gcm/renderengine/device.h"

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
}

void EngineUpdate()
{
    // TODO: Implement EngineUpdate
}

void EngineRelease()
{
    SaveConfig();
    // TODO: Implement EngineRelease
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