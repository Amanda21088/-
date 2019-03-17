#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
class Solution
{
public:
	int firstUniqChar(string s)
	{
		//ͳ��ÿ���ַ����ֵĴ���
		int count[256] = { 0 };
		int size = s.size();
		for (int i = 0; i < size; i++)
		{
			count[s[i]] += 1;
		}
		//���β���ֻ����һ�ε��ַ���
		for (int i = 0; i < size; i++)
		{
			if (1 == count[s[i]])
				return i;
		}

		return -1;
	}
};

int main()
{
	Solution s;
	char* a = "lee";
	int m = s.firstUniqChar(a);
	cout << m << endl;
	system("pause");
	return 0;
}