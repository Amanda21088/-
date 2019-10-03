#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//(1)构造函数私有化
//(2)提供一个全局的静态方法（全局访问点）
//(3)在类中定义一个静态指针，指向本类的变量的静态变量指针

class Singelton
{
private:
	Singelton()
	{
		cout << "构造函数" << endl;
	}
public:
	static Singelton* getInstance()
	{
		if (p_single == NULL)
		{
			p_single = new Singelton;
		}
		return p_single;
	}

	static void freeInstance()
	{
		if (p_single != NULL)
		{
			delete p_single;
			p_single = NULL;
		}
	}
private:
	static Singelton* p_single;
};
Singelton* Singelton::p_single = NULL;//静态函数成员要在类外初始化