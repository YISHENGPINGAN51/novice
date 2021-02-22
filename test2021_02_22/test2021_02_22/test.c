#define _CRT_SECURE_NO_WARNINGS

//第三种算法,最好
#include <stdio.h>

int count_bin_one(int n)
{
	int count = 0;
	while (n)
	{
		n &= (n - 1);
		count++;
	}
	return count;
}

int main()
{
	int n = 0;
	printf("请输入一个数：");
	scanf("%d", &n);
	int count = count_bin_one(n);
	printf("count = %d\n", count);
	return 0;
}

//第二种算法
//#include <stdio.h>
//
//int count_bin_one(int n)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32;i++)
//	{
//		if ((n >> i) & 1 == 1)
//		{
//			count++;
//		}
//	}
//	return count;
//}
//
//int main()
//{
//	int n = 0;
//	printf("请输入一个数：");
//	scanf("%d", &n);
//	int count = count_bin_one(n);
//	printf("count = %d\n", count);
//	return 0;
//}

//第一种方法
//#include <stdio.h>
//
//int count_bin_one(unsigned int n)
//{
//	int count = 0;
//	while (n)
//	{
//		if (n % 2 == 1)
//		{
//			count++;
//		}
//		n /= 2;
//	}
//	return count;
//}
//
//int main()
//{
//	int n = 0;
//	printf("请输入一个数：");
//	scanf("%d", &n);
//	int count = count_bin_one(n);
//	printf("count = %d\n", count);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 6,7,8,9,10 };
//	int i = 0;
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	int tmp = 0;
//	for (i = 0; i < sz; i++)
//	{
//		tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//	return 0;
//}

//#include <stdio.h>
//
//void Init(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//}
//
//void Print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void Reverse(int arr[], int sz)
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
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//Init(arr, sz);
//	Print(arr, sz);
//	Reverse(arr, sz);
//	Print(arr, sz);
//	return 0;
//}
