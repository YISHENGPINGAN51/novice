#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>

void menu()
{
	char arr1[] = "********************************";
	char arr2[] = "****    1. Add    2. Sub    ****";
	char arr3[] = "****    3. Mul    4. Div    ****";
	char arr4[] = "****    0. Exit             ****";
	char arr5[] = "********************************";
	char brr1[] = "                                ";
	char brr2[] = "                                ";
	char brr3[] = "                                ";
	char brr4[] = "                                ";
	char brr5[] = "                                ";
	int left = 0;
	int right = strlen(arr1) - 1;
	
	while (left <= right)
	{
		brr1[left] = arr1[left];
		brr1[right] = arr1[right];
		brr2[left] = arr2[left];
		brr2[right] = arr2[right];
		brr3[left] = arr3[left];
		brr3[right] = arr3[right]; 
		brr4[left] = arr4[left];
		brr4[right] = arr4[right];
		brr5[left] = arr5[left];
		brr5[right] = arr5[right];
		printf("%s\n%s\n%s\n%s\n%s\n", brr1, brr2, brr3, brr4, brr5);
		Sleep(200);//��Ϣ0.2��
		system("cls");//ִ��ϵͳ�����һ������-cls - �����Ļ
		left++;
		right--;
	}
	printf("%s\n%s\n%s\n%s\n%s\n", brr1, brr2, brr3, brr4, brr5);
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

int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	int (*pfArr[])(int, int) = { 0, Add, Sub, Mul, Div };
	int sz = sizeof(pfArr) / sizeof(pfArr[0]);
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		if (input >= 1 && input < sz)
		{
			printf("����������������:>");
			scanf("%d%d", &x, &y);
			int ret = pfArr[input](x, y);
			printf("%d\n", ret);
			system("pause");
		}
		else if (input == 0)
		{
			printf("3��󼴽��˳�\n");
			Sleep(3000);
		}
		else
		{
			printf("ѡ���������������\n");
		}
	} while (input);
	return 0;
}
