#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//void LeftMove(int n, char* a,int sz)
//{
//	while (n--)
//	{
//		char tmp = a[0];
//		for (int i = 1; i < sz; i++)
//		{
//			a[i - 1] = a[i];
//		}
//		a[sz - 1] = tmp;
//	}
//	printf("%s", a);
//
//}
//int main()
//{
//	char a[] = "ABCDE";
//	printf("%s\n", a[5]);
//	int sz = strlen(a);
//	int n = 0;
//	printf("请输入左旋的位数：\n");
//	scanf("%d", &n);
//	printf("请输出左旋后的字符串：\n");
//	LeftMove(n, a,sz);
//	system("pause");
//	return 0;
//
//}


char left_reverse(char* a,int n,int sz)
{
		while (n--)
		{
			char tmp = a[0];
			for (int i = 1; i < sz; i++)
			{
				a[i - 1] = a[i];
			}
			a[sz - 1] = tmp;
		}

}
char right_reverse(char* b,int n,int sz)
{
	while (n--)
	{
		char tmp = b[sz - 1];
		for (int i = sz-1; i >= 0; i--)
		{
			b[i+1] = b[i];
		}
		b[0] = tmp;
	}
}

int main()
{
	char s1 = "abcde";
	char s2 = "bcdea";
	char s3 = "eabcd";
	int n = 0;
	printf("请输入移动的位数：");
	scanf("%d", &n);
	int sz = strlen(s1);
	if (strcmp((left_reverse(s1, n, sz)), s2) == 0 || strcmp((right_reverse(s1, n, sz)), s3) == 0)
		return 1;
	else
		return 0;
	system("pause");
	return 0;
}