#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>

int Y(int s)
{
	for (int i = 2; i < s; i++)
	{
		if (s % i == 0)
		{
			return 1;
		}
		else
			return 0;
	}

}
int main()
{
	int y;
	int tmp = 0;
	printf("请输入一个数字:\n");
	scanf("%d", &y);
	tmp = Y(y);
	if (1 == tmp)
		printf("是\n");
	else
		printf("不是\n");
	system("pause");
	return 0;
}
