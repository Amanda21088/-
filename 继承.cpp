#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string.h>

using namespace std;

class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name = "juju";//����
	int _age = 21;
};

class Student : public Person
{
protected:
	int _stuid;//ѧ��
};

class Teacher : public Person
{
protected:
	int _jobid; // ���� 
};

int main()
{
	Student s;
	Teacher t;
	s.Print();
	t.Print();

	system("pause");
	return 0;
}
