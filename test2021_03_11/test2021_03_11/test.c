#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int line = 0;
	int i = 0;
	int j = 0;
	scanf("%d", &line);
	for (i = 0; i < line; i++)
	{
		for (j = 0; j < line - i - 1; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 0; i < line - 1; i++)
	{
		for (j = 0; j < i + 1; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * (line - 1 - i) - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 100000; i++)
//	{
//		int n = 1;
//		int tmp = i;
//		int sum = 0;
//		while (tmp /= 10)
//		{
//			n++;
//		}
//		tmp = i;
//		while (tmp)
//		{
//			sum += pow(tmp % 10, n);
//			tmp /= 10;
//		}
//		if (i == sum)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int a = 0;
//	int n = 0;
//	int ret = 0;
//	int sum = 0;
//	scanf("%d%d", &a, &n);
//	for (int i = 0; i < n; i++)
//	{
//		ret = ret * 10 + a;
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//void reverse(char* str)
//{
//	assert(str);
//	int len = strlen(str);
//	char* left = str;
//	char* right = str + len - 1;
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	char arr[100] = { 0 };
//	scanf("%s", arr);
//	reverse(arr);
//	printf("%s\n", arr);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//void reverse(char* arr, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	int tmp = 0;
//	while (left < right)
//	{
//		tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	char arr[100] = { 0 };
//	scanf("%s", arr);
//	int sz = strlen(arr);
//	printf("%d\n", sz);
//	reverse(arr, sz);
//	printf("%s\n", arr);
//	return 0;
//}
