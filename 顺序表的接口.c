#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#pragma once
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* array;  // 指向动态开辟的数组
	size_t size ;       // 有效数据个数 
	size_t capicity ;   // 容量空间的大小
}SeqList;

void SeqListInit(SeqList* ps, size_t capacity)
{
	assert(ps);
	ps->array = (SLDataType*)malloc(sizeof(SLDataType)*capacity);
	ps->size = 0;
	ps->capicity = capacity;
}
void SeqListDestory(SeqList* ps)
{
	assert(ps);
	if (ps->array)
	{
		free(ps->array);
		ps->array = NULL;
		ps->size = 0;
		ps->capicity = 0;
	}
}
void CheckCapacity(SeqList* ps)
{
	assert(ps);
	if (ps->size == ps->capicity)
	{
		ps->capicity *= 2;
		ps->array = realloc(ps->array, ps->capicity*sizeof(SLDataType));
		assert(ps->array);
	}

}
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps && pos <= ps->size);
	CheckCapacity(ps);
	size_t end = ps->size;//会发生隐式类型转换，所以要把size_t转换成int
	/*while ((int)pos <= end)
	{
	ps->array[end + 1] = ps->array[end];
	end--;
	}*/
	while (pos < end)//推荐用这种，否则会很容易出现错误
	{
		ps->array[end] = ps->array[end - 1];
		--end;
	}

	ps->array[pos] = x;
	ps->size++;
}
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps && pos < ps->size);
	size_t begin = pos + 1;
	size_t end = ps->size;
	while (begin < end - 1)
	{
		ps->array[begin - 1] = ps->array[begin];
		begin++;
	}
	ps->size--;
}
void SeqListPushBack(SeqList* ps, SLDataType x)
{
	/*assert(ps);
	CheckCapacity(ps);
	ps->array[ps->size] = x;
	ps->size++;*/
	SeqListInsert(ps, ps->size, x);//可以复用Insert的代码
}
void SeqListPopBack(SeqList* ps)
{
	/*assert(ps && ps->size > 0);
	ps->size--;*/
	SeqListErase(ps, ps->size - 1);
}
void SeqListPushFront(SeqList* ps, SLDataType x)
{
	/*assert(ps);
	CheckCapacity(ps);

	int end = ps->size -1;
	while (end >= 0)
	{
		ps->array[end + 1] = ps->array[end];
		end--;
	}*/
	SeqListInsert(ps, 0, x);//可以复用Insert的代码
}
void SeqListPopFront(SeqList* ps)
{
	/*assert(ps);
	size_t begin = 0;
	while (begin < ps->size - 1)
	{
		ps->array[begin] = ps->array[begin + 1];
		begin++;
	}*/
	SeqListErase(ps, 0);
}
int SeqListFind(SeqList* ps, SLDataType x)
{
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
	{
		if (ps->array[i] == x)
		{
			return i;
		}
	}
	return -1;
}
//非空返回1，空返回0
int SeqListEmpty(SeqList* ps)
{
	assert(ps);
	return ps->size > 0 ? 1 : 0;
}
void SeqListModify(SeqList* ps, size_t pos, SLDataType x)//修改
{
	assert(ps && pos < ps->size);
	ps->array[pos] = x;
}
void SeqListRemove(SeqList* ps, SLDataType x)
{
	assert(ps);
	SeqListErase(ps, SeqListFind(ps, x));
}

//扩展面试题实现
void SeqListBubbleSort(SeqList* ps)
{
	assert(ps);
	size_t finish = ps->size;
	while (finish > 1)
	{
		int flag = 0;//优化
		for (size_t i = 1; i < finish; i++)
		{
			if (ps->array[i - 1] > ps->array[i])
			{
				SLDataType tmp = ps->array[i - 1];
				ps->array[i - 1] = ps->array[i];
				ps->array[i] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
		finish--;
	}
}
// 本题要求：时间复杂度：O(N) 空间复杂度 O(1) 
void SeqListRemoveAll(SeqList* ps, SLDataType x) //删除所有x
{
	assert(ps);
	//int pos = 0;
	//while (-1 != (pos = SeqListFind(ps, x)))//Find和Erase的配合进行删除，但是不符合要求
	//{
	//	SeqListErase(ps, pos);
	//}

	//降低时间复杂度
	/*for (size_t i = 0; i < ps->size; i++)
	{
		if (ps->array[i] == x)
		{
			SeqListErase(ps, i);
		}
	}*/

	//最优的方法,机智！！！！！
	int count = 0;
	for (size_t i = 0; i < ps->size; i++)
	{
		if (ps->array[i] = x)
			count++;
		else
			ps->array[i - count] = ps->array[i];
	}
	ps->size -= count;
}

void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->array[i]);
	}
	printf("\n");
}
void SeqListTest()
{
	SeqList s;
	SeqListInit(&s, 10);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 9);
	SeqListPushBack(&s, 10);
	SeqListPushBack(&s, 11);
	SeqListPushBack(&s, 12);
	SeqListPrint(&s);

	SeqListErase(&s, 2);
	SeqListPrint(&s);

	/*SeqListInsert(&s, 2, 2);
	SeqListPrint(&s);*/

	SeqListDestory(&s);
}
int main()
{
	SeqListTest();
	system("pause");
	return 0;
}
