#include "stdafx.h"
#include "RoundKeyManager.h"
#include "SBox.h"
RoundKeyManager::RoundKeyManager() {}
RoundKeyManager::~RoundKeyManager() {}

std::vector<Bit> RoundKeyManager::GetRoundKeys(Bit key) {
	auto box = SBox::Instance();
	std::vector<Bit> ans;
	Bit res;
	Bit sim = key;
	unsigned long lst=sim.GetColumn(3);
	for (int i = 0; i < 10; i++) {
		res.Clear();
		for (int j = 0; j < Bit::MAXN; j++) {
			unsigned long mask = (lst << 8) | (lst >> 8 * 3);
			mask = box->GetDWord(mask);
			mask ^= sim.GetColumn(j);
			if (j == 0) {
				unsigned long bit = 0;
				for (int k = 0; k < 4; k++) {
					bit <<= 8;
					bit |= rcon[k][i];
				}
				mask ^= bit;
			}
			res.SetColumn(j, mask);
			lst = mask;
		}
		ans.push_back(res);
		sim = res;
	}
	return ans;
}

std::vector<std::vector<unsigned char>> RoundKeyManager::rcon = { { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36 }, 
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } };