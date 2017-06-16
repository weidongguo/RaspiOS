//
// kernel.cpp
//
// Circle - A C++ bare metal environment for Raspberry Pi
// Copyright (C) 2014  R. Stange <rsta2@o2online.de>
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
#include "kernel.h"
#include "contextswitch.h"
#include "thread.h"
#include <hal/uart.h>
#include "myTask.h"
#include <circle/timer.h>

static const char FromKernel[] = "kernel";
CKernel::CKernel (void) :	m_Screen (m_Options.GetWidth (), m_Options.GetHeight ()),
	m_Timer (&m_Interrupt),
	m_Logger (m_Options.GetLogLevel (), &m_Timer),
  m_CoreManager(&m_Logger, &m_Screen, &m_Memory)
{
	m_ActLED.Blink (5);	// show we are alive
}

CKernel::~CKernel (void)
{
}

boolean CKernel::Initialize (void)
{
	boolean bOK = TRUE;

	if (bOK)
	{
		bOK = m_Screen.Initialize ();
	}

	if (bOK)
	{
		bOK = m_Serial.Initialize (115200);
	}

	if (bOK)
	{
		CDevice *pTarget = m_DeviceNameService.GetDevice (m_Options.GetLogDevice (), FALSE);
		if (pTarget == 0)
		{
			pTarget = &m_Screen;
		}

		bOK = m_Logger.Initialize (&m_Screen);
	}

	if (bOK)
	{
		bOK = m_Interrupt.Initialize ();
	}

	if (bOK)
	{
		bOK = m_Timer.Initialize ();
	}

	if (bOK)
	{
		bOK = m_CoreManager.Initialize();
	}

	return bOK;
}

TShutdownMode CKernel::Run (void)
{
	m_Logger.Write (FromKernel, LogNotice, "Compile time: " __DATE__ " " __TIME__);

	myTask *task1 = new myTask('1');
	//m_Scheduler.Sleep(1);
	myTask *task2 = new myTask('2');
	//m_Scheduler.Sleep(1);
	myTask *task3 = new myTask('3');
	//m_Scheduler.Sleep(1);
	myTask *task4 = new myTask('4');
	//m_Scheduler.Sleep(1);
	myTask *task5 = new myTask('5');
	//m_Scheduler.Sleep(1);
	myTask *task6 = new myTask('6');

	//prevents compiler warnings about unused variables
	(void)task1;
	(void)task2;
	(void)task3;
	(void)task4;
	(void)task5;
	(void)task6;

	CTimer::Get()->MsDelay(100);

	while(1) {
		m_Logger.Write (FromKernel, LogNotice, "core %d is about to yield in main()", m_Scheduler.schedNum);
		m_Scheduler.startFromSecondary();
	}

	return ShutdownHalt;
}

void CKernel::TimerHandler (unsigned hTimer, void *pParam, void *pContext)
{
#if 1
	// jump to an invalid address (execution is only allowed below _etext, see circle.ld)
	void (*pInvalid) (void) = (void (*) (void)) 0x500000;

	(*pInvalid) ();
#else
	// alternatively execute an undefined instruction
	asm volatile (".word 0xFF000000");
#endif
}
