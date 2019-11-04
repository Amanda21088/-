#define _CRT_SECURE_NO_WARNINGS 1
class Point
{
public:
	Point(int x = 0, int y = 0)
		:_x(x)
		, _y(y)
	{}
private:
	int _x;
	int _y;
};

int main()
{
	Point p{ 1, 2 };
	return 0;
}

int main()
{
	const int x = 10;
	const int y = 1024;
	char c1{ x };//可以通过编译
	char c2{ y };//无法通过编译，y的高字节丢失

	return 0;
}

#include<map>
#include<string>
using namespace std;
int main()
{
	short a = 32670;
	short b = 32670;

	// c如果给成short，会造成数据丢失，如果能够让编译器根据a+b的结果推导c的实际类型，就不会存在问题 
	short c = a + b;

	std::map<std::string, std::string> m{ { "apple", "苹果" }, { "banana", "香蕉" } };

	//使用迭代器遍历容器，迭代器类型太繁琐
	std::map<std::string, std::string>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << " " << it->second << endl;
		++it;
	}
}