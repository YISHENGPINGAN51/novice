#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

char* my_strcpy(char* dest, const char* src)
{
	char* tmp = dest;
	while ((*dest++ = *src++) != '\0')
	{
		;
	}
	return tmp;
}

int main()
{
	char arr1[6] = "12345";
	char arr2[6] = "56789";
	printf("%s\n", my_strcpy(arr1, arr2));
	return 0;
}