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
		cur->_col = RED;//�ⲻ��ѡ��ɫ����Ϊÿ��·���ĺڽ�㶼��һ���ģ��������ڵĻ�Υ������
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
		//�ﵽƽ��
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent = grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)
				{
					//��һ���������ɫ
					parent->_col = BLA;
					uncle->_col = BLA;
					grandfather->_col = RED;

					cur = granffather;
					parent = cur->_parent;
				}
				else//uncle�����ڻ��ߴ�����Ϊ��
				{
					//�����������˫��->����
					if (cur == parent->_right)//����
					{
						RotateL(parent);
						swap(cur, parent);//��ת֮��cur��parent��λ�÷����˸ı�
					}
					//�ڶ����������������ɫ
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
					//��ɫ
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