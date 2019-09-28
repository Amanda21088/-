#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<thread>
#include<mutex>
//C++11
//shared_ptr:����ȫ��֧�ֿ��������ü�������Ƹ��ӣ�ѭ������
namespace juju
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr)
			:_ptr(ptr)
			, _pcount(new int(1))//������ʼ��Ϊ1
			, _pmtx(new std::mutex)
		{}

		~shared_ptr()
		{
			Release();
		}

		shared_ptr(const shared_ptr<T>& ap)//��������
			:_ptr(ap._ptr)
			, _pcount(ap._pcount)//��һ�������̰߳�ȫ��
			, _pmtx(ap._pmtx)
		{
				//++(*_pcount);
				AddRef();//��������
			}

		shared_ptr<T>& operator=(shared_ptr<T> & ap)
		{
			//��ֹ�Լ����Լ���ֵ
			//if (this != &ap)
			if (_ptr != ap._ptr)//�Ż�ͬһ��ռ�ĸ�ֵ
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
			if (--(*_pcount) == 0)//���������жϷ����м䣬����д�������������
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
		if (--(*_pcount) == 0)//���ܻ��ͷ�����
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
		int* _pcount;//���ܽ���Ū�ɾ�̬����һ������ռ䣬����һ���û���ͷ�
		std::mutex *_pmtx;
	};
}
void test_shared_ptr()
{
	juju::shared_ptr<int> ap1(new int);
	juju::shared_ptr<int> ap2(ap1);
	ap1 = ap2;//���ͬһ��ռ�����໥��ֵ���������֣�����Ҫ�ڸ�ֵ�ǽ����Ż�

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
//��ô�����̰߳�ȫ���⣿�������������delete������,�Ǿ����̰߳�ȫ
void test_shared_ptr_safe()
{
	juju::shared_ptr<int> ap(new int);

	std::thread t1(test_multi_thread_copy, ap, 10);//�ɹ����ȡ����n�Ĵ�С
	std::thread t2(test_multi_thread_copy, ap, 10);
	t1.join();
	t2.join();

	std::cout << ap.use_count() << std::endl;

	struct ListNode
	{
		ListNode* _next;
		ListNode* _prev;


		~ListNode()
		{
			cout << "~ListNode()" << endl;
		}
	};
	void test_shared_ptr_cycle_ref()//ѭ������
	{
		ListNode* cur = new ListNode;
		ListNode* next = new ListNode;

		cur->_next = next;
		next->_prev = next;
	}
}
int main()
{
	//test_shared_ptr();
	test_shared_ptr_safe();
	system("pause");
	return 0;
}