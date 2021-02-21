#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	float v[5];
	float* vp;
	for (vp = &v[5]; vp > &v[0];)
	{
		*--vp = 0;
	}
	return 0;
}

//#include <stdio.h>
//
//int gcd(int a, int b)
//{
//	return b == 0 ? a : gcd(b, a % b);//我愿称之为暴力美学版辗转相除
//}
//
//int lcm(int a, int b)
//{
//	return a * b / gcd(a, b);//不愧是我
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("请输入两个数：");
//	scanf("%d%d", &a, &b);
//	printf("这两个数的最大公约数是%d\n", gcd(a, b));
//	printf("这两个数的最小公倍数是%d\n", lcm(a, b));
//	return 0;
//}

//#include <stdio.h>
//
//int fun(int num)
//{
//	int mul = 1;
//	int tmp = 0;
//	for (; num > 0; num /= 10)
//	{
//		tmp = num % 10;
//		mul *= tmp;
//	} 
//	return mul;
//}
//
//int main()
//{
//	int num = 0;
//	printf("请输入一个数：");
//	scanf("%d", &num);
//	printf("这个数各个位上的数字之积是%d\n", fun(num));
//	return 0;
//}

//#include <stdio.h>
//
//int fab(int a, int b)
//{
//	if (a >= b)
//	{
//		return a - b;
//	}
//	else
//	{
//		return b - a;
//	}
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("请输入要求差的绝对值的两个数：");
//	scanf("%d%d", &a, &b);
//	printf("这两个数差的绝对值是%d\n", fab(a, b));
//	return 0;
//}
