

#define _CRT_SECURE_NO_WARNINGS 1

}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char psw[10] = "";
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		printf("please input:");
		scanf("%s", &psw);
		if (strcmp(psw, "password") == 0)//条件成立
			break;
	}
	if (i == 3)
	{
		printf("exit\n");
	}
	else
	{
		printf("log in\n");
	}
	system("pause");
	return 0;
}
