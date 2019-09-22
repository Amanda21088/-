#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	//实现删除v中所有偶数
	//下面的程序会崩溃，如果是偶数。erase导致it失效
	//对失效的迭代器进行++it，会导致程序崩溃
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			v.erase(it);
		}
		++it;
	}

	//以上程序要改成下面那样，erase会返回删除位置的下一个位置
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			it = v.erase(it);
		}
		else
		{
			++it;
		}
	}
	return 0;
}