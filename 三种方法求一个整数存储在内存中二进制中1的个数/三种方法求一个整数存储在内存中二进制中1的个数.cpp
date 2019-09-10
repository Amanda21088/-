#define _CRT_SECURE_NO_WARNINGS 
//方法1
int main()
{
	int num = 10;
	int count = 0; //计数
	while (num)
	{
		if (num % 2 == 1)
		{
			count++;
		}
		num /= 2;
	}
	printf("%二进制中1的个数 = %d\n", count);
	system("pause");
	return 0;
}
//
////思考这样的实现方式有没有问题？

#include<stdio.h>
int main()
{
	int num = -1;
	int i = 0;
	int count = 0;//计数
	for (i = 0; i < 32; i++)
	{
		if (((num >> i) & 1) == 1)
			count++;
	}
	printf("%二进制中1的个数 = %d\n", count);
	system("pause");
	return 0;
}
////思考还能不能继续优化？
//
#include<stdio.h>
int main()
{
	int num = -1;
	int i = 0;
	int count = 0;//计数
	while (num)
	{
		count++;
		num = num&(num - 1);
	}
	printf("%二进制中1的个数 = %d\n", count);
	system("pause");
	return 0;
}
////这种方式是不是很好？达到了优化的效果，但是难以想到。

