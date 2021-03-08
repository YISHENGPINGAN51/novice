#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void menu()
{
	printf("******************************\n");
	printf("**    1. Add       2. Sub   **\n");
	printf("**    3. Mul       4. Div   **\n");
	printf("**    5. Xor       0. Exit  **\n");
	printf("******************************\n");
}

int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

int Xor(int x, int y)
{
	return x ^ y;
}


void Calc(int (*pf)(int, int))
{
	int x = 0;
	int y = 0;
	printf("����������������:>");
	scanf("%d%d", &x, &y);
	printf("%d\n", pf(x, y));
}

int main()
{
	int input = 0;

	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			Calc(Add);
			break;
		case 2:
			Calc(Sub);
			break;
		case 3:
			Calc(Mul);
			break;
		case 4:
			Calc(Div);
			break;
		case 5:
			Calc(Xor);
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}


//
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//
//	//pfArr ��һ������ָ������ - ת�Ʊ�
//	int(*pfArr[])(int, int) = {0, Add, Sub, Mul, Div, Xor};
//	do
//	{
//		menu();
//		printf("��ѡ��:>");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 5)
//		{
//			printf("����������������:>");
//			scanf("%d%d", &x, &y);
//			int ret = pfArr[input](x, y);
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("�˳�\n");
//		}
//		else
//		{
//			printf("ѡ�����\n");
//		}
//	} while (input);
//}