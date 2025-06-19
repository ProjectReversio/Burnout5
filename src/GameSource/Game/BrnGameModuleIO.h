#pragma once

#include "types.hpp"
#include "GameShared/GameClasses/Module/CgsDataStructure.h"
#include "GameShared/GameClasses/Module/CgsIOBuffer.h"
#include "GameSource/Resource/SharedIO/BrnGameDataRequestQueue.h"

namespace BrnGame
{
    namespace BrnGameModuleIO
    {
        class InputBuffer : public CgsModule::IOBuffer, public CgsModule::DataStructure
        {
        public:
            void Construct();
            bool Prepare();
            bool Release();
            void Destruct();
            void Clear();
        };

        class OutputBuffer : public CgsModule::IOBuffer, public CgsModule::DataStructure
        {
            typedef BrnResource::GameDataIO::RequestInterface<1024> ResourceRequestInterface;

        private:
            ResourceRequestInterface mResourceRequestInterface;

        public:
            void Construct();
            bool Prepare();
            bool Release();
            void Destruct();
            void Clear();

            const ResourceRequestInterface* GetResourceRequestInterface() const;
        };
    }
}
