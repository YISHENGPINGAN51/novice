#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

double Pow(int n, int k)
{
	if (k < 0)
	{
		return 1.0/Pow(n, -k);
	}
	else if (k == 0)
	{
		return 1;
	}
	else
	{
		return n*Pow(n, k - 1);
	}
}

int main()
{
	int n = 0;
	int k = 0;
	printf("��ֱ�����n��k��ֵ��");
	scanf("%d%d", &n, &k);
	printf("%d��%d�η���%lf\n", n, k, Pow(n, k));
	return 0;
}

//#include <stdio.h>
//
//int DigitSum(unsigned int m)
//{
//	int sum = m % 10;
//	if (m > 9)
//	{
//		sum += DigitSum(m / 10);
//	}
//	return sum;
//}
//
//int main()
//{
//	int m = 0;
//	printf("������һ������");
//	scanf("%d", &m);
//	printf("��������֮����%d\n", DigitSum(m));
//	return 0;
//}
