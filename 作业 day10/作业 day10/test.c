#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int count_one_bits(unsigned int n)
//{
//	int i = 1;
////	int count = 0;                
////	for (i = 1; i <32; i++)    
////	{
////		if ((n & 1) == 1)
////		{
////			count++;
////		}
////		n = n >> 1;
////	}
////	return count;
////}
////int main()
////{
////	int sum = 0;
////	sum = count_one_bits(15);
////	printf("%d\n", sum);
////}
//
//
//
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int n = 0;
//	printf("请输入一个数字：\n");
//	scanf("%d", &n);
//	for (i = 0; i < 32; i += 2)
//	{
//		printf("%d ", (n >> i) &1);
//	}
//	printf("\n");
//	for (i = 1; i < 32; i += 2)
//	{
//		printf("%d ", (n >> i) & 1);
//	}
//	printf("\n");
//	for (i = 0; i < 32; i++)
//	{
//		printf("%d ",(n >> i) & 1);
//	}
//	system("pause");
//	return 0;
//}
//
//int m(int n)
//{
//	if (n >= 10)
//	{
//		m(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//int main()
//
//{
//	int n = 52;
//	m(n);
//	system("pause");
//}
void p(int n, int m)
{
	int ret = 0;
	int count = 0;
	ret = m ^ n;
	while (ret != 0)
	{
		ret = ret &(ret - 1);
		count++;
	}
	printf("%d", count);
}
int main()
{
	int m = 0;
	int n = 0;
	scanf("%d %d", &m, &n);
	p(m, n);
	system("pause");
	
	
}