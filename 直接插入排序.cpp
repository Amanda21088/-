#define _CRT_SECURE_NO_WARNINGS 1
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while ()
		{
			if (tmp > a[end])
			{
				a[end + 1] = a[end];
				end--;

				a[end + 1] = tmp;
			}
			else
				break;
		}
	}
}
