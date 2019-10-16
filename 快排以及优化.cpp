#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
int a[100], n;
void quicksort(int left, int right)
{
	int i;//ָ���һ����
	int j;//ָ�����һ����
	int tmp;//���׼��
	if (left > right)
		return;
	tmp = a[left];
	i = left;
	j = right;
	while (i != j)
	{
		while (i < j && a[j] >= tmp)
		{
			j--;
		}
		while (i < j && a[i] <= tmp)
		{
			i++;
		}
		if (i < j)
		{
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	//���ս���׼����λ
	a[left] = a[i];
	a[i] = tmp;
	quicksort(left, i - 1);//����������ߵģ�������һ���ݹ�Ĺ���
	quicksort(i + 1, right);//���������ұߵ� ��������һ���ݹ�Ĺ���
}
int main()
{
	int i;
	//��������
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	quicksort(1, n); //�����������
	//��������Ľ��
	for (i = 1; i < n; i++)
		printf("%d ", a[i]);

	system("pause");
	return 0;
}


//�Ż�
//���ﻹ��һ�ּ򵥵ģ�ͨ���׶��Ŀ������򷽷����������£�

#include <stdio.h>

void swap(int a[], int i, int j)
{
	int t;
	t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void quickSort(int a[], int left, int right)
{
	int mid, i, j;

	if (left >= right)
		return;

	mid = a[left];
	i = left;
	j = left + 1;
	while (j <= right)
	{
		if (a[j] <= mid)
		{
			i++;
			swap(a, i, j);
		}
		j++;
	}
	swap(a, i, left);
	quickSort(a, left, i - 1);
	quickSort(a, i + 1, right);
}

int main()
{
	int a[9] = { 8, 2, 6, 12, 1, 9, 5, 5, 10 };
	int i;
	quickSort(a, 0, 8);/*�ź���Ľ��*/
	for (i = 0; i<9; i++)
		printf("%d\n", a[i]);
	return 0;
}
