#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	char c = 1;
	printf("%u\n", sizeof(c));
	printf("%u\n", sizeof(+c));
	printf("%u\n", sizeof(!c));
	//int a = 5;
	//printf("%d\n", sizeof a);//����д�в��У�
	//printf("%d\n", sizeof int);//
	return 0;
}