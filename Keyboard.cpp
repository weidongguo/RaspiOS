#include "Keyboard.h"

Keyboard* Keyboard::s_pThis = 0;

Keyboard::Keyboard(CUSBKeyboardDevice *pUsbKeyboardDevice)
{
	m_pUsbKeyboardDevice = pUsbKeyboardDevice;
	BufferIndex = 0;
	eol = false;
	s_pThis = this;	
}

Keyboard::~Keyboard(){
	s_pThis = 0;	
}

Keyboard* Keyboard::Get(){
	return s_pThis;
}

int Keyboard::AppendToBuffer(const char c){
	if(BufferIndex >= BUFFER_SIZE)
		return -1;

	if(c == '\n' || c == '\r'){
		Buffer[BufferIndex] = '\0';
		eol = true;
	} else {
		Buffer[BufferIndex++] = c;
	}
	return 0;
}

void Keyboard::ClearBuffer(){
	BufferIndex = 0;
	eol = false;
}

bool Keyboard::IsEndOfLine(){
	return eol;
}

char* Keyboard::GetBuffer(){
	return Buffer;	
}


