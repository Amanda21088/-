#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#pragma once
enum Color
{
	RED,
	BLA,
};
template<class K, class V>
class RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	std::pair<K, V> _kv;
	Color _col;
};
template<class K, class V>
class RBTree
{
	typedef  RBTreeNode<K, V> Node;
public:
	bool Insert(const std::pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLA;
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			parent = cur;
			if (cur->_kv.first < kv.first)
			{
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(kv);
		cur->_col = RED;//这不能选黑色，因为每条路径的黑结点都是一样的，如果插入黑的会违反规则
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		//达到平衡
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent = grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)
				{
					//第一种情况：变色
					parent->_col = BLA;
					uncle->_col = BLA;
					grandfather->_col = RED;

					cur = granffather;
					parent = cur->_parent;
				}
				else//uncle不存在或者存在且为黑
				{
					//第三种情况：双旋->单旋
					if (cur == parent->_right)//单旋
					{
						RotateL(parent);
						swap(cur, parent);//旋转之后cur和parent的位置发生了改变
					}
					//第二种情况：单旋＋变色
					RotateR(grandfather);
					parent->_col = BLA;
					grandfather->_col = RED;
				}
			}
			else//parent = grandfarher->_right
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					//变色
					parent->_col = BLA;
					uncle->_col = BLA;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(cur, parent);
					}
					RotateL(grandfather);
					parent->_col = BLA;
					grandfather->_col = RED;
				}
			}
		}
		_root->_col = BLA;
		return true;
	}
private:
	Node* _root = nullptr;
};

int main()
{

	system("pause");
	return 0;
}