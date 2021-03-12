#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	char a = 3, b = 6, c;
	c = a ^ b << 2;
	printf("%d\n", c);
	return 0;
}
