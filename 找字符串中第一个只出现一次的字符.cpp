#define _CRT_SECURE_NO_WARNINGS 1
class Solution{
public:
	//统计每个字符出现的次数
	int firstUniqChar(string s)
	{
		int count[256] = { 0 };
		int size = s.size();
		for (int i = 0; i < size(); i++)
		{
			count[s[i]] += 1;
		}
	}
	//遍历，查找出现一次的字符
	for (inti = 0; i < size; i++)
	{
		if (1 == count[s[i]])
			return i;
	}
	return -1;
};