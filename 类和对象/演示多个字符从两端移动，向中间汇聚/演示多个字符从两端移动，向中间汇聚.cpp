

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
int main()
{
	char arr1[] = "i love xiaoweixiang";
	char arr2[] = "###################";
	int left = 0;
	int right = strlen(arr1) - 1;
	printf("%s\n", arr2);
	//whileѭ��ʵ��
	while (left <= right)
	{
	Sleep(1000);
	arr2[left] = arr1[left];
	arr2[right] = arr1[right];
	left++;
	right--;
	printf("%s\n", arr2);
	}
	//forѭ��ʵ��
	for (left = 0, right = strlen(arr1) - 1; left <= right; left++, right--)
	{
		Sleep(1000);
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s\n", arr2);
	}
	system("pause");
	return 0;

}
