#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

//全局变量
int postion_x, postion_y;    //飞机的位置
int bullet_x, bullet_y;		 //子弹的位置
int enemy_x, enemy_y;		 //敌机位置
int high, width;             //游戏画面的尺寸
int sorce;					 //得分

void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };//第二个值为0表示隐藏光标
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void startup()              //赋值
{
	high = 20;
	width = 30;
	postion_x = high / 2;
	postion_y = width / 2;
	bullet_x = -1;
	bullet_y = postion_y;
	enemy_x = 0;
	enemy_y = postion_y;
	sorce = 0;
	HideCursor();
}

void show()					//显示画面
{
	gotoxy(0, 0);
	int i, j;
	for (i = 0; i < high; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (i == postion_x && j == postion_y)
				printf("*");		//飞机
			else if (i == bullet_x && j == bullet_y)
				printf("|");		//激光
			else if (i == enemy_x && j == enemy_y)
				printf("+");		//敌机
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("得分：%d\n", sorce);
}

void updateWithoutInput()	//与用户输入无关的更新
{
	if (bullet_x > -1)
		bullet_x--;			//子弹向上移
	
	if (bullet_x == enemy_x && bullet_y == enemy_y)		//子弹敌机相遇
	{
		enemy_x = 0;		//敌机消失
		sorce++;			//分数加一
		enemy_y = rand() % width;	//随机位置生成敌机
		bullet_x = 0;		//子弹消失
	}

	if (enemy_x > high)			//敌机跑出显示屏幕
	{
		enemy_x = 0;			//敌机下落
		enemy_y = rand() % width;
	}

	//控制敌机下落的速度，每隔几次循环才移动一次敌机
	static int speed = 0;
	if (speed < 10)
		speed++;
	if (speed == 10)
	{
		enemy_x++;
		speed = 0;
	}
	Sleep(50);
	
}

void updateWithInput()		//与用户输入有关的更新
{
	char input;
	if (_kbhit())
	{
		input = _getch();	//读取用户输入，不必输入回车
		if (input == 'a' || input == 'A')
			postion_y--;
		if (input == 'd' || input == 'D')
			postion_y++;
		if (input == 'w' || input == 'W')
			postion_x--;
		if (input == 's' || input == 'S')
			postion_x++;
		if (input == 'j' || input == 'J')		//输出激光	
		{
			bullet_x = postion_x - 1;
			bullet_y = postion_y;
		}
	}
}

int main()
{
	startup();
	while (1)
	{
		show();
		updateWithoutInput();
		updateWithInput();

	}
	return 0;
}