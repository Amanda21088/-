#define _CRT_SECURE_NO_WARNINGS 1
// write your code here cpp
//DFS�㷨�������ڻ����㷨
//'.'��Ϊ0��'#'��'@'��Ϊ1���߹���Ҳ��Ϊ1
//����һ��DFSֻҪ�ݹ������������Ҿ���
//��һ��ȫ�ֱ�����¼���
#include<iostream>
#include<string.h>
using namespace std;
int a[20][20] = { 0 };
int count = 0;//��¼�ߵĺ�ɫ��ש�Ĳ���
int m, n;
void dfs(int x, int y)
{
	if (a[x][y] == 1 || x < 0 || x >= m || y < 0 || y >= n)//�ݹ�ı߽�����
		return;//�������������һ����ֱ��return
	//����
	count++;
	a[x][y] = 1;//�߹���·Ҳ��Ϊ1
	dfs(x, y + 1);
	dfs(x, y - 1);
	dfs(x - 1, y);
	dfs(x + 1, y);
}
int main()
{
	while (~scanf("%d %d", &m, &n))//ֻ�����������뷽ʽ��������cin
	{
		getchar();//��getchar��ԭ���ǽ�m��n���ȥ֮����һ������
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
		memset(a, 0, sizeof(a));//ȫ�ֱ�����ʼ��
	}
	return 0;
}
