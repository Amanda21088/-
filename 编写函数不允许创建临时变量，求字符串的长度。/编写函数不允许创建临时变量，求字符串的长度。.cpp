#define _CRT_SECURE_NO_WARNINGS 1

//
#include <stdio.h>
#include <windows.h>

int main()
{

	system("pause");
	return 0;
}
//#include<stdio.h>
//#include<stdlib.h>
//int Strlen(const char* str)
//{
//	if (*str == '\0')
//		return 0;
//	else
//		return 1 + Strlen(str + 1);//这一定要给str+1，让它由a移向b
//}
//int main()
//{
//	char *p = "abcdef";
//	int tmp = Strlen(p);
//	printf("%d\n", tmp);
//	system("pause");
//	return 0;
//}
////求n的阶乘
//int fact（int n)
//{
//	int result = 1;
//	while (n > 1)
//	{
//		result *= n;
//		n -= 1;
//	}
//	return result;
//}
////求第n个斐波那契数
//int fib(int n)
//{
//	int n1 = 1;
//	int n2 = 1;
//	int n3 = 0;
//	if (n <= 2)
//		return 1;
//	for (int i = 3; i < n; i++)
//	{
//		n3 = n1 + n2;
//		n1 = n2;
//		n2 = n3;
//	}
//	return n3;
//}