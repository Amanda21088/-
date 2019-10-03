#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//(1)���캯��˽�л�
//(2)�ṩһ��ȫ�ֵľ�̬������ȫ�ַ��ʵ㣩
//(3)�����ж���һ����ָ̬�룬ָ����ı����ľ�̬����ָ��

class Singelton
{
private:
	Singelton()
	{
		cout << "���캯��" << endl;
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
Singelton* Singelton::p_single = NULL;//��̬������ԱҪ�������ʼ��