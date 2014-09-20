#pragma once
#include "IRoundKeyManager.h"
class RoundKeyManager : public IRoundKeyManager {
private:
	static std::vector<std::vector<unsigned char>> rcon;
public:
	RoundKeyManager();
	virtual ~RoundKeyManager();
	virtual std::vector<Bit> GetRoundKeys(Bit key);
};

