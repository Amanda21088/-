#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
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
			,_pcount(new int(1))//������ʼ��Ϊ1
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

		shared_ptr(const shared_ptr<T>& ap)//��������
			:_ptr(ap._ptr)
			, _pcount(ap._pcount)
		{
			++(*_pcount);
		}

		shared_ptr<T>& operator=(shared_ptr<T> & ap)
		{
			//��ֹ�Լ����Լ���ֵ
			//if (this != &ap)
			if (_ptr != ap._ptr)//�Ż�ͬһ��ռ�ĸ�ֵ
			{
				if (--(*_pcount))//�����ռ�ֻʣ���һ����ʱ����ȥ�ͷ���������ֱ���ͷ�
				{
					delete _ptr;//����ֱ���ͷţ������һ��ռ����ap1��Ҳ��ap2������ֱ���ͷŵ��ռ䣬ap2���ڴ�ͳ�������
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
		int* _pcount;//���ܽ���Ū�ɾ�̬����һ������ռ䣬����һ���û���ͷ�
	};
}void test_shared_ptr()
{
	juju::shared_ptr<int> ap1(new int);
	juju::shared_ptr<int> ap2(ap1);
	ap1 = ap2;//���ͬһ��ռ�����໥��ֵ���������֣�����Ҫ�ڸ�ֵ�ǽ����Ż�

	juju::shared_ptr<int> ap3(new int);
	ap1 = ap3;
}

int main()
{
	test_shared_ptr();
	system("pause");
	return 0;
}
