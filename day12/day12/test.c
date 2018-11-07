#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//#include<math.h>
//#include<stdlib.h>
//unsigned int reverse_bit(unsigned int m)
//{
//	int i = 0;
//	int arr[32] = { 0 };
//	int sum = 0;
//	for (i = 0; i < 32; i++)
//	{
//		arr[i] = m & 1;
//		m = m >> 1;
//	}
//	for (i = 0; i < 32; i++)
//	{
//		sum += arr[i] * pow(2, 31 - i);
//	}
//	return sum;
//
//}
//int main()
//{
//	unsigned int n = reverse_bit(25);
//	printf("%u\n", n);
//	system("pause");
//	return 0;
//}


//#include<stdio.h>
//int ava(int a, int b)
//{
//	return(a + b) >> 1;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a,&b);
//	ava(a, b);
//	printf("%d\n", ava(a, b));
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int find = 0;
//	int i = 0;
//	int arr[] = { 1, 3, 5, 7, 5, 3, 1 };
//	for (i = 0; i < 7; i++)
//	{
//		find ^= arr[i];
//	}
//	printf("%d\n", find);
//	system("pause");
//	return 0;

int strlen(char* str)
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

void reverse_s(char* start, char* end)
{
	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

void reverse(char* str)
{
	char* left = str;
	char* right = str + strlen(str) - 1;
	char* cur = str;
	reverse_s(left, right);
	//局部逆转
	while (*cur)
	{
		char* start = cur;
		//寻找字串尾点
		while ((*cur != ' ') && (*cur != '\0'))
		{
			cur++;
		}
		reverse_s(start, cur - 1);
		//走到下一个字串的起点
		if (*cur == ' ')
		{
			cur++;
		}
	}
}


int main()
{
	char arr[] = "i am a student";
	//int len = sizeof(arr) / sizeof(arr[0]);
	reverse(arr);
	printf("%s", arr);
	printf("\n");

	system("pause");
	return 0;
}

