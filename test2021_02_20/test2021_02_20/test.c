#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int row_max(int array[3][4], int i)
{
	int j = 0;
	int tmp = 0;
	int max = array[i][j];
	for (j = 0; j < 4; j++)
	{
		if (max < array[i][j])
		{
			max = array[i][j];
		}
	}
	return max;
}

int col_min(int array[3][4], int j)
{
	int i = 0;
	int tmp = 0;
	int min = array[i][j];
	for (i = 0; i < 3; i++)
	{
		if (min > array[i][j])
		{
			min = array[i][j];
		}
	}
	return min;
}

int main()
{
	int array[3][4] = { 2,1,3,4,5,7,6,8,10,9,11,12 };
	int tmp = 0;
	for (int i = 0; i < 3; i++)
	{
		tmp = row_max(array, i);
		for (int j = 0; j < 4; j++)
		{
			if (tmp == col_min(array, j))
			{
				printf("靶点是%d\n", tmp);
			}
		}
	}
	return 0;
}

//第一种方法
//#include <stdio.h>//头文件
//int main()//主函数入口
//{
//	int i, j;//定义整型变量
//	int array[10][10];//定义二维数组
//	for (i = 0; i < 10; i++)//for循环
//	{
//		array[i][i] = 1;//给二维数组的每一行的最后一个赋值为1
//		array[i][0] = 1;//第二维数组的每一行的开头赋值为1
//	}
//	for (i = 2; i < 10; i++)//外层循环限制行
//	{
//		for (j = 1; j <= i - 1; j++)//内层循环限制列
//		{
//			array[i][j] = array[i - 1][j] + array[i - 1][j - 1];//给中间的数赋值
//		}
//	}
//	for (i = 0; i < 10; i++)//外层循环限制行
//	{
//		for (j = 0; j <= i; j++)//内层循环限制列
//		{
//			printf("%6d", array[i][j]);//输出二维数组，宽度为6
//		}
//		printf("\n");//换行
//	}
//	return 0;//函数返回值为0
//}


//第二种方法
//#include <stdio.h>
//
//int factorial(int t)
//{
//	int end = 0;
//	if (t == 0)
//	{
//		end = 1;
//	}
//	else
//	{
//		end = t * factorial(t - 1);
//	}
//	return end;
//}
//
//int combination_number(int m, int n)
//{
//	int z = 0;
//	z = factorial(m) / factorial(n) / factorial(m - n);
//	return z;
//}
//
//int main()
//{
//	int a[10][10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 10; j++)
//		{
//			a[i][j] = combination_number(i, j);
//			printf("%-3d ", a[i][j]);
//			if (i == j)
//			{
//				printf("\n");
//				break;
//			}
//		}
//	}
//	return 0;
//}


//第三种方法
//#include <stdio.h>
//
//int combination_number(int m, int n)
//{
//	int z = 0;
//	int tmp1 = 1;
//	int tmp2 = 1;
//	int k = 0;
//	int s = n;
//	for (k = 0; k < s; k++)
//	{
//		tmp1 *= m;
//		m -= 1;
//		tmp2 *= n;
//		n -= 1;
//	}
//	z = tmp1 / tmp2;
//	return z;
//}
//
//int main()
//{
//	int a[10][10] = { 0 };
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j < 10; j++)
//		{
//			a[i][j] = combination_number(i, j);
//			printf("%-3d ", a[i][j]);
//			if (i == j)
//			{
//				printf("\n");
//				break;
//			}
//		}
//	}
//	return 0;
//}