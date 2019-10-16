#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h.>
//void LeftMove(char* arr, int n)
//{
//
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		char tmp = *arr;
//		int j = 0;
//		while (*(arr + j + 1))
//		{
//			*(arr + j) = *(arr + j + 1);
//				j++;
//		}
//		*(arr + j) = tmp;
//	}
//}
//int main()
//{
//	int n = 0;
//	char arr[] = "ABCDEF";
//	printf("%s\n", &arr);
//	printf("请输入左旋的位数：");
//	scanf("%d", &n);
//	printf("左旋后的字符串：\n");
//	LeftMove(arr, n);
//	printf("%s\n", arr);
//	system("pause");
//	return 0;
//}


#include <stdio.h>
#include <string.h>
#define N 100
int main()
{
	char s1[N], s2[N];
	int i, j, k, n, m, temp;
	scanf("%s %s", s1, s2);
	n = strlen(s1);
	m = strlen(s2);
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j<n; j++)
		{
			if (s1[j]>s1[k])
			{
				k = j;
			}
		}
		if (k != i)
		{
			temp = s1[k];
			s1[k] = s1[i];
			s1[i] = temp;
		}
	}
	for (i = 0; i < m - 1; i++)
	{
		k = i;
		for (j = i + 1; j<m; j++)
		{
			if (s2[j]>s2[k])
			{
				k = j;
			}
		}
		if (k != i)
		{
			temp = s2[k];
			s2[k] = s2[i];
			s2[i] = temp;
		}
	}
	if (strcmp(s1, s2) == 0)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	system("pause");
	return 0;


}