#include "CgsDataBuffer.h"

void CgsModule::DataBuffer::SetDataStructure(DataStructure *pDataStructure)
{
    mpDataStructure = pDataStructure;
}

void CgsModule::DataBuffer::Construct()
{
    mxStatusFlags.Clear();
    mpDataStructure = nullptr;
    mbMultiThreaded = false;
}

bool CgsModule::DataBuffer::Prepare()
{
    mxStatusFlags.Clear();
    mpDataStructure = nullptr;
    return true;
}

bool CgsModule::DataBuffer::Release()
{
    mpDataStructure = nullptr;
    return true;
}

void CgsModule::DataBuffer::Destruct()
{
    mpDataStructure = nullptr;
}

void CgsModule::DataBuffer::UnlockForWrite()
{
    if (mbMultiThreaded)
        mMutex.Unlock();
    else
        mxStatusFlags.UnSetBit(1);
}

void CgsModule::DataBuffer::LockForWrite()
{
    if (mbMultiThreaded)
        mMutex.Lock(EA::Thread::RWMutex::kLockTypeWrite);
    else
        mxStatusFlags.SetBit(1);
}

void CgsModule::DataBuffer::LockForRead()
{
    if (mbMultiThreaded)
        mMutex.Lock(EA::Thread::RWMutex::kLockTypeRead);
    else
        mxStatusFlags.SetBit(2);
}

void CgsModule::DataBuffer::UnlockForRead()
{
    if (mbMultiThreaded)
        mMutex.Unlock();
    else
        mxStatusFlags.UnSetBit(2);
}

bool CgsModule::DataBuffer::IsBufferLocked()
{
    // TODO: This may be wrong as it doesn't seem to be in the decompile, but this is most likely the intended behavior.

    if (mbMultiThreaded)
    {
        return mMutex.GetLockCount(EA::Thread::RWMutex::kLockTypeRead) > 0 ||
               mMutex.GetLockCount(EA::Thread::RWMutex::kLockTypeWrite) > 0;
    }

    return mxStatusFlags.IsFullUpTo(3); // Check if either read or write flag is set
}



