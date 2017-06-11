//
// CoreManager.cpp
//
// Multicore Manager

#include "CoreManager.h"

#ifdef ARM_ALLOW_MULTI_CORE

#define MAX_ITERATION	5000

CoreManager::CoreManager (CLogger *pLogger, CScreenDevice *pScreen, CMemorySystem *pMemorySystem)
:	
	CMultiCoreSupport (pMemorySystem),
	m_pScreen (pScreen),
  	m_pLogger (pLogger)
{
  
}

CoreManager::~CoreManager (void)
{
	m_pScreen = 0;
  	m_pLogger = 0;
}

void CoreManager::Run (unsigned coreNumber)
{
//#ifdef ARM_ALLOW_MULTI_CORE
	m_pLogger->Write("CoreManager", LogNotice, "core %d is ready to be scheduled.", coreNumber);  
//#endif
}

// Override.
void CoreManager::IPIHandler (unsigned nCore, unsigned nIPI)
{
	assert (nCore < CORES);
	assert (nIPI < 32);
	if (nIPI == IPI_HALT_CORE)
	{
		CLogger::Get ()->Write ("IPIHandler", LogDebug, "CPU core %u will halt now - entering wfi mode", nCore);

		halt ();
	} else if (nIPI == IPI_USER) {
		u32 funct = read32 (ARM_LOCAL_MAILBOX3_CLR0 + 0x10 * nCore);

		if(funct) 
			((handler_no_args_t)funct)();
	} else {
		CLogger::Get ()->Write ("IPIHandler", LogDebug, "no IPI handler found for core %d", nCore);
	}
}

void CoreManager::AssignTask(unsigned int nCore, handler_no_args_t funct) {
  if(nCore <= 3) {
  	write32 (ARM_LOCAL_MAILBOX3_CLR0 + 0x10 * nCore, (u32) 0xffffffff);
    write32 (ARM_LOCAL_MAILBOX3_SET0 + 0x10 * nCore, (u32) funct);
  }
}

void CoreManager::WakeUp(unsigned int coreNum) {
	SendIPI(coreNum, IPI_USER);
}

#endif