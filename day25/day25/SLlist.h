#include"Common.h"
#pragma once
typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;

typedef struct SList
{
	SListNode* _head;
}SList;

void SListInit(SList* plist);
void SListDistory(SList* plist);

void SListPrint(SList* plist);

void SListPushBack(SList* plist, SLTDataType x);
void SListPopBack(SList* plist);
void SListPushFront(SList* plist, SLTDataType x);
void SListPopFront(SList* plist);
SListNode* SListFind(SList* plist, SLTDataType x);
// 在pos的后面进行插入 
void SListInsertAfter(SListNode* pos, SLTDataType x);
// 在pos的前面进行插入 
void SListEraseAfter(SListNode* pos);
void SListRemove(SList* plist, SLTDataType x); 
void SListEraseAfter(SListNode* pos);

void SListTest1();
