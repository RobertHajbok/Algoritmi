#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int mat[9][9];
int out[9][9];
int Val_init(int x, int y, int val)
{
	int i, j;
	//Scaneaza orizontal si vertical
	for (i = 0; i < 9; i++)
		if (val == out[i][y] || val == out[x][i])
			return 0;
	//Scaneaza propriul patrat
	if (x < 3)
	{
		if (y < 3)
		{
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					if (val == out[i][j])
					{
						return 0;
					}
				}
			}
		}
		else if (y < 6)
		{
			for (i = 0; i < 3; i++)
			{
				for (j = 3; j < 6; j++)
				{
					if (val == out[i][j])
					{
						return 0;
					}
				}
			}
		}
		else
		{
			for (i = 0; i < 3; i++)
			{
				for (j = 6; j < 9; j++)
				{
					if (val == out[i][j])
					{
						return 0;
					}
				}
			}
		}
	}
	else if (x < 6)
	{
		if (y < 3)
		{
			for (i = 3; i < 6; i++)
			{
				for (j = 0; j < 3; j++)
				{
					if (val == out[i][j])
					{
						return 0;
					}
				}
			}
		}
		else if (y < 6)
		{
			for (i = 3; i < 6; i++)
			{
				for (j = 3; j < 6; j++)
				{
					if (val == out[i][j])
					{
						return 0;
					}
				}
			}
		}
		else
		{
			for (i = 3; i < 6; i++)
			{
				for (j = 6; j < 9; j++)
				{
					if (val == out[i][j])
					{
						return 0;
					}
				}
			}
		}
	}
	else
	{
		if (y < 3)
		{
			for (i = 6; i < 9; i++)
			{
				for (j = 0; j < 3; j++)
				{
					if (val == out[i][j])
					{
						return 0;
					}
				}
			}
		}
		else if (y < 6)
		{
			for (i = 6; i < 9; i++)
			{
				for (j = 3; j < 6; j++)
				{
					if (val == out[i][j])
					{
						return 0;
					}
				}
			}
		}
		else
		{
			for (i = 6; i < 9; i++)
			{
				for (j = 6; j < 9; j++)
				{
					if (val == out[i][j])
					{
						return 0;
					}
				}
			}
		}
	}
	return val;
}
int backtrack(int x, int y)
{
	int temp, i;
	if (out[x][y] == 0)
	{
		for (i = 1; i < 10; i++)
		{
			temp = Val_init(x, y, i);
			if (temp > 0)
			{
				out[x][y] = temp;
				if (x == 8 && y == 8)
					return 1;
				else if (x == 8)
				{
					if (backtrack(0, y + 1))
						return 1;
				}
				else
				{
					if (backtrack(x + 1, y))
						return 1;
				}
			}
		}
		if (i == 10)
		{
			if (out[x][y] != mat[x][y])
				out[x][y] = 0;
			return 0;
		}
	}
	else
	{
		if (x == 8 && y == 8)
		{
			return 1;
		}
		else if (x == 8)
		{
			if (backtrack(0, y + 1))
				return 1;
		}
		else
		{
			if (backtrack(x + 1, y))
				return 1;
		}
	}
}
void main()
{
	int i, j;
	FILE* f;
	printf("Sudokul de rezolvat este :\n");
	f = fopen("sudoku_in.txt", "r");
	for (i = 0; i < 9; i++)
	{
		fscanf(f, "%d %d %d %d %d %d %d %d %d", &mat[i][0], &mat[i][1], &mat[i][2], &mat[i][3], &mat[i][4], &mat[i][5], &mat[i][6], &mat[i][7], &mat[i][8]);
	}
	fclose(f);
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			out[i][j] = mat[i][j];
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
	if (backtrack(0, 0))
	{
		printf("Solutia este :\n");
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
				printf("%d ", out[i][j]);
			printf("\n");
		}
	}
	else
		printf("Nu exista solutie!\n");
	_getch();
}
