#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//void print(int* arr, int sz)
//{
//	int i = 0;
//	int j = 9;
//	int tmp = 0;
//	while (i < j)
//	{
//		while (i < j && arr[i] % 2 != 0)
//		{
//			i++;
//		}
//		while (i < j && arr[j] % 2 != 1)
//		{
//			j--;
//		}
//		if (i < j)
//		{
//			tmp = arr[i];
//			arr[i] = arr[j];
//			arr[j] = tmp;
//		}
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//	system("pause");
//	return 0;
//}

int find(int a[3][3], int row, int col, int k, int* px, int* py)
{
	int i = 0;
	int j = col - 1;
	while (i < row && j >= 0)
	{
 		if (a[i][j] == k)
		{
			*px = i;
			*py = j;
			return 1;
		}
		else if (a[i][j] < k)
		{
			i++;
		}
		else
		{
			j--;
		}
	}
}
int main()
{
	int px = 0; 
	int py = 0;
	int arr[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	find(arr[3][3], 3, 3, 7, &px, &py);
	printf("%d %d", px, py);
	system("pause");
	return 0;
}