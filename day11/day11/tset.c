#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//#define M 10
//int main()
//{
//	int a[M][M] = { 0 };
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < M; i++)
//	{
//		for (j = 0; j < i; j++)
//		{
//			if ((i == j) || (j == 0))
//				a[i][j] = 1;
//			else
//				a[i][j] = a[i-1][j]+a[i-1][j-1];
//			printf("%-2d ", a[i][j]);
//			
//			
//		}
//		printf("\n");
//	}
//	system("pause");
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//	for (a = 1; a <= 5; a++)
//	{
//		for (a = 1; a <= 5; a++)
//		{
//			for (b = 1; b <= 5; b++)
//			{
//				for (c = 1; c <= 5; c++)
//				{
//					for (d = 1; d <= 5; d++)
//					{
//						for (e = 1; e <= 5; e++)
//						{
//							if (((b == 2) + (a == 3) == 1) && ((b == 2) + (e == 4) == 1)
//								&& ((c == 1) + (d == 2) == 1) && ((c == 5) + (d == 3) == 1)
//								&& ((e == 4) + (a == 1) == 1) && (a*b*c*d*e == 120))
//								printf("a = %d,b = %d,c = %d,d = %d,e = %d",a,b,c,d,e);
//							
//						}
//					}
//				}
//			}
//		}
//	}
//	system("pause");
//}

int main()
{
	int A = 0;
	int B = 0;
	int C = 0;
	int D = 0;
	int i = 0;
	int m = 0;
	for (i = 1; i < 5; i++)
	{
		if (i == 1)
		{
			A = 1; C = 1; D = 0; m = 1;
		}
		if (i == 2)
		{
			A = 0; C = 0; D = 0; m = 1;
		}
		if (i == 3)
		{
			A = 0; C = 1; D = 0; m = 0;
		}
		if (i == 4)
		{
			A = 0; C = 0; D = 0; m = 1;
		}
		if (A + B + C + D + m == 1 && m == D)
		{
			printf("A = %d,B = %d,C = %d,D = %d", A, B, C, D);
		}
		
	}
	system("pause");
}