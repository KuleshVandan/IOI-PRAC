#include <stdio.h>

#define  SIDELEN  20

int main(void)
{
	int grid[SIDELEN][SIDELEN];
	for(int i = 0; i < SIDELEN; i++)
	{
		for(int j = 0; j < SIDELEN; j++)
		{
			scanf("%d", &grid[i][j]);
		}
	}

	int max = 0;

	// LEFT-RIGHT
	for(int i = 0; i < SIDELEN; i++)
	{
		for(int j = 0; j < SIDELEN - 3; j++)
		{
			int product = grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3];
			if(product > max)
			{
				max = product;
			}
		}
	}

	//UP-DOWN
	for(int i = 0; i < SIDELEN - 3; i++)
	{
		for(int j = 0; j < SIDELEN; j++)
		{
			int product = grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j];
			if(product > max)
			{
				max = product;
			}
		}
	}

	//TOP LEFT RIGHT BOTTOM DIAGONAL
	for(int i = 0; i < SIDELEN - 3; i++)
	{
		for(int j = 0; j < SIDELEN - 3; j++)
		{
			int product = grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3];
			if(product > max)
			{
				max = product;
			}
		}
	}

	// TOP RIGHT LEFT BOTTOM DIAGONAL
	for(int i = 0; i < SIDELEN - 3; i++)
	{
		for(int j = 3; j < SIDELEN; j++)
		{
			int product = grid[i][j] * grid[i + 1][j - 1] * grid[i + 2][j - 2] * grid[i + 3][j - 3];
			if(product > max)
			{
				max = product;
			}
		}
	}

	printf("%d\n", max);

	return 0;
}
