#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<thread>
#include<mutex>
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
			, _pcount(new int(1))//将它初始化为1
			, _pmtx(new std::mutex)
		{}

		~shared_ptr()
		{
			Release();
		}

		shared_ptr(const shared_ptr<T>& ap)//拷贝构造
			:_ptr(ap._ptr)
			, _pcount(ap._pcount)//这一部分是线程安全的
			, _pmtx(ap._pmtx)
		{
				//++(*_pcount);
				AddRef();//加锁操作
			}

		shared_ptr<T>& operator=(shared_ptr<T> & ap)
		{
			//防止自己给自己赋值
			//if (this != &ap)
			if (_ptr != ap._ptr)//优化同一块空间的赋值
			{
				Release();
	
				_ptr = ap._ptr;
				_pcount = ap._pcount;
				_pmtx = ap._pmtx;

				AddRef();
			}
			return *this;
		}
		void AddRef()
		{
			_pmtx->lock();
			++(*_pcount);
			_pmtx->unlock();
		}

		void Release()
		{
			bool deleteflag = false;
			_pmtx->lock();
			if (--(*_pcount) == 0)//必须把这个判断放在中间，不能写成下面那种情况
			{
				delete _ptr;
				delete _pcount;
				deleteflag = true;
			}
			_pmtx->unlock();
			if (deleteflag == true)
			{
				delete _pmtx;
			}
		/*_pmtx->lock;
		--(*_pcount);
		_pmtx->unlock();
		if (--(*_pcount) == 0)//可能会释放两次
		{
			delete _ptr;
			delete _pcount;
			delete _pmtx;
		}*/
	}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		int use_count()
		{
			return *_pcount;
		}
	private:
		T* _ptr;
		int* _pcount;//不能将它弄成静态，万一在两块空间，其中一块会没被释放
		std::mutex *_pmtx;
	};
}
void test_shared_ptr()
{
	juju::shared_ptr<int> ap1(new int);
	juju::shared_ptr<int> ap2(ap1);
	ap1 = ap2;//如果同一块空间里的相互赋值，自娱自乐，我们要在赋值那进行优化

	juju::shared_ptr<int> ap3(new int);
	ap1 = ap3;
}

void test_multi_thread_copy(juju::shared_ptr<int>& ap, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		juju::shared_ptr<int> copy(ap);
	}
}
//怎么测试线程安全问题？如果析构函数的delete被调了,那就是线程安全
void test_shared_ptr_safe()
{
	juju::shared_ptr<int> ap(new int);

	std::thread t1(test_multi_thread_copy, ap, 10);//成功与否取决于n的大小
	std::thread t2(test_multi_thread_copy, ap, 10);
	t1.join();
	t2.join();

	std::cout << ap.use_count() << std::endl;

	struct ListNode
	{
		/*std::shared_ptr<ListNode> _next;
		std::shared_ptr<ListNode> _prev;*/

		std::weak_ptr<ListNode> _next;//解决循环引用，常规场景不用
		std::weak_ptr<ListNode> _prev;


		~ListNode()
		{
			cout << "~ListNode()" << endl;
		}
	};
	void test_shared_ptr_cycle_ref()//循环引用
	{
		std::shared_ptr<ListNode> cur(new ListNode);//析构函数自动释放，不用手动释放
		std::shared_Ptr<ListNode> next(new ListNode);

		cur->_next = next;
		next->_prev = next;

		//防止抛异常，为了解决复杂的过程我们使用RAII
		/*delete cur;
		delete next;*/

		cout << cur.use_count() << endl;
		cout << next.use_count() << endl;

	}
}
int main()
{
	//test_shared_ptr();
	test_shared_ptr_safe();
	system("pause");
	return 0;
}