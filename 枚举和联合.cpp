#define _CRT_SECURE_NO_WARNINGS 1
//λ��
struct S
{
	int _a : 2;//**����aռ�����ֽ�,һ���ֽڰ˸�����λ**
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
	enum Day day = Mon; **//��ʼ��ֻ�ܸ����г�Ա**
		day = Tues;
	printf("%d\n", Mon);
	printf("%d\n", Tues);
	printf("%d\n", Wed);
	printf("%d\n", Thur);
	return 0;
}

