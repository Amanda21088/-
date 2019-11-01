#define _CRT_SECURE_NO_WARNINGS 1
// write your code here cpp
//DFS算法，类似于回溯算法
//'.'记为0，'#'和'@'记为1，走过的也记为1
//对于一次DFS只要递归它的上下左右就行
//用一个全局变量记录结果
#include<iostream>
#include<string.h>
using namespace std;
int a[20][20] = { 0 };
int count = 0;//记录走的黑色瓷砖的步数
int m, n;
void dfs(int x, int y)
{
	if (a[x][y] == 1 || x < 0 || x >= m || y < 0 || y >= n)//递归的边界条件
		return;//满足上面的任意一个就直接return
	//否则
	count++;
	a[x][y] = 1;//走过的路也置为1
	dfs(x, y + 1);
	dfs(x, y - 1);
	dfs(x - 1, y);
	dfs(x + 1, y);
}
int main()
{
	while (~scanf("%d %d", &m, &n))//只能用这种输入方式，不能用cin
	{
		getchar();//用getchar的原因是将m，n输进去之后还有一个换行
		int x, y;
		char c;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> c;
				if (c == '@')
				{
					x = i;
					y = j;
				}
				else
				{
					if (c == '#')
						a[i][j] = 1;
				}
			}
			getchar();
		}
		dfs(x, y);
		cout << count << endl;
		count = 0;
		memset(a, 0, sizeof(a));//全局变量初始化
	}
	return 0;
}
