#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

//ȫ�ֱ���
int postion_x, postion_y;    //�ɻ���λ��
int bullet_x, bullet_y;		 //�ӵ���λ��
int enemy_x, enemy_y;		 //�л�λ��
int high, width;             //��Ϸ����ĳߴ�
int sorce;					 //�÷�

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
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };//�ڶ���ֵΪ0��ʾ���ع��
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void startup()              //��ֵ
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

void show()					//��ʾ����
{
	gotoxy(0, 0);
	int i, j;
	for (i = 0; i < high; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (i == postion_x && j == postion_y)
				printf("*");		//�ɻ�
			else if (i == bullet_x && j == bullet_y)
				printf("|");		//����
			else if (i == enemy_x && j == enemy_y)
				printf("+");		//�л�
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("�÷֣�%d\n", sorce);
}

void updateWithoutInput()	//���û������޹صĸ���
{
	if (bullet_x > -1)
		bullet_x--;			//�ӵ�������
	
	if (bullet_x == enemy_x && bullet_y == enemy_y)		//�ӵ��л�����
	{
		enemy_x = 0;		//�л���ʧ
		sorce++;			//������һ
		enemy_y = rand() % width;	//���λ�����ɵл�
		bullet_x = 0;		//�ӵ���ʧ
	}

	if (enemy_x > high)			//�л��ܳ���ʾ��Ļ
	{
		enemy_x = 0;			//�л�����
		enemy_y = rand() % width;
	}

	//���Ƶл�������ٶȣ�ÿ������ѭ�����ƶ�һ�εл�
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

void updateWithInput()		//���û������йصĸ���
{
	char input;
	if (_kbhit())
	{
		input = _getch();	//��ȡ�û����룬��������س�
		if (input == 'a' || input == 'A')
			postion_y--;
		if (input == 'd' || input == 'D')
			postion_y++;
		if (input == 'w' || input == 'W')
			postion_x--;
		if (input == 's' || input == 'S')
			postion_x++;
		if (input == 'j' || input == 'J')		//�������	
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