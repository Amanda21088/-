#define _CRT_SECURE_NO_WARNINGS 1
//����1
//#include<stdio.h>
//#include<stdlib.h>
//int add(int a, int b)
//{
//	return a + b;
//}
//int sub(int a, int b)
//{
//	return a - b;
//}
//int mul(int a, int b)
//{
//	return a * b;
//}
//int chu(int a, int b)
//{
//	return a / b;
//}
//int main()
//{
//	int x, y;
//	int input = 1;
//	int ret = 0;
//	while (input)
//	{
//		printf("*************************************\n");
//		printf("*****   1. add     2. sub     *******\n");
//		printf("*****   3. mul     4. chu     *******\n");
//		printf("*************************************\n");
//		printf("��ѡ��\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("�������������\n");
//			scanf("%d %d", &x, &y);
//			ret = add(x, y);
//			break;
//		case 2:
//			printf("�������������\n");
//			scanf("%d %d", &x, &y);
//			ret = sub(x, y);
//			break;
//		case 3:
//			printf("�������������\n");
//			scanf("%d %d", &x, &y);
//			ret = mul(x, y);
//			break;
//		case 4:
//			printf("�������������\n");
//			scanf("%d %d", &x, &y);
//			ret = chu(x, y);
//			break;
//		default:
//			printf("ѡ�����������ѡ��");
//			break;
//		}
//		printf("ret = %d\n", ret);
//	}
//	system("pause");
//	return 0;
//}

//����2��ʹ�ú���ָ������ʵ�֣�
#include<stdio.h>
#include<stdlib.h>
int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mul(int a, int b)
{
	return a * b;
}
int chu(int a, int b)
{
	return a / b;
}
int main()
{
	int x, y;
	int input = 1;
	int ret = 0;
	int(*p[5])(int x, int y) = { 0, add, sub, mul, chu };//ת�Ʊ�
	while (input)
	{
		printf("*************************************\n");
		printf("*****   1. add     2. sub     *******\n");
		printf("*****   3. mul     4. chu     *******\n");
		printf("*************************************\n");
		printf("��ѡ��\n");
		scanf("%d", &input);
		if (input <= 4 && input >= 1)
		{
			printf("�����������");
			scanf("%d %d", &x, &y);
			ret = (*p[input])(x, y);
		}
		else
		{
			printf("��������");
		}
		printf("ret = %d\n", ret);
	}
	system("pause");
	return 0;
}