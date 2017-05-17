//
// CoreManager.h
//
// Circle - A C++ bare metal environment for Raspberry Pi
// Copyright (C) 2015  R. Stange <rsta2@o2online.de>
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
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

#include "thread.h"

typedef void (*core_handler_t)(CLogger*, int);

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

	void Run (unsigned nCore);

	// Override.
	void IPIHandler (unsigned nCore, unsigned nIPI);	// handles IPI on this core

	void AssignTask(unsigned int coreNum, core_handler_t funct);

	void WakeUp(unsigned int coreNum);


  	core_handler_t funct[CORES]; 

  

private:
	void Calculate (float x1, float x2, float y1, float y2, unsigned nMaxIteration,
			unsigned nPosY0, unsigned nHeight);


private:
	CScreenDevice *m_pScreen;
  CLogger *m_pLogger;
};

#endif
