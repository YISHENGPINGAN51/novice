#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int a = -1;
	a = a << 1;
	printf("%d\n", a);
	return 0;
}

//#define h 25
//#define w 35
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<windows.h>
//#include<time.h>
//#include<stdlib.h>
//void snow()
//{
//	int bol = 0, time = 1;
//	int a[h][w];
//	while (1)
//	{
//		if (time == 1)
//		{
//			for (int i = 0; i < h; i++)
//				for (int j = 0; j < w; j++)
//					a[i][j] = 1;
//		}
//		for (int i = 0; i < h; i++)
//		{
//			if (i == (h - 2))
//				for (int j = 0; j < w; j++)
//				{
//					if (j == (35 - 3 - 8 - 1))
//					{
//						printf("* * * * */    \\* ");//小路 
//						//printf("*/              \\ ");//院子 
//						j += 8;
//					}
//					else printf("* ");
//				}
//			else if (i == (h - 1))
//				for (int j = 0; j < w; j++)
//				{
//					if (j == (35 - 1 - 10 - 1))
//					{
//						printf(" * * * */      \\*");//小路 
//						//printf("/                \\*");//院子 
//						j += 9;
//					}
//					else printf(" *");
//				}
//			else
//			{
//				for (int j = 0; j < w; j++)
//				{
//					if (i == (25 - 8 - 1) && j == (35 - 3 - 2 - 1))
//						printf("▌");
//					else if (i == (25 - 7 - 1) && j == (35 - 3 - 2 - 1))
//						printf("▌");
//					else if (i == (25 - 6 - 1) && j == (35 - 3 - 8 - 1))
//					{
//						printf("▂▃▅▅▆▆▇▅▃");
//						j += 8;
//					}
//					else if (i == (25 - 5 - 1) && j == (35 - 3 - 8 - 1))
//					{
//						printf("  ▇▇▇▇▇  ");
//						j += 8;
//					}
//					else if (i == (25 - 4 - 1) && j == (35 - 3 - 8 - 1))
//					{
//						printf("  ▇▇    ▇  ");
//						j += 8;
//					}
//					else if (i == (25 - 3 - 1) && j == (35 - 3 - 8 - 1))
//					{
//						printf("  ▇▇▇▇  ┠ ▇  ");
//						j += 8;
//					}
//					else if (i == (25 - 2 - 1) && j == (35 - 3 - 8 - 1))
//					{
//						printf("  ▇▇▇▇____▇  ");
//						j += 8;
//					}
//					else if (i == 0)
//					{
//						bol = rand() % 10;  //降雪大小 
//						a[i][j] = bol;
//						if (bol == 0)
//							printf("* ");
//						else printf("  ");
//					}
//					else
//					{
//						if (a[i][j] == 0)
//							printf("* ");
//						else printf("  ");
//					}
//				}
//			}
//			if (i != h - 1)
//				printf("\n");
//		}
//		for (int i = (h - 3); i > 0; i--)
//			for (int j = 0; j < w; j++)
//				a[i][j] = a[i - 1][j];
//		Sleep(500);
//		system("cls");
//		time++;
//	}
//}
//VOID HideConsoleCursor(VOID) {//消除光标 
//	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
//	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),
//		&cursor_info);
//}
//int main()
//{
//	system("mode con cols=70 lines=25");
//	HideConsoleCursor();
//	srand((unsigned int)time(NULL));
//	snow();
//	return 0;
//}
//

//#include <stdio.h>
//#include <math.h>
//
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int flag = 1;
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//		{
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 2, 1, 4, 3, 5, 7, 6, 8, 9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	bubble_sort(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//int my_strlen(char* str)
//{
//	if (*str != '\0')
//		return 1 + my_strlen(str + 1);
//	else
//		return 0;
//}
//
//int main()
//{
//	char arr[] = "bit";
//	int len = my_strlen(arr);
//	printf("len = %d\n", len);
//	return 0;
//}

//int binary_research(int arr[], int k, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	if (left > right)
//	{
//		return (-1);
//	}
//}
//
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int k = 7;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = binary_research(arr, k, sz);
//	if (ret == -1)
//	{ 
//		printf("找不到指定的数字\n");
//	}
//	else
//	{
//		printf("找到了，下标是：%d\n", ret);
//	}
//	return 0;
//}
//void is_leap_year(int n)
//{
//	if (n % 4 == 0 && n % 100 != 0 || n % 400 == 0)
//	{
//		printf("%d年是闰年\n", n);
//	}
//	else
//	{
//		printf("%d年不是闰年\n", n);
//	}
//}
//
//int main()
//{
//	int i = 0;
//	printf("请输入一个年份：");
//	scanf("%d", &i);
//	is_leap_year(i);
//	return 0;
//}

////是素数返回1.不是素数返回0
//int is_prime(int n)
//{
//	int m = 0;
//	for (m = 2; m <= sqrt(n); m++)
//	{
//		if (n % m == 0)
//		{
//			return 0;
//		}
//	}
//	if (m > sqrt(n))
//	{
//		return 1;
//	}
//}
//
//int main()
//{
//	//打印100-200之间的素数
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		//判断i是否为素数
//		if (is_prime(i) == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int ch[10] = { 0 };
//	int i = 0;
//	int max = ch[0];
//	printf("请输入10个整数：\n");
//	for(i = 0; i < 10; i++)
//	{
//		printf("第%d个数：", i + 1);
//		scanf("%d", &ch[i]);
//	}
//	for(i = 0; i < 10; i++)
//	{
//		if(max <= ch[i])
//		{
//			max = ch[i];
//		}
//	}
//	printf("这十个数的最大值是%d\n", max);
//	return 1;
//}
//#include <stdio.h>
//#include <math.h>
//
//
//int main()
//{
//	int i = 0;
//	int  j = 0;
//	for (i = 101; i <= 200; i += 2)
//	{
//		for (j = 2; j <= sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (j > sqrt(i))
//		{
//			printf("%d ", i);
//		}
//
//	}
//	return 0;
//}
//#include <stdio.h>
//
//int main()
//{
//	char ch[10] = { 0 };
//	char ch[10] = getchar();
//	printf("%s\n", ch);
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	printf("c:\code\test.c\n");//\c有问题，VC不可执行，VS可执行
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	switch (a)
//	{
//	case 1: 
//		printf("1");
//		break;
//	case 2: 
//		printf("2");
//		break;
//	}
//	return 0;
//}
