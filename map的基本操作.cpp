#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;
//mulimap��map������
//(1)mulimap����key���࣬����map������key����
//(2)mulimapû��operator[],����map��
////дһ��pair�ľ���ṹ��������
//template<class K, class V)//��(1���ֵĽṹ
//struct pair
//{
//	K first;
//	V second;
//};
////дһ��make_pair�ľ���ṹ��������
//template<class K, class V>//��(2���ֵĽṹ
//inline std::pair(K, V) make_pair(const K& k, const V& v)
//{
//	return std::pair<K, V>(k, v);
//}

void test_map()
{
	//key/value.ͨ���ؼ��ֲ���ӳ�������Ϣvalue
	map<string, string> m;

	//pair��һ���ṹ�壬�����first(K)��second(V)
	m.insert(std::pair<string, string>("sort", "����"));//(1)
	m.insert(std::pair<string, string>("string", "�ַ���"));
	//�����ϱ���һ�󴮣��Ƕ�ô���Ӱ����м򵥵�д���𣿿��±�
	m.insert(make_pair("sort", "����"));//����ģ��(2) �������Ǹ��������Լ���������
	//Ҳ�����������룬����operator[]
	m["pair"];
	m["key"] = "�ؼ���";

	std::map<string, string>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << (*it).first << " :" << (*it).second << endl;
		++it;
	}
	cout << endl;

	string strs[] = { "ƻ��", "ƻ��", "����", "�㽶", "ƻ��", "����", "ƻ��" };
	//ͳ��ˮ�����ֵĴ���
	//��һ��ͳ�Ƶķ���
	//map<string, int> countmap;//����һ���յ�����
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
	//�ڶ���ͳ�Ƶķ���
	map<string, int> countmap;
	for (const auto& str : strs)
	{
		countmap[str]++;//operator[]
	}

	//������ͳ�Ƶķ���
	for (const auto& str : strs)
	{
		auto ret = countmap.insert(make_pair(str, 1));
		if (ret.second == false)//�������ʧ�ܣ���֤��countmap���������
		{
			ret.first->second++;
		}
	}
	map<string, int>::iterator cit = countmap.begin();
	while (cit != countmap.end())//key���ǰ�����ĸ��acll���ŵ�
	{
		cout << cit->first << " :" << cit->second << endl;
		cit++;
	}
	cout << endl;
	//��auto����(ѧ���������
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
