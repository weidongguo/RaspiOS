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
#include <assert.h>
#include "screentask.h"

static const char FromKernel[] = "kernel";
CKernel* CKernel::s_pThis = 0;

bool EnterIsPressed = false;

CKernel::CKernel (void) :	m_Screen (m_Options.GetWidth (), m_Options.GetHeight ()),
	m_Timer (&m_Interrupt),
	m_Logger (m_Options.GetLogLevel (), &m_Timer)
	//m_DWHCI (&m_Interrupt, &m_Timer),
	//m_PWMSoundDevice (&m_Interrupt)
#ifdef ARM_ALLOW_MULTI_CORE	
    ,
    m_CoreManager(&m_Logger, &m_Screen, &m_Memory)
#endif 
{
	s_pThis = this;
	m_ActLED.Blink (5);	// show we are alive
}

CKernel::~CKernel (void)
{
	s_pThis = 0;
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
/*
	if (bOK)
	{
		bOK = m_DWHCI.Initialize ();
	}

	if (bOK)
	{
		bOK = m_Net.Initialize ();
	}
	*/

#ifdef ARM_ALLOW_MULTI_CORE
	if (bOK)
	{
		bOK = m_CoreManager.Initialize();
	}
#endif

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
	/*
	// Set up Keyboard.
	CUSBKeyboardDevice *pKeyboard = (CUSBKeyboardDevice *) m_DeviceNameService.GetDevice ("ukbd1", FALSE);
	if (pKeyboard == 0)
	{
		m_Logger.Write (FromKernel, LogError, "Keyboard not found");
		return ShutdownHalt;
	}	
	pKeyboard->RegisterKeyPressedHandler (KeyPressedHandler);
	Keyboard keyboard(pKeyboard);	
	
	// Set up HTTP Client.	
	CString IPString;
	m_Net.GetConfig ()->GetIPAddress ()->Format (&IPString);
	m_Logger.Write (FromKernel, LogNotice, "My IP Address is \"%s\"",
			(const char *) IPString);
	*/
	//HTTPClient *httpclient = new HTTPClient(&m_Net, &m_PWMSoundDevice, &m_Screen);
	/*
	while(1) {
		//if(keyboard.IsEndOfLine()) {
		//	new HTTPClient(&m_Net, &m_PWMSoundDevice, &m_Screen);
		//}

		m_Scheduler.Yield();
	}*/

	for (unsigned nTaskID = 1; nTaskID <= 4; nTaskID++)
	{
		new CScreenTask (nTaskID, &m_Screen);
	}

	// the main task
//	while (1)
//	{
		static const char Message[] = "Main ****\n";
		m_Screen.Write (Message, sizeof Message-1);

		//m_Event.Clear ();
		//m_Timer.StartKernelTimer (1 * HZ, TimerHandler, this);
		TimerHandler(0, this, 0);
	//	m_Event.Wait ();
//	}
		while(1);
 
	return ShutdownHalt;
}

void CKernel::TimerHandler (unsigned hTimer, void *pParam, void *pContext)
{
	CLogger::Get()->Write (FromKernel, LogNotice, "TimerHandler() enters.");
	CKernel *pThis = (CKernel *) pParam;
	assert (pThis != 0);

	//pThis->m_Event.Set ();
	pThis->m_Timer.StartKernelTimer (1 * HZ, TimerHandler, pThis);
 
	pThis->m_Scheduler.Yield();
}

/*
void CKernel::KeyPressedHandler (const char *pString)
{
	assert (s_pThis != 0);
	unsigned int stringLen = strlen(pString);
	s_pThis->m_Screen.Write (pString, stringLen);

	Keyboard* keyboard = Keyboard::Get();
	assert(keyboard != 0);

	if(keyboard->IsEndOfLine())
		keyboard->ClearBuffer();

	for(int i = 0 ; i < stringLen; i++) {
		keyboard->AppendToBuffer(pString[i]);
	}
}
*/
