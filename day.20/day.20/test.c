#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//11.11.2

//int 
//float
//��������
//�Զ������ͣ��ṹ�壬ö�٣�����
//struct Student
//{
//	char name[20];
//	short age;
//	char sex[5];
//}stu1��stu2��stu3;
//int main()
//{
//	struct Student stu4;
//	return 0;
//}

//�����ṹ��
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
//	ps = &stu1;//�����ǲ��Ϸ��ģ���Ȼps��stu1������һ���������������Ͳ�ͬ
//}

//�ṹ��������
//struct Node
//{
//	int data;//4
//	struct Node* next; //4  //����ķ���
//};
//int main()
//{
//	struct Node n;
//	return 0;
//}

//typedef struct Node
//{
//	int data;//4
//	struct Node* next; //4  ����ʡȥstruct
//}Node;
//int main()
//{
//	struct Node n;
//	return 0;
//}


//�ṹ���ڴ����  very important!!!!!!
//#include<stddef.h>//offsetof��ͷ�ļ�
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
//	int i;//4    �������ṹ���ܴ�СΪ16
//};
//struct S4
//{
//	char c1;//0
//	//1-7
//	struct S3 s3;//8-23  Ƕ�׽ṹ�嵽���뵽�Լ�������������������
//	double d;//24-31
//};
//int main()
//{
//	printf("%d\n", sizeof(struct S3));//16
//	printf("%d\n", sizeof(struct S4));//32
//	//struct S1 s1 = { 0 };
//	//rintf("%d\n", offsetof(struct S2, c1));//0   offsetof����  �������ʼλ�õ�ƫ����
//	//printf("%d\n", offsetof(struct S2, c2));//1
//	//printf("%d\n", offsetof(struct S2, i));//4
//	//struct S1 s1 = { 0 };
//	//struct S2 s2 = { 0 };
//	//printf("%d\n", sizeof(struct S1));//12    //���ִ�ӡ��ʽ��һ��
//	//printf("%d\n", sizeof(s1));
//	//printf("%d\n", sizeof(struct S2));//8
//	//printf("%d\n", sizeof(s2));
//	system("pause");
//	return 0;
//}
//�ṹ���ڴ����Ĺ���    Ҫ��������
//1.��һ����Ա��Զ�����ڽṹ����ʼλ�õ�0ƫ�ƴ�
//2.�ӵڶ�����Ա��ʼ��ÿ����Ա������ĳ������������������ƫ�ƴ�
//�������������Ա����Ĵ�С��Ĭ�϶������Ľ�Сֵ
//Ĭ�϶�������	VS������:8   Linux gcc��4
//3.�ṹ����ܴ�С���������г�Ա������������������������
//4.����ṹ����Ƕ�׽ṹ�壬
//Ƕ�׽ṹ��Ҫ���뵽����������������������
//�ṹ����ܴ�С�����ж�����������Ƕ�׽ṹ�Ķ�������������������������

//����ԭ�����Ч��

//��ʡ�ռ�ķ�������С�ķ���һ��


//ʵ�ֺ�offsetof�ķ���������ṹ���ƫ������
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
////�޸�Ĭ�϶�����
//#pragma pack(4)//��Ĭ�϶�������Ϊ4
//struct S
//{
//	double d;//0-7
//	char c;//8
//};
//#pragma pack()//ûд���ִ����޸�ȡ��
//int main()
//{
//	printf("%d\n", sizeof(struct S));//12
//	return 0;
//}
////#pragma pack(1) ����û�ж��룬0ƫ����
//
//
//�ṹ�崫�Σ�����ַ�������ṹ�壩




λ��(��Ա����������) charҲ�������ͼ���
struct S
{
	int _a : 2;//����aռ�����ֽ�,һ���ֽڰ˸�����λ
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
λ�ε��ڴ����
1.λ�εĳ�Ա������int��unsigned int����signed int������char���������ͼ��壩����
2.λ�εĿռ�������Ҫ��4���ֽڣ�int������1���ֽڣ�char���ķ�ʽ�����ٵ�
3.λ���漰�ܶ಻ȷ�����أ�λ���ǲ���ƽ̨�ģ�ע�ؿ���ֲ�ĳ���Ӧ�ñ���ʹ��λ��
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


//ö��
//��define������  #define ���ܵ���
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
	enum Day day = Mon;//��ʼ��ֻ�ܸ����г�Ա
	day = Tues;
	printf("%d\n", Mon);
	printf("%d\n", Tues);
	printf("%d\n", Wed);
	printf("%d\n", Thur);
	return 0;
}
//ΪʲôҪ��ö���滻#define
//1.���Ӵ���Ŀɶ��ԺͿ�ά����
//2.��#define����ı�ʶ���Ƚ�ö�������ͼ�飬�����Ͻ�
//3.��ֹ��������Ⱦ
//4.���ڵ��ԣ�#define���ɵ���
//5.ʹ�÷��㣬һ�ο��Զ���������



//����
union Un
{
	char i;//��Ա����һ���ռ�
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
//�жϻ����Ĵ�С��
//��ͨ��ʽ
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
		printf("С��");
	}
	else
		printf("���");
	return 0;
}

//���ϵķ�ʽ�ж�
int check_sys()
{
	union Un
	{
		char c;
		int i;
	}u;
	u.i = 1;
	//����1��С��
	//����0�����
	return u.c;//ȡ����һ���ֽڣ���������ͨ����
}
int main()
{
	int ret = check_sys();
	if (ret == 1)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
	return 0;
}

//�����ϵĴ�С
union Un
{
	char c;
	int i;
};
union Un2
{
	short c[7];//short�����ֽ�
	int i;
};
int main()
{
	printf("%d\n", sizeof(union Un));//8
	printf("%d\n", sizeof(union Un2));//16
	return 0;
}
//���ϴ��ڶ���
//���ϵĴ�С����������Ա�Ĵ�С
//������Ա��������������������ʱ����Ҫ���뵽������������������








