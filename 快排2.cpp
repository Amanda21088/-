#define _CRT_SECURE_NO_WARNINGS 1
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
	quickSort(a, 0, 8);/*排好序的结果*/
	for (i = 0; i<9; i++)
		printf("%d\n", a[i]);
	return 0;
}
