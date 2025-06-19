#pragma once

#include "types.hpp"
#ifdef WIN32
#include <Windows.h>
#endif

namespace CgsSystem
{
#ifdef WIN32
    static const s32 knHardwarePathMaxLength = MAX_PATH + 7;
#else
    static const s32 knHardwarePathMaxLength = 1024;
#endif

    class HardwareInit
    {
    public:
#ifdef WIN32
        static void InitializeHardware(const char* lpCmdLine);
#else
        static void InitializeHardware(s32 lnArgc, char* lapcArgv[]);
#endif

        static char* GetWorkingDirectory() { return macRootPath; }
        static char* GetFOPENDirectory() { return macFOPENPath; }

        static void ReleaseHardware();

        static void UpdateHardware();

        static bool IsAlreadyRunning();

        static bool IsHardwareWantingToShutdown() { return mbHardwareRequestsShutdown; }

        static bool IsGuideOnScreen() { return mbIsGuideOnScreen; }

        static bool HasDetectedAutomaticTestingFile() { return mbHasDetectedAutomaticTestingFile; }

        static char* GetAutoScriptToRun() { return macAutoTestScriptToRun; }

        static char* GetTitleIDFromCommandLine() { return macTitleIdFromCmdLine; }

        static bool IsHardDiskAvailable();

    private:
        static char macRootPath[knHardwarePathMaxLength];
        static char macFOPENPath[knHardwarePathMaxLength];

        static char macAutoTestScriptToRun[64];

        static char macTitleIdFromCmdLine[10];

        //static JobScheduler mJobManager; // TODO: Implement HardwareInit

        static char macJobManagerBuffer[400 * 1024]; // 400 KB buffer for job manager

        //static CgsMemory::HeapMallocCoreAllocator mJobManagerAllocator; // TODO: Implement HardwareInit

    public:
        static volatile bool mbHardwareRequestsShutdown;

    private:
        static bool mbIsGuideOnScreen;

        static bool mbHasDetectedAutomaticTestingFile;

        static bool DetermineIsPartyEditionVersion();

    };
}
