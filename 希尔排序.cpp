#define _CRT_SECURE_NO_WARNINGS 1
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			if (a[i] > a[i + gap])
			{
				int tmp = a[i];
				a[i] = a[i + gap];
				a[i + gap] = tmp;
			}
		}
	}
}

