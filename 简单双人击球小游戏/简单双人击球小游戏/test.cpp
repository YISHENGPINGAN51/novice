#define _CRT_SECURE_NO_WARNINGS

#include <graphics.h>
#include <conio.h>

int main()
{
	initgraph(640, 480);
	srand(GetTickCount());
	setbkcolor(WHITE);
	cleardevice();

	setfillcolor(BLACK);
	setlinecolor(BLACK);
	settextstyle(30, 0, L"verdana");
	settextcolor(BLACK);

	int p1_x, p1_y, p2_x, p2_y, ball_x, ball_y;
	int dx, dy;
	int win = 1;							// 赢玩家
	p1_x = 45;								// 左板
	p1_y = 240;
	p2_x = 595;								// 右板
	p2_y = 240;
	ball_x = rand() % 240 + 200;			// 小球 x 坐标
	ball_y = rand() % 180 + 150;			// 小球 y 坐标
	dx = (rand() % 2 * 2 - 1) * 2;			// 小球移动增量
	dy = (rand() % 2 * 2 - 1) * 2;			// 小球移动增量

	outtextxy(190, 200, L"Put Enter To Begin");
	while (_getwch() != 13);

	cleardevice();

	// player
	settextstyle(20, 0, L"Verdana");
	outtextxy(20, 50, L"Payer1");
	outtextxy(565, 50, L"Player2");

	// 提示
	settextstyle(15, 0, L"Verdana");
	outtextxy(20, 400, L"W 向上");
	outtextxy(20, 425, L"S 向下");
	outtextxy(590, 400, L"O 向上");
	outtextxy(590, 425, L"L 向下");

	line(50, 100, 590, 100);											// 上边界
	line(50, 380, 590, 380);											// 下边界
	solidcircle(ball_x, ball_y, 10);

	wchar_t key = 0;
	while (true)
	{
		clearcircle(ball_x, ball_y, 10);								// 清除小球位置
		clearrectangle(p1_x - 5, p1_y - 20, p1_x + 5, p1_y + 20);		// 清除左板
		clearrectangle(p2_x - 5, p2_y - 20, p2_x + 5, p2_y + 20);		// 清除右板

		if (_kbhit())
		{
			// 获取按键
			key = _getwch();

			// 判断板移动的位置
			if (key == L's')
				p1_y += 30;
			else if (key == L'w')
				p1_y -= 30;
			else if (key == L'l')
				p2_y += 30;
			else if (key == L'o')
				p2_y -= 30;
		}

		// 判断左右俩板是否超出移动界限
		if ((p1_y - 20) < 100)
			p1_y = 120;
		else if ((p1_y + 20) > 380)
			p1_y = 360;
		else if ((p2_y - 20) < 100)
			p2_y = 120;
		else if ((p2_y + 20) > 380)
			p2_y = 360;

		// 画左右两板位置
		solidrectangle(p1_x - 5, p1_y - 20, p1_x + 5, p1_y + 20);
		solidrectangle(p2_x - 5, p2_y - 20, p2_x + 5, p2_y + 20);

		ball_x = ball_x + dx;
		ball_y = ball_y + dy;

		// 判断小球遇到左右板反弹
		if (ball_x < 62)
		{
			if (ball_y < p1_y + 20 && ball_y > p1_y - 20)
			{
				dx = -dx;
				dx += dx / 10;
			}
			else
			{
				win = 2;
				solidcircle(ball_x, ball_y, 10);
				break;
			}
		}
		else if (ball_x > 578)
		{
			if (ball_y < p2_y + 20 && ball_y > p2_y - 20)
			{
				dx = -dx;
				dx += dx / 10;
			}
			else
			{
				solidcircle(ball_x, ball_y, 10);
				break;
			}
		}

		// 判断小球遇到上下边界反弹
		if (ball_y < 115)
			dy = -dy;
		else if (ball_y > 364)
			dy = -dy;

		solidcircle(ball_x, ball_y, 10);

		Sleep(20);
	}

	settextstyle(30, 0, L"Verdana");
	if (win == 1)
		outtextxy(250, 200, L"Player1 赢");
	else
		outtextxy(250, 200, L"Player2 赢");

	_getch();
	closegraph();
	return 0;
}
