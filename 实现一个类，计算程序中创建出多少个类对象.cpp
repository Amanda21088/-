#define _CRT_SECURE_NO_WARNINGS 1
#include <Winsock2.h>
#include <stdio.h>
int main()
{
	//ԭ�ͣ�in_addr_t inet_addr(const char *cp);
	//�������ַ�����һ�����ʮ���Ƶ�IP��ַ
	//�����ȷִ�н�����һ���޷��ų��������������������ַ�������һ���Ϸ���IP��ַ��������INADDR_NONE��
	in_addr ipAddr;
	ipAddr.S_un.S_addr = inet_addr("127.0.0.1"); //���ַ�����ʽ��IP��ַת��Ϊ�������ֽ�˳�������ֵ
	printf("\n%u", ipAddr.S_un);
	system("pause");
	return 0;
}