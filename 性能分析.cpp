#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<time.h>
using namespace std;
  //����+ȥ��
void test_unordered_set()
{
	unordered_set<int> us;
	us.insert(4);
	us.insert(8);
	us.insert(4);
	us.insert(3);
	us.insert(4);
	us.insert(2);
	us.insert(5);
	us.insert(1);
	unordered_set<int>::iterator it = us.begin();
	while (it != us.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	for (auto e : us)
	{
		cout << e << " ";
	} cout << endl;
	auto ret = us.find(5);
	if (ret != us.end())
	{
		cout << "�ҵ���";
	}
}
void test_unordered_map()
{
	unordered_map<string, string> um;
	um.insert(make_pair("sort", "����"));
	um.insert(make_pair("string", "�ַ���"));
	um.insert(make_pair("left", "���"));
	um.insert(make_pair("left", "ʣ��"));//�������ʧ�ܣ�key�����ظ�
	um["insert"];
	um["insert"] = "����";

	unordered_map<string, string>::iterator it = um.begin();
	while (it != um.end())
	{
		cout << it->first << ": " << it->second << endl;
		it++;
	}
	cout << endl;
	for (const auto e : um)
	{
		cout << e.first << ": " << e.second << endl;
	}
	cout << endl;

}
void test_op()//���ܷ���
{
	set<int> s;
	unordered_set<int> us;

	srand(time(0));
	vector<int> v;
	const size_t n = 10000000;
	v.reserve(n);
	for (size_t i = 0; i < 10000000; i++)
	{
		v.push_back(rand());
	}
	//insert������
	size_t begin1 = clock();
	for (size_t i = 0; i < v.size(); i++)
	{
		s.insert(v[i]);
	}
	size_t end1 = clock();

	size_t begin2 = clock();
	for (size_t i = 0; i < v.size(); i++)
	{
		us.insert(v[i]);
	}
	size_t end2 = clock();

	cout <<"set insert:" << end1 - begin1 << endl;
	cout << "unordered_set insert:" << end2 - begin2 << endl;

	//find������
	begin1 = clock();
	for (size_t i = 0; i < v.size(); i++)
	{
		s.find(rand());
	}
	end1 = clock();

	begin2 = clock();
	for (size_t i = 0; i < v.size(); i++)
	{
		us.find(rand());
	}
	end2 = clock();

	cout << "set find:" << end1 - begin1 << endl;
	cout << "unordered_set find: "<< end2 - begin2 << endl;

	//erase������
	begin1 = clock();
	for (size_t i = 0; i < v.size(); i++)
	{
		s.erase(rand());
	}
	end1 = clock();

	begin2 = clock();
	for (size_t i = 0; i < v.size(); i++)
	{
		us.erase(rand());
	}
	end2 = clock();

	cout << "set erase:" << end1 - begin1 << endl;
	cout << "unordered_set erase: " << end2 - begin2 << endl;
}
int main()
{
	//test_unordered_set();
	//test_unordered_map();
	test_op();
	system("pause");
	return 0;
}