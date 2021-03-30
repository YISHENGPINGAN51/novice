#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//#include <string.h>
//
//int is_left_move(char* str1, char* str2)
//{
//	int len1 = strlen(len1);
//	int len2 = strlen(len2);
//	if (len1 != len2)
//		return 0;
//	//1.在str1字符串中追加一个str1字符串
//	strncat(str1, str1, 6);//abcdefabcdef
//	//2.判断str2指向的字符串是否是str1指向的字符串的子串
//	//strstr - 找子串
//	char* ret = strstr(str1, str2);
//	if (ret == NULL)
//		return 0;
//	else
//		return 1;
//}
//
//int main()
//{
//	char arr1[30] = "abcdef";
//	char arr2[] = "cdefab";
//	int ret = is_left_move(arr1, arr2);
//	if (ret == 1)
//	{
//		printf("Yes\n");
//	}
//	else
//		printf("No\n");
//	return 0;
//}

#include <stdio.h>

//int FindNum(int arr[3][3], int k, int row, int col)
//{
//	int x = 0;
//	int y = col - 1;
//	while (x <= row - 1 && y >= 0)
//	{
//		if (arr[x][y] > k)
//			y--;
//		else if (arr[x][y] < k)
//			x++;
//		else
//			return 1;
//	}
//	return 0;
//}

int findnum(int arr[3][3], int k, int* px, int* py)
{
	int x = 0;
	int y = *py - 1;
	while (x <= *px - 1 && y >= 0)
	{
		if (arr[x][y] > k)
			y--;
		else if (arr[x][y] < k)
			x++;
		else
		{
			*px = x;
			*py = y;
			return 1;
		}
	}
	//找不到
	*px = -1;
	*py = -1;
	return 0;
}

int main()
{
	int arr[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	int k = 7;
	int x = 3;
	int y = 3;
	int ret = findnum(arr, k, &x, &y);
	if (ret == 1)
	{
		printf("找到了\n");
		printf("下标是: %d %d\n", x, y);
	}
	else
		printf("找不到\n");
	return 0;
}