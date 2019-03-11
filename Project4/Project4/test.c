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
//����
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
		i = i + 1;//i��0��
		scanf("%d", &L.a[i]);
	} while (L.a[i] != -1);

	L.length = i;

	//��ʼ
	inster(L); printf("\n");
	bubble(L); printf("\n");
	select(L); printf("\n");
	shell(L.a, L.length); printf("\n");
	quick_sort(L.a, 0, L.length - 1); printf("\n");
	HeapSort(L.a, L.length); printf("\n");
	MergeSort(L.a, L.b, L.length); printf("\n");
	Bucket_sort(L.a, L.length); printf("\n");
}


//��������
void inster(sqlist L)
{
	int i, j;
	int temp;
	for (i = 1; i<L.length; i++)
	{
		temp = L.a[i];

		for (j = i; j>0 && L.a[j - 1]>temp; j--)
		{
			L.a[j] = L.a[j - 1];//�ڱ�(������һ��Ҫ�ŵ�)
		}
		L.a[j] = temp;
	}

	printf("��������");
	for (int j = 0; j < L.length; j++) printf("%d ", L.a[j]);//
}

//ð������
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
	printf("ð������");
	for (int j = 0; j < L.length; j++) printf("%d ", L.a[j]);//
}

//ѡ������
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
		key = SelectMinKey(L.a, L.length, i);           //ѡ����С��Ԫ��  
		if (key != i) {
			tmp = L.a[i];  L.a[i] = L.a[key]; L.a[key] = tmp; //��СԪ�����iλ��Ԫ�ػ���  
		}
	}
	printf("ѡ������");
	for (int j = 0; j < L.length; j++)  printf("%d ", L.a[j]);//
}

//ϣ������
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
	for (int div = len / 2; div >= 1; div = div / 2)//������div�������ϼ�С
	{
		for (int i = 0; i <= div; ++i)//�����div��
		{
			for (int j = i; j<len - div; j += div)//��ÿ����в�������
			for (int k = j; k<len; k += div)
			if (data[j]>data[k])
				swapInt(data + j, data + k);//������������ֵ
		}
	}
	printf("ϣ������");
	for (int j = 0; j < L.length; j++)  printf("%d ", L.a[j]);//
}

//��������
void quick_sort(int s[], int l, int r)//l�����±꣬r�����±�
{
	int i, j, key;
	if (l < r)
	{
		i = l;
		j = r;
		key = L.a[i];//��������ѡȡһ�����ݣ�ͨ��ѡ�õ�һ�����ݣ���Ϊ�ؼ�����(key)
		//L.a[i]���൱��һ�����ա������ԷŽ�ȥ
		while (i < j)//��`ֱ`��`ָ�뽻�桿
		{
			while (i < j && L.a[j] > key)
				j--; /* ���������ҵ�һ��С��key���� */
			if (i < j)
				L.a[i++] = L.a[j];


			while (i < j && L.a[i] < key)
				i++; /* ���������ҵ�һ������key���� */
			if (i < j)
				L.a[j--] = L.a[i];
		}
		L.a[i] = key;//��λ���ϣ��γ�����������
		//����Ϊ���ֲ��֡�����������������������������������������
		/* �ݹ���� */
		quick_sort(L.a, l, i - 1); //����l������i-1
		quick_sort(s, i + 1, r);   //����i+1������r
	}
	if (l == r) {
		printf("��������");
		for (int j = 0; j < L.length; j++)  printf("%d ", L.a[j]);//
	}
}

//��  ����
void AdjustDown(int A[], int i, int len)
{
	int temp = A[i]; // �ݴ�A[i] 

	for (int largest = 2 * i + 1; largest<len; largest = 2 * largest + 1)
	{
		if (largest != len - 1 && A[largest + 1]>A[largest])
			++largest;     // ������ӽ��� 
		if (temp < A[largest])
		{
			A[i] = A[largest];
			i = largest;     // ��¼�������λ�� 
		}
		else
			break;
	}
	A[i] = temp;  // ��ɸѡ����ֵ��������λ�� 
}
void BuildMaxHeap(int A[], int len)
{
	for (int i = len / 2 - 1; i >= 0; --i) // ��i=n/2-1��0������������ 
		AdjustDown(A, i, len);
}
void HeapSort(int A[], int n)
{
	BuildMaxHeap(A, n);    // ��ʼ���� 
	for (int i = n - 1; i>0; --i) // n-1�˵Ľ����ͽ��ѹ���  
	{
		// ������ĶѶ�Ԫ�أ��Ͷѵ�Ԫ�ؽ����� 
		A[0] = A[0] ^ A[i];
		A[i] = A[0] ^ A[i];
		A[0] = A[0] ^ A[i];
		// ��������ʣ���n-1��Ԫ������ɶ� 
		AdjustDown(A, 0, i);
	}

	printf("������");
	for (int j = 0; j < L.length; j++)  printf("%d ", L.a[j]);//
}

//��·�鲢����
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
			Merge(q, rf, i, i + s - 1, i + len - 1); //�Եȳ��������ӱ�ϲ�  
			i = i + len;
		}
		if (i + s < lenght) {
			Merge(q, rf, i, i + s - 1, lenght - 1); //�Բ��ȳ��������ӱ�ϲ�  
		}
		tmp = q; q = rf; rf = tmp; //����q,rf���Ա�֤��һ�˹鲢ʱ���Դ�q �鲢��rf  
	}
	printf("�鲢����");
	for (int j = 0; j < L.length; j++)  printf("%d ", *(rf + j));//
}

