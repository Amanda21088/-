#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<vector>
#include<iostream>
using namespace std;
class BitSet
{
public:
	BitSet(size_t Bitnum)
		:_Bitnum(Bitnum)
	{
		_bits.resize((Bitnum >> 8) + 1, 0);

	}
	void Set(size_t x)//把那个位设置成1，代表存在
	{
		//size_t index = x / 8;
		size_t index = x >> 3;
		size_t num = x % 8;

		_bits[index] |= (1 << num);
	}
	void Reset(size_t x)//把那个位设置成0，代表不存在
	{
		//size_t index = x / 8;
		size_t index = x >> 3;
		size_t num = x % 8;

		_bits[index] &= (~(1 << num));
	}
	bool Test(size_t x)//存在返回1，不存在返回0
	{
		size_t index = x >> 3;
		size_t num = x % 8;

		return _bits[index] & (1 << num);
	}
private:
	vector<char> _bits;//一个char，8个bite
	size_t _Bitnum;
};

void TestBitSet()
{
	BitSet bs(10000);
	bs.Set(9999);
	bs.Set(999);
	bs.Set(99);
	bs.Set(9);

	cout << bs.Test(9999) << endl;
	cout << bs.Test(999) << endl;
	cout << bs.Test(99) << endl;
	cout << bs.Test(9) << endl;
}

int main()
{
	TestBitSet();
	system("pause");
	return 0;
}
