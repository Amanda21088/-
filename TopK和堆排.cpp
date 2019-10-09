#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int HPDataType; 
typedef struct Heap 
{
	HPDataType* _a;    
	int _size;    
	int _capacity; 
}Heap;

void AjustDown(HPDataType* a, size_t n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			HPDataType tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;

			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_a[0];
}

void TopK()//找出前K个最小的---->建大堆
{
	const size_t N = 100000;
	const size_t K = 100;

	size_t* a = (size_t*)malloc(sizeof(size_t) * N);
	for (size_t i = 0; i < N; i++)
	{
		a[i] = rand();
	}

	Heap hp;
	HeapInit(&hp, a, K);
	for (size_t i = K; i < N; i++)
	{
		if (HeapTop(&hp) > a[i]);
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}
	HeapPrint(&hp);
}
// 堆排序 
void HeapSort(int* a, int n)
{
	//升序--->先建大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AjustDown(a, n, i);
	}

	size_t end = n - 1;
	while (end > 0)
	{
		Swap(a[0], a[end]);
		AjustDown(a, end, 0);
		end--;
	}

}

