#include "CgsModuleSingleBuffered.h"

void CgsModule::ModuleSingleBuffered::Construct()
{
    this->mePrepareStage = EManagerPrepareStage::E_MANAGERPREPARESTAGE_START;
    this->meReleaseStage = EManagerReleaseStage::E_MANAGERRELEASESTAGE_START;

    this->mbIsNewModule = false;

    mInputBuffer.Construct();
    mOutputBuffer.Construct();

    this->mpInputStructure = nullptr;
    this->mpOutputStructure = nullptr;
}

bool CgsModule::ModuleSingleBuffered::Prepare()
{
    switch (mePrepareStage)
    {
        case EManagerPrepareStage::E_MANAGERPREPARESTAGE_START:
            mePrepareStage = EManagerPrepareStage::E_MANAGERPREPARESTAGE_START;
            mpInputStructure  = nullptr;
            mpOutputStructure = nullptr;
        case EManagerPrepareStage::E_MANAGERPREPARESTAGE_INPUT:
            mePrepareStage = EManagerPrepareStage::E_MANAGERPREPARESTAGE_INPUT;
            if (!mbIsNewModule)
            {
                mInputBuffer.Prepare();
            }
        case EManagerPrepareStage::E_MANAGERPREPARESTAGE_ALLOCINPUT:
            mePrepareStage = EManagerPrepareStage::E_MANAGERPREPARESTAGE_ALLOCOUTPUT;
            if (!mbIsNewModule)
            {
                CgsModule::DataStructure *lpDataStructure = CreateInputDataStructure();
                if (!lpDataStructure)
                    return false;
                mInputBuffer.SetDataStructure(lpDataStructure);
            }
        case EManagerPrepareStage::E_MANAGERPREPARESTAGE_OUTPUT:
            mePrepareStage = EManagerPrepareStage::E_MANAGERPREPARESTAGE_OUTPUT;
            if (!mbIsNewModule)
            {
                mOutputBuffer.Prepare();
            }
        case EManagerPrepareStage::E_MANAGERPREPARESTAGE_ALLOCOUTPUT:
            mePrepareStage = EManagerPrepareStage::E_MANAGERPREPARESTAGE_ALLOCOUTPUT;
            if (!mbIsNewModule)
            {
                CgsModule::DataStructure * dsOut = CreateOutputDataStructure();
                if (!dsOut)
                    return false;
                mOutputBuffer.SetDataStructure(dsOut);
            }
        case EManagerPrepareStage::E_MANAGERPREPARESTAGE_DATASTRUCTURES:
            mePrepareStage = EManagerPrepareStage::E_MANAGERPREPARESTAGE_DATASTRUCTURES;
            if (!mbIsNewModule)
            {
                if (!mpInputStructure)
                    LockInputForWrite();

                if (!mpOutputStructure)
                    LockOutputForWrite();

                if (!PrepareDataStructures(mpInputStructure, mpOutputStructure))
                    return false;

                UnlockInputForWrite();
                UnlockOutputForWrite();
            }
        case EManagerPrepareStage::E_MANAGERPREPARESTAGE_DONE:
            this->meReleaseStage = EManagerReleaseStage::E_MANAGERRELEASESTAGE_START;
            this->mePrepareStage = EManagerPrepareStage::E_MANAGERPREPARESTAGE_DONE;
            return true;
        default:
            return false;
    }
}

bool CgsModule::ModuleSingleBuffered::Release()
{
    switch (meReleaseStage)
    {
        case EManagerReleaseStage::E_MANAGERRELEASESTAGE_START:
            meReleaseStage = EManagerReleaseStage::E_MANAGERRELEASESTAGE_START;
            mpInputStructure  = nullptr;
            mpOutputStructure = nullptr;
        case EManagerReleaseStage::E_MANAGERRELEASESTAGE_DATASTRUCTURES:
            meReleaseStage = EManagerReleaseStage::E_MANAGERRELEASESTAGE_DATASTRUCTURES;
            if (!mbIsNewModule)
            {
                if (!mpInputStructure)
                    LockInputForWrite();
                if (!mpOutputStructure)
                    LockOutputForWrite();

                if (!ReleaseDataStructures(mpInputStructure, mpOutputStructure))
                    return false;

                UnlockInputForWrite();
                UnlockOutputForWrite();
            }
        case EManagerReleaseStage::E_MANAGERRELEASESTAGE_FREEINPUT:
            meReleaseStage = EManagerReleaseStage::E_MANAGERRELEASESTAGE_FREEINPUT;
            if (!mbIsNewModule)
            {
                CgsModule::DataStructure* lpDataStructure = mInputBuffer.GetDataStructure();
                if (!DestroyInputDataStructure(lpDataStructure))
                    return false;
                mInputBuffer.SetDataStructure(nullptr);
            }
        case EManagerReleaseStage::E_MANAGERRELEASESTAGE_INPUT:
            meReleaseStage = EManagerReleaseStage::E_MANAGERRELEASESTAGE_INPUT;
            if (!mbIsNewModule)
            {
                mInputBuffer.Release();
            }
        case EManagerReleaseStage::E_MANAGERRELEASESTAGE_FREEOUTPUT:
            meReleaseStage = EManagerReleaseStage::E_MANAGERRELEASESTAGE_FREEOUTPUT;
            if (!mbIsNewModule)
            {
                CgsModule::DataStructure *lpDataStructure = mOutputBuffer.GetDataStructure();
                if (!DestroyOutputDataStructure(lpDataStructure))
                    return false;
                mOutputBuffer.SetDataStructure(nullptr);
            }
        case EManagerReleaseStage::E_MANAGERRELEASESTAGE_OUTPUT:
            meReleaseStage = EManagerReleaseStage::E_MANAGERRELEASESTAGE_OUTPUT;
            if (!mbIsNewModule)
            {
                mOutputBuffer.Release();
            }
        case EManagerReleaseStage::E_MANAGERRELEASESTAGE_DONE:
            mePrepareStage = EManagerPrepareStage::E_MANAGERPREPARESTAGE_START;
            meReleaseStage = EManagerReleaseStage::E_MANAGERRELEASESTAGE_DONE;
            return true;
        default:
            return false;
    }
}

void CgsModule::ModuleSingleBuffered::Destruct()
{
    this->mpInputStructure = nullptr;
    this->mpOutputStructure = nullptr;
    mInputBuffer.Destruct();
    mOutputBuffer.Destruct();
}

void CgsModule::ModuleSingleBuffered::Update()
{
    // Empty on purpose as this is for derived classes to implement
}

void CgsModule::ModuleSingleBuffered::SetMultiThreaded(bool isMultiThreaded)
{
    mInputBuffer.SetMultiThreaded(isMultiThreaded);
    mOutputBuffer.SetMultiThreaded(isMultiThreaded);
}

void CgsModule::ModuleSingleBuffered::LockForInput()
{
    mInputBuffer.LockForWrite();
    mpInputStructure = mInputBuffer.GetDataStructure();
}

void CgsModule::ModuleSingleBuffered::UnlockForInput()
{
    mInputBuffer.UnlockForWrite();
    mpInputStructure = nullptr;
}

void CgsModule::ModuleSingleBuffered::LockForOutput()
{
    mOutputBuffer.LockForRead();
    mpOutputStructure = mOutputBuffer.GetDataStructure();
}

void CgsModule::ModuleSingleBuffered::UnlockForOutput()
{
    mOutputBuffer.UnlockForRead();
    mpOutputStructure = nullptr;
}

CgsModule::DataStructure* CgsModule::ModuleSingleBuffered::CreateInputDataStructure()
{
    return nullptr; // Placeholder for derived classes to implement
}

CgsModule::DataStructure* CgsModule::ModuleSingleBuffered::CreateOutputDataStructure()
{
    return nullptr; // Placeholder for derived classes to implement
}

bool CgsModule::ModuleSingleBuffered::DestroyInputDataStructure(DataStructure* lpDataStructure)
{
    return false; // Placeholder for derived classes to implement
}

bool CgsModule::ModuleSingleBuffered::DestroyOutputDataStructure(DataStructure* lpDataStructure)
{
    return false; // Placeholder for derived classes to implement
}

bool CgsModule::ModuleSingleBuffered::PrepareDataStructures(DataStructure* lpInputDataStructure, DataStructure* lpOutputDataStructure)
{
    return false; // Placeholder for derived classes to implement
}

bool CgsModule::ModuleSingleBuffered::ReleaseDataStructures(DataStructure* lpInputDataStructure, DataStructure* lpOutputDataStructure)
{
    return false; // Placeholder for derived classes to implement
}

CgsModule::DataStructure* CgsModule::ModuleSingleBuffered::LockInputForRead()
{
    mInputBuffer.LockForRead();
    mpInputStructure = mInputBuffer.GetDataStructure();
    return mpInputStructure;
}

void CgsModule::ModuleSingleBuffered::UnlockInputForRead()
{
    mInputBuffer.UnlockForRead();
    mpInputStructure = nullptr;
}

CgsModule::DataStructure *CgsModule::ModuleSingleBuffered::LockOutputForWrite()
{
    mOutputBuffer.LockForWrite();
    mpOutputStructure = mOutputBuffer.GetDataStructure();
    return mpOutputStructure;
}

void CgsModule::ModuleSingleBuffered::UnlockOutputForWrite()
{
    mOutputBuffer.UnlockForWrite();
    mpOutputStructure = nullptr;
}

CgsModule::DataStructure *CgsModule::ModuleSingleBuffered::LockInputForWrite()
{
    mInputBuffer.LockForWrite();
    mpInputStructure = mInputBuffer.GetDataStructure();
    return mpInputStructure;
}

void CgsModule::ModuleSingleBuffered::UnlockInputForWrite()
{
    mInputBuffer.UnlockForWrite();
    mpInputStructure = nullptr;
}

CgsModule::DataStructure* CgsModule::ModuleSingleBuffered::LockOutputForRead()
{
    mOutputBuffer.LockForRead();
    mpOutputStructure = mOutputBuffer.GetDataStructure();
    return mpOutputStructure;
}

void CgsModule::ModuleSingleBuffered::UnlockOutputForRead()
{
    mOutputBuffer.UnlockForRead();
    mpOutputStructure = nullptr;
}
