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
//	return b == 0 ? a : gcd(b, a % b);//��Ը��֮Ϊ������ѧ��շת���
//}
//
//int lcm(int a, int b)
//{
//	return a * b / gcd(a, b);//��������
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("��������������");
//	scanf("%d%d", &a, &b);
//	printf("�������������Լ����%d\n", gcd(a, b));
//	printf("������������С��������%d\n", lcm(a, b));
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
//	printf("������һ������");
//	scanf("%d", &num);
//	printf("���������λ�ϵ�����֮����%d\n", fun(num));
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
//	printf("������Ҫ���ľ���ֵ����������");
//	scanf("%d%d", &a, &b);
//	printf("����������ľ���ֵ��%d\n", fab(a, b));
//	return 0;
//}
