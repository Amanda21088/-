#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string line;
	//��Ҫʹ��cin>>line,��Ϊ�������ո�ͽ�����
	//while(cin>>line)
	while (getline(cin, line))
	{
		size_t pos = line.rfind(' ');
		cout << line.size() - pos - 1 << endl;
	}

	return 0;
}


class Solution
{
public:
	bool IsNumberOrLetter(char c)
	{
		if (c >= '0' && c <= '9' ||
			c >= 'a' && c <= 'z' ||
			c >= 'A' && c <= 'Z')
		{
			return true;
		}
		return false;
	}
	bool isPalindrome(string s)
	{
		if (s.empty())
		{
			return true;
		}
		int begin = 0;
		int end = s.size() - 1;
		char* p = (char*)s.c_str();
		// ��ǰ������һ�������ַ�������ĸ
		while (begin < end)
		{
			while (begin != end)
			{
				if (IsNumberOrLetter(s[begin]))
					break;
				++begin;
			}
			// �Ӻ���ǰ��һ�������ַ�������ĸ
			while (begin < end)
			{
				if (IsNumberOrLetter(s[end]))
					break;
				--end;
			}

			if (begin < end)
			{
				// ���start��endλ���ַ��Ƿ���� �����Ƿ����ִ�С����� 
				if ((s[begin] + 32 - 'a') % 32 != (s[end] + 32 - 'a') % 32)
					return false;
				++begin;
				--end;
			}
		}
	};
}