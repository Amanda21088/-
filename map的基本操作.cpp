#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;
//mulimap与map的区别
//(1)mulimap允许key冗余，但是map不允许key冗余
//(2)mulimap没有operator[],但是map有
////写一下pair的具体结构是怎样的
//template<class K, class V)//第(1）种的结构
//struct pair
//{
//	K first;
//	V second;
//};
////写一下make_pair的具体结构是怎样的
//template<class K, class V>//第(2）种的结构
//inline std::pair(K, V) make_pair(const K& k, const V& v)
//{
//	return std::pair<K, V>(k, v);
//}

void test_map()
{
	//key/value.通过关键字查找映射关联信息value
	map<string, string> m;

	//pair是一个结构体，里边有first(K)和second(V)
	m.insert(std::pair<string, string>("sort", "排序"));//(1)
	m.insert(std::pair<string, string>("string", "字符串"));
	//看看上边那一大串，是多么复杂啊，有简单的写法吗？看下边
	m.insert(make_pair("sort", "排序"));//函数模板(2) 调上面那个函数，自己推演类型
	//也可以这样插入，利用operator[]
	m["pair"];
	m["key"] = "关键字";

	std::map<string, string>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << (*it).first << " :" << (*it).second << endl;
		++it;
	}
	cout << endl;

	string strs[] = { "苹果", "苹果", "西瓜", "香蕉", "苹果", "西瓜", "苹果" };
	//统计水果出现的次数
	//第一种统计的方法
	//map<string, int> countmap;//这是一个空的容器
	//for (const auto& str : strs)
	//{
	//	auto it = countmap.find(str);
	//	if (it != countmap.end())
	//	{
	//		it->second++;
	//	}
	//	else
	//	{
	//		countmap.insert(std::make_pair(str, 1));
	//	}
	//}
	//第二种统计的方法
	map<string, int> countmap;
	for (const auto& str : strs)
	{
		countmap[str]++;//operator[]
	}

	//第三种统计的方法
	for (const auto& str : strs)
	{
		auto ret = countmap.insert(make_pair(str, 1));
		if (ret.second == false)//假如插入失败，就证明countmap中有这个了
		{
			ret.first->second++;
		}
	}
	map<string, int>::iterator cit = countmap.begin();
	while (cit != countmap.end())//key还是按照字母的acll码排的
	{
		cout << cit->first << " :" << cit->second << endl;
		cit++;
	}
	cout << endl;
	//用auto遍历(学会用这个）
	for (auto& kv : countmap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
}
int main()
{
	test_map();
	system("pause");
	return 0;
}
