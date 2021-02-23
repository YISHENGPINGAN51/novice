#include <stdio.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <graphics.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")  //��ý���豸�ӿڿ��ļ�

#define PI 3.1415926
#define NUM 13  //�̻�������
#define WIDTH 960
#define HEIGHT 640

//��������: vs2019 + easyx

struct Fire
{
	int x, y;
	int cen_x, cen_y;  //���ĵ�����
	int r;             //��ǰ���Ű뾶
	int max_r;         //������Ű뾶
	int width, height;
	DWORD pixel[240][240];  //ͼƬ��������
	bool isShow;            //�̻��Ƿ�׼������
	bool isDraw;            //�Ƿ�����̻�
}fire[NUM];

struct Jet  //�̻���
{
	int x, y;  //����
	int hx, hy;  //��ߵ������
	bool isShoot;  //�̻����Ƿ��ڷ�����
	IMAGE img[2];
	byte n : 1;  //λ��  0 1 0 1 0 1 0 1
}jet[NUM];

void welcome()
{
	mciSendString(L"open ./fire/bk1.mp3", 0, 0, 0);
	mciSendString(L"play ./fire/bk1.mp3", 0, 0, 0);
	for (int i = 0; i < 50; i++)
	{
		//�����Ļ
		cleardevice();
		int x = 500 + 180 * sin(2 * PI / 60 * i);
		int y = 200 + 180 * cos(2 * PI / 60 * i);
		//����������ʽ
		settextstyle(i, 0, L"����");
		settextcolor(RGB(0, 202, 0));
		setbkmode(TRANSPARENT);
		outtextxy(x, y, L"������׳���");
		Sleep(20);
	}
	_getch();//�����������
	cleardevice();
	settextstyle(25, 0, L"����");
	outtextxy(300, 100, L"�װ���xxx");
	outtextxy(300, 150, L"�Դӵ�һ�쿴����");
	outtextxy(300, 200, L"�ҵ��ľͲ�������");
	outtextxy(300, 250, L"�������ϵ��¶��뿴����");
	outtextxy(300, 300, L"...");
	outtextxy(300, 350, L"...");
	outtextxy(300, 400, L"--��ĳ��");
}
void InitData(int i);
void loading()
{
	//��ʼ������Ч��
	IMAGE bloomImg, tImg;
	loadimage(&bloomImg, L".fire/flower.jpg", 3120, 240);
	for (int i = 0; i < NUM; i++)
	{
		InitData(i);
		SetWorkingImage(&bloomImg);
		getimage(&tImg, i * 240, 0, 240, 240);
		SetWorkingImage(&tImg);
		for (int a = 0; a < 240; a++)
		{
			for (int b = 0; b < 240; b++)
			{
				fire[i].pixel[a][b] = getpixel(a, b);

			}
		}


	}
	//��ʼ���̻���
	IMAGE jetImg;
	loadimage(&jetImg, L"./fire/shoot.jpg", 200, 50);
	SetWorkingImage(&jetImg);
	for (int i = 0; i < NUM; i++)
	{
		int n = rand() % 5;
		getimage(&jet[i].img[0], n * 20, 0, 20, 50);
		getimage(&jet[i].img[1], n * 20 + 100, 0, 20, 50);
		putimage(i * 20, 0, &jet[i].img[0]);
		jet[i].isShoot = false;
	}
	SetWorkingImage();
}
void InitData(int i)
{
	fire[i].cen_x = 120;
	fire[i].cen_y = 120;
	fire[i].max_r = 120;
	fire[i].r = 0;
	fire[i].width = 240;
	fire[i].height = 240;
	fire[i].isDraw = false;
	fire[i].isShow = false;
}

//�����̻���
void creatJet()
{
	int i = rand() % NUM;  //[0.,13)
	if (jet[i].isShoot == false)
	{
		jet[i].x = rand() % (WIDTH - 20);
		jet[i].y = rand() % 100 + HEIGHT;
		jet[i].hx = jet[i].x;
		jet[i].hy = rand() % (HEIGHT / 3 * 2);
		jet[i].isShoot = true;
	}
}
//�����̻���
void shoot()
{
	for (int i = 0; i < NUM; i++)
	{
		if (jet[i].isShoot)
		{
			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);
			//�ж��Ƿ�ﵽ��ߵ���
			if (jet[i].y > jet[i].hy)
			{
				jet[i].y -= 5;
				jet[i].n++;
			}
			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);
			if (jet[i].y <= jet[i].hy)
			{
				jet[i].isShoot = false;
				//���Կ�ʼ���̻���
				fire[i].x = jet[i].x;
				fire[i].y = jet[i].y;
				fire[i].isShow = true;
			}
		}
	}
}
void bloom(DWORD* pMem)
{
	for (int i = 0; i < NUM; i++)
	{
		if (fire[i].isShow)
		{
			if (fire[i].r < fire[i].max_r)
			{
				fire[i].r++;
				fire[i].isDraw = true;  //���Կ�ʼ�����̻���
			}
			if (fire[i].r >= fire[i].max_r)
			{
				InitData(i);
			}
		}
		if (fire[i].isDraw)
		{
			//��ǰ�뾶�£�Բ�ϵ�ÿ�����Ӧ�Ļ���
			for (double a = 0; a <= 2*PI; a += 0.01)
			{
				int img_x = fire[i].cen_x + fire[i].r * cos(a);//���Բ��ÿ���������
				int img_y = fire[i].cen_y + fire[i].r * sin(a);
				if (img_x > 0 && img_x < fire[i].width && img_y>0 && img_y < fire[i].height)
				{
					//������ڵ����ŵ㣬��Ӧ����Ļ����
					int win_x = fire[i].x + fire[i].r * cos(a);
					int win_y = fire[i].y + fire[i].r * sin(a);
					if (win_x > 0 && win_x < WIDTH && win_y > 0 && win_y < WIDTH)
					{
						pMem[win_y * WIDTH + win_x] = BGR(fire[i].pixel[img_x][img_y]);
					}
				}
			}
		}
	}
}

int main()
{
	//��������
	initgraph(WIDTH, HEIGHT);
	//�������������
	srand((unsigned int)time(NULL) + clock());
	welcome();
	loading();
	DWORD* pMem = GetImageBuffer();//��ȡ���ڵ��ڴ�ָ��

	while (1)  //��ֹ����
	{
		for (int i = 0; i < WIDTH; i++)
		{
			for (int k = 0; k < 4; k++)
			{
				int x = rand() % WIDTH;
				int y = rand() % HEIGHT;
				if (y < HEIGHT)
				{
					pMem[y * WIDTH + x] = BLACK;
				}
			}
		}
		creatJet();
		shoot();
		bloom(pMem);
		Sleep(10);//�ó�������n����   �Ż����Լ�д��ʱ�� �� ʱ���Ϳ�����һ���򵥵Ķ�ʱ��   *�Դ�ָ�룬ͼ��ѧ...
	}
	closegraph();
	return 0;
}