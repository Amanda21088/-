#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int q, op, x;
	//s1存放插入的数，s2中放最小的值
	stack<int> s1, s2;
	cin >> q;
	while (q--)
	{
		cin >> op;
		if (op == 0)
		{
			cout << s2.top() << endl;
		}
		else if (op == 1)
		{
			cin >> x;
			s1.push(x);
			if (s2.empty() || x < s2.tpo())
			{
				s2.push(x);
			}
		}
		else if (op == 2)
		{
			cout << s1.top() << endl;
			if (s1.top() == s2.top())
			{
				s2.pop();//如果要弹出的元素就是最小栈，两边的栈顶都要pop
			}
			s1.pop();
		}
	}
	return 0;
}