#define _CRT_SECURE_NO_WARNINGS

#include <graphics.h>
#include <ctime>
#include <conio.h>
#include <vector>
using namespace std;

// ��������
struct point
{
	int x;
	int y;
};

// �ߵ�����
struct Snake
{
	vector <point> xy;			// ÿ������
	point next;					// Ϊ��һ��Ԥ����λ��
	vector <COLORREF> color;	// ÿ����ɫ
	int num;					// ����
	int position;				// ����
}snake;

// ʳ�������
struct Food
{
	point fdxy[10];			// ����
	int grade;				// ����
	int num = 1;			// ʳ������
	COLORREF color[10];		// ʳ����ɫ
}food;

enum position { up, down, left, right };		// ö���ߵķ���

// ��ʼ����
void initSnake()
{
	point xy;
	xy.x = 20;
	xy.y = 0;
	snake.xy.push_back(xy);
	snake.color.push_back(RGB(rand() % 256, rand() % 256, rand() % 256));	// ����һ�������ɫ
	xy.x = 10;
	xy.y = 0;
	snake.xy.push_back(xy);
	snake.color.push_back(RGB(rand() % 256, rand() % 256, rand() % 256));	// ����һ�������ɫ
	xy.x = 0;
	xy.y = 0;
	snake.xy.push_back(xy);
	snake.color.push_back(RGB(rand() % 256, rand() % 256, rand() % 256));	// ����һ�������ɫ
	snake.num = 3;
	snake.position = right;
}

// ����
void drawSnake()
{
	for (int i = 0; i < snake.num; i++)
	{
		setfillcolor(snake.color[i]);
		fillrectangle(snake.xy[i].x, snake.xy[i].y, snake.xy[i].x + 10, snake.xy[i].y + 10);
	}
}

// �ƶ���
void moveSnake()
{
	// ��Ԥ��������Ϊδ�ƶ�ǰ��β��
	snake.next = snake.xy[snake.num - 1];
	// ������ͷ����Ľ��ƶ�������ǰ��һ��
	for (int i = snake.num - 1; i >= 1; i--)
		snake.xy[i] = snake.xy[i - 1];
	// ���ݵ�ǰ�ƶ������ƶ���ͷ
	switch (snake.position)
	{
	case right:
		snake.xy[0].x += 10;
		break;
	case left:
		snake.xy[0].x -= 10;
		break;
	case up:
		snake.xy[0].y -= 10;
		break;
	case down:
		snake.xy[0].y += 10;
	}
}

// ��������
void keyDown()
{
	char userKey = _getch();
	if (userKey == -32)			// �������Ƿ����
		userKey = -_getch();	// ��ȡ���巽�򣬲�������������ĸ�� ASCII ��ͻ
	switch (userKey)
	{
	case 'w':
	case 'W':
	case -72:
		if (snake.position != down)
			snake.position = up;
		break;
	case 's':
	case 'S':
	case -80:
		if (snake.position != up)
			snake.position = down;
		break;
	case 'a':
	case 'A':
	case -75:
		if (snake.position != right)
			snake.position = left;
		break;
	case 'd':
	case 'D':
	case -77:
		if (snake.position != left)
			snake.position = right;
		break;
	}
}

// ��ʼ��ʳ��
void initFood(int num /* ʳ���� */)
{
	food.fdxy[num].x = rand() % 80 * 10;
	food.fdxy[num].y = rand() % 60 * 10;
	for (int i = 0; i < snake.num; i++)
		if (food.fdxy[num].x == snake.xy[i].x && food.fdxy[num].y == snake.xy[i].y)		// ����ʳ��������������
		{
			food.fdxy[num].x = rand() % 80 * 10;
			food.fdxy[num].y = rand() % 60 * 10;
		}
}

// ��ʳ��
void drawFood()
{
	for (int i = 0; i <= food.num - 1; i++)
	{
		setfillcolor(food.color[i] = RGB(rand() % 256, rand() % 256, rand() % 256));	// ÿ�����¸���ʳ��һ���������ɫ
		fillrectangle(food.fdxy[i].x, food.fdxy[i].y, food.fdxy[i].x + 10, food.fdxy[i].y + 10);
	}
}

// ��ʳ��
void eatFood()
{
	for (int i = 0; i <= food.num - 1; i++)
		if (snake.xy[0].x == food.fdxy[i].x && snake.xy[0].y == food.fdxy[i].y)
		{
			snake.num++;
			snake.xy.push_back(snake.next);					// ����һ���ڵ�Ԥ��λ��
			snake.color.push_back(food.color[i]);			// �������ڵ���ɫ����Ϊ��ǰ�Ե�ʳ�����ɫ
			food.grade += 100;
			initFood(i);
			if (food.num < 10 && food.grade % 500 == 0 && food.grade != 0)
			{
				food.num++;									// ÿ�� 500 �֣�����һ��ʳ���ʳ������������ 10 ��
				initFood(food.num - 1);						// ��ʼ�������ӵ�ʳ��
			}
			break;
		}
}

// ������ʾ
void showgrade()
{
	wchar_t grade[20] = L"";
	swprintf_s(grade, L"����:%d", food.grade);
	outtextxy(650, 50, grade);
}

// ��Ϸ����
bool gameOver()
{
	// ײǽ����ǽ������չһȦ���������޷������ͼ��Ե��
	if (snake.xy[0].y <= -10 && snake.position == up)			return true;
	if (snake.xy[0].y + 10 >= 610 && snake.position == down)	return true;
	if (snake.xy[0].x <= -10 && snake.position == left)			return true;
	if (snake.xy[0].x + 10 >= 810 && snake.position == right)	return true;
	// ײ�Լ�
	for (int i = 1; i < snake.num; i++)
	{
		if (snake.xy[0].x <= snake.xy[i].x + 10 && snake.xy[0].x >= snake.xy[i].x && snake.xy[0].y == snake.xy[i].y && snake.position == left)
			return true;
		if (snake.xy[0].x + 10 >= snake.xy[i].x && snake.xy[0].x + 10 <= snake.xy[i].x + 10 && snake.xy[0].y == snake.xy[i].y && snake.position == right)
			return true;
		if (snake.xy[0].y <= snake.xy[i].y + 10 && snake.xy[0].y >= snake.xy[i].y && snake.xy[0].x == snake.xy[i].x && snake.position == up)
			return true;
		if (snake.xy[0].y + 10 >= snake.xy[i].y && snake.xy[0].y + 10 <= snake.xy[i].y + 10 && snake.xy[0].x == snake.xy[i].x && snake.position == down)
			return true;
	}
	return false;
}

int main()
{
	initgraph(800, 600);
	setbkcolor(RGB(95, 183, 72));
	srand((unsigned)time(NULL));
	settextcolor(BLUE);
	setbkmode(TRANSPARENT);			// �����������ģʽΪ͸��
	initSnake();
	initFood(0);
	drawSnake();
	while (!gameOver())
	{
		Sleep(150);
		BeginBatchDraw();			// ��ʼ������ͼ�������Ǳ�����˸
		cleardevice();
		if (_kbhit()) keyDown();
		moveSnake();
		eatFood();
		drawFood();
		drawSnake();
		showgrade();
		EndBatchDraw();				// ����������ͼ
	}
	// �����Ϊײǽ�������˻ص�ײǽǰ��״̬�Ա㽫��������ʾ����
	if (snake.xy[0].y <= -10 && snake.position == up ||
		snake.xy[0].y + 10 >= 610 && snake.position == down ||
		snake.xy[0].x <= -10 && snake.position == left ||
		snake.xy[0].x + 10 >= 810 && snake.position == right)
	{
		for (int i = 0; i <= snake.num - 2; i++)
			snake.xy[i] = snake.xy[i + 1];
		snake.xy[snake.num - 1] = snake.next;
		drawSnake();
	}
	_getch();						// ��������˳�
	return 0;
}

