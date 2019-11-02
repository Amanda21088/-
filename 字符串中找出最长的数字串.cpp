#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	//abcd12345ed125ss123456789
	string s;//要输入的字符串
	string cur;//存连续最长的那个数字串
	string tmp;//存每一个连续的字符串

	cin >> s;
	int size = s.size();
	for (int i = 0; i <= size; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			cur += s[i];
		}
		else
		{
			if (tmp.size() < cur.size())
			{
				tmp = cur;
			}
			else
			{
				cur.clear();
			}
		}
	}

	cout << tmp;
	system("pause");
	return 0;

}
