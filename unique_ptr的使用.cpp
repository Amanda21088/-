#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
//C++11
//unique_ptr:简单粗暴，防拷贝。效率高，鼓励公司使用
namespace juju
{
	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}
		~unique_ptr()
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
		unique_ptr(const unique_ptr<T>& ap) = delete;//将拷贝构造和赋值都禁止掉
		unique_ptr<T>&operator=(const unique_ptr<T>& ap) = delete;


	private:
		T* _ptr;
	};
}void test_unique_ptr()
{
	juju::unique_ptr<int> ap1(new int);
}

int main()
{
	test_unique_ptr();
	system("pause");
	return 0;
}
