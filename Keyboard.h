#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <circle/usb/usbkeyboard.h>
#include "HTTPClient.h"

#define BUFFER_SIZE		1024

class Keyboard{
private:
	char Buffer[BUFFER_SIZE];
	unsigned int BufferIndex;
	bool eol;

	CUSBKeyboardDevice *m_pUsbKeyboardDevice;

public:	
	Keyboard(CUSBKeyboardDevice *pUsbKeyBoardDevice);
	~Keyboard();
	int AppendToBuffer(const char c);
	void ClearBuffer();
	void ClearEndOfLine();
	bool IsEndOfLine();
	char* GetBuffer();


	static Keyboard* Get();
	static Keyboard *s_pThis;

};


#endif