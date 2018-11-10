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
//	const char*p = "abcdef";//常量字符串，不能被修改，const修饰的*p，这样才能保证p不会被改
//	printf("%s\n", p);
//	return 0;
//}

//int main()
//{
//	char arr1[] = "abcdef";//arr1代表首元素的地址
//	char arr2[] = "abcdef";//arr2也代表首元素地址，两个地址（空间）肯定不一样  字符串的比较不能用=，只能用strcmp函数
//	char*p1 = "abcdef";//常量字符串会一直保持不变
//	char*p2 = "abcdef";
//	if (arr1 == arr2)                             《 剑指offer》
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
//	//char* a[5];//指针数组
//	//数组指针 指向数组的指针
//	//整型指针  int*
//	//字符指针  char*
//	int arr[10];
//	int(*p)[10] = &arr;//数组指针
//	return 0;
//}
//&数组名代表数组的地址
//数组名代表首元素的地址，他俩值一样，意义却不一样。

//数组指针的使用
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
//			printf("%d\n", *(*(arr + i) + j));//运用数组指针
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	//int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9.10 };
//	////int *p = arr;    如果遍历的话，直接*p+1，一直＋
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