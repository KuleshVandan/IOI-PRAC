#include <stdio.h>
#include <stdlib.h>

#define  SIZE      15
#define  MAX(a, b) (((a) > (b)) ? (a) : (b))

int main(void)
{
	int *lattice[SIZE];

	for(int i = 0; i < SIZE; i++)
	{
		lattice[i] = malloc(sizeof(int) * (i + 1));

		for(int j = 0; j <= i; j++)
		{
			scanf("%d", (lattice[i] + j));
		}
	}

	for(int i = SIZE - 2; i >= 0; i--)
	{
		for(int j = 0; j <= i; j++)
		{
			lattice[i][j] += MAX(lattice[i + 1][j], lattice[i + 1][j + 1]);
		}
	}

	printf("%d\n", lattice[0][0]);

	return 0;
}
