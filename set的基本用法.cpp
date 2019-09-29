#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;
void test_set()
{
	//1. key.���ҹؼ����ڲ���
	//2. ���� + ȥ��
	//3. �����޸ģ����˵ײ����������
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
	it = s.find(2);//O(logN) �ײ��Ƕ�����������ֻ��ҪѰ�Ҹ߶ȴξͿ���
	//it = find(s.begin(), s.end(), 5);//O(N) ��������
	if (it != s.end())
	{
		cout << "�ҵ���" << endl;
		s.erase(it);//�еĻ���ɾ��û�еĻ������ͻᱨ��
	}
	s.erase(3);//���������ɾ��û�оͲ��ܣ�һ�������
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	//1. key.���ҹؼ����ڲ���
	//2. ����
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