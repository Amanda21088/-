#define _CRT_SECURE_NO_WARNINGS 1
class Solution
{
public:
	int evalRPN(vector<string>& tokens)
	{
		stack<int> s;
		int tmp = 0;
		for (int i = 0; i < tokens.size(); i++)
		{
			if (tokens[i] != '+' && tokens[i] != '-' && tokens[i] != '*' && tokens != '/')
			{
				s.push(atoi(token[i]).c_str());
			}
			else
			{
				switch (token[i])
				case +:
					tmp = s.top();
					s.pop();
					s.push(s.top() + tmp);
				case -:
					tmp = s.top();
					s.pop();
					s.push(s.top() - tmp);
				case *:
					tmp = s.top();
					s.pop();
					s.push(s.top() * tmp);
				case / :
					tmp = s.top();
					s.pop();
					s.push(s.top() / tmp);
			}	
		}
		return s.top();
	}
};