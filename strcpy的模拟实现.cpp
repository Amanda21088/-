#define _CRT_SECURE_NO_WARNINGS 1

//较为直观的一中写法
char* my_strcpy(char * dest, const char* source)//const不能丢
{
	//不要忘了写assert
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
//代码2
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
