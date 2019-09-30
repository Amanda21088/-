#pragma once
#include<iostream>
using namespace std;
template<class T>
struct BSTNode{
	BSTNode(const T& data = T())
			:_pleft(nullptr)
			, _pright(nullptr)
			,_data(data)
	{}
	BSTNode<T>* _pleft;
	BSTNode<T>* _pright;
	T _data;
};
template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
public:
	BSTree()
		:_proot(nullptr)
	{}
	Node* Find(const T& data)
	{
		Node* pcur = _proot;
		while (pcur)
		{
			if (data == pcur->_data)
				return pcur;
			else if (data < pcur->_data)
				pcur = pcur->_pleft;
			else
				pcur = pcur->_pright;
		}
		//û�ҵ�
		return nullptr;
	}

	bool Insert(const T& data)
	{
		//����ǿ���
		if (nullptr == _proot)
		{
			_proot = new Node(data);
			return true;
		}
		//�ǿ�
		Node* pcur = _proot;
		Node* parent = nullptr;
		while (pcur)
		{
			parent = pcur;
			if (data < pcur->_data)
				pcur = pcur->_pleft;
			else if (data > pcur->_data)
				pcur = pcur->_pright;
			else
				return false;
		}
		//����
		Node* cur = new Node(data);
		if (data < parent->_data)
			parent->_pleft = cur;
		else
			parent->_pright = cur;

		return true;
	}
	//����Ĳ���
	Node* LeftMost()
	{
		if (nullptr == _proot)
		{
			return nullptr;
		}
		Node* pcur = _proot;
		while (pcur->_pleft)
		{
			pcur = pcur->_pleft;
		}
		return pcur;
	}

	void InOrder()
	{
		_InOrder(_proot);
	}

	bool Delete(const T& data)
	{
		if (proot == nullptr)
			return false;
		//�Ҷ����������д�ɾ���Ľ��
		Node* pcur = proot;
		Node* parent = nullptr;
		while (pcur)
		{
			if (data == pcur->_data)
				break;
			else if (data < pcur->_data)
				parent = pcur;
			pcur = pcur->_pleft;
			else
				parent = pcur;
			pcur = pcur->_pright;
		}
		//û�ҵ�
		if (nullptr == pcur)
			return false;
		//(1)Ҷ�ӽ��---->����ֱ��ɾ��
		//(2)ֻ������--->ֱ��ɾ��
		//(3)ֻ���Һ���--->ֱ��ɾ��
		//(4)���Һ��Ӿ�����--->��һ��������
		//Ҷ�ӽڵ��ֻ���Ѻ��ӵĽڵ�
		if (nullptr == pcur->_pleft)
		{
			//��ɾ���ڵ�Ϊ���ڵ�
			if (pcur == proot)
				proot = pcur->_pright;
			else
			{
				//��ɾ�����Ϊ˫�׵�����
				if (pcur == parent->_pleft)
				{
					parent->_pleft = pcur->_pright;
				}
				else
					//��ɾ���ڵ�Ϊ˫�׵��Һ���
				{
					parent->_pright = pcur->_pright;
				}
			}
		}
		//ֻ�����ӵĽڵ�
		else if (nullptr == pcur->_right)
		{
			//��ɾ���ڵ�Ϊ���ڵ�
			if (pcur == proot)
				proot = pcur->_pright;
			else
			{
				//��ɾ�����Ϊ˫�׵�����
				if (pcur == parent->_pleft)
				{
					parent->_pleft = pcur->_pleft;
				}
				else
					//��ɾ���ڵ�Ϊ˫�׵��Һ���
				{
					parent->_pright = pcur->_pleft;
				}
			}
		}
		//���Һ��Ӿ�����
		//���������ҽڵ�������������ҽڵ�
		else
		{
			Node* pfirstofin = pcur->_pright;
			while (pfirstofin->_pleft)
			{
				parent = pfirstofin;
				pfirstofin = pfirstofin->_pleft;
			}
			pcur->_data = pfirstofin->_data;
			if (pfirstofin == parent->_pleft)
				parent->_pleft = pfistofin->_pright;
			else
				parent->_pright = pfistofin->_pright;

		}
		return true;
	}
private:
	Node* _proot;
	void _InOrder(Node* proot)
	{
		if (proot)
		{
			_InOrder(proot->_pleft);
			cout << proot->_data << " ";
			_InOrder(proot->_pright);

		}
	}
	void _Destory(Node*& proot)
	{
		if (proot)
		{
			_Destory(proot->_pleft);
			_Destory(proot->_pright);
			delete proot;
			proot = nullptr;
		}
	}
};

void TestBSTree()
{
	int array[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree<int> t;
	for (auto e : array)
		t.Insert(e);

	cout << t.LeftMost()->_data << endl;
	t.InOrder();

	BSTNode<int>* pcur = t.Find(2);
	if (pcur)
	{
		cout << "2 is in BSTree" << endl;
	}
	else
	{
		cout << "2 is not in BSTree" << endl;

	}
}

