#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

//strncpy��ģ��ʵ��

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

//strncat��ģ��ʵ��

char* my_strncat(char*dest, const char*src, int num)
{
	char*ret = dest;//�����������assertǰ��
	assert(src != NULL);
	assert(dest != NULL);
	
	//��\0
	while (*dest != '\0')//ע�⣡��������������destǰ��*
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

//strncmp��ģ��ʵ��
 
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