#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string line;
	//��Ҫ��cin>>line,��Ϊcin�����ո�ͽ�����
	//��while(cin >> line)
	while (getline(line))
	{
		size_t pos = line.rfind(" ");
		cout << line.size() - 1 - pos << endl;
	}
	return 0;
}