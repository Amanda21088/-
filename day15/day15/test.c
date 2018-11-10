#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//#include<assert.h>
///*char* my_strcpy(char* dst,char const *src)
//{
//	char*ret = dst;
//	assert(src != NULL);
//	assert(dst != NULL);
//	while (*dst++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char src[] = "abcdefghi";
//	my_strcpy(src, "hello");
//	printf("%s\n", src);
//	system("pause");
//	return 0;
//}
//char* my_strcat(char* dst, char* src)
//{
//	char* ret = dst;
//	assert(dst != NULL);
//	assert(src != NULL);
//	//1.找第一个\0
//	while (*dst != '\0')
//	{
//		dst++;
//	}
//	//2.拷贝
//	while (*dst++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr[20] = "hello";
//	my_strcat(arr, " bit");
//	printf("%s\n", arr);
//	system("pause");
//}

//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 4, 3, 2, 1 };
//	int i = 0; 
//	int j = 0;
//	for (i = 0; i < 10; i++)
//	{
//		int tmp = arr[i];
//		for (j = 0; j < 10; j++)
//		{
//			if ((i != j) && (arr[j] == tmp))
//			{
//				break;
//			}
//			
//		}
//		if (j == 10)
//		{
//			printf("%d ", tmp); 
//		}
//		
//	}
//	system("pause");
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	int money = 20;
//	int sum = money;
//	int empty = money;
//	while (empty > 1)
//	{
//		sum += (empty / 2);
//		empty -= (empty / 2);
//	}
//	printf("总共汽水数：%d\n", sum);
//	return 0;
//}
