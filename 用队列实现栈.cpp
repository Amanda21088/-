#define _CRT_SECURE_NO_WARNINGS 1
class Mystack {
public:
	queue<int> q;
	//ѹջ��һ����
	void push(int x)
	{
		q.push(x);
	}
	
	//�Ƴ�ջ��Ԫ��
	int pop()
	{
		int size = q.size() - 1;
		for (int i = 0; i < size; i++)
		{
			int tmp = q.front();
			q.pop();
			q.push(tmp);//���Ƴ�����Ԫ�ؼ������ڶ��еĶ�β
		}
		int d = q.front();//������־���ջ��Ԫ��
		q.pop();
		return d;
	}

	//��ȡջ��Ԫ��
	int top()
	{
		int size = q.size() - 1;
		for (int i = 0; i < size; i++)
		{
			int tmp = q.front();
			q.pop();
			q.push(tmp);//���Ƴ�����Ԫ�ؼ������ڶ��еĶ�β
		}
		int d = q.front();//������־���ջ��Ԫ��
		q.pop();
		q.push(d);//ֻ�ǻ�ȡջ��Ԫ�أ�������Ҫɾ��
		return d;//����ջ��Ԫ��
	}

	//�ж�ջ�Ƿ�Ϊ��
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
