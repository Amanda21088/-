#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
#include"Common.h"

void ListInit(List* plist)
{
	assert(plist);
	plist->_head = (ListNode*)malloc(sizeof(ListNode));
	plist->_head->_next = plist->_head->_prev = plist->_head;
}
void ListDistory(List* plist)
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(plist->_head);
	plist->_head = NULL;
}

void ListPrint(List* plist)
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
	printf("<-head->");
	while (cur != plist->_head)
	{
		printf("<-%d->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
ListNode* ListBuyNode(LTDataType x)
{
	ListNode* Newnode = (ListNode*)malloc(sizeof(ListNode));
	Newnode->_data = x;
	Newnode->_next = NULL;
	return Newnode;
}

void ListPushBack(List* plist, LTDataType x)//后插
{
	assert(plist);
	/*ListNode* cur = plist->_head;
	while (cur->_next != cur)
	{
		cur = cur->_next;
	}
	ListNode* Newnode = ListBuyNode(x);
	cur->_next = Newnode;
	Newnode->_prev = cur;
	Newnode->_next = cur;
	cur->_prev = Newnode;*/
	ListNode* cur = plist->_head->_prev;
	ListNode* Newnode = ListBuyNode(x);
	cur->_next = Newnode;
	Newnode->_prev = cur;
	Newnode->_next = plist->_head;
	plist->_head->_prev = Newnode;
}
void ListPopBack(List* plist)
{
	assert(plist && plist->_head->_next != plist->_head);
	ListNode* head = plist->_head;
	ListNode* pprve = head->_prev;
	ListNode* prev = head->_prev->_prev;
	prev->_next = head;
	head->_prev = prev;
	free(pprve);
}
void ListPopFront(List* plist)
{
	assert(plist);
	ListNode* next = plist->_head->_next;
	ListNode* pnext = next->_next;
	plist->_head->_next = pnext;
	pnext->_prev = plist->_head;
	free(next);
}
void ListPushFront(List* plist, LTDataType x)//前插
{
	assert(plist);
	ListNode* Newnode = ListBuyNode(x);
	if (plist->_head == NULL)
	{
		plist->_head->_next = Newnode;
	}
	ListNode* head = plist->_head;
	ListNode* next = head->_next;
	head->_next = Newnode;
	Newnode->_prev = head;
	Newnode->_next = next;
	next->_prev = Newnode;
}

ListNode* ListFind(List* plist, LTDataType x)
{
	assert(plist && plist->_head->_next != plist->_head);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	while (cur != head)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* Newnode = ListBuyNode(x);
	ListNode* prev = pos->_prev;
	prev->_next = Newnode;
	Newnode->_prev = prev;
	Newnode->_next = pos;
	pos->_prev = Newnode;
}

void ListErase(List* plist, ListNode* pos)
{

	assert(plist);
	ListNode* next = pos->_next;
	ListNode* prev = pos->_prev;
	prev->_next = next;
	next->_prev = prev;
	free(pos);
}

void ListRemove(List* plist, LTDataType x)
{

	assert(plist);
	ListNode* cur = ListFind(plist, x);
	ListErase(plist, cur);

}
void ListTest()
{
	List plist;
	ListInit(&plist);
	ListPushFront(&plist, 1);
	ListPushFront(&plist, 2);
	ListPushFront(&plist, 3);
	ListPushFront(&plist, 4);
	ListPushFront(&plist, 5);
	ListPushFront(&plist, 6);//前插

	ListPushBack(&plist, 0);//后插
	ListPopBack(&plist);//后删
	//ListPopFront(&plist);//前删
	//ListNode* cur =  ListFind(&plist, 3);
	//ListInsert(cur, 7);
	//ListNode* cur = ListFind(&plist, 3);
	//ListErase(&plist, cur);
	//ListRemove(&plist, 5);



	ListPrint(&plist);
	ListDistory(&plist);

}