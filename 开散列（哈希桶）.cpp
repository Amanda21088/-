#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include<iostream>
//开散列
template<class V>
struct HashNode
{
	HashNode<V>* _next;
	V _valuefiled;//值—>K 或者 pair<K, V>
};
//unordered_map -> HashTable<K, pair<K, V>, KeyOfValue)
//unordered_set -> HashTable<K, K, KeyOfValue)   第二个参数决定它是哪个的底层
template<class K, class V, class KeyOfValue>//通过Key去找到value
class HashTable
{
	typedef HashNode<V> Node;
public:
	pair<Node*, bool> Insert(const V& v)
	{
		//负载因子 == 1
		if (_num == _table.size())
		{
			size_t newsize = _table.size() = 0 ? 10 : _table.size() * 2;
			vector<HashNode*> newtable;
			newtable.resize(newsize, nullptr);
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				while (cur)
				{
					//重新计算它在新表的位置，移动到新表
					Node* next = cur->_next;
					size_t index = kov(cur->_valuefiled) % newtable.size();
					cur->_next = newtable[index];
					newtable[index] = cur;

					cur = cur->_next;
				}
				_table[i] = nullptr;
			}
			_table.swap(newtable);
		}
		KeyOfValue kov;
		size_t index = kov(v) % _table.size();
		//用头插进行插入，头插效率高
		Node* cur = _table[index];
		while (cur)
		{
			if (kov(cur->_valuefiled) == kov(v))
			{
				return make_pair(cur, false);
			}
			cur = cur->_next;
		}
		Node* newnode = new Node(v);
		newnode->_next = _table[index];
		_table[index] = newnode;
		_num++;
		return make_pair(newnode, true);
	}
private:
	vector<HashNode*> _table;
	size_t _num;
};