#pragma once
#include "Bit.h"
class ISBox {
public:
	virtual unsigned char Get(int i, int j) = 0;
	virtual unsigned char GetByte(unsigned char byte) = 0;
	virtual unsigned long GetDWord(unsigned long dword) = 0;
	virtual Bit Get(Bit mat) = 0;
	virtual ~ISBox() {}
};