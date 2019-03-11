#include<iostream>
using namespace std;
class String

{
public:
	String(const char* str = "")
	{
		if (str == nullptr)
			str = "";

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(nullptr)
	{
		String strTmp(s._str);
		swap(_str, strTmp);
	}

	//�Աȴ�ͳд���ĸ�ֵ���ĸ��ȽϺã�
	String& operator=(String s)
	{
		swap(_str, s._str);
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};