#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string line;
	//不要用cin>>line,因为cin遇到空格就结束了
	//即while(cin >> line)
	while (getline(line))
	{
		size_t pos = line.rfind(" ");
		cout << line.size() - 1 - pos << endl;
	}
	return 0;
}