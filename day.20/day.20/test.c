#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//11.11.2

//int 
//float
//内置类型
//自定义类型：结构体，枚举，联合
//struct Student
//{
//	char name[20];
//	short age;
//	char sex[5];
//}stu1，stu2，stu3;
//int main()
//{
//	struct Student stu4;
//	return 0;
//}

//匿名结构体
//struct
//{
//	char name[20];
//	short age;
//	char sex[5];
//}stu1;
//
//struct
//{
//	char name[20];
//	short age;
//	char sex[5];
//}*ps;
//int main()
//{
//	ps = &stu1;//这样是不合法的，虽然ps和stu1的内容一样，但他俩的类型不同
//}

//结构体自引用
//struct Node
//{
//	int data;//4
//	struct Node* next; //4  //链表的方法
//};
//int main()
//{
//	struct Node n;
//	return 0;
//}

//typedef struct Node
//{
//	int data;//4
//	struct Node* next; //4  不能省去struct
//}Node;
//int main()
//{
//	struct Node n;
//	return 0;
//}


//结构体内存对齐  very important!!!!!!
//#include<stddef.h>//offsetof的头文件
//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
////struct S2
////{
////	char c1;
////	char c2;
////	int i;
////};
//struct S3
//{
//	double d;//8
//	char c;//1
//	int i;//4    最后算出结构体总大小为16
//};
//struct S4
//{
//	char c1;//0
//	//1-7
//	struct S3 s3;//8-23  嵌套结构体到对齐到自己最大对齐数的整数倍处
//	double d;//24-31
//};
//int main()
//{
//	printf("%d\n", sizeof(struct S3));//16
//	printf("%d\n", sizeof(struct S4));//32
//	//struct S1 s1 = { 0 };
//	//rintf("%d\n", offsetof(struct S2, c1));//0   offsetof代表  相对于起始位置的偏移量
//	//printf("%d\n", offsetof(struct S2, c2));//1
//	//printf("%d\n", offsetof(struct S2, i));//4
//	//struct S1 s1 = { 0 };
//	//struct S2 s2 = { 0 };
//	//printf("%d\n", sizeof(struct S1));//12    //两种打印方式都一样
//	//printf("%d\n", sizeof(s1));
//	//printf("%d\n", sizeof(struct S2));//8
//	//printf("%d\n", sizeof(s2));
//	system("pause");
//	return 0;
//}
//结构体内存对齐的规则    要牢牢掌握
//1.第一个成员永远都放在结构体起始位置的0偏移处
//2.从第二个成员开始，每个成员都放在某个对齐数的整数倍的偏移处
//这个对齐数：成员自身的大小和默认对齐数的较小值
//默认对齐数：	VS环境下:8   Linux gcc：4
//3.结构体的总大小必须是所有成员对齐数中最大对齐数的整数倍
//4.如果结构体中嵌套结构体，
//嵌套结构体要对齐到自身最大对齐数的整数倍，
//结构体的总大小是所有对齐数（包含嵌套结构的对齐数）中最大对齐数的整数倍

//对其原因：提高效率

//节省空间的方法：把小的放在一起


//实现宏offsetof的方法（计算结构体的偏移量）
//#include<stddef.h>
//struct S
//{
//	char c;
//	int i;
//};
//int main()
//{
//	printf("%d\n", offsetof(struct S, c));
//	printf("%d\n", offsetof(struct S, i));
//	system("pause");
//	return 0;
//}
//
////修改默认对齐数
//#pragma pack(4)//将默认对齐数改为4
//struct S
//{
//	double d;//0-7
//	char c;//8
//};
//#pragma pack()//没写数字代表修改取消
//int main()
//{
//	printf("%d\n", sizeof(struct S));//12
//	return 0;
//}
////#pragma pack(1) 代表没有对齐，0偏移量
//
//
//结构体传参（传地址）（传结构体）




位段(成员必须是整型) char也属于整型家族
struct S
{
	int _a : 2;//代表a占两个字节,一个字节八个比特位
	int _b : 5;
	int _c : 10;
	int _d : 30;
};
int main()
{
	printf("%d\n", sizeof(struct S));
	system("pause");
	return 0;
}
位段的内存分配
1.位段的成员可以是int，unsigned int或者signed int或者是char（属于整型家族）类型
2.位段的空间上是需要以4个字节（int）或者1个字节（char）的方式来开辟的
3.位段涉及很多不确定因素，位段是不跨平台的，注重可移植的程序应该避免使用位段
struct S
{
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
};
int main()
{
	struct S s = { 0 };  //very important!!!
	//printf("%d\n", sizeof(struct S));//3
	s.a = 10;
	s.b = 12;
	s.c = 3;
	s.d = 4;
	return 0;
}


//枚举
//和define的区别  #define 不能调试
enum Day
{
	Mon = 1,//0
	Tues,//1
	Wed,//2
	Thur,
	Fri,
	Sat,
	Sun
};
int main()
{
	enum Day day = Mon;//初始化只能赋已有成员
	day = Tues;
	printf("%d\n", Mon);
	printf("%d\n", Tues);
	printf("%d\n", Wed);
	printf("%d\n", Thur);
	return 0;
}
//为什么要用枚举替换#define
//1.增加代码的可读性和可维护性
//2.和#define定义的标识符比较枚举有类型检查，更加严谨
//3.防止了命名污染
//4.便于调试，#define不可调试
//5.使用方便，一次可以定义多个常量



//联合
union Un
{
	char i;//成员共用一个空间
	int c;
	double d;
};
int main()
{
	union Un u = { 0 };
	printf("%d\n", sizeof(union Un));//8
	printf("%p\n", &(u.c));
	printf("%p\n", &(u.i));
	printf("%p\n", &(u.d));
	return 0;
}
//判断机器的大小端
//普通方式
int check_sys()
{
	int a = 1;
	return *(char*)&a;
}
int main()
{
	int ret = check_sys();
	if (ret == 1)
	{
		printf("小端");
	}
	else
		printf("大端");
	return 0;
}

//联合的方式判断
int check_sys()
{
	union Un
	{
		char c;
		int i;
	}u;
	u.i = 1;
	//返回1，小端
	//返回0，大端
	return u.c;//取出第一个字节，类似于普通方法
}
int main()
{
	int ret = check_sys();
	if (ret == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}

//求联合的大小
union Un
{
	char c;
	int i;
};
union Un2
{
	short c[7];//short两个字节
	int i;
};
int main()
{
	printf("%d\n", sizeof(union Un));//8
	printf("%d\n", sizeof(union Un2));//16
	return 0;
}
//联合存在对齐
//联合的大小至少是最大成员的大小
//当最大成员不是最大对齐数的整数倍时，就要对齐到最大对齐数的整数倍处








