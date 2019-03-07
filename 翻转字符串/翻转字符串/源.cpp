#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	void reverseString(string<char>& s)
	{
		if (s.empty())
		{
			return s;
		}

		size_t start = 0;
		size_t end = s.size() - 1;

		while (start < end)
		{
			s.swap(s[start], s[end]);
			start++;
			end--;
		}
		return s;

	}
};