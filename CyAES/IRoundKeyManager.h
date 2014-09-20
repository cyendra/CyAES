#pragma once

#include "stdafx.h"
#include "Bit.h"

class IRoundKeyManager {
public:
	virtual std::vector<Bit> GetRoundKeys(Bit key) = 0;
	virtual ~IRoundKeyManager() {}
};

