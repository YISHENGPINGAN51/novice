#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int fun(int num, int s[])
{
	int i = 0;
	while (num >= 100)
	{
		int tmp = num;
		int sum = 0;
		while (tmp != 0)
		{
			sum = sum + tmp % 10;
			tmp = tmp / 10;
		}
		if (sum == 10)
		{
			s[i] = num;
			i++;
		}
		num--;
	}
	return 0;
}

int main()
{
	int num = 0;
	int s[100] = { 0 };
	int i = 0;
	int ret = 0;
	printf("请输入一个数：");
	scanf("%d", &num);
	ret = fun(num, s);
	if (ret == 0)
	{
		for (i = 0; s[i] != 0; i++)
		{
			printf("%d ", s[i]);
			if ((i + 1) % 5 == 0)
			{
				printf("\n");
			}
		}
	}
	printf("\n");
	return 0;
}