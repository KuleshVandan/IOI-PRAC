#include <stdio.h>

int modMexp(int n, int M);
int periodicStrCount(int d, int M);

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);

	int periodicStrs = periodicStrCount(N, M);
	int totalStrs    = modMexp(N, M);

	int nonPeriodicStrs = totalStrs - periodicStrs;
	printf("%d\n", nonPeriodicStrs + (nonPeriodicStrs < 0 ? M : 0));

	return 0;
}

/**
 * Return 2^n mod  M
 */

int modMexp(int n, int M)
{
	int result = 1;

	for(int i = 0; i < n; i++)
	{
		result *= 2;
		result %= M;
	}

	return result;
}

int periodicStrCount(int N, int M)
{
	int total = 0;
	for(int d = 1; d < N; d++)
	{
		if(N % d == 0)
		{
			total += modMexp(d, M) - periodicStrCount(d, M);
			total %= M;
		}
	}

	return total;
}
