/*
ID: ahem
PROG: transform
LANG: C
*/

/**
 * This code could be refactored into
 * something much better
 */

#include <stdio.h>
#include <stdlib.h>

int N;

void rotate90(char A[][N]);
void reflectH(char A[][N]);

int compare(char A[][N], char B[][N]);

int main(void)
{
	FILE *fin  = fopen("transform.in", "r");
	FILE *fout = fopen("transform.out", "w");

	fscanf(fin, "%d", &N);

	char iniGrid[N][N], finGrid[N][N];

	for(int i = 0; i < N; i++)
	{
		fgetc(fin);
		for(int j = 0; j < N; j++)
		{
			iniGrid[i][j] = fgetc(fin);
		}
	}

	for(int i = 0; i < N; i++)
	{
		fgetc(fin);
		for(int j = 0; j < N; j++)
		{
			finGrid[i][j] = fgetc(fin);
		}
	}

	int min = 7;

	if(compare(iniGrid, finGrid))
	{
		if(6 < min) min = 6;
	}

	rotate90(iniGrid);
	if(compare(iniGrid, finGrid))
	{
		if(1 < min) min = 1;
	}

	rotate90(iniGrid);
	if(compare(iniGrid, finGrid))
	{
		if(2 < min) min = 2;
	}

	rotate90(iniGrid);
	if(compare(iniGrid, finGrid))
	{
		if(3 < min) min = 3;
	}

	rotate90(iniGrid);
	reflectH(iniGrid);
	if(compare(iniGrid, finGrid))
	{
		if(4 < min) min = 4;
	}

	rotate90(iniGrid);
	if(compare(iniGrid, finGrid))
	{
		if(5 < min) min = 5;
	}

	rotate90(iniGrid);
	if(compare(iniGrid, finGrid))
	{
		if(5 < min) min = 5;
	}

	rotate90(iniGrid);
	if(compare(iniGrid, finGrid))
	{
		if(5 < min) min = 5;
	}

	fprintf(fout, "%d\n", min);

	return 0;
}

int compare(char A[][N], char B[][N])
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(A[i][j] != B[i][j]) return 0;
		}
	}

	return 1;
}

void rotate90(char A[][N])
{
	for(int i = 0; i < N; i++)  			// transpose
	{
		for(int j = i + 1; j < N; j++)
		{
			char tem = A[i][j];
			A[i][j]  = A[j][i];
			A[j][i]  = tem;
		}
	}

	reflectH(A);
}

void reflectH(char A[][N])
{
	for(int j = 0; j < N/2; j++)
	{
		for(int i = 0; i < N; i++)
		{
			char tem    = A[i][j];
			A[i][j]     = A[i][N-j-1];
			A[i][N-j-1] = tem;
		}
	}
}
