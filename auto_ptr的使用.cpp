#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

//C++98
//1.管理权转移。带有缺陷的早期设计，公司严禁使用他
//2.如果面试官让你写一个智能指针，不要写auto_ptr,因为他本来就是带有缺陷的
namespace juju
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}
		~auto_ptr()
		{
			if (_ptr != nullptr)
			{
				std::cout << "delete:" << _ptr << std::endl;
				delete _ptr;
			}
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		//ap1(ap2)拷贝构造
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;//现对象赋给原对象的时候，原对象指控，处于悬空状态
		}
	private:
		T* _ptr;
	};
}

	void test_auto_ptr()
	{
		juju::auto_ptr<int> ap1(new int);
		juju::auto_ptr<int> ap2(ap1);

		*ap1 = 10;//悬空
		*ap2 = 20;
	}
int main()
{
	test_auto_ptr();
	system("pause");
	return 0;
}