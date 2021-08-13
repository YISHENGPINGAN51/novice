#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define CITY_MAX 20  //FYL����
#define DIGIT 4      //FYL����

unsigned int city[CITY_MAX] =   //FYL����
{
  9286            /*����*/
, 55374           /*��ɳ*/
, 32670           /*�人*/
, 32608           /*֣��*/
, 27835           /*����*/
, 54945           /*̫ԭ*/
, 22346           /*ʯ��ׯ*/
, 11636           /*����*/
, 21609           /*���*/
, 25581           /*����*/
, 27514           /*����*/
, 50882           /*����*/
, 49668           /*�ൺ*/
, 43990           /*����*/
, 47128           /*����*/
, 17289           /*�Ϸ�*/
, 24295           /*�Ͼ�*/
, 8609            /*����*/
, 63052           /*�ϲ�*/
, 22333           /*����*/
};

unsigned int city_ready[CITY_MAX][DIGIT];  //FYL����

void Transform(void)  //��������10������ת���ɶ�Ӧ��16���Ƶ�ASCIIֵ��һλһ�����ִ洢��������  //FYL����
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