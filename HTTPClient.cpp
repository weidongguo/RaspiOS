//
// httpdaemon.cpp
//
// A simple HTTP webserver
//
// Circle - A C++ bare metal environment for Raspberry Pi
// Copyright (C) 2015-2016  R. Stange <rsta2@o2online.de>
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
//#include <circle/net/httpdaemon.h>
#include <circle/net/ipaddress.h>
#include <circle/net/in.h>
#include <circle/usb/netdevice.h>
#include <circle/sysconfig.h>
#include <circle/logger.h>
#include <circle/string.h>
#include <circle/util.h>
#include <assert.h>

#include "HTTPClient.h"
#include "Keyboard.h"

#define HTTPD_VERSION		"0.01"
#define SERVER			"HTTPClient/" HTTPD_VERSION " (Circle)"

#define MAX_CLIENTS		10

#define HTTPD_STACK_SIZE	TASK_STACK_SIZE

static const char FromHTTPDaemon[] = "http";

// const u8 	TARGET_SERVER_IP[] = 	{169,237,118,13};
// const u8 	TARGET_SERVER_IP[] = 	{207,241,228,108};
const u8 	TARGET_SERVER_IP[] = 	{207,241,224,2}; //https::/archive.org
// const u8 	TARGET_SERVER_IP[] = 	{151,101,65,69}; //https::/stackoverflow.com
// const u8 	TARGET_SERVER_IP[] = 	{52,25,109,230}; //http://www.geeksforgeeks.org/

const u16   TARGET_SERVER_PORT =	80;

char Buffer[20 * 1024* 1024];
// char* Buffer;
char phase_2_link[1000] = {'\0'};
char final_link[1000] = {'\0'};

#define HOST_IP  		"169.237.118.12"

//unsigned HTTPClient::s_nInstanceCount = 0;
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

HTTPClient::HTTPClient (CNetSubSystem *pNetSubSystem, CPWMSoundDevice *pPWMSoundDevice, CScreenDevice *pScreen, CSocket *pSocket, unsigned nMaxContentSize, u16 nPort)
:	CTask (HTTPD_STACK_SIZE),
	m_pNetSubSystem (pNetSubSystem),
	m_pScreen(pScreen),
	m_pSocket (pSocket),
	m_nMaxContentSize (nMaxContentSize),
	m_nPort (nPort),
	m_pContentBuffer (0),
	m_pPWMSoundDevice(pPWMSoundDevice)
{
	//s_nInstanceCount++;

	if (m_nMaxContentSize > 0)
	{
		m_pContentBuffer = new u8[m_nMaxContentSize];
		assert (m_pContentBuffer != 0);
	}
}

HTTPClient::~HTTPClient (void)
{
	//assert (m_pSocket == 0);

	delete m_pContentBuffer;
	m_pContentBuffer = 0;

	m_pNetSubSystem = 0;
	assert(false);
	//s_nInstanceCount--;
}

void HTTPClient::Run (void)
{

	Keyboard *keyboard = Keyboard::Get();
	if(keyboard->IsEndOfLine())
		Request(keyboard->GetBuffer());
	/*
	if (m_pSocket == 0)
	{
		//Listener ();

	}
	else
	{
		Worker ();
	}
	*/
}

void HTTPClient::Request(const char* songName){
 	CLogger::Get()->Write("HTTPClient", LogDebug, "Song name: %s", songName);

	assert (m_pNetSubSystem != 0);
	m_pSocket = new CSocket (m_pNetSubSystem, IPPROTO_TCP);
	assert (m_pSocket != 0);
	CLogger::Get()->Write("HTTPClient", LogDebug, "Binding...");
	if (m_pSocket->Bind (m_nPort) < 0)
	{
		CLogger::Get ()->Write (FromHTTPDaemon, LogError, "Cannot bind socket (port %u)", m_nPort);

		delete m_pSocket;
		m_pSocket = 0;

		return;
	}
	CIPAddress targetIP = CIPAddress(TARGET_SERVER_IP);
  	CString Header;

    // Header.Format ("GET http://207.241.224.2/dontwork HTTP/1.0\r\n"
    //         //  "Connection: keep-alive\r\n"
    //          "\r\n",songName);
   CLogger::Get()->Write("HTTPClient", LogDebug, "Connecting...");
   int ret = m_pSocket->Connect(targetIP, TARGET_SERVER_PORT);

   CLogger::Get()->Write("HTTPClient", LogDebug, "Connection status %d", ret);
   char* ptr = Buffer;
  u32 totalLen = 0;
   int i,temp=1;
  // for(int j=0;j<4;j++){
  //
  //   if ((temp=m_pSocket->Send ((const char *) Header, Header.GetLength (), MSG_DONTWAIT)) < 0)
  // 	{
  // 		CLogger::Get ()->Write (FromHTTPDaemon, LogError, "Cannot send header");
  //
  // 		delete m_pSocket;
  // 		m_pSocket = 0;
  //
  // 		return;
  // 	}
  //   CLogger::Get()->Write("HTTPClient", LogDebug, "Temp: %d", temp);
  //
  //
  // 	for( i = 0; (ret = m_pSocket->Receive(ptr, 1600, 0)) > 0; i++) {
  // 		CLogger::Get()->Write("HTTPClient", LogDebug, "Receive status: %d", ret);
  // 		CLogger::Get()->Write("HTTPClient", LogDebug, "Block %d Received", i);
  // 		//CLogger::Get()->Write("HTTPClient", LogDebug, "Data... %s", ptr);
  //     if(i==70)  // No need to receive the entire html page. Only a part of it is necessary.
  //       break;
  // 		ptr += ret;
  // 		totalLen += ret;
  // 	}
  // 	// CLogger::Get()->Write("HTTPClient", LogDebug, "Data... \n %s", Buffer);
  // 	CLogger::Get()->Write("HTTPClient", LogDebug, "Done %d",j);
  // 	CLogger::Get()->Write("HTTPClient", LogDebug, "Final status: %d", ret);
  //   CLogger::Get()->Write("HTTPClient", LogDebug, "totalLen: %d", totalLen);
  //
  //   delete m_pSocket;
  //   m_pSocket = new CSocket (m_pNetSubSystem, IPPROTO_TCP);;
  //   if (m_pSocket->Bind (m_nPort) < 0)
  // 	{
  // 		CLogger::Get ()->Write (FromHTTPDaemon, LogError, "Cannot bind socket (port %u)", m_nPort);
  //
  // 		delete m_pSocket;
  // 		m_pSocket = 0;
  //
  // 		return;
  // 	}
  //   CLogger::Get()->Write("HTTPClient", LogDebug, "Connecting...");
  //    ret = m_pSocket->Connect(targetIP, TARGET_SERVER_PORT);
  //
  //   CLogger::Get()->Write("HTTPClient", LogDebug, "Connection status %d", ret);
  // } while(1);

	// send HTTP response header

  Header.Format ("GET http://207.241.224.2/search.php?query=%s HTTP/1.0\r\n"
           "Connection: keep-alive\r\n"
           "\r\n",songName);
  //
  // Header.Format ("GET http://207.241.224.2/search.php?query=%s HTTP/1.0\r\n"
  //          "Connection: keep-alive\r\n"
  //          "\r\n",songName);
	// // // Header.Format ("GET /search.php?query=%s HTTP/1.1\r\n"
	// // // 	       "Host: " HOST_IP "\r\n"
	// // // 	       "Connection: keep-alive\r\n"
	// // // 	       "\r\n",songName);
  // //
	CLogger::Get()->Write("HTTPClient", LogDebug, "Header: %s", (const char*)(Header));

	if (m_pSocket->Send ((const char *) Header, Header.GetLength (), MSG_DONTWAIT) < 0)
	{
		CLogger::Get ()->Write (FromHTTPDaemon, LogError, "Cannot send header");

		delete m_pSocket;
		m_pSocket = 0;

		return;
	}
  // // //
  // // //
	// char *ptr = Buffer;
	// u32 totalLen = 0;
	//  int i;
  // // // // //
	for( i = 0; (ret = m_pSocket->Receive(ptr, 1600, 0)) > 0; i++) {
		CLogger::Get()->Write("HTTPClient", LogDebug, "Receive status: %d", ret);
		CLogger::Get()->Write("HTTPClient", LogDebug, "Block %d Received", i);
		//CLogger::Get()->Write("HTTPClient", LogDebug, "Data... %s", ptr);
    // if(i==70)  // No need to receive the entire html page. Only a part of it is necessary.
    //   break;
		ptr += ret;
		totalLen += ret;
	}
	// CLogger::Get()->Write("HTTPClient", LogDebug, "Data... \n %s", Buffer);
	CLogger::Get()->Write("HTTPClient", LogDebug, "Done");
	CLogger::Get()->Write("HTTPClient", LogDebug, "Final status: %d", ret);
  CLogger::Get()->Write("HTTPClient", LogDebug, "totalLen: %d", totalLen);
	CLogger::Get()->Write("HTTPClient", LogDebug, "Number of blokcs received: %d", i);
  /*memset(Buffer,'\0',2000);
  Buffer = "<div> <div class=\"C234\"> \\
              <div \\
        class=\" \\
          item-ttl \\
                                      C C2 \\
        \" \\
      > \\
        <a href=\"/details/adele_201601\" title=\"adele\"> \\
                          <div class=\"tile-img\">\\
              <img class=\"item-img \" source=\"/services/img/adele_201601\" style=\"height:123px\">\\
            </div><!--/.tile-img-->\\
\\
\\
\\
          <div class=\"ttl\">\\
            adele              </div>\\
        </a>\\
      </div>\\
\\
    <div class=\"hidden-tiles pubdate C C3\">\\
      <nobr class=\"hidden-xs\">Jan 16, 2016</nobr>\\
      <nobr class=\"hidden-sm hidden-md hidden-lg\">01/16</nobr>\\
    </div>\\
\\
    <div class=\"by C C4\">\\
\\
                        </div><!--/.C4-->\\
  </div><!--/.C234-->\\
\\
\\
  <div class=\"mt-icon C C5\">\\
              <span class=\"iconochive-movies\"  aria-hidden=\"true\"></span><span class=\"sr-only\">movies</span>              </div>\\
\\
\\
          <h6 class=\"stat \">\\
      <span class=\"iconochive-eye\"  aria-hidden=\"true\"></span><span class=\"sr-only\">eye</span>          <nobr>4,142</nobr>\\
    </h6>\\
\\
\\
          <h6 class=\"stat\">\\
      <span class=\"iconochive-favorite\"  aria-hidden=\"true\"></span><span class=\"sr-only\">favorite</span>          0        </h6>\\
\\
              <h6 class=\"stat\">\\
        <span class=\"iconochive-comment\"  aria-hidden=\"true\"></span><span class=\"sr-only\">comment</span>            0          </h6>\\
                      </div><!--/.item-ia-->\\
\\
\\
<div class=\"details-ia hidden-tiles\">\\
  <div class=\"C1\"></div>\\
  <div class=\"C234\">\\
    <span>adele</span><br/>                Topic: adele<br/>                      </div>\\
  <div class=\"C5\"></div>\\
</div>\\
\\
\\
\\
<div class=\"item-ia\" data-id=\"Adele_201703\">\\
\\
        <a class=\"stealth\" tabindex=\"-1\" href=\"/details/opensource_audio\">\\
    <div class=\"item-parent\">\\
      <div class=\"item-parent-img\"><img source=\"/services/img/opensource_audio\"/></div>\\
      <div class=\"item-parent-ttl\">Community Audio</div>\\
    </div><!--/.item-parent-->\\
  </a>\\
\\
\\
  <div class=\"hidden-tiles views C C1\">\\
              <nobr class=\"hidden-xs\">20,346</nobr>\\
      <nobr class=\"hidden-sm hidden-md hidden-lg\">20K</nobr>\\
          </div>\\
\\
\\
\\
\\
  <div class=\"C234\">\\
              <div\\
        class=\"\\
          item-ttl\\
                                      C C2\\
        \"\\
      >\\
        <a href=\"/details/Adele_201703\" title=\"Adele\">\\
                          <div class=\"tile-img\">\\
              <img class=\"item-img \" source=\"/services/img/Adele_201703\" style=\"height:45px\">\\
            </div><!--/.tile-img--> \\
            \\
\\
                          <div class=\"ttl\">\\
                            Adele              </div>\\
                        </a>\\
                      </div>\\
\\
                    <div class=\"hidden-tiles pubdate C C3\">\\
                      <nobr class=\"hidden-xs\">Mar 12, 2017</nobr>\\
                      <nobr class=\"hidden-sm hidden-md hidden-lg\">03/17</nobr>\\
                    </div>\\
\\
                    <div class=\"by C C4\">\\
\\
                                  <span class=\"hidden-lists\">by</span>\\
                        <span class=\"byv\"\\
                              title=\"Adele\">Adele</span>\\
                                        </div><!--/.C4-->\\
                  </div><!--/.C234-->\\
\\
\\
                  <div class=\"mt-icon C C5\">\\
                              <span class=\"iconochive-audio\"  aria-hidden=\"true\"></span><span class=\"sr-only\">audio</span>              </div>";
*/
  // memset(phase_2_link,'\0',1000);
  // memset(final_link,'\0',1000);
   GetLinkForPhase2();
  CLogger::Get()->Write("HTTPClient", LogDebug, "Phase 2 Link... \n %s", phase_2_link);
 //  //while(1);
 // Header.Format ("GET http://207.241.224.2/search.php?query=adele HTTP/1.0\r\n"
 //          "Connection: keep-alive\r\n"
 //          "\r\n");

 // Header.Format ("GET http://archive.org/download/Hello_20161104/Hello.mp3 HTTP/1.0\r\n"
 //          "Connection: keep-alive\r\n"
 //          "\r\n");
 // Header.Format ("GET http://ia601908.us.archive.org/10/items/Hello_20161104/Hello.mp3 HTTP/1.0\r\n"
 //          "Connection: keep-alive\r\n"
 //          "\r\n");
		//THis is working.....
    // Header.Format ("GET http://207.241.224.2/details/Adele_201703/ HTTP/1.0\r\n"
    //          "Connection: keep-alive\r\n"
    //          "\r\n");

    // m_pSocket = new CSocket (m_pNetSubSystem, IPPROTO_TCP);
    // assert (m_pSocket != 0);
    // CLogger::Get()->Write("HTTPClient", LogDebug, "Binding...");
    // if (m_pSocket->Bind (m_nPort) < 0)
    // {
    //   CLogger::Get ()->Write (FromHTTPDaemon, LogError, "Cannot bind socket (port %u)", m_nPort);
    //
    //   delete m_pSocket;
    //   m_pSocket = 0;
    //
    //   return;
    // }
    // targetIP = CIPAddress(TARGET_SERVER_IP);
    // delete m_pSocket;
    // m_pSocket = new CSocket (m_pNetSubSystem, IPPROTO_TCP);
    // assert (m_pSocket != 0);
    // CLogger::Get()->Write("HTTPClient", LogDebug, "Binding...");
    // if (m_pSocket->Bind (m_nPort) < 0)
    // {
    //   CLogger::Get ()->Write (FromHTTPDaemon, LogError, "Cannot bind socket (port %u)", m_nPort);
    //
    //   delete m_pSocket;
    //   m_pSocket = 0;
    //
    //   return;
    // }
    //
    //   CLogger::Get()->Write("HTTPClient", LogDebug, "Connecting...");
    //   ret = m_pSocket->Connect(targetIP, TARGET_SERVER_PORT);
    //
    //   CLogger::Get()->Write("HTTPClient", LogDebug, "Connection status %d", ret);

    // Header for phase 2
    Header.Format ("GET http://207.241.224.2/details/Adele_201703/ HTTP/1.0\r\n"
             "Connection: keep-alive\r\n"
             "\r\n");
    // Header.Format ("GET http://207.241.224.2%s/ HTTP/1.0\r\n"
    //          "Connection: keep-alive\r\n"
    //          "\r\n",phase_2_link);


		CLogger::Get()->Write("HTTPClient", LogDebug, "Header: %s", (const char*)(Header));

		if (m_pSocket->Send ((const char *) Header, Header.GetLength (), MSG_DONTWAIT) < 0)
		{
			CLogger::Get ()->Write (FromHTTPDaemon, LogError, "Cannot send header");

			delete m_pSocket;
			m_pSocket = 0;

			return;
		}
    CLogger::Get()->Write("HTTPClient", LogDebug, "Header sent..\n");

    //
		ptr= Buffer;
		totalLen = 0;
    // ret = m_pSocket->Receive(ptr, 300, 0);

    for(i= 0; (ret = m_pSocket->Receive(ptr, 1600, 0)) > 0; i++) {
     CLogger::Get()->Write("HTTPClient", LogDebug, "Receive status: %d", ret);
     CLogger::Get()->Write("HTTPClient", LogDebug, "Block %d Received", i);
     CLogger::Get()->Write("HTTPClient", LogDebug, "Data... %s", ptr);
    //  if(i==80)  // No need to receive the entire html page. Only a part of it is necessary.
    //    break;
     ptr += ret;
     totalLen += ret;
   }
  //  CLogger::Get()->Write("HTTPClient", LogDebug, "Data... \n %s", Buffer);
   CLogger::Get()->Write("HTTPClient", LogDebug, "Done");
   CLogger::Get()->Write("HTTPClient", LogDebug, "Final status: %d", ret);
   CLogger::Get()->Write("HTTPClient", LogDebug, "totalLen: %d", totalLen);
   CLogger::Get()->Write("HTTPClient", LogDebug, "Number of blokcs received: %d", i);

    // while (1) {
    //
    // }
    // return;
    /*Buffer="    <div>            <a class=\"stealth\" href=\"/download/Hello_20161104/Hello.ogg\" title=\"3.7M\">\\
                      <span class=\"hover-badge-stealth\">\\
                        <span class=\"iconochive-download\"  aria-hidden=\"true\"></span><span class=\"sr-only\">download</span>                    1 file                  </span>\\
                    </a>\\
                  </div>\\
                                  <a class=\"format-summary download-pill\" href=\"/download/Hello_20161104/Hello.ogg\" title=\"3.7M\" data-toggle=\"tooltip\" data-placement=\"auto left\" data-container=\"body\">\\
                      OGG VORBIS                  <span class=\"iconochive-download\"  aria-hidden=\"true\"></span><span class=\"sr-only\">download</span>                </a>\\
                              </div>\\
                          <div class=\"format-group\">\\
                                <div class=\"summary-rite\">\\
                    <a class=\"stealth\" href=\"/download/Hello_20161104/Hello_20161104_archive.torrent\" title=\"2.5K\">\\
                      <span class=\"hover-badge-stealth\">\\
                        <span class=\"iconochive-download\"  aria-hidden=\"true\"></span><span class=\"sr-only\">download</span>                   1 file                  </span>\\
                    </a>\\
                  </div>\\
                                  <a class=\"format-summary download-pill\" href=\"/download/Hello_20161104/Hello_20161104_archive.torrent\" title=\"2.5K\" data-toggle=\"tooltip\" data-placement=\"auto left\" data-container=\"body\">\\
                      TORRENT                  <span class=\"iconochive-download\"  aria-hidden=\"true\"></span><span class=\"sr-only\">download</span>                </a>\\
                              </div>\\
                          <div class=\"format-group\">\\
                                <div class=\"summary-rite\">\\
                    <a class=\"stealth\" href=\"/download/Hello_20161104/Hello_20161104_vbr.m3u\" title=\"5.6M\">\\
                      <span class=\"hover-badge-stealth\">\\
                        <span class=\"iconochive-download\"  aria-hidden=\"true\"></span><span class=\"sr-only\">download</span>                   1 file                  </span>\\
                    </a>\\
                  </div>\\
                                  <a class=\"format-summary download-pill\" href=\"/download/Hello_20161104/Hello_20161104_vbr.m3u\" title=\"5.6M\" data-toggle=\"tooltip\" data-placement=\"auto left\" data-container=\"body\">\\
                      VBR M3U                  <span class=\"iconochive-download\"  aria-hidden=\"true\"></span><span class=\"sr-only\">download</span>                </a>\\
                              </div>\\
                          <div class=\"format-group\">\\
                                <div class=\"summary-rite\">\\
                    <a class=\"stealth\" href=\"/download/Hello_20161104/Hello.mp3\" title=\"5.6M\">\\
                      <span class=\"hover-badge-stealth\">\\
                        <span class=\"iconochive-download\"  aria-hidden=\"true\"></span><span class=\"sr-only\">download</span>                    1 file                  </span>\\
                    </a>\\
                  </div>\\
                                  <a class=\"format-summary download-pill\" href=\"/download/Hello_20161104/Hello.mp3\" title=\"5.6M\" data-toggle=\"tooltip\" data-placement=\"auto left\" data-container=\"body\">\\
                      VBR MP3                  <span class=\"iconochive-download\"  aria-hidden=\"true\"></span><span class=\"sr-only\">download</span>                </a>\\
                              </div>\\
                        <div class=\"show-all\">\\
                <div class=\"pull-right\">\\
                  <a class=\"boxy-ttl hover-badge\" href=\"/compress/Hello_20161104\"><span class=\"iconochive-download\"  aria-hidden=\"true\"></span><span class=\"sr-only\">download</span> 8 Files</a><br/>";
*/
     GetDownloadLink();

		CLogger::Get()->Write("HTTPClient", LogDebug, "Download Link... \n %s", final_link);
    while(1);
		Header.Format ("GET /%s HTTP/1.1\r\n"
			       "Host: " HOST_IP "\r\n"
			       "Connection: keep-alive\r\n"
			       "\r\n",final_link);

		CLogger::Get()->Write("HTTPClient", LogDebug, "Header: %s", (const char*)(Header));

		if (m_pSocket->Send ((const char *) Header, Header.GetLength (), MSG_DONTWAIT) < 0)
		{
			CLogger::Get ()->Write (FromHTTPDaemon, LogError, "Cannot send header");

			delete m_pSocket;
			m_pSocket = 0;

			return;
		}

		ptr= Buffer;
		totalLen = 0;
		for( i = 0; (ret = m_pSocket->Receive(ptr, 1600, 0)) > 0; i++) {
			CLogger::Get()->Write("HTTPClient", LogDebug, "Receive status: %d", ret);
			CLogger::Get()->Write("HTTPClient", LogDebug, "Block %d Received", i);
			// CLogger::Get()->Write("HTTPClient", LogDebug, "Data... %s", ptr);
			ptr += ret;
			totalLen += ret;
		}
		CLogger::Get()->Write("HTTPClient", LogDebug, "Data... \n %s", Buffer);
		CLogger::Get()->Write("HTTPClient", LogDebug, "Done");
		CLogger::Get()->Write("HTTPClient", LogDebug, "Final status: %d", ret);
	  CLogger::Get()->Write("HTTPClient", LogDebug, "totalLen: %d", totalLen);
		CLogger::Get()->Write("HTTPClient", LogDebug, "Number of blokcs received: %d", i);

    m_pPWMSoundDevice->Playback(Buffer, totalLen / 1, 1, 8);
	for (unsigned nCount = 0; m_pPWMSoundDevice->PlaybackActive (); nCount++)
	{

	}



}

// Parse the buffer to get the link.
char * HTTPClient::GetLinkForPhase2(){
	char* saveptr,*token,*token1,songlink[1000];
	//saveptr = (char *)Buffer;
	//  token = strtok_r(buffer," ", &saveptr); // does nothing important.. just some trimming.
  // printf("first %s\n",token );
  int flag=0;
  token = my_strstr(Buffer,"<div>",flag);
  memset(songlink,'\0',sizeof(songlink));
  int i=0;
	do {
    i++;
    //for(int i=0;i<200;i++)

    // token = strtok_r(0,"<head>",&saveptr);
    // printf("middle %s\n",token );
    token = my_strstr(token,"<div class=\"C234\">",flag);
    token = my_strstr(token,"<div class=\"C234\">",flag);
    token = my_strstr(token,"<a href=\"",flag);
    // CLogger::Get()->Write("HTTPClient", LogDebug, "token... \n %s", token);

		token1 = strtok_r(token,"\"",&saveptr);
    token1 = strtok_r(0,"\"",&saveptr);
    // printf("second %s\n",token1 );
		// token = strtok_r(0,"<div class=\"C234\">",&saveptr);
    // printf("third %s\n",saveptr );
		// token = strtok_r(0,"<a href=\"",&saveptr);
    // printf("fourth %s\n",token1 );
    // CLogger::Get()->Write("HTTPClient", LogDebug, "token1... \n %s", token1);

		// char* token1 = strtok_r(token,"\"",&saveptr);  // this token contains the song link.
    //return token1;

		strcpy(phase_2_link, token1);
    // CLogger::Get()->Write("HTTPClient", LogDebug, "token1... \n %s", songlink);
    token = my_strstr(saveptr,"<div class=\"mt-icon C C5\">",flag);
    // printf("test %s\n",token );
    token = my_strstr(token,"<span class=\"iconochive-",flag);
    // printf("test %s\n",token );
		// token = strtok_r(0,"<div class=\"mt-icon C C5\">",&saveptr);
		// token = strtok_r(0,"<span class=\"iconochive-",&saveptr);
		token1 = strtok_r(token,"-",&saveptr);
    token1 = strtok_r(0,"\"",&saveptr); // token1 contains whether it's audio or video or text...
    // CLogger::Get()->Write("HTTPClient", LogDebug, "token1 (checking for audio)... \n %s", token1);
    token=saveptr;
  // }while(i<2);
	} while(strcmp(token1,"audio") != 0);
  // if(strcmp(token1,"audio")==0)
  //   CLogger::Get()->Write("HTTPClient", LogDebug, "audio found\n");
	return songlink;
}

// Parse the buffer to get the final link to download the song.
char* HTTPClient::GetDownloadLink(){
	char* saveptr,*token,*token1,songlink[1000];
  // token = strtok_r(buffer," ", &saveptr); // does nothing important.. just some trimming.

	int cnt=0,len;
  int flag=0;
  token = my_strstr(Buffer,"<a class=\"stealth download-pill\"",flag);

  if(flag==1)
  	{
      // printf("flag=1...\n" );
      token = my_strstr(Buffer,"<div>",flag);
      do{
    		cnt++;
        token = my_strstr(token,"<a class=\"format-summary download-pill\"",flag);
    		// token = strtok_r(buffer,"<a class=\"format-summary download-pill\"", &saveptr);
        token = my_strstr(token,"href=\"",flag);
    		token1 = strtok_r(token,"\"",&saveptr);
    		token1 = strtok_r(0,"\"",&saveptr);  // this token contains the download link.

        // printf("songlink.. %s\n", token1 );
        strcpy(songlink, token1);
    		len = strlen(token1);
        token=saveptr;
      }while(strcmp(token1+len-3,"mp3")!=0); // If last 3 characters are
  }
  else{
    // printf("flag=0...\n" );
      token = my_strstr(Buffer,"<div>",flag);
      do {

        token = my_strstr(token,"<a class=\"stealth download-pill\"",flag);
        token = my_strstr(token,"href=\"",flag);

        token1 = strtok_r(token,"\"",&saveptr);
    		token1 = strtok_r(0,"\"",&saveptr);  // this token contains the download link.

        strcpy(songlink, token1);
        //  printf("songlink.. %s\n", songlink );
    		len = strlen(token1);
        token=saveptr;
      } while(strcmp(token1+len-3,"mp3")!=0);
  }
  //  printf("songlink.. %s\n", songlink );
   strcpy(final_link,songlink);
	return songlink;
}


/*
void HTTPClient::Listener (void)
{
	assert (m_pNetSubSystem != 0);
	m_pSocket = new CSocket (m_pNetSubSystem, IPPROTO_TCP);
	assert (m_pSocket != 0);

	if (m_pSocket->Bind (m_nPort) < 0)
	{
		CLogger::Get ()->Write (FromHTTPDaemon, LogError, "Cannot bind socket (port %u)", m_nPort);

		delete m_pSocket;
		m_pSocket = 0;

		return;
	}

	if (m_pSocket->Listen () < 0)
	{
		CLogger::Get ()->Write (FromHTTPDaemon, LogError, "Cannot listen on socket");

		delete m_pSocket;
		m_pSocket = 0;

		return;
	}

	while (1)
	{
		CIPAddress ForeignIP;
		u16 nForeignPort;
		CSocket *pConnection = m_pSocket->Accept (&ForeignIP, &nForeignPort);
		if (pConnection == 0)
		{
			CLogger::Get ()->Write (FromHTTPDaemon, LogWarning, "Cannot accept connection");

			continue;
		}

		if (s_nInstanceCount >= MAX_CLIENTS+1)
		{
			CLogger::Get ()->Write (FromHTTPDaemon, LogWarning, "Too many clients");

			delete pConnection;

			continue;
		}

		CreateWorker (m_pNetSubSystem, pConnection);
	}
}
*/

/*
void HTTPClient::Worker (void)
{
	assert (m_pSocket != 0);

	// parse HTTP request
	THTTPStatus Status = ParseRequest ();
	if (Status == HTTPUnknownError)		// unknown error cannot be reported to client
	{
		delete m_pSocket;
		m_pSocket = 0;

		return;
	}

	// process HTTP request
	unsigned nContentLength = m_nMaxContentSize;
	const char *pContentType = "text/html";

	const char *pStatusMsg = "OK";

	if (Status == HTTPOK)
	{
		// get content
		assert (m_pContentBuffer != 0);
		Status = GetContent (m_RequestPath, m_RequestParams, m_RequestFormData,
				     m_pContentBuffer, &nContentLength, &pContentType);
		assert (nContentLength <= m_nMaxContentSize);
		assert (pContentType != 0);
	}

	if (Status != HTTPOK)
	{
		switch (Status)
		{
		case HTTPBadRequest:		pStatusMsg = "Bad Request";			break;
		case HTTPNotFound:		pStatusMsg = "Not Found";			break;
		case HTTPRequestEntityTooLarge:	pStatusMsg = "Request Entity Too Large";	break;
		case HTTPRequestURITooLong:	pStatusMsg = "Request-URI Too Long";		break;
		case HTTPInternalServerError:	pStatusMsg = "Internal Server Error";		break;
		case HTTPMethodNotImplemented:	pStatusMsg = "Method Not Implemented";		break;
		case HTTPVersionNotSupported:	pStatusMsg = "Version Not Supported";		break;
		default:			pStatusMsg = "Unknown Error";			break;
		}

		CString ErrorPage;
		ErrorPage.Format ("<!DOCTYPE html>\n"
				  "<html>\n"
				  "<head><title>%u %s</title></head>\n"
				  "<body><h1>%s</h1></body>\n"
				  "</html>\n", Status, pStatusMsg, pStatusMsg);

		nContentLength = ErrorPage.GetLength ();
		if (nContentLength > m_nMaxContentSize)
		{
			nContentLength = m_nMaxContentSize;
		}

		assert (m_pContentBuffer != 0);
		memcpy (m_pContentBuffer, (const char *) ErrorPage, nContentLength);
		pContentType = "text/html";	// may has been changed by GetContent()
	}

	// write log line
	const u8 *pClientIP = m_pSocket->GetForeignIP ();
	if (pClientIP == 0)			// connection closed in the meantime?
	{
		delete m_pSocket;
		m_pSocket = 0;

		return;
	}
	CIPAddress ClientIP (pClientIP);

	CString IPString;
	ClientIP.Format (&IPString);

	const char *pMethod;
	switch (m_RequestMethod)
	{
	case HTTPRequestMethodGet:	pMethod = "GET";	break;
	case HTTPRequestMethodHead:	pMethod = "HEAD";	break;
	case HTTPRequestMethodPost:	pMethod = "POST";	break;
	default:			pMethod = "UNKNOWN";	break;
	}

	CLogger::Get ()->Write (FromHTTPDaemon, LogDebug, "%s \"%s %s\" %u %u",
				(const char *) IPString, pMethod, m_RequestURI, Status, nContentLength);

	// send HTTP response header
	CString Header;
	Header.Format ("HTTP/1.1 %u %s\r\n"
		       "Server: " SERVER "\r\n"
		       "Content-Type: %s\r\n"
		       "Content-Length: %u\r\n"
		       "Connection: close\r\n"
		       "\r\n", Status, pStatusMsg, pContentType, nContentLength);

	if (m_pSocket->Send ((const char *) Header, Header.GetLength (), MSG_DONTWAIT) < 0)
	{
		CLogger::Get ()->Write (FromHTTPDaemon, LogError, "Cannot send response header");

		delete m_pSocket;
		m_pSocket = 0;

		return;
	}

	// send response
	if (   m_RequestMethod != HTTPRequestMethodHead
	    && nContentLength > 0)
	{
		assert (m_pContentBuffer != 0);
		if (m_pSocket->Send (m_pContentBuffer, nContentLength, MSG_DONTWAIT) < 0)
		{
			CLogger::Get ()->Write (FromHTTPDaemon, LogError, "Cannot send response");

			delete m_pSocket;
			m_pSocket = 0;

			return;
		}
	}

	delete m_pSocket;		// closes connection
	m_pSocket = 0;
}
*/

THTTPStatus HTTPClient::ParseRequest (void)
{
	THTTPStatus Status = HTTPOK;

	m_RequestMethod = HTTPRequestMethodUnknown;
	m_RequestURI[0] = '\0';
	m_RequestPath[0] = '\0';
	m_RequestParams[0] = '\0';
	m_bRequestFormDataAvailable = FALSE;
	m_nRequestContentLength = 0;
	m_RequestFormData[0] = '\0';

	char Buffer[FRAME_BUFFER_SIZE];
	char Line[HTTP_MAX_REQUEST_LINE+1];
#if HTTP_MAX_REQUEST_LINE+FRAME_BUFFER_SIZE+2000 > HTTPD_STACK_SIZE
	#error Increase HTTPD_STACK_SIZE!
#endif

	unsigned nState = 0;	// 0: parse header, 1: parse form data, 2: leave
	unsigned nLine = 0;
	unsigned nChar = 0;

	int nResult;

	assert (m_pSocket != 0);
	while (   nState < 2
	       && (nResult = m_pSocket->Receive (Buffer, sizeof Buffer, 0)) > 0)
	{
		for (unsigned i = 0; i < (unsigned) nResult; i++)
		{
			char chChar = Buffer[i];

			if (nState == 0)
			{
				if (chChar == '\r')
				{
					continue;
				}

				if (chChar == '\n')		// end of line
				{
					if (nChar == 0)		// empty line is end of header
					{
						if (   m_bRequestFormDataAvailable
						    && m_nRequestContentLength > 0)
						{
							nChar = 0;
							nState = 1;
						}
						else
						{
							nState = 2;
						}
					}
					else
					{
						if (nLine++ == 0)	// first line?
						{
							if (Status == HTTPOK)
							{
								Status = ParseMethod (Line);
							}
						}
						else
						{
							if (Status == HTTPOK)
							{
								Status = ParseHeaderField (Line);
							}
						}

						nChar = 0;
					}
				}
				else
				{
					// accumulate option line
					if (nChar < sizeof Line-1)
					{
						Line[nChar++] = chChar;
						Line[nChar] = '\0';
					}
					else
					{
						Status = HTTPRequestEntityTooLarge;
					}
				}
			}
			else if (nState == 1)
			{
				m_RequestFormData[nChar++] = chChar;
				m_RequestFormData[nChar] = '\0';

				if (nChar >= m_nRequestContentLength)
				{
					nState = 2;
				}
			}
		}
	}

	if (nResult < 0)
	{
		CLogger::Get ()->Write (FromHTTPDaemon, LogError, "Receive failed");

		return HTTPUnknownError;
	}

	if (Status != HTTPOK)
	{
		return Status;
	}

	if (nLine == 0)
	{
		return HTTPUnknownError;
	}

	// check for parameters
	const char *pParams = strchr (m_RequestURI, '?');
	if (pParams != 0)
	{
		strncpy (m_RequestPath, m_RequestURI, pParams-m_RequestURI);
		m_RequestPath[pParams-m_RequestURI] = '\0';

		strcpy (m_RequestParams, pParams+1);
	}
	else
	{
		strcpy (m_RequestPath, m_RequestURI);
	}

	return HTTPOK;
}

THTTPStatus HTTPClient::ParseMethod (char *pLine)
{
	// "METHOD uri HTTP/1.1" expected

	char *pToken;
	char *pSavePtr;

	assert (pLine != 0);
	if ((pToken = strtok_r (pLine, " ", &pSavePtr)) == 0)
	{
		return HTTPMethodNotImplemented;
	}

	if (strcmp (pToken, "GET") == 0)
	{
		m_RequestMethod = HTTPRequestMethodGet;
	}
	else if (strcmp (pToken, "HEAD") == 0)
	{
		m_RequestMethod = HTTPRequestMethodHead;
	}
	else if (strcmp (pToken, "POST") == 0)
	{
		m_RequestMethod = HTTPRequestMethodPost;
	}
	else
	{
		return HTTPMethodNotImplemented;
	}

	if ((pToken = strtok_r (0, " ", &pSavePtr)) == 0)
	{
		return HTTPBadRequest;
	}

	if (strlen (pToken) > sizeof m_RequestURI-1)
	{
		return HTTPRequestURITooLong;
	}

	strcpy (m_RequestURI, pToken);

	if (   (pToken = strtok_r (0, "/", &pSavePtr)) == 0
	    || strcmp (pToken, "HTTP") != 0)
	{
		return HTTPBadRequest;
	}

	if ((pToken = strtok_r (0, " \n", &pSavePtr)) == 0)
	{
		return HTTPBadRequest;
	}

	if (strcmp (pToken, "1.1") != 0)
	{
		return HTTPVersionNotSupported;
	}

	return HTTPOK;
}

THTTPStatus HTTPClient::ParseHeaderField (char *pLine)
{
	char *pToken;
	char *pSavePtr;

	assert (pLine != 0);
	if ((pToken = strtok_r (pLine, ":", &pSavePtr)) == 0)
	{
		return HTTPBadRequest;
	}

	if (strcmp (pToken, "Content-Type") == 0)
	{
		if ((pToken = strtok_r (0, " ", &pSavePtr)) == 0)
		{
			return HTTPBadRequest;
		}

		if (strcmp (pToken, "application/x-www-form-urlencoded") == 0)
		{
			m_bRequestFormDataAvailable = TRUE;
		}
	}
	else if (strcmp (pToken, "Content-Length") == 0)
	{
		if ((pToken = strtok_r (0, " ", &pSavePtr)) == 0)
		{
			return HTTPBadRequest;
		}

		unsigned nAccu = 0;
		while (*pToken != '\0')
		{
			unsigned nDigit = *pToken++ - '0';
			if (nDigit > 9)
			{
				return HTTPBadRequest;
			}

			nAccu *= 10;
			nAccu += nDigit;

			if (nAccu > HTTP_MAX_FORM_DATA)
			{
				return HTTPRequestEntityTooLarge;
			}
		}

		m_nRequestContentLength = nAccu;
	}

	return HTTPOK;
}
