#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
	int i, j;
	int x = 5;
	int y = 10;
	char input;
	int isFire = 0;

	int ny = 5;
	int isKilled = 0;

	while (1)
	{
			system("cls");
	 	
			if (!isKilled)
			{
				for (j = 0; j < ny; j++)
					printf(" ");
				printf("+");
			}

			if (isFire == 0)
			{
				for (i = 0; i < x; i++)
					printf("\n");
			}
			else
			{
				for (i = 0; i < x; i++)
				{
					for (j = 0; j < y; j++)
						printf(" ");
					printf("  |\n");
				}
				if (y + 2 == ny)
					isKilled = 1;
				isFire = 0;
			}

			for (j = 0; j < y; j++) 
				printf(" ");
			printf("  *\n");
			for (j = 0; j < y; j++)
				printf(" ");
			printf("*****\n");
			for (j = 0; j < y; j++)
				printf(" ");
			printf(" * * \n");
			if (_kbhit())
			{
				input = _getch();
				if (input == 'a'||input=='A') 
					y--;
				if (input == 'd'||input=='D')
					y++;
				if (input == 's'||input=='S')
					x++;
				if (input == 'w'||input=='W')
					x--;
				if (input == 'j'||input=='J')
					isFire = 1;
			}
		}
		return 0;
	}