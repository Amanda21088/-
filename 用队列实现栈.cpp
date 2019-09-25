#define _CRT_SECURE_NO_WARNINGS 1
class Mystack {
public:
	queue<int> q;
	//压栈是一样的
	void push(int x)
	{
		q.push(x);
	}
	
	//移除栈顶元素
	int pop()
	{
		int size = q.size() - 1;
		for (int i = 0; i < size; i++)
		{
			int tmp = q.front();
			q.pop();
			q.push(tmp);//将移出来的元素继续放在队列的队尾
		}
		int d = q.front();//这个数字就是栈顶元素
		q.pop();
		return d;
	}

	//获取栈顶元素
	int top()
	{
		int size = q.size() - 1;
		for (int i = 0; i < size; i++)
		{
			int tmp = q.front();
			q.pop();
			q.push(tmp);//将移出来的元素继续放在队列的队尾
		}
		int d = q.front();//这个数字就是栈顶元素
		q.pop();
		q.push(d);//只是获取栈顶元素，并不需要删除
		return d;//返回栈顶元素
	}

	//判断栈是否为空
	bool empty()
	{
		if (!q.empty())
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};
