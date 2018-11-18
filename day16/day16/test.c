#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>
//函数的模拟实现
//strcpy 字符串的复制
//char* my_strcpy(char*dest, const char*src)
//{
//	char* ret = dest;
//	assert(src != NULL);
//	assert(dest != NULL);
//	while (src != '\0')
//	{
//		*dest++ = *src++;
//	}
//	*dest = '\0';
//	return ret;
//}
//int main()
//{
//	char a[] = "abcd";
//	char b[] = "defg";
//	my_strcpy(a, b);
//	printf("%s\n", my_strcpy(a, b));
//	system("pause");
//	return 0;
//}

//strcat的模拟实现
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char *ret = dest;
//	//找\0
//	while (*dest != '\0')
//	{
//		*dest++;
//	}
//	while (*src != '\0')
//	{
//		*dest++ = *src++;
//	}
//	*dest = '\0';
//	return ret;
//
//}
//int main()
//{
//	char a[] = "abcd";
//	char b[] = "efgh";
//	printf("%s\n", my_strcat(a, b));
//	system("pause");
//	return 0;
//}

//strstr的模拟实现
//char* my_strstr(const char*dest, char*src)
//{
//	assert(dest != NULL);
//	while (*dest != '\0')
//	{
//		if (*dest == *src)
//		{
//			return dest;
//		}
//		dest++;
//	}
//}
//int main()
//{
//	char a[] = "abcdefgh";
//	char b[] = "cd";
//	printf("%s\n", my_strchr(a, b));
//	system("pause");
//	return 0;
//}


//strcmp的模拟实现
//int my_strcmp(const char*s1, const char*s2)
//{
//	assert(s1 != NULL);
//	assert(s2 != NULL);
//	while (*s1 == *s2)
//	{
//		if (*s1 == *s2)
//		{
//			return 0;
//		}
//		s1++;
//		s2++;
//	}
//	if (*s1 > *s2)
//	{
//		return 1;
//	}
//	else
//		return -1;
//}
//int main()
//{
//	char a[] = "abcdefgh";
//	char b[] = "f";
//	int ret = my_strcmp(a, b);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

//memcpy的模拟实现(记住他的参数)
//void my_memcpy(void *dest, const void*src, int count)//count代表字节
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	void* ret = dest;
//	while (count--)
//	{
//		*((char *)dest)++ = *((char *)src)++;
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[20] = { 0 };
//	int arr2[] = { 1, 2, 3, 4, 5 };
//	my_memcpy(arr1, arr2, 12);
//	for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
//	{
//		printf("%d\n", arr1[i]);
//	}
//	system("pause");
//	return 0;
//}

//memmove的模拟实现
void my_memmove(void *dest, const void*src, int count)
{
		assert(dest != NULL);
		assert(src != NULL);
		void* ret = dest;
		return ret;
	if (dest < src)
	{
		while (count--)
		{
			*((char *)dest)++ = *((char *)src)++;
		}

		//前-->后
	}
	else
	{
		while (count--)
		{
			*((char*)dest + count) = *((char*)src + count);
		}
		//后-->前
	}
	return ret;
}
int main()
{
	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	my_memmove(arr1+2,arr1,16);
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr1[i]);
	}
	system("pause");
	return 0;
}