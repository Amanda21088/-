#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
//C++11
//shared_ptr:功能全，支持拷贝，引用计数。设计复杂，循环引用
namespace juju
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr)
			:_ptr(ptr)
			,_pcount(new int(1))//将它初始化为1
		{}

		~shared_ptr()
		{
			if (--(*_pcount) == 0)
			{
				std::cout << "delete:" << _ptr << std::endl;
				delete _ptr;
				delete _pcount;
			}
		}

		shared_ptr(const shared_ptr<T>& ap)//拷贝构造
			:_ptr(ap._ptr)
			, _pcount(ap._pcount)
		{
			++(*_pcount);
		}

		shared_ptr<T>& operator=(shared_ptr<T> & ap)
		{
			//防止自己给自己赋值
			//if (this != &ap)
			if (_ptr != ap._ptr)//优化同一块空间的赋值
			{
				if (--(*_pcount))//当这块空间只剩最后一个的时候，再去释放他。不能直接释放
				{
					delete _ptr;//不能直接释放，如果第一块空间既有ap1，也有ap2，那你直接释放掉空间，ap2的内存就出问题了
					delete _pcount;
				}
				_ptr = ap._ptr;
				_pcount = ap._pcount;

				++(*_pcount);
			}
			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
		int* _pcount;//不能将它弄成静态，万一在两块空间，其中一块会没被释放
	};
}void test_shared_ptr()
{
	juju::shared_ptr<int> ap1(new int);
	juju::shared_ptr<int> ap2(ap1);
	ap1 = ap2;//如果同一块空间里的相互赋值，自娱自乐，我们要在赋值那进行优化

	juju::shared_ptr<int> ap3(new int);
	ap1 = ap3;
}

int main()
{
	test_shared_ptr();
	system("pause");
	return 0;
}
