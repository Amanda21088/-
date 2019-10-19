#define _CRT_SECURE_NO_WARNINGS 1
void SelectSort(int* a, int n)
{
	int min = 0;
	int max = 0;

	for (int i = 0; i<n - 1; i++)
	{
		min = i;

		for (int j = i; j < n - 1; j++)
		{
			if (a[min] > a[j + 1])
			{
				min = j + 1;
			}

		}
		Swap(&a[min], &a[i]);
	}
}

