#define _CRT_SECURE_NO_WARNINGS 1
class A
{
public:
	A()
	{
		++_count;
	}
	A(const A& t)
	{
		++_count;
	}
	static int GetACount()
	{
		return _count;
	}
private:
	static int _count;
};
int A::_count = 0;

void TestA()
{
	cout << A::GetACount() << endl;
	A a1, a2;
	A a3(a1);
	cout << A::GetACount() << endl;
}