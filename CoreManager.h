//
// CoreManager.h
//

#ifndef _coremanager_h
#define _coremanager_h

#include <circle/multicore.h>
#include <circle/screen.h>
#include <circle/memory.h>
#include <circle/types.h>
#include <circle/logger.h>
#include <circle/bcm2836.h>
#include <assert.h>
#include <circle/memio.h>
#include <circle/startup.h>

typedef void (*handler_no_args_t)();

class CoreManager
#ifdef ARM_ALLOW_MULTI_CORE
	: public CMultiCoreSupport
#endif
{
public:
	CoreManager (CLogger *pLogger, CScreenDevice *pScreen, CMemorySystem *pMemorySystem);
	~CoreManager (void);

#ifndef ARM_ALLOW_MULTI_CORE
	boolean Initialize (void)	{ return TRUE; }
#endif

	// Override.
	void Run (unsigned nCore);

	// Override.
	void IPIHandler (unsigned nCore, unsigned nIPI);	// handles IPI on this core

	void AssignTask(unsigned int coreNum, handler_no_args_t funct);

	void WakeUp(unsigned int coreNum);

private:
	CScreenDevice *m_pScreen;
  CLogger *m_pLogger;
};

#endif
