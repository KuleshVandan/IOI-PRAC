/*
ID: yashary1
PROG: beads
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>

#define  MAX(a, b)  (((a) > (b)) ? (a) : (b))

int beadCount(int start, char beads[], int len);

int main(void)
{
	FILE *fin  = fopen("beads.in", "r");
	FILE *fout = fopen("beads.out", "w");

	int N;
	fscanf(fin, "%d", &N);

	fgetc(fin);

	char beads[N];
	for(int i = 0; i < N; i++)
	{
		beads[i] = fgetc(fin);
	}

	int max = 0;
	for(int i = 0; i < N; i++)
	{
		int currentBeads = beadCount(i, beads, N);
		if(currentBeads > max) max = currentBeads;
	}

	fprintf(fout, "%d\n", max);

	return 0;
}

int mod(int a, int b)
{
	int r = a % b;
	return r < 0 ? r + b : r;
}

int cmp(int ind, int s, int e)
{
	if(s > e)
	{
		return s < ind || ind < e;
	}
	else if(s == e)
	{
		return ind != s;
	}
	else
	{
		return s < ind && ind < e;
	}
}

int beadCount(int start, char beads[], int len)
{
	int maxLeft  = 0;
	int maxRight = 0;

	int leftRInd  = mod(start - 1, len);
	int leftBInd  = mod(start - 1, len);
	int rightRInd = mod(start, len);
	int rightBInd = mod(start, len);

	{
		int leftRed = 0;
		int leftBlu = 0;

		while((beads[leftRInd] == 'r' || beads[leftRInd] == 'w') && leftRed < len)
		{
			leftRed++;
			leftRInd = mod(leftRInd - 1, len);
		}

		while((beads[leftBInd] == 'b' || beads[leftBInd] == 'w') && leftBlu < len)
		{
			leftBlu++;
			leftBInd = mod(leftBInd - 1, len);
		}

		if(leftRed > leftBlu)
		{
			maxLeft  = leftRed;

			leftBInd = mod(leftRInd + 1, len);
			leftRInd = mod(start - 1, len);
		}
		else
		{
			maxLeft  = leftBlu;

			leftRInd = mod(start - 1, len);
			leftBInd = mod(leftBInd + 1, len);
		}
	}

	{
		int rightRed = 0;
		int rightBlu = 0;

		while((beads[rightRInd] == 'r' || beads[rightRInd] == 'w') && rightRed < len && cmp(rightRInd, leftRInd, leftBInd))
		{
			rightRed++;
			rightRInd = mod(rightRInd + 1, len);
		}

		while((beads[rightBInd] == 'b' || beads[rightBInd] == 'w') && rightBlu < len && cmp(rightBInd, leftRInd, leftBInd))
		{
			rightBlu++;
			rightBInd = mod(rightBInd + 1, len);
		}

		maxRight = MAX(rightRed, rightBlu);
	}

	return maxLeft + maxRight;
}
