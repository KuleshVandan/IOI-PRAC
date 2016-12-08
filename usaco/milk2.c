/*
ID: argh
PROG: milk2
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>

#define  MAXLEN  5000

void quick_sort(int A[][2], int N);

int main(void)
{
	FILE *fin  = fopen("milk2.in", "r");
	FILE *fout = fopen("milk2.out", "w");

	int N;
	fscanf(fin, "%d", &N);

	int timings[MAXLEN][2];		// [k][0] is start, [k][1] is end
	for(int i = 0; i < N; i++)
	{
		fscanf(fin, "%d %d", &timings[i][0], &timings[i][1]);
	}

	quick_sort(timings, N);

	int maxMilk = 0;
	int minMilk = 0;

	int prevMax = 0;

	int startMilk = timings[0][0];

	for(int i = 0; i < N - 1; i++)
	{
		if(timings[i][1] - startMilk > maxMilk) maxMilk = timings[i][1] - startMilk;
		if(timings[i][1] > prevMax) prevMax = timings[i][1];

		if(timings[i + 1][0] > prevMax)
		{
			startMilk = timings[i + 1][0];
		}

		if(timings[i + 1][0] - prevMax > minMilk) minMilk = timings[i + 1][0] - prevMax;
	}

	if(timings[N - 1][1] - startMilk > maxMilk) maxMilk = timings[N - 1][1] - startMilk;

	fprintf(fout, "%d %d\n", maxMilk, minMilk);

	return 0;
}

void quick_sort(int A[][2], int N)
{
	if(N < 2) return;

	int i, j;
	int pivot = A[N / 2][0];

	for (i = 0, j = N - 1; ; i++, j--)
	{
		while (A[i][0] < pivot) i++;
		while (A[j][0] > pivot) j--;

		if (i >= j) break;

		int swapTemp0 = A[i][0];
		int swapTemp1 = A[i][1];

		A[i][0] = A[j][0];
		A[i][1] = A[j][1];

		A[j][0] = swapTemp0;
		A[j][1] = swapTemp1;
	}

	quick_sort(A, i);
	quick_sort(A + i, N - i);
}
