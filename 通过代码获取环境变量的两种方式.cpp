#define _CRT_SECURE_NO_WARNINGS 1
//�����е���������
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

//ͨ������������environ��ȡ
#include<stdio.h>

int main(int argc, char* argv[])
{
	//extern��ʾ�ⲿ�������ⲿ����
	extern char **environ;
	int i = 0;
	for (; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}

	return 0;
}