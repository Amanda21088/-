#define _CRT_SECURE_NO_WARNINGS 1
class Solution{
public:
	string reverseString(string s)
	{
		if (s.empty())
			return s;

		size_t start = 0;
		size_t end = s.size() - 1;

		while (start < end)
		{
			swap(s[start], s[end]);
			start++;
			end--;
		}
		return s;
	}
};