#define _CRT_SECURE_NO_WARNINGS 1
void * my_memcpy(void* dest, const void* src, size_t count)
{
	void* ret = dest;
	while (count--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;//�����strcpyģ��ʵ�ֵ�����
		src = (char*)dest + 1;
	}
}
