#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int arr[] = { 1, 2, 3, 5, 6, 2, 1, 1, 6, 7, 8, 9, 4, 4, 0, 11 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int n = 0;
	int count = 0;
	printf("请输入0-9之间你要查找的数字：");
	scanf("%d", &n);

	for (i = 0; i < sz; i++)
	{
		if (arr[i] / 10 > 0)
		{
			if (n == arr[i] / 10)
			{
				count++;
			}
			if (n == arr[i] % 10)
			{
				count++;
			}
		}
		else
		{
			if (n == arr[i])
			{
				count++;
			}
		}
	}
	printf("%d一共出现了%d次\n", n, count);

	return 0;
}

//#include <stdio.h>
//#include <string.h>
//
//int Del_num(int* arr, int sz)
//{
//	int i = 1;
//	int j = 1;
//	for (i = 1; i < sz; i++)
//	{
//		if (*(arr + i) != *(arr + i - 1))
//		{
//			*(arr + j) = *(arr + i);
//			j++;
//		}
//	}
//	return j;
//}
//
//int main()
//{
//	int arr[] = { 4, 5, 5, 5, 6, 6, 7, 8, 9, 10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = Del_num(arr, sz);
//	printf("%d\n", ret);
//	return 0;
//}

//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int x = 0;
//	int n = 0;
//	int num = 0;
//	int ret = 0;
//	int tmp = 0;
//
//	printf("please put in x: ");
//	scanf("%d", &x);
//	printf("please put in n: ");
//	scanf("%d", &n);
//
//	while (x > 0)
//	{
//		tmp = x % n;
//		x /= n;
//		ret += tmp * (int)pow(10, num);
//		num++;
//	}
//
//	printf("after changing is %d\n", ret);
//
//	return 0;
//}
