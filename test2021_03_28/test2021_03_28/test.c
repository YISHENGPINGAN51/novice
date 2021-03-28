#define _CRT_SECURE_NO_WARNINGS

//×óÐýk¸ö×Ö·û´®

//#include <stdio.h>
//#include <string.h>
//#include <assert.h>

//1.±©Á¦Çó½â·¨
//
//void left_move(char* arr, int k)
//{
//	assert(arr);
//	int i = 0;
//	int len = strlen(arr);
//	for (i = 0; i < k; i++)
//	{
//		//×óÐý×ªÒ»¸ö×Ö·û
//		//1
//		char tmp = *arr;
//		//2
//		int j = 0;
//		for (j = 0; j < len - 1; j++)
//		{
//			*(arr + j) = *(arr + j + 1);
//		}
//		//3
//		*(arr + len - 1) = tmp;
//	}
//}

//2.Èý²½·´×ª·¨
//ab cdef
//ba fedc
//cdefab
//

//ÄæÐò×Ö·û´®µÄº¯Êý
//void reverse(char* left, char* right)
//{
//	assert(left);
//	assert(right);
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
//void left_move(char* arr, int k)
//{
//	assert(arr);
//	int len = strlen(arr);
//	assert(k <= len);
//	reverse(arr, arr + k - 1);//ÄæÐò×ó±ß
//	reverse(arr + k, arr + len - 1);//ÄæÐòÓÒ±ß
//	reverse(arr, arr + len - 1);//ÄæÐòÕûÌå
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	left_move(arr, 2);
//
//	printf("%s\n", arr);
//
//	return 0;
//}

#include <stdio.h>
#include <string.h>
#include <assert.h>

void reverse(char* left, char* right)
{
	assert(left);
	assert(right);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

void left_move(char* arr, int k)
{
	assert(arr);
	int len = strlen(arr);
	assert(k <= len);
	reverse(arr, arr + k - 1);//ÄæÐò×ó±ß
	reverse(arr + k, arr + len - 1);//ÄæÐòÓÒ±ß
	reverse(arr, arr + len - 1);//ÄæÐòÕûÌå
}

int is_left_move(char* s1, char* s2)
{
	int len = strlen(s1);
	int i = 0;
	for (i = 0; i < len; i++)
	{
		left_move(s1, 1);
		int ret = strcmp(s1, s2);
		if (ret == 0)
			return 1;
	}
	return 0;
}

int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "cdefab";
	int ret = is_left_move(arr1, arr2);
	if (ret == 1)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}