#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int n = 0;
	int i = 0;
	int j = 1;

again:
	printf("������һ������");
	scanf("%d", &n);
	if(0 == n)
	{
		printf("0! = 1");
	}
	else if(n < 0)
	{
		printf("���������������������\n");
		goto again;
	}
	else
	{
		for (i = 1; i <= n; i++)
		{
			j = j * i;
		}
		printf("%d! = %d\n", n, j);
	}
	return 0;
}
