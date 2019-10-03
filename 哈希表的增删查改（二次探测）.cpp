#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<vector>
#include<iostream>
#include<stdlib.h>
using namespace std;
enum State
{
	EXITS,
	EMPTY,
	DELETE,
};
template<class K, class V>
struct HashData
{
	std::pair<K, V> _kv;
	State _state;
};
template<class K, class V>
class HashTable
{
	typedef HashData<K, V> HashData;
public:
	bool Insert(const std::pair<K, V>& kv)
	{
		//如果表为空或者负载因子到达0.7则增容
		if (_table.size() == 0 || _num*10 / _table.size() == 7)
		{
			size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
			HashTable<K, V> newht;
			newht._table.resize(newsize);
			for (size_t i = 0; i < _table.size(); i++)
			{
				if (_table[i]._state == EXITS)
				{
					newht.Insert(_table[i]._kv);
				}
				newht._table.swap(_table);
			}
		}
		size_t start = kv.first % _table.size();
		size_t index = start;
		size_t i = 1;
		//二次探测
		while (_table[index]._state == EXITS)
		{
			if (_table[index]._kv.first == kv.first)
			{
				return false;
			}
			index = start + i*i;//二次探测
			index %= _table.size();
			++i;

			/*if (index == _table.size())
			{
				index = 0;
			}*/
		}
		_table[index]._kv = kv;
		_table[index]._state = EXITS;
		_num++;
		return true;
	}
	HashData* Find(const K& key)
	{
		size_t start = kv.first % _table.size();
		size_t index = start;
		size_t i = 1;
		while (_table[index]._state != EMPTY)
		{
			if (_table[index]._kv.first == key)
			{
				return &_table[index];
			}
			else
			{
				index = start + i*i;//二次探测
				++i;

				index %= _table.size();
			}
		}
		return nullptr;
	}
	bool Erase(const K& key)
	{
		HashData* ret = Find(key);
		if (ret)
		{
			ret->_state = DELETE;
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	vector<HashData> _table;
	size_t _num = 0;//存储数据的个数
};

void TestHashTable()
{
	HashTable<int, int> ht;
	ht.Insert(std::make_pair(3, 3));
	ht.Insert(std::make_pair(13, 13));
	ht.Insert(std::make_pair(33, 33));
}

int main()
{
	TestHashTable();
	system("pause");
	return 0;
}