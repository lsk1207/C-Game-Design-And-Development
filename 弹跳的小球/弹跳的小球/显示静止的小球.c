#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
int main()
{
	int i, j;
	int x = 0;
	int y = 5;
	int left = 0;
	int right = 20;
	int top = 0;
	int bottom = 10;
		
	int velocity_x = 1;
	int velocity_y = 1;
	
	while (1)
	{
		x = x + velocity_x;
		y = y + velocity_y;

		system("cls");
		for (i = 0; i < x; i++)
			printf("\n");
		for (j = 0; j < y; j++)
			printf(" ");
		printf("o");
		printf("\n");
		Sleep(50);

		if (x == top ||x == bottom)
			velocity_x = -velocity_x;
		if (x == left||x == right)
			velocity_y = -velocity_y;
	}
	return 0;
}