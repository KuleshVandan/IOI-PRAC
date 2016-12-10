/*
ID: 25.8069758011 is the root of all evil
PROG: barn1
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>

void quicksort(int *A, int len);

int cows[200];
int diff[199];

int main(void)
{
	FILE *fin  = fopen("barn1.in", "r");
	FILE *fout = fopen("barn1.out", "w");

	int M, S, C;
	fscanf(fin, "%d %d %d", &M, &S, &C);

	for(int i = 0; i < C; i++)
	{
		fscanf(fin, "%d", &cows[i]);
	}
	quicksort(cows, C);

	for(int i = 1; i < C; i++)
	{
		diff[i - 1] = cows[i] - cows[i - 1] - 1;
	}

	quicksort(diff, C - 1);

	int covered = cows[C - 1] - cows[0] + 1;
	for(int i = C - 2; i >= C - M; i--)
	{
		covered -= diff[i];
	}

	fprintf(fout, "%d\n", covered);

	return 0;
}

void quicksort(int *A, int len)
{
  if (len < 2) return;
 
  int pivot = A[len / 2];
 
  int i, j;
  for (i = 0, j = len - 1; ; i++, j--)
  {
    while (A[i] < pivot) i++;
    while (A[j] > pivot) j--;
 
    if (i >= j) break;
 
    int temp = A[i];
    A[i]     = A[j];
    A[j]     = temp;
  }
 
  quicksort(A, i);
  quicksort(A + i, len - i);
}
