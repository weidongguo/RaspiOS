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
	m_PWMSoundDevice (&m_Interrupt)
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
//
// void CKernel::Request(){
//
//   memset(Buffer,'\0',2000);
//   Buffer = "<div> <div class=\"C234\"> \\
//               <div \\
//         class=\" \\
//           item-ttl \\
//                                       C C2 \\
//         \" \\
//       > \\
//         <a href=\"/details/adele_201601\" title=\"adele\"> \\
//                           <div class=\"tile-img\">\\
//               <img class=\"item-img \" source=\"/services/img/adele_201601\" style=\"height:123px\">\\
//             </div><!--/.tile-img-->\\
// \\
// \\
// \\
//           <div class=\"ttl\">\\
//             adele              </div>\\
//         </a>\\
//       </div>\\
// \\
//     <div class=\"hidden-tiles pubdate C C3\">\\
//       <nobr class=\"hidden-xs\">Jan 16, 2016</nobr>\\
//       <nobr class=\"hidden-sm hidden-md hidden-lg\">01/16</nobr>\\
//     </div>\\
// \\
//     <div class=\"by C C4\">\\
// \\
//                         </div><!--/.C4-->\\
//   </div><!--/.C234-->\\
// \\
// \\
//   <div class=\"mt-icon C C5\">\\
//               <span class=\"iconochive-movies\"  aria-hidden=\"true\"></span><span class=\"sr-only\">movies</span>              </div>\\
// \\
// \\
//           <h6 class=\"stat \">\\
//       <span class=\"iconochive-eye\"  aria-hidden=\"true\"></span><span class=\"sr-only\">eye</span>          <nobr>4,142</nobr>\\
//     </h6>\\
// \\
// \\
//           <h6 class=\"stat\">\\
//       <span class=\"iconochive-favorite\"  aria-hidden=\"true\"></span><span class=\"sr-only\">favorite</span>          0        </h6>\\
// \\
//               <h6 class=\"stat\">\\
//         <span class=\"iconochive-comment\"  aria-hidden=\"true\"></span><span class=\"sr-only\">comment</span>            0          </h6>\\
//                       </div><!--/.item-ia-->\\
// \\
// \\
// <div class=\"details-ia hidden-tiles\">\\
//   <div class=\"C1\"></div>\\
//   <div class=\"C234\">\\
//     <span>adele</span><br/>                Topic: adele<br/>                      </div>\\
//   <div class=\"C5\"></div>\\
// </div>\\
// \\
// \\
// \\
// <div class=\"item-ia\" data-id=\"Adele_201703\">\\
// \\
//         <a class=\"stealth\" tabindex=\"-1\" href=\"/details/opensource_audio\">\\
//     <div class=\"item-parent\">\\
//       <div class=\"item-parent-img\"><img source=\"/services/img/opensource_audio\"/></div>\\
//       <div class=\"item-parent-ttl\">Community Audio</div>\\
//     </div><!--/.item-parent-->\\
//   </a>\\
// \\
// \\
//   <div class=\"hidden-tiles views C C1\">\\
//               <nobr class=\"hidden-xs\">20,346</nobr>\\
//       <nobr class=\"hidden-sm hidden-md hidden-lg\">20K</nobr>\\
//           </div>\\
// \\
// \\
// \\
// \\
//   <div class=\"C234\">\\
//               <div\\
//         class=\"\\
//           item-ttl\\
//                                       C C2\\
//         \"\\
//       >\\
//         <a href=\"/details/Adele_201703\" title=\"Adele\">\\
//                           <div class=\"tile-img\">\\
//               <img class=\"item-img \" source=\"/services/img/Adele_201703\" style=\"height:45px\">\\
//             </div><!--/.tile-img-->";
//
// 	char * phase_2_link = GetLinkForPhase2();
// 	m_Logger.Write (FromKernel, LogNotice, "Phase 2 Link... \n %s",
//  		 phase_2_link);
//   // CLogger::Get()->Write("kernl", LogDebug, "Phase 2 Link... \n %s", phase_2_link);
//   while(1);
//
//     return;
// 		char* final_link = GetDownloadLink();
//
// 		m_Logger.Write (FromKernel, LogNotice, "Download Link... \n %s",
// 	 		 final_link);
// 		// CLogger::Get()->Write("HTTPClient", LogDebug, "Download Link... \n %s", final_link);
//
//
//
// }
//
// // Parse the buffer to get the link.
// char * CKernel::GetLinkForPhase2(){
// 	char* saveptr,*token,*token1,songlink[1000];
// 	//saveptr = (char *)Buffer;
// 	//  token = strtok_r(buffer," ", &saveptr); // does nothing important.. just some trimming.
//   // printf("first %s\n",token );
//   token = my_strstr(Buffer,"<div>");
//   memset(songlink,'\0',sizeof(songlink));
//   int i=0;
// 	do {
//     i++;
//     //for(int i=0;i<200;i++)
//
//     // token = strtok_r(0,"<head>",&saveptr);
//     // printf("middle %s\n",token );
//     token = my_strstr(token,"<div class=\"C234\">");
//     token = my_strstr(token,"<div class=\"C234\">");
//     token = my_strstr(token,"<a href=\"");
//     CLogger::Get()->Write("HTTPClient", LogDebug, "token... \n %s", token);
//
// 		token1 = strtok_r(token,"\"",&saveptr);
//     token1 = strtok_r(0,"\"",&saveptr);
//     // printf("second %s\n",token1 );
// 		// token = strtok_r(0,"<div class=\"C234\">",&saveptr);
//     // printf("third %s\n",saveptr );
// 		// token = strtok_r(0,"<a href=\"",&saveptr);
//     // printf("fourth %s\n",token1 );
//     CLogger::Get()->Write("HTTPClient", LogDebug, "token1... \n %s", token1);
//
// 		// char* token1 = strtok_r(token,"\"",&saveptr);  // this token contains the song link.
//     //return token1;
//
// 		strcpy(songlink, token1);
//     CLogger::Get()->Write("HTTPClient", LogDebug, "token1... \n %s", songlink);
//     token = my_strstr(saveptr,"<div class=\"mt-icon C C5\">");
//     // printf("test %s\n",token );
//     token = my_strstr(token,"<span class=\"iconochive-");
//     // printf("test %s\n",token );
// 		// token = strtok_r(0,"<div class=\"mt-icon C C5\">",&saveptr);
// 		// token = strtok_r(0,"<span class=\"iconochive-",&saveptr);
// 		token1 = strtok_r(token,"-",&saveptr);
//     token1 = strtok_r(0,"\"",&saveptr); // token1 contains whether it's audio or video or text...
//     CLogger::Get()->Write("HTTPClient", LogDebug, "token1 (checking for audio)... \n %s", token1);
//     token=saveptr;
//   }while(i<2);
// 	//} while(strcmp(token1,"audio") != 0);
// 	return songlink;
// }
//
// // Parse the buffer to get the final link to download the song.
// char* CKernel::GetDownloadLink(){
// 	char* saveptr,*token,*token1,songlink[1000];
//   // token = strtok_r(buffer," ", &saveptr); // does nothing important.. just some trimming.
// token = my_strstr(Buffer,"<head>");
// 	int cnt=0,len;
// 	do{
// 		cnt++;
//     token = my_strstr(token,"<a class=\"format-summary download-pill\"");
// 		// token = strtok_r(buffer,"<a class=\"format-summary download-pill\"", &saveptr);
//     token = my_strstr(token,"href=\"");
// 		token1 = strtok_r(token,"\"",&saveptr);
// 		token1 = strtok_r(0,"\"",&saveptr);  // this token contains the download link.
//
//     // printf("songlink.. %s\n", token1 );
//     strcpy(songlink, token1);
// 		len = strlen(token1);
//     token=saveptr;
//   }while(strcmp(token1+len-4,"mp3")!=0 && cnt<4); // If last 3 characters are
// 	return songlink;
// }

TShutdownMode CKernel::Run (void)
{
	m_Logger.Write (FromKernel, LogNotice, "Compile time: " __DATE__ " " __TIME__);

	// Set up Keyboard.
	 CUSBKeyboardDevice *pKeyboard = (CUSBKeyboardDevice *) m_DeviceNameService.GetDevice ("ukbd1", FALSE);
	if (pKeyboard == 0)
	{
		m_Logger.Write (FromKernel, LogError, "Keyboard not found");
		return ShutdownHalt;
	}
	pKeyboard->RegisterKeyPressedHandler (KeyPressedHandler);
	Keyboard keyboard(pKeyboard);

	//Set up HTTP Client.
	CString IPString;
	m_Net.GetConfig ()->GetIPAddress ()->Format (&IPString);
	m_Logger.Write (FromKernel, LogNotice, "My IP Address is \"%s\"",
			(const char *) IPString);

	HTTPClient *httpclient = new HTTPClient(&m_Net, &m_PWMSoundDevice, &m_Screen);

	while(1) {
		if(keyboard.IsEndOfLine())
		 	m_Scheduler.Yield();
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
