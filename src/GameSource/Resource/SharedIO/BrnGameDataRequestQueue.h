#pragma once

#include "types.hpp"
#include "GameShared/GameClasses/System/Resource/CgsResourceRequestQueue.h"

namespace BrnResource
{
    namespace GameDataIO
    {
        template<size_t T>
        class RequestQueue : public CgsResource::ResourceIO::ResourceRequestQueue<T>
        {
            // Empty?
        };

        template<size_t T>
        class RequestInterface
        {
        private:
            RequestQueue<T> mRequestQueue;

        public:
            // TODO: Implement RequestInterface Methods
        };
    }
}
