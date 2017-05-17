//
// CoreManager.cpp
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

#include "CoreManager.h"

#define MAX_ITERATION	5000

CoreManager::CoreManager (CLogger *pLogger, CScreenDevice *pScreen, CMemorySystem *pMemorySystem)
:	
#ifdef ARM_ALLOW_MULTI_CORE
	CMultiCoreSupport (pMemorySystem),
#endif
	m_pScreen (pScreen),
  m_pLogger (pLogger)
{
  for(int i = 0; i < CORES; i++){
    funct[i] = 0;
  }
}

CoreManager::~CoreManager (void)
{
	m_pScreen = 0;
  	m_pLogger = 0;
}

void CoreManager::Run (unsigned coreNumber)
{
#ifdef ARM_ALLOW_MULTI_CORE
	unsigned nQuarterHeight = m_pScreen->GetHeight () / 4;

	m_pLogger->Write("CoreManager", LogNotice, "core %d is running\n", coreNumber);  
 	
  	if(funct[coreNumber])
	  	funct[coreNumber](m_pLogger, coreNumber);

 
#else
  	funct[0](m_pLogger, coreNumber);	
#endif
  	if(coreNumber != 0)
  		SendIPI(coreNumber, IPI_HALT_CORE);
}

// Override.
void CoreManager::IPIHandler (unsigned nCore, unsigned nIPI)
{
	assert (nCore < CORES);
	assert (nIPI < 32);

	if (nIPI == IPI_HALT_CORE)
	{
		CLogger::Get ()->Write ("FromMultiCore", LogDebug, "Bro CPU core %u will halt now", nCore);

		halt ();
	} else {
		CLogger::Get ()->Write ("FromMultiCore", LogDebug, "No case found");
	}
}

void CoreManager::AssignTask(unsigned int nCore, core_handler_t funct) {
  if(nCore >= 0 && nCore <= 3)
    write32 (ARM_LOCAL_MAILBOX3_SET0 + 0x10 * nCore, (u32) funct);
}

void CoreManager::WakeUp(unsigned int coreNum) {
	SendIPI(coreNum, IPI_HALT_CORE + 1);
}

// See: http://en.wikipedia.org/wiki/Mandelbrot_set
void CoreManager::Calculate (float x1, float x2, float y1, float y2, unsigned nMaxIteration,
				       unsigned nPosY0, unsigned nHeight)
{
	float dx = (x2-x1) / m_pScreen->GetWidth ();
	float dy = (y2-y1) / nHeight;

	float y0 = y1;
	for (unsigned nPosY = nPosY0; nPosY < nPosY0+nHeight; nPosY++, y0 += dy)
	{
		float x0 = x1;
		for (unsigned nPosX = 0; nPosX < m_pScreen->GetWidth (); nPosX++, x0 += dx)
		{
			float x = 0.0;
			float y = 0.0;
			unsigned nIteration = 0;
			for (; x*x+y*y < 2*2 && nIteration < nMaxIteration; nIteration++)
			{
				float xtmp = x*x - y*y + x0;
				y = 2*x*y + y0;
				x = xtmp;
			}

#if DEPTH == 8
			TScreenColor Color = (TScreenColor) (nIteration * 3 / nMaxIteration);
#elif DEPTH == 16
			TScreenColor Color = (TScreenColor) (nIteration * 65535 / nMaxIteration);
			Color++;
#else
	#error DEPTH must be 8 or 16
#endif
			m_pScreen->SetPixel (nPosX, nPosY, Color);
		}
	}
}
