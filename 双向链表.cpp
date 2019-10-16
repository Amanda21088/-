#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LTDateType;

typedef struct ListNode
{
	LTDateType _data;
	struct ListNode* _prev;
	struct ListNode* _next;
}ListNode;

typedef struct List
{
	ListNode* _head;
}List;

ListNode* BuyListNode(LTDateType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_next = NULL;
	node->_prev = NULL;
	node->_data = x;

	return node;
}
void ListInit(List* plist)
{
	assert(plist);
	ListNode* head = BuyListNode(-1);//默认为头结点
	head->_next = head;
	head->_prev = head;

	plist->_head = head;
}
void ListDestory(List* plist)
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = cur->_next;
	}
	free(plist->_head);
	plist->_head = NULL;
}
void ListInsert(ListNode* pos, LTDateType x)//在pos前进行插入
{
	assert(pos);
	ListNode* newnode = BuyListNode(x);
	ListNode* prev = pos->_prev;

	prev->_next = newnode;
	newnode->_prev = prev;
	newnode->_next = pos;
	pos->_prev = newnode;
}
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;
	free(pos);
	prev->_next = next;
	next->_prev = prev;
}
void ListPrint(List* plist)
{
	assert(plist);
	printf("<-head->");
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		printf("<-%d->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void ListPushBack(List* plist, LTDateType x)
{
	/*ListNode* head = plist->_head;
	ListNode* tail = head->_prev;
	ListNode* newnode = BuyListNode(x);
	tail->_next = newnode;
	newnode->_next = head;
	head->_prev = newnode;*/
	ListInsert(plist->_head->_prev, x);
}
void ListPopBack(List* plist)
{
	/*assert(plist && plist->_head->_next != plist->_head);
	ListNode* head = plist->_head;
	ListNode* tail = head->_prev;
	ListNode* prev = tail->_prev;
	free(tail);
	prev->_next = head;
	head->_prev = prev;*/
	ListErase(plist->_head->_prev);
}
void ListPushFront(List* plist, LTDateType x)
{
	/*assert(plist);
	ListNode* head = plist->_head;
	ListNode* newnode = BuyListNode(x);
	ListNode* next = head->_next;
	head->_next = newnode;
	newnode->_prev = head;
	newnode->_next = next;
	next->_prev = newnode;*/
	ListInsert(plist->_head->_next, x);
}
void ListPopFront(List* plist)
{
	/*assert(plist && plist->_head->_next != plist->_head);
	ListNode* head = plist->_head;
	ListNode* next = head->_next;
	ListNode* nextnext = next->_next;
	free(next);
	head->_next = nextnext;
	nextnext->_prev = head;*/
	ListErase(plist->_head->_next);
}
ListNode* Find(List* plist, LTDateType x)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	while (cur != plist->_head)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

int ListSize(List* plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	int count = 0;
	while (cur != plist->_head)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}
int ListEmpty(List* plist)
{
	assert(plist);
	//return ListSize(plist) == 0 ? 0 : -1;//尽量不要调用size那个接口，效率太低了
	return plist->_head->_next == plist->_head ? 0 : -1;//O(1)
}
void ListRemove(List* plist, LTDateType x)
{
	assert(plist);
	ListNode* node = Find(plist, x);
	if (node)
		ListErase(node);
}

void ListTest1()
{
	List list;
	ListInit(&list);
	ListPushBack(&list, 1);
	ListPushBack(&list, 2);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);
	ListPushBack(&list, 5);

	ListPrint(&list);
	ListPushFront(&list, 6);
	ListPrint(&list);
	ListPopFront(&list);
	ListPrint(&list);

}

int main()
{
	ListTest1();
	system("pause");
	return 0;
}