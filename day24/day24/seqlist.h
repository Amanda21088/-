#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include"common.h"

typedef int SLDateType;

typedef struct SeqList
{
	SLDateType* _array;
	size_t _size;//不是下标
	size_t _capicity;
}SeqList;

void SeqListInit(SeqList*ps, size_t capacity);
void SeqListDistory(SeqList*ps);
void SeqListInsertBack(SeqList*ps, SLDateType x);//尾插
void SeqListDeletBack(SeqList*ps);

void SeqListInsertFront(SeqList*ps, SLDateType x);//前插
void SeqListDeletFront(SeqList*ps);

void SeqListInsert(SeqList*ps, size_t pos, SLDateType x);
void SeqListErase(SeqList*ps, size_t pos);
int SeqListFind(SeqList*ps, SLDateType x);
size_t SeqListSize(SeqList *ps);
int SeqListEmpty(SeqList* ps);
void SeqListModify(SeqList*ps, size_t pos, SLDateType x);
void SeqListRemove(SeqList*ps, SLDateType x);
void SeqListBubbleSort(SeqList* ps);
int SeqListBinaryFind(SeqList* ps, SLDateType x);
void SeqListRemoveAll(SeqList* psl, SLDateType x);



void ckeckcapacity(SeqList*ps);
void SeqListPrint(SeqList*ps);
void SeqListTest();
