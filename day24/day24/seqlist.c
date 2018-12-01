#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"

void SeqListInit(SeqList*ps, size_t capacity)
{
	ps->_array = (SLDateType*)malloc(sizeof(SLDateType)*capacity);
	ps->_size = 0;
	ps->_capicity = capacity;
}

void SeqListDistory(SeqList*ps)
{
	if (ps->_array)
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_capicity = ps->_size = 0;
	}
}
void checkcapacity(SeqList*ps)
{
	assert(ps);
	if (ps->_size == ps->_capicity)
	{
		ps->_capicity *= Capacity_MAX;
		ps->_array = (SLDateType*)realloc(ps->_array,ps->_capicity*sizeof(SLDateType));
		assert(ps->_array);
	}

}
void SeqListInsertBack(SeqList*ps, SLDateType x)
{
	checkcapacity(ps);
	assert(ps);
	ps->_array[ps->_size] = x;
	ps->_size++;
}
void SeqListDeletBack(SeqList*ps)
{
	assert(ps);
	ps->_array[ps->_size - 1] = 0;
	ps->_size--;
}

void SeqListInsertFront(SeqList*ps, SLDateType x)
{
	int end = ps->_size - 1;
	checkcapacity(ps);
	assert(ps);
	while (end>=0)
	{
		ps->_array[end+1] = ps->_array[end];
		end--;
	}
	ps->_array[0] = x;
	ps->_size++;
}
void SeqListDeletFront(SeqList*ps)
{
	assert(ps);
	int begain = 0;
	while (begain<ps->_size-1)
	{
		ps->_array[begain] = ps->_array[begain+1];
		begain++;
	}
	ps->_size--;
}

void SeqListPrint(SeqList*ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->_size; i++)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}
void SeqListInsert(SeqList*ps, size_t pos, SLDateType x)//pos是下标
{
	assert(ps&&pos<=ps->_size);
	int end = ps->_size - 1;
	while (end>=pos-1)
	{
		ps->_array[end+1] = ps->_array[end];
		end--;
	}
	ps->_array[pos] = x;
	ps->_size++;
}

void SeqListErase(SeqList*ps, size_t pos)
{
	assert(ps);
	int end = ps->_size - 1;
	while (end>pos)
	{
		ps->_array[pos] = ps->_array[pos + 1];;
		pos++;
	}
	ps->_size--;
}

int SeqListFind(SeqList*ps, SLDateType x)
{
	assert(ps);
	for (size_t i = 0; i < ps->_size; i++)
	{
		if (x == ps->_array[i]);
		{
			return i;
		}
	}
	return -1;
}
size_t SeqListSize(SeqList *ps)
{
	assert(ps);
	size_t count = 0;
	for (size_t i = 0; i < ps->_size; i++)
	{
		count++;
	}
	return count;
}
int SeqListEmpty(SeqList* ps)
{
	assert(ps);
	free(ps->_array);
	ps->_array = NULL;
	return ps->_array;
}
void SeqListModify(SeqList*ps, size_t pos, SLDateType x)
{
	assert(ps);
	ps->_array[pos] = x;
}
void SeqListRemove(SeqList*ps, SLDateType x)//查找并删除
{
	assert(ps);
	size_t m = SeqListFind(ps, x);
	SeqListErase(ps, m);
}
void SeqListBubbleSort(SeqList* ps)
{
	for (size_t i = 0; i < ps->_size-2; i++)
	{
		for (size_t j = 0; j < ps->_size - i - 1; j++)
		{
			if (ps->_array[j - 1]>ps->_array[j])
			{
				size_t tmp = ps->_array[j - 1];
				ps->_array[j - 1] = ps->_array[j];
				ps->_array[j] = tmp;
			}
		}
	}
}
int SeqListBinaryFind(SeqList* ps, SLDateType x)
{
	assert(ps);
	size_t left = 0;
	size_t right = ps->_size-1;
	size_t mid = left + (right - left) / 2;
	while (left <= right)
	{
		size_t mid = left + (right - left) / 2;
		if (x > ps->_array[mid])
		{
			left =mid + 1;
		}
		else if (x < ps->_array[mid])
		{
			right = mid - 1;
		}
		else
			return mid;

	}
	return -1;

}
void SeqListRemoveAll(SeqList* ps, SLDateType x)//删除相同数
{
	assert(ps);
	size_t cur = 0;
	size_t dst = 0;
	while (cur < ps->_size)
	{
		if (ps->_array[cur] != x)
		{
			ps->_array[dst] = ps->_array[cur];
			dst++;

		}
		cur++;
	}
	ps->_size = dst;
}


void SeqListTest()
{
	SeqList s;
	SeqListInit(&s, 10); 
	//SeqListInsertBack(&s, 3);
	SeqListInsertBack(&s, 1);
	SeqListInsertBack(&s, 2);
	SeqListInsertBack(&s, 1);
	SeqListInsertBack(&s, 5);

	//SeqListDeletBack(&s);
	//SeqListInsertFront(&s, 3);
	//SeqListDeletFront(&s);
	//SeqListRemoveAll(&s, 1);
	//SeqListBubbleSort(&s);
	//SeqListInsert(&s, 2, 3);
	//SeqListErase(&s, 2);
	SeqListRemoveAll(&s, 1);
	//SeqListModify(&s, 1, 5);
	SeqListPrint(&s);
	//printf("%d\n", SeqListBinaryFind(&s, 4));
	//printf("%d\n", SeqListFind(&s, 1));
	//printf("%d\n", SeqListFind(&s, 2));
	//printf("%d\n", SeqListFind(&s, 3));
	//printf("%d\n", SeqListFind(&s, 4));
	//printf("%d\n", SeqListSize(&s));
	//printf("%d\n", SeqListEmpty(&s));

	SeqListDistory(&s);

}