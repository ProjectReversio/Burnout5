#include "device.h"

#include <Windows.h>

bool renderengine::gFullscreen = false;
s32 renderengine::gDisplayWidth = 640;
s32 renderengine::gDisplayHeight = 480;
HWND renderengine::hWnd = nullptr;

bool renderengine::Device::Initialize()
{
    // TODO: Implement renderengine::Device::Initialize

    gDisplayWidth = 800;
    gDisplayHeight = 600;

    // TODO: Implement renderengine::Device::Initialize

    //gFullscreen = true;
    gFullscreen = false; // Force fullscreen off for now

    // TODO: Implement renderengine::Device::Initialize

    return true;
}

void renderengine::Device::Start()
{
    // TODO: Implement renderengine::Device::Start

    ShowWindow(hWnd, SW_SHOWNORMAL);

    // TODO: Implement renderengine::Device::Start
}
