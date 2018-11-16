#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//函数指针的学习
//11_4_1
//11_4-2


//void test()
//{
//	printf("hehe\n");
//}
//int add(int a, int b)
//{
//	return a + b;
//}
//int main()
//{
//	int (*p)(int, int) = &add;
//	//int(*p)[10] = &arr;
//	printf("%d\n", (*add)(1, 2));
//	system("pause");
//}
//int main()
//{
//	//printf("%p\n", &test);	
//	//(*test)();
//	//test();
//	printf("%d\n", (*add)(2, 3));
//	system("pause");
//	return 0;
//}

//(*(void(*)())0)()
//调用0地址处的无参返回类型是void的函数

//void(*signai(int, void(*)(int)))(int)  
//signal是一个函数的声明
//函数的参数有两个，该指针指向的函数有一个参数，类型为int，函数的返回类型为void
//signal函数的返回类型为函数指针
//该指针指向的函数有一个参数，类型为int，函数的返回类型为void

//int(*arr[10])();
//函数指针数组 
//arr先和[]结合，所以它是数组，去掉arr[10],剩下的int（*）（）是函数指针，这个指针指向的函数没有参数，返回类型是int


//void menu()
//{
//	printf("*********************************************\n");
//	printf("*********     1.add     2.sub      **********\n");
//	printf("*********     3.mul     4.div      **********\n");
//	printf("*********          0.exit          **********\n");
//	printf("*********************************************\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", input);
//		if (input >= 1 && input <= 4)
//		{
//			printf("请输入两个操作数：>");
//			scanf("%d%d",&x,&y);
//		}
//		switch (input)
//		{
//		case 1:
//			ret = Add(x, y);
//			break;
//		case 2:
//			ret = Sub(x, y);
//			break;
//		case 3:
//			ret = Mul(x, y);
//			break;
//		case 4:
//			ret = Div(x,y);
//			break;
//		case 0:
//			printf("退出\n");
//			break;
//		default:
//			printf("输入错误\n");
//			break;
//		}
//		printf("%d\n", ret);
//	} while (input);
//	system("pause");
//	return 0;
//}

//改造后
//转移表
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	int(*pfun[5])(int, int) = {0, Add, Sub, Mul, Div};//利用函数指针数组提高代码的效率，减少了代码量
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", input);
//		if (input >= 1 && input <= 4)
//		{
//			printf("请输入两个操作数：>");
//			scanf("%d%d",&x,&y);
//			ret = pfun[input](x, y);
//			printf("%d\n", ret);
//		}	
//	} while (input);
//	system("pause");
//	return 0;
//}

//利用函数指针不断地提高代码的效率
//提高代码的可读性

//enum option    //利用枚举
//{
//	EXIT,//0
//	ADD,//1
//	SUB,//2
//	MUI,//3
//	DIV//4
//
//};
//void Calc(int(*pfun)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	printf("请输入两个操作数：");
//	ret = pfun(x, y);
//	printf("%d\n", ret);
//	
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", input);
//		if (input >= 1 && input <= 4)
//		{
//			printf("请输入两个操作数：>");
//			scanf("%d%d",&x,&y);
//		}
//		switch (input)
//		{
//		case ADD:       //利用枚举，从这就可以看到函数调用的函数，更直观一些	
//			Calc(Add);  //f防止出错
//			break;
//		case SUB:
//			Calc(Sub);
//			break;
//		case MUI:
//			Calc(Mul);
//			break;
//		case DIV:
//			Calc(Div);;
//			break;
//		case EXIT:
//			printf("退出\n");
//			break;
//		default:
//			printf("输入错误\n");
//			break;
//		}
//
//	} while (input);
//	system("pause");
//	return 0;
//}
//char* my_strcpy(char*dst, const char*src)
//{
//	//..
//}
//int main()
//{
//	int arr[6] = { 0 };
//	int (*parr)[6] = &arr;//parr数组指针
//	char*(*pfun)(char*, const char*) = my_strcpy;
//	return 0;
//}

//int ADD(int x, int y)
//{
//	return x + y;
//}
//int SUB(int x, int y)
//{
//	return x - y;
//}
//char*test1(int a, int*b)
//{
//
//}
//char*test2(int a, int*b)
//{
//
//}
//int main()
//{
//	char*(*pfun)(int,int*) = test1;                  //函数指针
//	char*(*pfun[2])(int,int*) = { test1, test2 };    //函数指针数组
//	char*(*(pfun)[2])(int , int*) = &pfun;           //指向函数指针数组的指针
//
//	//int(*pfun[2])(int, int) = { ADD, SUB };
//	//int(*(*p)[2])(int,int) = &pfun;
//	return 0;
//}


//回调函数
//qsort函数

//void qsort(void *base, size_t num, size_t width,
//	int(__cdecl *compare)(const void *eleml,const void *elem2))
//
//__cdecl--函数的调用约定
//
//void bubble_sort(int* arr,int sz)
//{
//	int i = 0;
//	//趟数
//	for (i = 0; i < sz-1; i++)
//	{
//		//每一趟的比较
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			int tmp = 0;
//			if (arr[j]>arr[j + 1])
//			{
//				tmp = arr[j + 1];
//				arr[j] = arr[j + 1];
//				arr[j] = tmp;
//			}
//		}
//		printf("\n");
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int main()
//{
//	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr,sz);
//	system("pause");
//	//size_t 无符号整型
//
//	return 0;
//}
//
//int cmp_int(const void*e1, const void*e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//int cmp_stu_by_age(const void*e1, const void*e2)
//{
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2-)>age);
//}
//int cmp_stu_by_name(const void*e1, const void*e2)
//{
//	return strcmp(((struct Stu*)e1)->name ,( (struct Stu*)e2)->name);
//}
//void test1()
//{
//	struct Stu s[3] = { {"zhangsan",20}, {"lisi",10}, {"wangwu",15} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0], cmp_stu_by_age));
//}
//
//void test2()
//{
//	int a = 10;
//	void* p = &a;   //void就像一个垃圾桶，可以接收其他类型的传递
//	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//}
//void Swap(char*buf1, char*buf2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++;
//		buf2++;
//	}
//}
//void bubble_sort(void*base,int sz,int width,int(*cmp)(const void*e1,const void*e2) )  //用qsort实现冒泡排序
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if ((cmp((char*)base + j*width, (char*)base + (j + 1)*width))>0)
//			{
//				Swap((char*)base + j*width, (char*)base + (j + 1)*width,width);
//			}
//		}
//	}
//}
int main()
{
	//sizeof(数组名) 
	//&数组名     只有这两种情况代表的是整个数组
	int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a));     //求数组大小（即字节）16
	printf("%d\n", sizeof(a + 0)); //首元素地址＋0（即首元素的地址）4
	printf("%d\n", sizeof(*a));    //4
	printf("%d\n", sizeof(a + 1)); //4
	printf("%d\n", sizeof(a[1]));  //4
	printf("%d\n", sizeof(&a));    //数组的地址 4
	printf("%d\n", sizeof(*&a));   //16  注意这个和上一个的区别
	printf("%d\n", sizeof(&a + 1));//4 跳过整个数组
	printf("%d\n", sizeof(&a[0])); //4
	printf("%d\n", sizeof(&a[0] + 1));//4  即第二个元素的地址
}

