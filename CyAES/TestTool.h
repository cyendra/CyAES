#pragma once

#include "stdafx.h"
#include "Bit.h"
#include "SBox.h"
namespace TestTool {
	using namespace std;
	const vector<unsigned char> bytes1 = { 0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34 };
	const vector<unsigned char> bytes2 = { 0x19, 0x3d, 0xe3, 0xbe, 0xa0, 0xf4, 0xe2, 0x2b, 0x9a, 0xc6, 0x8d, 0x2a, 0xe9, 0xf8, 0x48, 0x08 };
	const vector<unsigned char> bytes3 = { 0x02, 0x03, 0x01, 0x01, 0x01, 0x02, 0x03, 0x01, 0x01, 0x01, 0x02, 0x03, 0x03, 0x01, 0x01, 0x02 };
	Bit GetBit(const vector<unsigned char>& bytes) {
		Bit bit;
		int i = 0;
		for each (auto var in bytes) {
			bit.Set(i++, var);
		}
		cout << "获取基础测试数据" << endl;
		bit.ShowMat();
		cout << endl;
		return bit;
	}

	Bit SubBit() {
		auto box = SBox::Instance();
		Bit bit = GetBit(bytes2);
		bit = box->Get(bit);
		cout << "SubBytes" << endl;
		bit.ShowMat();
		cout << endl;
		return bit;
	}

	Bit ShiftRows(Bit bit) {
		for (int i = 1; i < 4; i++) bit.ShiftRow(i, i);
		bit.ShowMat();
		cout << endl;
		return bit;
	}

	Bit MixColumns(Bit bit) {
		auto mat = GetBit(bytes3);
		bit.Mix(bit);
		bit.ShowMat();
		cout << endl;
		return bit;
	}

	void TestAll() {
		auto b = SubBit();
		b = ShiftRows(b);
		b = MixColumns(b);
		system("pause");
	}

}