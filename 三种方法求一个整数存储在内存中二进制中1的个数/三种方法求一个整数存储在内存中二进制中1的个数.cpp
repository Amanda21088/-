#define _CRT_SECURE_NO_WARNINGS 
//����1
int main()
{
	int num = 10;
	int count = 0; //����
	while (num)
	{
		if (num % 2 == 1)
		{
			count++;
		}
		num /= 2;
	}
	printf("%��������1�ĸ��� = %d\n", count);
	system("pause");
	return 0;
}
//
////˼��������ʵ�ַ�ʽ��û�����⣿

#include<stdio.h>
int main()
{
	int num = -1;
	int i = 0;
	int count = 0;//����
	for (i = 0; i < 32; i++)
	{
		if (((num >> i) & 1) == 1)
			count++;
	}
	printf("%��������1�ĸ��� = %d\n", count);
	system("pause");
	return 0;
}
////˼�����ܲ��ܼ����Ż���
//
#include<stdio.h>
int main()
{
	int num = -1;
	int i = 0;
	int count = 0;//����
	while (num)
	{
		count++;
		num = num&(num - 1);
	}
	printf("%��������1�ĸ��� = %d\n", count);
	system("pause");
	return 0;
}
////���ַ�ʽ�ǲ��Ǻܺã��ﵽ���Ż���Ч�������������뵽��

