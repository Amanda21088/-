#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//����ָ���ѧϰ
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
//����0��ַ�����޲η���������void�ĺ���

//void(*signai(int, void(*)(int)))(int)  
//signal��һ������������
//�����Ĳ�������������ָ��ָ��ĺ�����һ������������Ϊint�������ķ�������Ϊvoid
//signal�����ķ�������Ϊ����ָ��
//��ָ��ָ��ĺ�����һ������������Ϊint�������ķ�������Ϊvoid

//int(*arr[10])();
//����ָ������ 
//arr�Ⱥ�[]��ϣ������������飬ȥ��arr[10],ʣ�µ�int��*�������Ǻ���ָ�룬���ָ��ָ��ĺ���û�в���������������int


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
//		printf("��ѡ��:>");
//		scanf("%d", input);
//		if (input >= 1 && input <= 4)
//		{
//			printf("������������������>");
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
//			printf("�˳�\n");
//			break;
//		default:
//			printf("�������\n");
//			break;
//		}
//		printf("%d\n", ret);
//	} while (input);
//	system("pause");
//	return 0;
//}

//�����
//ת�Ʊ�
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	int(*pfun[5])(int, int) = {0, Add, Sub, Mul, Div};//���ú���ָ��������ߴ����Ч�ʣ������˴�����
//	do
//	{
//		menu();
//		printf("��ѡ��:>");
//		scanf("%d", input);
//		if (input >= 1 && input <= 4)
//		{
//			printf("������������������>");
//			scanf("%d%d",&x,&y);
//			ret = pfun[input](x, y);
//			printf("%d\n", ret);
//		}	
//	} while (input);
//	system("pause");
//	return 0;
//}

//���ú���ָ�벻�ϵ���ߴ����Ч��
//��ߴ���Ŀɶ���

//enum option    //����ö��
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
//	printf("������������������");
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
//		printf("��ѡ��:>");
//		scanf("%d", input);
//		if (input >= 1 && input <= 4)
//		{
//			printf("������������������>");
//			scanf("%d%d",&x,&y);
//		}
//		switch (input)
//		{
//		case ADD:       //����ö�٣�����Ϳ��Կ����������õĺ�������ֱ��һЩ	
//			Calc(Add);  //f��ֹ����
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
//			printf("�˳�\n");
//			break;
//		default:
//			printf("�������\n");
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
//	int (*parr)[6] = &arr;//parr����ָ��
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
//	char*(*pfun)(int,int*) = test1;                  //����ָ��
//	char*(*pfun[2])(int,int*) = { test1, test2 };    //����ָ������
//	char*(*(pfun)[2])(int , int*) = &pfun;           //ָ����ָ�������ָ��
//
//	//int(*pfun[2])(int, int) = { ADD, SUB };
//	//int(*(*p)[2])(int,int) = &pfun;
//	return 0;
//}


//�ص�����
//qsort����

//void qsort(void *base, size_t num, size_t width,
//	int(__cdecl *compare)(const void *eleml,const void *elem2))
//
//__cdecl--�����ĵ���Լ��
//
//void bubble_sort(int* arr,int sz)
//{
//	int i = 0;
//	//����
//	for (i = 0; i < sz-1; i++)
//	{
//		//ÿһ�˵ıȽ�
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
//	//size_t �޷�������
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
//	void* p = &a;   //void����һ������Ͱ�����Խ����������͵Ĵ���
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
//void bubble_sort(void*base,int sz,int width,int(*cmp)(const void*e1,const void*e2) )  //��qsortʵ��ð������
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
	//sizeof(������) 
	//&������     ֻ��������������������������
	int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a));     //�������С�����ֽڣ�16
	printf("%d\n", sizeof(a + 0)); //��Ԫ�ص�ַ��0������Ԫ�صĵ�ַ��4
	printf("%d\n", sizeof(*a));    //4
	printf("%d\n", sizeof(a + 1)); //4
	printf("%d\n", sizeof(a[1]));  //4
	printf("%d\n", sizeof(&a));    //����ĵ�ַ 4
	printf("%d\n", sizeof(*&a));   //16  ע���������һ��������
	printf("%d\n", sizeof(&a + 1));//4 ������������
	printf("%d\n", sizeof(&a[0])); //4
	printf("%d\n", sizeof(&a[0] + 1));//4  ���ڶ���Ԫ�صĵ�ַ
}

