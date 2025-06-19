#pragma once

#include "types.hpp"
#include "GameShared/GameClasses/Module/CgsVariableEventQueue.h"

namespace CgsResource
{
    namespace ResourceIO
    {
        template<size_t T>
        class ResourceRequestQueue : public CgsModule::VariableEventQueue<T, 16>
        {
        public:
            // TODO: Implement ResourceRequestQueue Methods
        };
    }
}
