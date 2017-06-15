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

const u8 	TARGET_SERVER_IP[] = 	{169,237,118,13};
const u16   TARGET_SERVER_PORT =	80;

u8 Buffer[30 * 1024 * 1024];

#define HOST_IP  		"169.237.118.12"

#define SOUND_CHANNELS   2

//unsigned HTTPClient::s_nInstanceCount = 0;

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

	//assert(false);
	//s_nInstanceCount--;
}

void HTTPClient::Run (void)
{
	Keyboard *keyboard = Keyboard::Get();
	if(keyboard->IsEndOfLine()){
		keyboard->ClearEndOfLine();
		Request(keyboard->GetBuffer());
		keyboard->ClearBuffer();
	}
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
	CLogger::Get()->Write("HTTPClient", LogDebug, "Connecting...");
	int ret = m_pSocket->Connect(targetIP, TARGET_SERVER_PORT);	
	
	CLogger::Get()->Write("HTTPClient", LogDebug, "Connection status %d", ret);
	
	
	// send HTTP response header
	CString Header;
	Header.Format ("GET /%s.raw HTTP/1.1\r\n"
		       "Host: " HOST_IP "\r\n"
		       "Connection: keep-alive\r\n"
		       "\r\n", songName);

	CLogger::Get()->Write("HTTPClient", LogDebug, "Header: %s", (const char*)(Header));

	if (m_pSocket->Send ((const char *) Header, Header.GetLength (), MSG_DONTWAIT) < 0)
	{
		CLogger::Get ()->Write (FromHTTPDaemon, LogError, "Cannot send header");

		delete m_pSocket;
		m_pSocket = 0;

		return;
	}	

	u8 *ptr = Buffer;
	u32 totalLen = 0;

	for(int i = 0; (ret = m_pSocket->Receive(ptr, 1600, 0)) > 0; i++) {
		CLogger::Get()->Write("HTTPClient", LogDebug, "Receive status: %d", ret);
		CLogger::Get()->Write("HTTPClient", LogDebug, "Block %d Received", i);
		ptr += ret;
		totalLen += ret;
	}

	CLogger::Get()->Write("HTTPClient", LogDebug, "Done");
	CLogger::Get()->Write("HTTPClient", LogDebug, "Final status: %d", ret);
    CLogger::Get()->Write("HTTPClient", LogDebug, "totalLen: %d", totalLen);

    m_pPWMSoundDevice->Playback(Buffer, totalLen / SOUND_CHANNELS, SOUND_CHANNELS, 8);
	for (unsigned nCount = 0; m_pPWMSoundDevice->PlaybackActive (); nCount++)
	{
		
	}
	
    
	delete m_pSocket;// disconnect
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
