#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
int A(int n)
{
	int tmp = 1;
	for (int i = 1; i <= n; i++)
	{
		tmp *= i;
	}
	return tmp;
}
int main()
{
	int sum = 0;
	for (int i = 1; i <= 10; i++)
	{
		sum += A(i);
	}
	printf("%d\n", sum);

	system("pause");
	return 0;
}
