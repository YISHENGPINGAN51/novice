#define _CRT_SECURE_NO_WARNINGS

// ��һ�����������в��Ҿ����ĳ������n�� ��дint binsearch(int x, int v[], int n); ���ܣ���v[0]<= v[1] <= v[2] <= ��. <= v[n - 1]�������в���x


#include <stdio.h>


int binsearch(int x, int v[], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (v[i] == x)
		{
			printf("v[%d] = %d\n", i, x);
			break;
		}
	}
	if (i == n)
	{
		printf("û�ҵ�\n");
	}
	return 0;
}

int main()
{
	int x = 0;
	//����˵��
	int v[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int n = sizeof(v) / sizeof(v[0]);
	printf("��������Ҫ���ҵ����֣�");
	scanf("%d", &x);
    binsearch(x, v, n);
	return 0;
}