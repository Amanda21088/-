#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//void test(int *p)
//{
//
//}
//int main()
//{
//	int num;
//	int *p2 = &num;
//	test(p2);
//	return 0;
//}
//int main()
//{
//	void test(int arr[])
//	{}
//	void test(int arr[10])
//	{}
//	void test(int *arr)
//	{}
//	void test2(int *arr[20])
//	{}
//	void test2(int **arr)
//	{}
//	int main()
//	{
//		int arr[10] = { 0 };
//		int *arr2[20] = { 0 };
//		test(arr);
//		test2(arr2);
//	}
//int main()
//{
//	int(*parr3[10])[5];
//	return 0;
//}
//int main()
//{
//	/*char ch = 'w';
//	char* pc = &ch;
//	*pc = 'e';*/
//	const char*p = "abcdef";//�����ַ��������ܱ��޸ģ�const���ε�*p���������ܱ�֤p���ᱻ��
//	printf("%s\n", p);
//	return 0;
//}

//int main()
//{
//	char arr1[] = "abcdef";//arr1������Ԫ�صĵ�ַ
//	char arr2[] = "abcdef";//arr2Ҳ������Ԫ�ص�ַ��������ַ���ռ䣩�϶���һ��  �ַ����ıȽϲ�����=��ֻ����strcmp����
//	char*p1 = "abcdef";//�����ַ�����һֱ���ֲ���
//	char*p2 = "abcdef";
//	if (arr1 == arr2)                             �� ��ָoffer��
//	{
//		printf("arr1 == arr2");//no
//
//	}
//	if (p1 == p2)
//	{
//		printf("p1 == p2");//ok
//	}
//	return 0;
//}

//
//int main()
//{
//	//char* a[5];//ָ������
//	//����ָ�� ָ�������ָ��
//	//����ָ��  int*
//	//�ַ�ָ��  char*
//	int arr[10];
//	int(*p)[10] = &arr;//����ָ��
//	return 0;
//}
//&��������������ĵ�ַ
//������������Ԫ�صĵ�ַ������ֵһ��������ȴ��һ����

//����ָ���ʹ��
//void print(int arr, int x, int y)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//}
//void print(int (*arr)[5], int x, int y)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%d\n", *(*(arr + i) + j));//��������ָ��
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	//int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9.10 };
//	////int *p = arr;    ��������Ļ���ֱ��*p+1��һֱ��
//	//int(*p)[10] = &arr;
//	//int i = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	printf("%d\n", (*p)[i]);
//	//}
//	int arr[3][5] = { 1, 2, 3, 4, 5, 2, 3, 4, 5, 6, 3, 4, 5, 6, 7 };
//	print(arr, 3, 5);
//
//	return 0;
//}