#define _CRT_SECURE_NO_WARNINGS 1
#include <Winsock2.h>
#include <stdio.h>
int main()
{
	//原型：in_addr_t inet_addr(const char *cp);
	//参数：字符串，一个点分十进制的IP地址
	//如果正确执行将返回一个无符号长整数型数。如果传入的字符串不是一个合法的IP地址，将返回INADDR_NONE。
	in_addr ipAddr;
	ipAddr.S_un.S_addr = inet_addr("127.0.0.1"); //将字符串形式的IP地址转换为按网络字节顺序的整型值
	printf("\n%u", ipAddr.S_un);
	system("pause");
	return 0;
}