/*
ID: leananddab
PROG: milk
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>

struct farmer
{
	int cost;
	int units;
} list[5000];

void quicksort(struct farmer A[], int len);

int main(void)
{
	FILE *fin  = fopen("milk.in", "r");
	FILE *fout = fopen("milk.out", "w");

	int unitsReq, cFarmers;
	fscanf(fin, "%d %d", &unitsReq, &cFarmers);

	for(int i = 0; i < cFarmers; i++)
	{
		fscanf(fin, "%d %d", &list[i].cost, &list[i].units);
	}

	quicksort(list, cFarmers);

	int tcost = 0, i = 0;
	while(unitsReq > list[i].units)
	{
		tcost += list[i].units * list[i].cost;
		unitsReq -= list[i].units;
		i++;
	}
	tcost += unitsReq * list[i].cost;

	fprintf(fout, "%d\n", tcost);

	return 0;
}

void quicksort(struct farmer *A, int len)
{
  if (len < 2) return;
 
  int pivot = A[len / 2].cost;
 
  int i, j;
  for (i = 0, j = len - 1; ; i++, j--)
  {
    while (A[i].cost < pivot) i++;
    while (A[j].cost > pivot) j--;
 
    if (i >= j) break;
 
    struct farmer temp  = A[i];
    A[i] = A[j];
    A[j] = temp;
  }
 
  quicksort(A, i);
  quicksort(A + i, len - i);
}
