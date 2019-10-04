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
	void Set(size_t x)//���Ǹ�λ���ó�1���������
	{
		//size_t index = x / 8;
		size_t index = x >> 3;
		size_t num = x % 8;

		_bits[index] |= (1 << num);
	}
	void Reset(size_t x)//���Ǹ�λ���ó�0����������
	{
		//size_t index = x / 8;
		size_t index = x >> 3;
		size_t num = x % 8;

		_bits[index] &= (~(1 << num));
	}
	bool Test(size_t x)//���ڷ���1�������ڷ���0
	{
		size_t index = x >> 3;
		size_t num = x % 8;

		return _bits[index] & (1 << num);
	}
private:
	vector<char> _bits;//һ��char��8��bite
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

template<class K, class HashFunc1, class HashFunc2, class HashFunc3>//һ��ֵӳ������λ��
class BloomFilter
{
public:
	void Set(const K& key)//��֧��Reset����Ϊ��¡������ӳ���˺ܶ��λ���ѳ�ͻ��λ��Ϊ�㣬��Ӱ��������ͻ��ӳ��
	{
		size_t index1 = HashFunc1()(key);
		size_t index2 = HashFunc2()(key);
		size_t index3 = HashFunc3()(key);

		_bs.Set(index1);
		_bs.Set(index2);
		_bs.Set(index3);

	}
	void Test(const K& key)//ֻҪ��һ��λ���ڣ������ж�������
	{
		size_t index1 = HashFunc1()(key);
		if (_bs.Test(index1) == false)
		{
			return false;
		}
		size_t index2 = HashFunc2()(key);
		if (_bs.Test(index1) == false)
		{
			return false;
		}
		size_t index3 = HashFunc3()(key);
		if (_bs.Test(index1) == false)
		{
			return false;
		}

		return true;//��������
	}
private:
	BitSet _bs;
};

int main()
{
	system("pause");
	return 0;
}