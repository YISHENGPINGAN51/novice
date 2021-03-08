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
		Sleep(200);//休息0.2秒
		system("cls");//执行系统命令的一个函数-cls - 清空屏幕
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
		printf("请选择:>");
		scanf("%d", &input);
		if (input >= 1 && input < sz)
		{
			printf("请输入两个操作数:>");
			scanf("%d%d", &x, &y);
			int ret = pfArr[input](x, y);
			printf("%d\n", ret);
			system("pause");
		}
		else if (input == 0)
		{
			printf("3秒后即将退出\n");
			Sleep(3000);
		}
		else
		{
			printf("选择错误，请重新输入\n");
		}
	} while (input);
	return 0;
}
