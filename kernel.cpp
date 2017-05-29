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
#include <hal/uart.h>

static const char FromKernel[] = "kernel";
CKernel::CKernel (void) :	m_Screen (m_Options.GetWidth (), m_Options.GetHeight ()),
	m_Timer (&m_Interrupt),
	m_Logger (m_Options.GetLogLevel (), &m_Timer),
	m_DWHCI (&m_Interrupt, &m_Timer)
  //m_CoreManager(&m_Logger, &m_Screen, &m_Memory)
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
		bOK = m_DWHCI.Initialize ();
	}

	if (bOK)
	{
		bOK = m_Net.Initialize ();
	}

	if (bOK)
	{
		//bOK = m_CoreManager.Initialize();
	}

	return bOK;
}
/*
void bar() {
	CLogger::Get ()->Write ("Wakeup", LogNotice, "core %d is running bar()", CMultiCoreSupport::ThisCore ());
}

void foo1(){
	CLogger::Get ()->Write ("Wakeup", LogNotice, "core %d is foo1() - sleep for 10 seconds", CMultiCoreSupport::ThisCore ());
   	CTimer::Get()->MsDelay(10000);
}

void foo2(){
	CLogger::Get ()->Write ("Wakeup", LogNotice, "core %d is foo2()", CMultiCoreSupport::ThisCore ());
}

void foo3(){
	CLogger::Get ()->Write ("Wakeup", LogNotice, "core %d is foo3()", CMultiCoreSupport::ThisCore ());
}
*/

void tfoo(unsigned int count, const void *params){
  CLogger::Get ()->Write ("Thread", LogNotice, "thread %d", ((int*)params)[0]);
}

void tfooinf(unsigned int count, const void *params){
  	while(1) {
	  CLogger::Get ()->Write ("Thread", LogNotice, "thread %d", ((int*)params)[0]);
	  CScheduler::Get()->Sleep(5);
	}
}

TShutdownMode CKernel::Run (void)
{
	m_Logger.Write (FromKernel, LogNotice, "Compile time: " __DATE__ " " __TIME__);
 
	CString IPString;
	m_Net.GetConfig ()->GetIPAddress ()->Format (&IPString);
	m_Logger.Write (FromKernel, LogNotice, "My IP Address is \"%s\"",
			(const char *) IPString);

	HTTPClient *httpclient = new HTTPClient(&m_Net);

	while(1) {
		m_Scheduler.Yield();
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
