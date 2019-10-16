#define _CRT_SECURE_NO_WARNINGS 1
//命令行第三个参数
#include<stdio.h>

int main(int argc, char *argv[], char* env[])
{
	int i = 0; 
	for (; env[i]; i++)
	{
		printf("%s\n", env[i]);
	}
	return 0;
}

//通过第三方变量environ获取
#include<stdio.h>

int main(int argc, char* argv[])
{
	//extern表示外部函数和外部变量
	extern char **environ;
	int i = 0;
	for (; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}

	return 0;
}