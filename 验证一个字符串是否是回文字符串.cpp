#define _CRT_SECURE_NO_WARNINGS 1
class Solution
{
public:
	bool isPalindrome(string s)
	{
		if (s.empty())
		{
			return true;
		}
		int begin = 0;
		int end = s.size() - 1;
		char* p = (char*)s.c_str();
		// 从前往后找一个数字字符或者字母
		while (begin < end)
		{
			while (begin != end)
			{
				if (IsNumberOrLetter(s[begin]))
					break;
				++begin;
			}
			// 从后往前找一个数字字符或者字母
			while (begin < end)
			{
				if (IsNumberOrLetter(s[end]))
					break;
				--end;
			}

			if (begin < end)
			{
				// 检测start和end位置字符是否相等 或者是否不区分大小的相等 
				if ((s[begin] + 32 - 'a') % 32 != (s[end] + 32 - 'a') % 32)
					return false;
				++begin;
				--end;
			}
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
		};