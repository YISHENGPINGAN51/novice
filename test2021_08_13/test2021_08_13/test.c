#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define CITY_MAX 20  //FYL新增
#define DIGIT 4      //FYL新增

unsigned int city[CITY_MAX] =   //FYL新增
{
  9286            /*广州*/
, 55374           /*长沙*/
, 32670           /*武汉*/
, 32608           /*郑州*/
, 27835           /*西安*/
, 54945           /*太原*/
, 22346           /*石家庄*/
, 11636           /*北京*/
, 21609           /*天津*/
, 25581           /*沈阳*/
, 27514           /*大连*/
, 50882           /*济南*/
, 49668           /*青岛*/
, 43990           /*徐州*/
, 47128           /*蚌埠*/
, 17289           /*合肥*/
, 24295           /*南京*/
, 8609            /*杭州*/
, 63052           /*南昌*/
, 22333           /*深圳*/
};

unsigned int city_ready[CITY_MAX][DIGIT];  //FYL新增

void Transform(void)  //将给出的10进制数转换成对应的16进制的ASCII值，一位一个数字存储在数组中  //FYL新增
{
	unsigned int i, j;
	unsigned int city_copy[CITY_MAX];
	memcpy(city_copy, city, sizeof(city));
	for (i = 0; i < CITY_MAX; i++)
	{
		for (j = 0; j < DIGIT; j++)
		{
			city_ready[i][DIGIT - 1 - j] = city_copy[i] % 16;
			city_copy[i] /= 16;
			if (city_ready[i][DIGIT - 1 - j] < 10)
			{
				city_ready[i][DIGIT - 1 - j] += 48;
			}
			else
			{
				city_ready[i][DIGIT - 1 - j] += 55;
			}
		}
	}
}

int main()
{
	while (1)
	{
		int i, j;
		scanf("%d", &i);
		printf("%d\n", city[i]);
		Transform();
		for (j = 0; j < DIGIT; j++)
		{
			printf("%d\n", city_ready[i][j]);
		}
	}
}