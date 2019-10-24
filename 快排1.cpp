#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int a[100], n;
void quicksort(int left, int right)
{
	int i;//指向第一个数
	int j;//指向最后一个数
	int tmp;//存基准数
	if (left > right)
		return;
	tmp = a[left];
	i = left;
	j = right;
	while (i != j)
	{
		while (i < j && a[j] >= tmp)
		{
			j--;
		}
		while (i < j && a[i] <= tmp)
		{
			i++;
		}
		if (i < j)
		{
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	//最终将基准数归位
	a[left] = a[i];
	a[i] = tmp;
	quicksort(left, i - 1);//继续处理左边的，这里是一个递归的过程
	quicksort(i + 1, right);//继续处理右边的 ，这里是一个递归的过程
}
int main()
{
	int i;
	//读入数据
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	quicksort(1, n); //快速排序调用
	//输出排序后的结果
	for (i = 1; i < n; i++)
		printf("%d ", a[i]);

	system("pause");
	return 0;
}
