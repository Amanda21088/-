#define _CRT_SECURE_NO_WARNINGS 1
void AjustDown(int* a, int root, int n)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (a[child] < a[child + 1] && child + 1 < n)
			++child;
		if (a[child] > a[parent])
		{
			int tmp = parent;
			parent = a[child];
			a[child] = tmp;

			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapSort(int* a, int root, int n)
{
	//½¨´ó¶Ñ
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AjustDown(a, i, n);
	}

	int end = n;
	for (int i = end; i >= 0; i--)
	{
		swap(a[0], a[end]);
		AjustDown(a, 0, i);
	}
}

