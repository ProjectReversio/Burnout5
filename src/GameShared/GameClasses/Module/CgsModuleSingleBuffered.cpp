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
    // TODO: Implement CgsModule::ModuleSingleBuffered::Prepare
    /*switch (this->mePrepareStage)
    {
        case EManagerPrepareStage::E_MANAGERPREPARESTAGE_START:
            break;
        case EManagerPrepareStage::E_MANAGERPREPARESTAGE_INPUT:
            break;
        case EManagerPrepareStage::E_MANAGERPREPARESTAGE_ALLOCINPUT:
            break;
        case EManagerPrepareStage::E_MANAGERPREPARESTAGE_OUTPUT:
            break;
        case EManagerPrepareStage::E_MANAGERPREPARESTAGE_ALLOCOUTPUT:
            break;
        case EManagerPrepareStage::E_MANAGERPREPARESTAGE_DATASTRUCTURES:
            break;
        case EManagerPrepareStage::E_MANAGERPREPARESTAGE_DONE:
            break;
    }*/
}

bool CgsModule::ModuleSingleBuffered::Release()
{
    // TODO: Implement CgsModule::ModuleSingleBuffered::Release
    /*switch (this->meReleaseStage)
    {
        case EManagerReleaseStage::E_MANAGERRELEASESTAGE_START:
            break;
        case EManagerReleaseStage::E_MANAGERRELEASESTAGE_DATASTRUCTURES:
            break;
        case EManagerReleaseStage::E_MANAGERRELEASESTAGE_FREEOUTPUT:
            break;
        case EManagerReleaseStage::E_MANAGERRELEASESTAGE_OUTPUT:
            break;
        case EManagerReleaseStage::E_MANAGERRELEASESTAGE_FREEINPUT:
            break;
        case EManagerReleaseStage::E_MANAGERRELEASESTAGE_INPUT:
            break;
        case EManagerReleaseStage::E_MANAGERRELEASESTAGE_DONE:
            break;
    }*/
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
