#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	int n = 0;
	scanf("%d", &n);
	int a[n][n];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if ((i = j) || (j = 0))
				a[i][j] = 1;
			else
				a[i][j] = i + j - 3;
			printf("%d", a[i][j]);
		}
		printf("\n"); 
	}
}