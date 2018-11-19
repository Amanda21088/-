#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

//strncpy的模拟实现

//char* my_strncpy(char* dest, const char*src, int num)
//{
//	assert(src != NULL);
//	char* ret = dest;
//	while (num--)
//	{
//		*dest++ = *src++;
//	}
//	return ret;
//}
//int main()
//{
//	char a[] = "abcd";
//	char b[] = "efgh";
//	int num = 0;
//	char*ret = my_strncpy(a, b, 3);
//	printf("%s\n", ret);
//	system("pause");
//	return 0;
//
//}

//strncat的模拟实现

char* my_strncat(char*dest, const char*src, int num)
{
	char*ret = dest;//定义变量放在assert前面
	assert(src != NULL);
	assert(dest != NULL);
	
	//找\0
	while (*dest != '\0')//注意！！！！别忘记在dest前＋*
	{
		dest++;
	}
	while (num--)
	{
			*dest++ = *src++;
	}
	*dest = '\0';
	return ret;
}
int main()
{
	char a[] = "abcd";
	char b[] = "efgh";
	printf("%s\n", my_strncat(a, b, 3));
	system("pause");
	return 0;
}

//strncmp的模拟实现
 
//int my_strncmp(char*s1, const char*s2, int num)
//{
//	assert(s1 != NULL);
//	assert(s2 != NULL);
//	while (num--)
//	{
//			while (*s1 == *s2)
//			{
//				if (*s1 == *s2)
//				{
//					return 0;
//				}
//				s1++;
//				s2++;
//			}
//			if (*s1 > *s2)
//			{
//				return 1;
//			}
//			else
//				return -1;
//	}
//}
//int main()
//{
//	char a[] = "abcd";
//	char b[] = "abcde";
//	printf("%d\n",strncmp(a, b, 4));
//	system("pause");
//	return 0;
//}