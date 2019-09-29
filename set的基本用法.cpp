#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;
void test_set()
{
	//1. key.查找关键字在不在
	//2. 排序 + 去重
	//3. 不能修改，改了底层的树就乱了
	std::set<int> s;
	s.insert(4);
	s.insert(1);
	s.insert(2);
	s.insert(5);
	s.insert(5);
	s.insert(4);

	std::set<int>::iterator it = s.begin();
	while(it != s.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	it = s.find(2);//O(logN) 底层是二叉搜索树，只需要寻找高度次就可以
	//it = find(s.begin(), s.end(), 5);//O(N) 暴力搜索
	if (it != s.end())
	{
		cout << "找到了" << endl;
		s.erase(it);//有的话就删，没有的话调它就会报错
	}
	s.erase(3);//有这个数就删，没有就不管，一般用这个
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	//1. key.查找关键字在不在
	//2. 排序
	multiset<int> ms;
	ms.insert(3);
	ms.insert(3);
	ms.insert(1);
	ms.insert(2);
	ms.insert(3);
	ms.insert(3);
	ms.insert(4);
	ms.insert(3);
	for (auto e : ms)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	test_set();
	system("pause");
	return 0;
}