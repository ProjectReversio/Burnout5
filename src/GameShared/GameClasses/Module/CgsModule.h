#pragma once

#include "CgsDataStructure.h"

namespace CgsModule
{
    class Module
    {
    public:
        Module();
        Module(const Module& other);

        virtual void Construct();
        virtual bool Prepare();
        virtual bool Release();
        virtual void Destruct();
        virtual void Update();
        virtual void SetMultiThreaded(bool isMultiThreaded);
        virtual void LockForInput();
        virtual void UnlockForInput();
        virtual void LockForOutput();
        virtual void UnlockForOutput();

    protected:
        bool mbIsNewModule;

        virtual bool DestroyInputDataStructure(DataStructure* pDataStructure);
        virtual bool DestroyOutputDataStructure(DataStructure* pDataStructure);
        virtual bool PrepareDataStructures(DataStructure* pInputDataStructure, DataStructure* pOutputDataStructure);
        virtual bool ReleaseDataStructures(DataStructure* pInputDataStructure, DataStructure* pOutputDataStructure);
    };
}
