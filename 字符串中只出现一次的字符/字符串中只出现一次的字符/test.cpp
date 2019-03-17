#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
class Solution
{
public:
	int firstUniqChar(string s)
	{
		//统计每个字符出现的次数
		int count[256] = { 0 };
		int size = s.size();
		for (int i = 0; i < size; i++)
		{
			count[s[i]] += 1;
		}
		//依次查找只出现一次的字符串
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