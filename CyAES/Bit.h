#pragma once
class Bit {
public:
	const static int MAXN = 4;
	const static int MAX_BYTE = MAXN * MAXN;
private:
	unsigned char bytes[MAXN][MAXN];
public:
	Bit();
	Bit(unsigned long long u1, unsigned long long u2);
	Bit(std::initializer_list<unsigned char> lst);
	Bit(const Bit& rhs);
	Bit& operator=(const Bit& rhs);
	void Clear();
	
	void Set(int i, int j, unsigned char val);
	void Set(int pos, unsigned char val);
	void SetRow(int i, unsigned long val);
	void SetColumn(int j, unsigned long val);
	
	unsigned char Get(int i, int j);
	unsigned char Get(int pos);
	unsigned long GetRow(int i);
	unsigned long GetColumn(int j);
	
	void ShiftRow(int i);
	void ShiftRow(int i, int d);
	void XorColumn(int j, unsigned long col);
	void Xor(const Bit& mat);
	void MixColumn(int j, const Bit& mat);
	void Mix(const Bit& mat);
	void UpRotate(int j);

	void ShowMat();
};

