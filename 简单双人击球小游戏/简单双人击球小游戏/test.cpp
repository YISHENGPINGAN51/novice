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
	int win = 1;							// Ӯ���
	p1_x = 45;								// ���
	p1_y = 240;
	p2_x = 595;								// �Ұ�
	p2_y = 240;
	ball_x = rand() % 240 + 200;			// С�� x ����
	ball_y = rand() % 180 + 150;			// С�� y ����
	dx = (rand() % 2 * 2 - 1) * 2;			// С���ƶ�����
	dy = (rand() % 2 * 2 - 1) * 2;			// С���ƶ�����

	outtextxy(190, 200, L"Put Enter To Begin");
	while (_getwch() != 13);

	cleardevice();

	// player
	settextstyle(20, 0, L"Verdana");
	outtextxy(20, 50, L"Payer1");
	outtextxy(565, 50, L"Player2");

	// ��ʾ
	settextstyle(15, 0, L"Verdana");
	outtextxy(20, 400, L"W ����");
	outtextxy(20, 425, L"S ����");
	outtextxy(590, 400, L"O ����");
	outtextxy(590, 425, L"L ����");

	line(50, 100, 590, 100);											// �ϱ߽�
	line(50, 380, 590, 380);											// �±߽�
	solidcircle(ball_x, ball_y, 10);

	wchar_t key = 0;
	while (true)
	{
		clearcircle(ball_x, ball_y, 10);								// ���С��λ��
		clearrectangle(p1_x - 5, p1_y - 20, p1_x + 5, p1_y + 20);		// ������
		clearrectangle(p2_x - 5, p2_y - 20, p2_x + 5, p2_y + 20);		// ����Ұ�

		if (_kbhit())
		{
			// ��ȡ����
			key = _getwch();

			// �жϰ��ƶ���λ��
			if (key == L's')
				p1_y += 30;
			else if (key == L'w')
				p1_y -= 30;
			else if (key == L'l')
				p2_y += 30;
			else if (key == L'o')
				p2_y -= 30;
		}

		// �ж����������Ƿ񳬳��ƶ�����
		if ((p1_y - 20) < 100)
			p1_y = 120;
		else if ((p1_y + 20) > 380)
			p1_y = 360;
		else if ((p2_y - 20) < 100)
			p2_y = 120;
		else if ((p2_y + 20) > 380)
			p2_y = 360;

		// ����������λ��
		solidrectangle(p1_x - 5, p1_y - 20, p1_x + 5, p1_y + 20);
		solidrectangle(p2_x - 5, p2_y - 20, p2_x + 5, p2_y + 20);

		ball_x = ball_x + dx;
		ball_y = ball_y + dy;

		// �ж�С���������Ұ巴��
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

		// �ж�С���������±߽練��
		if (ball_y < 115)
			dy = -dy;
		else if (ball_y > 364)
			dy = -dy;

		solidcircle(ball_x, ball_y, 10);

		Sleep(20);
	}

	settextstyle(30, 0, L"Verdana");
	if (win == 1)
		outtextxy(250, 200, L"Player1 Ӯ");
	else
		outtextxy(250, 200, L"Player2 Ӯ");

	_getch();
	closegraph();
	return 0;
}
