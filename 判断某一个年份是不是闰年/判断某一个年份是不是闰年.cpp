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
	printf("������һ������:\n");
	scanf("%d", &y);
	tmp = Y(y);
	if (1 == tmp)
		printf("��\n");
	else
		printf("����\n");
	system("pause");
	return 0;
}
