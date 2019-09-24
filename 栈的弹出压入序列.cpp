#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.empty() || popV.empty() || pushV.size() != popV.size())
			return false;
		stack<int> s;
		for (int i = 0, j = 0; i < pushV.size(); i++)
		{
			s.push(pushV[i]);
			while (!s.empty() && s.top() == popV[j])//while循环这的括号不能少啊，我都崩溃了
			{
				s.pop();
				j++;
			}
		}
		if (s.empty())
			return true;
		else
			return false;
	}
};
