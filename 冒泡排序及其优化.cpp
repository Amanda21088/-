#define _CRT_SECURE_NO_WARNINGS 1
void BubbleSort(int* a, int n)
{
	int flag = 0;//”≈ªØ
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}


