#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct sqlist
{
	int a[100];
	int b[100];
	int length;
}L;
//声明
void inster(sqlist L);
void bubble(sqlist L);
void select(sqlist L);
void shell(int*data, unsigned int len);
void quick_sort(int s[], int l, int r);
void HeapSort(int A[], int n);
void MergeSort(int *r, int *rf, int lenght);
void Bucket_sort(int *pArr, int len);

void main()
{
	L.a[100] = 0;
	int i = -1;
	do
	{
		i = i + 1;//i从0起
		scanf("%d", &L.a[i]);
	} while (L.a[i] != -1);

	L.length = i;

	//开始
	inster(L); printf("\n");
	bubble(L); printf("\n");
	select(L); printf("\n");
	shell(L.a, L.length); printf("\n");
	quick_sort(L.a, 0, L.length - 1); printf("\n");
	HeapSort(L.a, L.length); printf("\n");
	MergeSort(L.a, L.b, L.length); printf("\n");
	Bucket_sort(L.a, L.length); printf("\n");
}


//插入排序
void inster(sqlist L)
{
	int i, j;
	int temp;
	for (i = 1; i<L.length; i++)
	{
		temp = L.a[i];

		for (j = i; j>0 && L.a[j - 1]>temp; j--)
		{
			L.a[j] = L.a[j - 1];//哨兵(就是下一个要放的)
		}
		L.a[j] = temp;
	}

	printf("插入排序：");
	for (int j = 0; j < L.length; j++) printf("%d ", L.a[j]);//
}

//冒泡排序
void bubble(sqlist L)
{
	for (int i = 0; i< L.length - 1; ++i) {
		for (int j = 0; j < L.length - i - 1; ++j) {
			if (L.a[j] > L.a[j + 1])
			{
				int tmp = L.a[j]; L.a[j] = L.a[j + 1];  L.a[j + 1] = tmp;
			}
		}
	}
	printf("冒泡排序：");
	for (int j = 0; j < L.length; j++) printf("%d ", L.a[j]);//
}

//选择排序
int SelectMinKey(int a[], int n, int i)
{
	int k = i;
	for (int j = i + 1; j< n; ++j) {
		if (a[k] > a[j]) k = j;
	}
	return k;
}
void select(sqlist L)
{
	int key, tmp;
	for (int i = 0; i < L.length; ++i)
	{
		key = SelectMinKey(L.a, L.length, i);           //选择最小的元素  
		if (key != i) {
			tmp = L.a[i];  L.a[i] = L.a[key]; L.a[key] = tmp; //最小元素与第i位置元素互换  
		}
	}
	printf("选择排序：");
	for (int j = 0; j < L.length; j++)  printf("%d ", L.a[j]);//
}

//希尔排序
void swapInt(int * a, int*b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
void shell(int*data, unsigned int len)
{
	if (len <= 1 || data == NULL)
		return;
	for (int div = len / 2; div >= 1; div = div / 2)//定增量div，并不断减小
	{
		for (int i = 0; i <= div; ++i)//分组成div组
		{
			for (int j = i; j<len - div; j += div)//对每组进行插入排序
			for (int k = j; k<len; k += div)
			if (data[j]>data[k])
				swapInt(data + j, data + k);//交换两个数的值
		}
	}
	printf("希尔排序：");
	for (int j = 0; j < L.length; j++)  printf("%d ", L.a[j]);//
}

//快速排序
void quick_sort(int s[], int l, int r)//l是左下标，r是右下标
{
	int i, j, key;
	if (l < r)
	{
		i = l;
		j = r;
		key = L.a[i];//首先任意选取一个数据（通常选用第一个数据）作为关键数据(key)
		//L.a[i]处相当于一个“空”，可以放进去
		while (i < j)//【`直`到`指针交叉】
		{
			while (i < j && L.a[j] > key)
				j--; /* 从右向左找第一个小于key的数 */
			if (i < j)
				L.a[i++] = L.a[j];


			while (i < j && L.a[i] < key)
				i++; /* 从左向右找第一个大于key的数 */
			if (i < j)
				L.a[j--] = L.a[i];
		}
		L.a[i] = key;//空位添上，形成完整新序列
		//以上为划分部分。。。。。。。。。。。。。。。。。。。。。
		/* 递归调用 */
		quick_sort(L.a, l, i - 1); //左起l，右至i-1
		quick_sort(s, i + 1, r);   //左至i+1，右起r
	}
	if (l == r) {
		printf("快速排序：");
		for (int j = 0; j < L.length; j++)  printf("%d ", L.a[j]);//
	}
}

//堆  排序
void AdjustDown(int A[], int i, int len)
{
	int temp = A[i]; // 暂存A[i] 

	for (int largest = 2 * i + 1; largest<len; largest = 2 * largest + 1)
	{
		if (largest != len - 1 && A[largest + 1]>A[largest])
			++largest;     // 如果右子结点大 
		if (temp < A[largest])
		{
			A[i] = A[largest];
			i = largest;     // 记录交换后的位置 
		}
		else
			break;
	}
	A[i] = temp;  // 被筛选结点的值放入最终位置 
}
void BuildMaxHeap(int A[], int len)
{
	for (int i = len / 2 - 1; i >= 0; --i) // 从i=n/2-1到0，反复调整堆 
		AdjustDown(A, i, len);
}
void HeapSort(int A[], int n)
{
	BuildMaxHeap(A, n);    // 初始建堆 
	for (int i = n - 1; i>0; --i) // n-1趟的交换和建堆过程  
	{
		// 输出最大的堆顶元素（和堆底元素交换） 
		A[0] = A[0] ^ A[i];
		A[i] = A[0] ^ A[i];
		A[0] = A[0] ^ A[i];
		// 调整，把剩余的n-1个元素整理成堆 
		AdjustDown(A, 0, i);
	}

	printf("堆排序：");
	for (int j = 0; j < L.length; j++)  printf("%d ", L.a[j]);//
}

//二路归并排序
void Merge(int *r, int *rf, int i, int m, int n)
{
	int j, k;
	for (j = m + 1, k = i; i <= m && j <= n; ++k) {
		if (r[j] < r[i]) rf[k] = r[j++];
		else rf[k] = r[i++];
	}
	while (i <= m)  rf[k++] = r[i++];
	while (j <= n)  rf[k++] = r[j++];
}
void MergeSort(int *r, int *rf, int lenght)
{
	int len = 1;
	int *q = r;
	int *tmp;
	while (len < lenght) {
		int s = len;
		len = 2 * s;
		int i = 0;
		while (i + len <lenght) {
			Merge(q, rf, i, i + s - 1, i + len - 1); //对等长的两个子表合并  
			i = i + len;
		}
		if (i + s < lenght) {
			Merge(q, rf, i, i + s - 1, lenght - 1); //对不等长的两个子表合并  
		}
		tmp = q; q = rf; rf = tmp; //交换q,rf，以保证下一趟归并时，仍从q 归并到rf  
	}
	printf("归并排序：");
	for (int j = 0; j < L.length; j++)  printf("%d ", *(rf + j));//
}

