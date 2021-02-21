#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>

int main()
{
	int n = 0;
	int ret = 1;
	int sum = 0;
	for (n = 1; n < 11; n++)
	{
		ret *= n;
		sum += ret;
	}
	printf("sum = %d\n", sum);

	return 0;
}
/*太过粗糙可以优化*/
//int main()
//{
//	int n = 0;
//	int i = 0;
//	int j = 1;
//	int sum = 0;
//	for (n = 1; n < 11; n++)
//	{
//		for (i = 1, j = 1; i <= n; i++)
//		{
//			j = j * i;
//		}
//		sum += j;
//	}
//	printf("sum = %d\n", sum);
//
//	return 0;
//}

