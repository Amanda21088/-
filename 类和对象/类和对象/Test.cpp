#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;

//class Date
//{
//public:
//	void Init(int year, int month, int day)//无参的构造函数
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	d1.Init(2019, 1, 15);
//	d1.Print();
//
//	Date d2;
//	d2.Init(2019, 1, 16);
//	d2.Print();
//
//	system("pause");
//	return 0;
//}


//class Date
//{
//public:
//	//无参构造函数
//	Date()
//	{}
//	//带参构造函数
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void TestDate()
//{
//	Date d1;    //调用无参构造函数
//	Date d2(2019, 1, 16);//调用带参的构造函数
//
//	//注意：如果通过无参构造函数创建对象时，对象后面不用跟括号，否则就变成了函数声明
//	//以下代码的函数：声明了d3函数，该函数无参，返回一个日期类型的对象
//	Date d3();
//}



class Date
{
public:
	int Year(int year) const
	{
		if ((year / 4 == 0 && year / 100 != 0) || (year / 400 == 0))
		{
			return 1;//是闰年
		}
		else
		{
			return 0;//不是闰年
		}
	}
	int GetMonthDay(int year, int month) const
	{
		int monthArray[13] = { 0, 31, 28, 31, 30 ,31, 30, 31, 31, 30, 31, 30, 31};
		if (month == 2 && Year(year) == 1)
			return 29;
		else
			return monthArray[month];
	}

	// 四个成员函数
	Date(int year = 2019, int month = 1, int day = 1)
	{
		if (year > 0 &&
			month > 0 && month < 13 &&
			day > 0 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "日期非法" << endl;
		}

	}

	bool operator==(const Date& d) const
	{
		return d._day == this->_day &&
			d._month == this->_month&&
			d._year == this->_year;
	}

	bool operator!=(const Date& d) const
	{
		return d._day != this->_day ||
			d._month != this->_month ||
			d._year != this->_year;
	}

	bool operator>(const Date& d) const
	{
		if (this->_year > d._year)
		{
			return 1;
		}
		else if (this->_year == d._year)
		{
			if (this->_month > d._month)
			{
				return 1;
			}
			else if (this->_month == d._month)
			{
				if (this->_day > d._day)
					return 1;
				else
					return 0;
			}
			else
				return 0;
		}
		else
			return 0;
	}


	bool operator<(const Date& d) const
	{
		if (this->_year < d._year)
		{
			return 1;
		}
		else if (this->_year == d._year)
		{
			if (this->_month < d._month)
			{
				return 1;
			}
			else if (this->_month == d._month)
			{
				if (this->_day < d._day)
					return 1;
				else
					return 0;
			}
			else
				return 0;
		}
		else
			return 0;
	}


	bool operator>=(const Date& d)
	{
		if (*this == d)
		{
			return 1;
		}
		if (this->_year > d._year)
		{
			return 1;
		}
		else if (this->_year == d._year)
		{
			if (this->_month > d._month)
			{
				return 1;
			}
			else if (this->_day == d._day)
			{
				if (this->_day > d._day)
					return 1;
				else
					return 0;
			}
			else
				return 0;
		}
		else
			return 0;

	}

	bool operator<=(const Date& d) const
	{
		if (*this == d)
		{
			return 1;
		}
		if (this->_year < d._year)
		{
			return 1;
		}
		else if (this->_year == d._year)
		{
			if (this->_month < d._month)
			{
				return 1;
			}
			else if (this->_month == d._month)
			{
				if (this->_day < d._day)
					return 1;
				else
					return 0;
			}
			else
				return 0;
		}
		else
			return 0;
	}

	

	//d1 + 10
	Date operator+(int day) const
	{
		Date ret(*this);
		while (ret._day + day > GetMonthDay(ret._year, ret._month))
		{
			day = day - (GetMonthDay(ret._year, ret._month) - ret._day);
			ret._day = 0;
			if (ret._month == 12)
			{
				ret._year++;
				ret._month = 0;
			}
			ret._month++;
		}
		ret._day += day;
		return ret;
	}

	//Date operator+=(int day)
	//{
	//	_day += day;
	//	while (_day > GetMonthDay(_year, _month))
	//	{
	//		day = _day - GetMonthDay(_year, _month);
	//		if (_month == 12)
	//		{
	//			_year++;
	//			_month = 1;
	//		}
	//		else
	//		{
	//			_month++;
	//		}	
	//		_day = day;
	//	}
	//	return* this;

	//}

	Date operator+=(int day)
	{
		while (this->_day + day > GetMonthDay(this->_year, this->_month))
		{
			day = day - (GetMonthDay(this->_year, this->_month) - this->_day);
			this->_day = 0;
			if (this->_month == 12)
			{
				this->_year++;
				this->_month = 0;
			}
			this->_month++;
		}
		this->_day = day;
		return* this;
	}

	Date operator-(int day) const
	{
		Date ret(*this);
		while (ret._day < day)
		{
			day = day - ret._day;
			if (ret._month == 1)
			{
				ret._month = 13;
				ret._year--;
			}
			ret._month--;
			ret._day = GetMonthDay(ret._year, ret._month);
		}
		ret._day -= day;
		return ret; 
	}


	Date operator-=(int day)
	{
		while (this->_day < day)
		{
			day = day - this->_day;
			this->_day = 0;
			if (this->_month == 1)
			{
				this->_month = 13;
				this->_year--;
			}
			this->_month--;
			this->_day = GetMonthDay(this->_year, this->_month);
		}
		this->_day -= day;
		return* this;
	}
	// 前置
	Date operator++()
	{
		if (_month == 12)
		{
			if (_day == GetMonthDay(this->_year, this->_month))
			{
				_year++;
				_month = 1;
				_day = 1;
			}
			else
			{
				_day++;
			}
		}
		else if (_day == GetMonthDay(this->_year, this->_month))
		{
			_month++;
			_day = 1;
		}
		return *this;
	}

	/*Date operator--()
	{
		if (_month == 1)
		{
			if (_day == 1)
			{
				_year--;
				_month = 12;
				_day = GetMonthDay(this->_year, this->_month);
			}
			else
			{
				_day--;
			}
		}
		else if (_day == 1)
		{
			_month--;
			_day = GetMonthDay(_year, _month);
		}
		else
		{
			_day--;
		}
		return*this;
	}*/

	Date operator--()
	{
		if (--_day == 0)
		{
			if (--_month == 0)
			{
				_year--;
				_month = 12;
			}
			_day = GetMonthDay(this->_year, this->_month);
		}
		return *this;
	}

	// 后置
	Date operator++(int)
	{
		Date ret(*this);
		*this += 1;
		return ret;

	}
	Date operator--(int)
	{
		Date ret(*this);
		*this -= 1;
		return ret;
	}

	// d1-d2
	int operator-(const Date& d) const
	{
		Date max = *this;
		Date min = d;
		int flag = 1;
		int day = 0;
		if (*this < d)
		{
			min = *this;
			max = d;
			flag = -1;
		}
		while (max > min)
		{
			day++;
			min++;
		}
		return (day*flag);

	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2019, 1, 15);
	d1.Print();

	Date d2(2019, 12, 17);
	d2.Print();
	
	//cout << (d2 > d1) << endl;
	//cout << (d2 < d1) << endl;
	//cout << (d2 >= d1) << endl;
	//cout << (d2 <= d1) << endl;
	//Date d3 = ++d2;
	//d3.Print();

	Date d4 = (d2--);
	d4.Print();
	d2++.Print();



	system("pause");

	return 0;
}
