#include <stdio.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <graphics.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")  //多媒体设备接口库文件

#define PI 3.1415926
#define NUM 13  //烟花弹数量
#define WIDTH 960
#define HEIGHT 640

//开发环境: vs2019 + easyx

struct Fire
{
	int x, y;
	int cen_x, cen_y;  //中心点坐标
	int r;             //当前绽放半径
	int max_r;         //最大绽放半径
	int width, height;
	DWORD pixel[240][240];  //图片像素数组
	bool isShow;            //烟花是否准备好了
	bool isDraw;            //是否绘制烟花
}fire[NUM];

struct Jet  //烟花弹
{
	int x, y;  //坐标
	int hx, hy;  //最高点的坐标
	bool isShoot;  //烟花弹是否在发射中
	IMAGE img[2];
	byte n : 1;  //位段  0 1 0 1 0 1 0 1
}jet[NUM];

void welcome()
{
	mciSendString(L"open ./fire/bk1.mp3", 0, 0, 0);
	mciSendString(L"play ./fire/bk1.mp3", 0, 0, 0);
	for (int i = 0; i < 50; i++)
	{
		//清除屏幕
		cleardevice();
		int x = 500 + 180 * sin(2 * PI / 60 * i);
		int y = 200 + 180 * cos(2 * PI / 60 * i);
		//设置字体样式
		settextstyle(i, 0, L"楷体");
		settextcolor(RGB(0, 202, 0));
		setbkmode(TRANSPARENT);
		outtextxy(x, y, L"浪漫表白程序");
		Sleep(20);
	}
	_getch();//按任意键继续
	cleardevice();
	settextstyle(25, 0, L"楷体");
	outtextxy(300, 100, L"亲爱的xxx");
	outtextxy(300, 150, L"自从第一天看见你");
	outtextxy(300, 200, L"我的心就不能自已");
	outtextxy(300, 250, L"不管天上地下都想看见你");
	outtextxy(300, 300, L"...");
	outtextxy(300, 350, L"...");
	outtextxy(300, 400, L"--房某人");
}
void InitData(int i);
void loading()
{
	//初始化绽放效果
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
	//初始化烟花弹
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

//产生烟花弹
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
//发射烟花弹
void shoot()
{
	for (int i = 0; i < NUM; i++)
	{
		if (jet[i].isShoot)
		{
			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);
			//判断是否达到最高点了
			if (jet[i].y > jet[i].hy)
			{
				jet[i].y -= 5;
				jet[i].n++;
			}
			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);
			if (jet[i].y <= jet[i].hy)
			{
				jet[i].isShoot = false;
				//可以开始放烟花了
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
				fire[i].isDraw = true;  //可以开始绘制烟花了
			}
			if (fire[i].r >= fire[i].max_r)
			{
				InitData(i);
			}
		}
		if (fire[i].isDraw)
		{
			//求当前半径下，圆上的每个点对应的弧度
			for (double a = 0; a <= 2*PI; a += 0.01)
			{
				int img_x = fire[i].cen_x + fire[i].r * cos(a);//求出圆上每个点的坐标
				int img_y = fire[i].cen_y + fire[i].r * sin(a);
				if (img_x > 0 && img_x < fire[i].width && img_y>0 && img_y < fire[i].height)
				{
					//针对现在的绽放点，对应的屏幕坐标
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
	//创建窗口
	initgraph(WIDTH, HEIGHT);
	//设置随机数种子
	srand((unsigned int)time(NULL) + clock());
	welcome();
	loading();
	DWORD* pMem = GetImageBuffer();//获取窗口的内存指针

	while (1)  //防止闪退
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
		Sleep(10);//让程序休眠n毫秒   优化：自己写定时器 简单 时间差就可以做一个简单的定时器   *显存指针，图形学...
	}
	closegraph();
	return 0;
}