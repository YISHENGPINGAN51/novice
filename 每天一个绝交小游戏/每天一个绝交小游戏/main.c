#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

void menu()
{
	char arr1[] = "*********************************************************";
	char arr2[] = "****   [1]开始游戏   [0]结束游戏   [9]获取游戏源码   ****";
	char arr3[] = "*********************************************************";
	char arr4[] = "                                                         ";
	char arr5[] = "                                                         ";
	char arr6[] = "                                                         ";
	int left = 0;
	int right = strlen(arr1)-1;

		while(left<=right)
		{
			arr4[left] = arr1[left];
			arr4[right] = arr1[right];
			arr5[left] = arr2[left];
			arr5[right] = arr2[right];
			arr6[left] = arr3[left];
			arr6[right] = arr3[right];
			printf("%s\n%s\n%s\n", arr4, arr5, arr6);
			Sleep(300);//休息0.3秒
			system("cls");//执行系统命令的一个函数-cls - 清空屏幕
			left++;
			right--;
		}
		printf("%s\n%s\n%s\n", arr4, arr5, arr6);
		printf("游戏规则：在0-100之间猜数字，按1开始游戏，按0结束游戏，按9获取游戏源码，输入数字后按回车继续\n");
		printf("注意事项：如果你选择开始游戏，你的电脑将在1分钟内关机，只要你能在规定时间内猜对数字，就可以取消关机\n");
}

//RAND_MAX-32767

void game()
{
	//1.生成一个随机数
	int count = 0;
	int ret = 0;
	int guess = 0;//接收猜的数字
	ret = rand() % 100 + 1;//生成1-100之间的随机数
	//printf("%d\n", ret);
	//2.猜数字
	while (1)
	{
		printf("请猜数字>: ");
		scanf("%d", &guess);
		if (guess > ret)
		{
			count++;
			printf("猜大了\n");
		}
		else if (guess < ret)
		{
			count++;
			printf("猜小了\n");
		}
		else
		{
			count++;
			printf("恭喜你，猜对了，祝你新年快乐！\n");
			printf("你一共猜了%d次\n\n", count);
			system("shutdown -a");
			system("pause");
			break;
		}
	}
}

void password()
{
	int i = 0;
	char code[20] = { 0 };
	int number = 0;
	for (i = 0; i < 3; i++)
	{
		number++;
		if (number == 2)
		{
			printf("提示：你可以试着输入5201314之类的密码\n");
		}
		printf("请输入密码>:");
		scanf("%s", code);
		if (strcmp(code, "1710905839") == 0)//== 不能用来比较两个字符串是否相等，应该使用一个库函数-strcmp
		{
			printf("密码正确\n");
			printf("游戏源码请联系作者QQ：1710905839，凭此截图获取源码，感谢您的支持！\n\n");
			system("pause");
			break;
		}
		else if(strcmp(code, "5201314") == 0 )
		{
			printf("多情总被无情恼，快想密码好不好\n");
		}
		else
		{
			printf("密码错误\n");
		}
	}
	if (i == 3)
	{
		printf("三次密码均错误，3秒后将返回上一级\n");
		Sleep(3000);//休息3秒
	}
}

int main()
{
	int input = 0;
	//拿时间戳来设置随机数的生成起始点
	//time_t time(time_t *timer)
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		printf("\n");
		switch (input)
		{
		case 1:
			system("shutdown -s -t 60");//关机
			game();//猜数字游戏
			break;
		case 0:
			printf("3秒后即将退出游戏\n");
			Sleep(3000);//休息3秒
			break;
		case 9:
			printf("请输入权限密码（最多输入三次）\n");
			password();
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}