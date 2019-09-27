#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include<iostream>
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= left)
		return;
	//������Ϊ������
	int mid = left + ((right - left) >> 1);
	//[left, mid]
	//[mid+1, right]
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	while (begin1 <= end1)
		tmp[index++] = a[begin1++];
	while (begin2 <= end2)
		tmp[index++] = a[begin2++];

	memcpy(a + left, tmp + left, sizeof(int)*(right - left + 1));
}
void MergeSort(int* a, int n)
{
	int *tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp); 
}

int main()
{
	int a[5] = { 4, 5, 2, 3, 1 };
	MergeSort(a, 5);

	return 0;
}