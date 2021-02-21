#define _CRT_SECURE_NO_WARNINGS

// 在一个有序数组中查找具体的某个数字n。 编写int binsearch(int x, int v[], int n); 功能：在v[0]<= v[1] <= v[2] <= …. <= v[n - 1]的数组中查找x


#include <stdio.h>


int binsearch(int x, int v[], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (v[i] == x)
		{
			printf("v[%d] = %d\n", i, x);
			break;
		}
	}
	if (i == n)
	{
		printf("没找到\n");
	}
	return 0;
}

int main()
{
	int x = 0;
	//举例说明
	int v[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int n = sizeof(v) / sizeof(v[0]);
	printf("请输入您要查找的数字：");
	scanf("%d", &x);
    binsearch(x, v, n);
	return 0;
}