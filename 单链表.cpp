#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType _data;
	struct  SListNode* _next;
}SListNode;

//无头单向不循环
typedef struct SList
{
	SListNode* _head;
}SList;

void SListInit(SList* plist)
{
	assert(plist);
	plist->_head = NULL;
}
void SListPrint(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL");
	printf("\n");
}

void SListDestory(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	SListNode* tmp = NULL;
	while (cur)
	{
		tmp = cur->_next;
		free(cur);
		cur = tmp;
	}
	plist->_head = NULL;//要记得把它置为空，不然它就会变成野指针
}
SListNode* BuySListNode(SLTDataType x)
{
	SListNode* pnode = (SListNode*)malloc(sizeof(SListNode));
	pnode->_data = x;
	pnode->_next = NULL;

	return pnode;
}
void SListPushBack(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* newnode = BuySListNode(x);
	if (plist->_head == NULL)
	{
		plist->_head = newnode;
	}
	else
	{
		SListNode* cur = plist->_head;
		SListNode* tmp = NULL;
		while (cur)
		{
			tmp = cur;
			cur = cur->_next;
		}
		tmp->_next = newnode;
		//newnode->_next = NULL;//这部不需要，因为创建出来的每个节点最后都指向空
	}
}
void SListPopBack(SList* plist)
{
	assert(plist);
	SListNode* prev = NULL;
	SListNode* tail = plist->_head;
	if (tail->_next == NULL)
	{
		free(tail);
		tail = NULL;
	}
	else
	{
		while (tail->_next != NULL)
		{
			prev = tail;
			tail = tail->_next;
		}
		free(tail);
		prev->_next = NULL;
	}
}

void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* newhead = BuySListNode(x);
	newhead->_next = plist->_head;
	plist->_head = newhead;
}
void SListPopFront(SList* plist)
{
	assert(plist);
	if (plist->_head == NULL)
	{
		return;
	}
	else
	{
		SListNode* cur = plist->_head;
		plist->_head = cur->_next;
		free(cur);
		cur = NULL;
	}
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
// 在pos的后面进行插入 
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	//pos newnode next
	SListNode* next = pos->_next;
	SListNode* newnode = BuySListNode(x);
	pos->_next = newnode;
	newnode->_next = next;
}
void SListTest1()
{
	SList list;
	SListInit(&list);
	SListPushFront(&list, 1);
	SListPushFront(&list, 2);
	SListPushFront(&list, 3);
	SListPushFront(&list, 4);
	SListPushFront(&list, 5);
	SListPushFront(&list, 6);
	SListPushFront(&list, 7);
	SListPushFront(&list, 8);

	SListPrint(&list);

	SListPushBack(&list, 2);
	SListPrint(&list);

	SListPopFront(&list);
	SListPopFront(&list);
	SListPrint(&list);

	SListPopBack(&list);
	SListPrint(&list);

	SListDestory(&list);
}

int main()
{
	SListTest1();
	system("pause");
	return 0;
}