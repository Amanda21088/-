#define _CRT_SECURE_NO_WARNINGS 1

//��Ϊֱ�۵�һ��д��
char* my_strcpy(char * dest, const char* source)//const���ܶ�
{
	//��Ҫ����дassert
	assert(dest != NULL);
	assert(src != NULL);
	while (*source != '\0')
	{
		*dest = *source;
		dest++;
		source++;
	}
	*dest = '\0';
	return dest;
}
//����2
char* my_strcpy(char * dest, const char* src)
{
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest++ = *src++)
	{
		;
	}
	return dest;
}
