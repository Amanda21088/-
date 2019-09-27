#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

//C++98
//1.����Ȩת�ơ�����ȱ�ݵ�������ƣ���˾�Ͻ�ʹ����
//2.������Թ�����дһ������ָ�룬��Ҫдauto_ptr,��Ϊ���������Ǵ���ȱ�ݵ�
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
		//ap1(ap2)��������
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;//�ֶ��󸳸�ԭ�����ʱ��ԭ����ָ�أ���������״̬
		}
	private:
		T* _ptr;
	};
}

	void test_auto_ptr()
	{
		juju::auto_ptr<int> ap1(new int);
		juju::auto_ptr<int> ap2(ap1);

		*ap1 = 10;//����
		*ap2 = 20;
	}
int main()
{
	test_auto_ptr();
	system("pause");
	return 0;
}