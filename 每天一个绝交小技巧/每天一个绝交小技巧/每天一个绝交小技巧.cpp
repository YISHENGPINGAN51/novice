#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>//system
#include <string.h>//strcmp

int main()
{
	char input[20] = { 0 };//存储数据
	//关机
	//system() - 专门用来执行系统命令的
	system("shutdown -s -t 60");//关机

again:
	printf("请注意，你的电脑在1分钟内即将关机，如果输入“房蕴力是大帅比”，就取消关机\n");
	printf("请输入>: ");
	scanf("%s", input);//%s - 字符串
	if (strcmp(input, "房蕴力是大帅比") == 0)//判断input中放的是不是“房蕴力是大帅比” - strcmp - string compare
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
	return 0;
}