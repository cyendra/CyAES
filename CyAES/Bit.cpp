#include "stdafx.h"
#include "Bit.h"


Bit::Bit() {
	Clear();
}

Bit::Bit(unsigned long long u1, unsigned long long u2) {
	
}

Bit::Bit(std::initializer_list<unsigned char> lst) {
	int i = 0;
	for each (unsigned char var in lst) {
		Set(i, var);
		i++;
	}
}

Bit::Bit(const Bit& rhs) {
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			bytes[i][j] = rhs.bytes[i][j];
		}
	}
}

Bit& Bit::operator=(const Bit& rhs) {
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			bytes[i][j] = rhs.bytes[i][j];
		}
	}
	return *this;
}

void Bit::Clear() {
	memset(bytes, 0, sizeof(bytes));
}

void Bit::Set(int i, int j, unsigned char val) {
	if (i < 0 || i >= MAXN || j < 0 || j >= MAXN) return;
	bytes[i][j] = val;
}

void Bit::Set(int pos, unsigned char val) {
	if (pos < 0 || pos >= MAX_BYTE) return;
	Set(pos % MAXN, pos / MAXN, val);
}

void Bit::SetRow(int i, unsigned long val) {
	for (int j = 0; j < MAXN; j++) {
		bytes[i][j] = (unsigned char)(val >> ((MAXN - j - 1) * 8));
	}
}

void Bit::SetColumn(int j, unsigned long val) {
	for (int i = 0; i < MAXN; i++) {
		bytes[i][j] = (unsigned char)(val >> ((MAXN - i - 1) * 8));
	}
}

unsigned char Bit::Get(int i, int j) {
	if (i < 0 || i >= MAXN || j < 0 || j >= MAXN) return 0;
	return bytes[i][j];
}

unsigned char Bit::Get(int pos) {
	if (pos < 0 || pos >= MAX_BYTE) return 0;
	return Get(pos % MAXN, pos / MAXN);
}

unsigned long Bit::GetRow(int i) {
	unsigned long dw = 0;
	for (int j = 0; j < MAXN; j++) {
		dw <<= 8;
		dw |= Get(i, j);
	}
	return dw;
}

unsigned long Bit::GetColumn(int j) {
	unsigned long dw = 0;
	for (int i = 0; i < MAXN; i++) {
		dw <<= 8;
		dw |= Get(i, j);
	}
	return dw;
}

void Bit::ShiftRow(int i) {
	unsigned char hd = Get(i, 0);
	for (int j = 0; j < MAXN - 1; j++) {
		unsigned char bt = Get(i, j + 1);
		Set(i, j, bt);
	}
	Set(i, MAXN - 1, hd);
}

void Bit::ShiftRow(int i, int d) {
	if (d < 0) return;
	d %= 4;
	while (d--) ShiftRow(i);
}

void Bit::XorColumn(int j, unsigned long col) {
	unsigned long loc = GetColumn(j);
	loc ^= col;
	SetColumn(j, loc);
}

void Bit::Xor(const Bit& mat) {
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			bytes[i][j] ^= mat.bytes[i][j];
		}
	}
}

void Bit::MixColumn(int j, const Bit& mat) {
	unsigned char a[MAXN];
	for (int i = 0; i < MAXN; i++) {
		a[i] = 0;
		for (int k = 0; k < MAXN; k++) {
			a[i] += mat.bytes[i][k] * bytes[k][j];
		}
	}
	for (int i = 0; i < MAXN; i++) {
		Set(i, j, a[i]);
	}
}

void Bit::Mix(const Bit& mat) {
	for (int j = 0; j < MAXN; j++) {
		MixColumn(j, mat);
	}
}

void Bit::UpRotate(int j) {
	unsigned char hd = Get(0, j);
	for (int i = 0; i < MAXN - 1; i++) {
		unsigned char bt = Get(i + 1, j);
		Set(i, j, bt);
	}
}

void Bit::ShowMat() {
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			//printf("%02d ",bytes[i][j]);
			std::cout << std::hex << (int)bytes[i][j] << " ";
		}
		std::cout << std::endl;
	}
}