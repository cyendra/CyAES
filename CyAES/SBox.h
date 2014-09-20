#pragma once
#include "ISBox.h"
class SBox : public ISBox {
private:
	static std::vector<std::vector<unsigned char>> box;
public:
	SBox();
	virtual ~SBox();
	virtual unsigned char Get(int i, int j);
	virtual unsigned char GetByte(unsigned char byte);
	virtual unsigned long GetDWord(unsigned long dword);
	virtual Bit Get(Bit mat);
	static SBox* Instance();
};

