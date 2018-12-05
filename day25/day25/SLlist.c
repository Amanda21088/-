#define _CRT_SECURE_NO_WARNINGS 1
#include"SLlist.h"
#include"Common.h"

void SListInit(SList* plist)
{
	assert(plist);
	plist->_head = NULL;
}

void SListDistory(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur != NULL)
	{
		SListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	plist->_head = NULL;//Ұָ��
}

//void SListEraseAfter(SList* plist, SLTDataType x)
//{
//	assert(plist);
//	SListNode* cur = plist->_head;
//	SListNode* next = cur->_next;
//	SListNode* pnext = next->_next;
//	while (cur->_next)
//	{
//		if (cur->_next == x)
//		{
//			cur = pnext;
//			free(next);
//		}
//		cur = cur->_next;
//	}
//}
void SListPrint(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur != NULL)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}
SListNode* SListBuyNode(SLTDataType x)
{
	SListNode* NewNode = (SListNode*)malloc(sizeof(SListNode));
	NewNode->_data = x;
	NewNode->_next = NULL;
	return NewNode;
}

void SListPushBack(SList* plist, SLTDataType x)//���
{
	assert(plist);
	SListNode* NewNode = SListBuyNode(x);
	if (plist->_head == NULL)
	{
		plist->_head = NewNode;
	}
	SListNode* cur = plist->_head;
	while (cur->_next)
	{
		cur = cur->_next;
	}
	cur->_next = NewNode;
	NewNode->_next = NULL;
}

void SListPopBack(SList* plist)//��ɾ
{
	assert(plist && plist->_head != NULL);
	if (plist->_head->_next == NULL)
	{
		free(plist->_head);
		plist->_head = NULL;
	}
	else
	{
		SListNode* prev = NULL;
		SListNode* tail = plist->_head;
		while (tail->_next != NULL)
		{
			prev = tail;
			tail = tail->_next;
		}
		free(tail);
		prev->_next = NULL;
	}
}

void SListPushFront(SList* plist, SLTDataType x)//ǰ��
{
	assert(plist);
	SListNode* Node = SListBuyNode(x);
	Node->_next = plist->_head;
	plist->_head = Node;
}
void SListPopFront(SList* plist)//ǰɾ
{
	assert(plist);
	SListNode* cur = plist->_head->_next;
	free(plist->_head);
	plist->_head = cur;
}

SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return cur;
}
// ��pos�ĺ�����в��� 
//void SListInsertAfter(SListNode* pos, SLTDataType x)
//{
//	assert(pos);
//	SListNode* next = pos->_next;
//	SListNode* NewNode = SListBuyNode(x);
//	next = NewNode;
//	NewNode->_next = next;
//}
// ��pos��ǰ����в��� 
void SListEraseAfter(SListNode*pos)
{
	assert(pos);
	SListNode* pnext = pos->_next;
	SListNode* next = pnext->_next;
	pos->_next = next;
	free(pnext);
	pnext = NULL;
}
void SListRemove(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* cmp = plist->_head;
	SListNode* cur =SListFind(plist, x);
	SListEraseAfter(cur);
}
void SListTest1()
{
		SList plist;
		SListInit(&plist);
		SListPushFront(&plist, 1);
		SListPushFront(&plist, 2);
		SListPushFront(&plist, 3);
		SListPushFront(&plist, 4);
		SListPushFront(&plist, 5);
		SListPushFront(&plist, 6);//ǰ��

		SListPushBack(&plist, 0);//���
		//SListPopFront(&plist);//ǰɾ
		SListPopBack(&plist);//��ɾ
		//SListRemove(&plist, 2);
		//SListPopFront(&plist);
		//SListPushBack(&plist, 3);
		//SListPopBack(&plist);
		SListPrint(&plist);

		SListDistory(&plist);

}
