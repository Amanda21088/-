#define _CRT_SECURE_NO_WARNINGS 1
char* my_strcat(char * dest, const char * src)
{
	assert(dest != NULL);
	assert(src != NULL);
	char* ret = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}