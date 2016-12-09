#include <stdio.h>

void quick_sort(int *a, int n);
int  similar(int A[], int B[]);
void solve(int test[]);

int N, K;

int sym[300] = {0};
int list[300][301];

int main(void)
{
	scanf("%d %d", &N, &K);

	sym[0] = 1;

	for(int i = 0; i < N; i++)
	{
		scanf("%d", &list[i][300]);
		for(int j = 0; j < list[i][300]; j++)
		{
			scanf("%d", &list[i][j]);
		}
		quick_sort(list[i], list[i][300]);
	}

	solve(list[0]);

	int counter = 0;
	for(int i = 0; i < N; i++)
	{
		if(sym[i]) counter++;
	}

	printf("%d\n", counter);

	return 0;
}

void solve(int test[])
{
	for(int i = 1; i < N; i++)
	{
		if(sym[i] == 0 && similar(test, list[i]))
		{
			sym[i] = 1;
			solve(list[i]);
		}
	}
}

int similar(int A[], int B[])
{
	int Ai = 0;
	int Bi = 0;

	int counter = 0;

	while(Ai < A[300] && Bi < B[300])
	{
		if(A[Ai] < B[Bi])
		{
			Ai++;
		}
		else if(A[Ai] == B[Bi])
		{
			counter++;

			Ai++;
			Bi++;
		}
		else
		{
			Bi++;
		}
	}

	return counter >= K;
}

void quick_sort(int *a, int n)
{
	if(n < 2) return;

	int i, j, p, t;
	p = a[n / 2];

	for(i = 0, j = n - 1;; i++, j--)
	{
		while(a[i] < p) i++;
		while(p < a[j]) j--;

		if(i >= j) break;

		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}

	quick_sort(a, i);
	quick_sort(a + i, n - i);
}
