#pragma once

#include "types.hpp"
#include <Windows.h>

namespace renderengine
{
    extern bool gFullscreen;
    extern s32 gDisplayWidth;
    extern s32 gDisplayHeight;
    extern HWND hWnd;

    class Device
    {
    public:
        static bool Initialize();
        static void Start();
    };
}
