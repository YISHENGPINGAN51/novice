#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>//system
#include <string.h>//strcmp

int main()
{
	char input[20] = { 0 };//�洢����
	//�ػ�
	//system() - ר������ִ��ϵͳ�����
	system("shutdown -s -t 60");//�ػ�

again:
	printf("��ע�⣬��ĵ�����1�����ڼ����ػ���������롰�������Ǵ�˧�ȡ�����ȡ���ػ�\n");
	printf("������>: ");
	scanf("%s", input);//%s - �ַ���
	if (strcmp(input, "�������Ǵ�˧��") == 0)//�ж�input�зŵ��ǲ��ǡ��������Ǵ�˧�ȡ� - strcmp - string compare
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
	return 0;
}