#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	//abcd12345ed125ss123456789
	string s;//Ҫ������ַ���
	string cur;//����������Ǹ����ִ�
	string tmp;//��ÿһ���������ַ���

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
