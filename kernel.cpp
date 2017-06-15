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

static const char FromKernel[] = "kernel";
CKernel* CKernel::s_pThis = 0;

bool EnterIsPressed = false;
//
// char* Buffer;
//
// char* my_strstr(char *haystack, const char *needle) {
//     if (haystack == 0 || needle == 0) {
//         return 0;
//     }
//
//     for ( ; *haystack; haystack++) {
//         // Is the needle at this point in the haystack?
//         const char *h, *n;
//         for (h = haystack, n = needle; *h && *n && (*h == *n); ++h, ++n) {
//             // Match is progressing
//         }
//         if (*n == '\0') {
//             // Found match!
//             return haystack;
//         }
//         // Didn't match here.  Try again further along haystack.
//     }
//     return 0;
// }

CKernel::CKernel (void) :	m_Screen (m_Options.GetWidth (), m_Options.GetHeight ()),
	m_Timer (&m_Interrupt),
	m_Logger (m_Options.GetLogLevel (), &m_Timer),
	m_DWHCI (&m_Interrupt, &m_Timer),
	m_PWMSoundDevice (&m_Interrupt),
	m_Dns(&m_Net)
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

	if (bOK)
	{
		bOK = m_DWHCI.Initialize ();
	}

	if (bOK)
	{
		bOK = m_Net.Initialize ();
	}

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

char* my_strstr(char *haystack, const char *needle,int &flag) {
  flag=0;
    if (haystack == 0 || needle == 0) {
        return 0;
    }

    for ( ; *haystack; haystack++) {
        // Is the needle at this point in the haystack?
        const char *h, *n;
        for (h = haystack, n = needle; *h && *n && (*h == *n); ++h, ++n) {
            // Match is progressing
        }
        if (*n == '\0') {
            // Found match!
            return haystack;
        }
        // Didn't match here.  Try again further along haystack.
    }
    // printf("no match\n" );
    flag=1;
    return 0;
}


void modifysong(char* song1,char* song2)
{
	size_t i,j;
	for ( i = 0,j=0; *(song1+i)!='\0'; i++) {
		if(*(song1+i)==' ')
		{
			 *(song2+j) = '%'; j++;
			 *(song2+j) = '2'; j++;
			 *(song2+j) = '0'; j++;
		}
		else
		{
			*(song2+j)= *(song1+i); j++;
		}
	}
	*(song2+j)='\0';
}

void CKernel::modify(char* loc1,char* loc2)
{
	 int flag;
	 char *token, *token1,*saveptr;
	 token = my_strstr(loc1,"http://",flag);
	 token1 = strtok_r(token,"/",&saveptr);
	 if(*saveptr== '/')
	  	saveptr++;
	 token1 =  strtok_r(0,"/",&saveptr);
	 m_Logger.Write (FromKernel, LogNotice, "Final location to send to dnsclient: %s",token1);
	 strcpy(loc2,token1);
}

TShutdownMode CKernel::Run (void)
{
	m_Logger.Write (FromKernel, LogNotice, "Compile time: " __DATE__ " " __TIME__);


	//Set up Keyboard.
	 CUSBKeyboardDevice *pKeyboard = (CUSBKeyboardDevice *) m_DeviceNameService.GetDevice ("ukbd1", FALSE);
	if (pKeyboard == 0)
	{
		m_Logger.Write (FromKernel, LogError, "Keyboard not found");
		return ShutdownHalt;
	}
	pKeyboard->RegisterKeyPressedHandler (KeyPressedHandler);
	Keyboard keyboard(pKeyboard);


	// HTTPClient *httpclient_test = new HTTPClient(&m_Net, &m_PWMSoundDevice, &m_Screen," ",5,80);
	//
	// m_Logger.Write (FromKernel, LogNotice, "Is task1 finished??");
	// m_Logger.Write (FromKernel, LogNotice, "Finished for httpclient1: %d",httpclient_test->finished);
	// while(1) {
	// 	if(keyboard.IsEndOfLine())
	// 	{
	// 		if(httpclient_test->finished==1)
	// 			 break;
	// 		m_Scheduler.Yield();
	// 	}
	//
	// }


	//Set up HTTP Client.
	CString IPString;
	m_Net.GetConfig ()->GetIPAddress ()->Format (&IPString);
	m_Logger.Write (FromKernel, LogNotice, "My IP Address is \"%s\"",
			(const char *) IPString);

	HTTPClient *httpclient1 = new HTTPClient(&m_Net, &m_PWMSoundDevice, &m_Screen," ",1,80);

	m_Logger.Write (FromKernel, LogNotice, "Is task1 finished??");
	m_Logger.Write (FromKernel, LogNotice, "Finished for httpclient1: %d",httpclient1->finished);
	while(1) {
		if(keyboard.IsEndOfLine())
		{
			if(httpclient1->finished==1)
				 break;
			m_Scheduler.Yield();
		}

	}
	while (httpclient1->finished==0) {
		m_Scheduler.Yield();
	}
	char phase_2_link[1000]={'\0'};
	strcpy(phase_2_link, httpclient1->link);
	m_Logger.Write (FromKernel, LogNotice, "Link for phase 2 (Inside Kernel): %s",phase_2_link);
	// while (1) {
	// 	 m_Scheduler.Yield();
	// }
	HTTPClient *httpclient2 = new HTTPClient(&m_Net, &m_PWMSoundDevice, &m_Screen,phase_2_link,2,90);

	while(1) {
		// if(keyboard.IsEndOfLine())
		   if(httpclient2->finished==1)
			 			break;
		 	m_Scheduler.Yield();
	}
	char phase_3_link[1000]={'\0'};
	char phase_3_linke[1000]={'\0'};
	strcpy(phase_3_link, httpclient2->link);

	//  strcpy(phase_3_link, "/download/Adele_201703/1. Adele - All I ask.mp3");
	modifysong(phase_3_link,phase_3_linke);
	m_Logger.Write (FromKernel, LogNotice, "Link for phase 3 (Inside Kernel): %s",phase_3_link);
	m_Logger.Write (FromKernel, LogNotice, "Link for phase 3 (Inside Kernel): %s",phase_3_linke);

	HTTPClient *httpclient3 = new HTTPClient(&m_Net, &m_PWMSoundDevice, &m_Screen,phase_3_linke,3,100);

	m_Logger.Write (FromKernel, LogNotice, "Finished for httpclient3: %d",httpclient3->finished);
	while(1) {
		if(httpclient3->finished==1)
			 break;
		if(keyboard.IsEndOfLine())
		{
			m_Scheduler.Yield();
		}

	}
	m_Logger.Write (FromKernel, LogNotice, "New location(Inside kernel): %s",httpclient3->link);
	m_Logger.Write (FromKernel, LogNotice, "test here");
	char modified_location[1000]={'\0'};
	modify(httpclient3->link,modified_location);

	m_Logger.Write (FromKernel, LogNotice, "Modified location(Inside kernel): %s",modified_location);
	m_Logger.Write (FromKernel, LogNotice, "test here");
	CIPAddress *targetIP = new CIPAddress;
	m_Dns.Resolve(modified_location,targetIP);

  m_Scheduler.MsSleep (1500);

	CString *pstring = new CString;
	// if(targetIP->IsNull())
	// 	m_Logger.Write (FromKernel, LogNotice, "IPAddress is NULL...");
	targetIP->Format(pstring);
	m_Logger.Write (FromKernel, LogNotice, "pstring: %s",(const char*)(* pstring));
	while (1) {

	}

	HTTPClient *httpclient4 = new HTTPClient(&m_Net, &m_PWMSoundDevice, &m_Screen,"http://ia801607.us.archive.org/12/items/Adele_201703/1.%20Adele%20-%20All%20I%20Ask.mp3",4,80);

	while (1) {
		m_Scheduler.Yield();
	}
	while (1) {
		/* code */
	}

	return ShutdownHalt;
}

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
