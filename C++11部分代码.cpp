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
	char c1{ x };//����ͨ������
	char c2{ y };//�޷�ͨ�����룬y�ĸ��ֽڶ�ʧ

	return 0;
}

#include<map>
#include<string>
using namespace std;
int main()
{
	short a = 32670;
	short b = 32670;

	// c�������short����������ݶ�ʧ������ܹ��ñ���������a+b�Ľ���Ƶ�c��ʵ�����ͣ��Ͳ���������� 
	short c = a + b;

	std::map<std::string, std::string> m{ { "apple", "ƻ��" }, { "banana", "�㽶" } };

	//ʹ�õ�������������������������̫����
	std::map<std::string, std::string>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << " " << it->second << endl;
		++it;
	}
}