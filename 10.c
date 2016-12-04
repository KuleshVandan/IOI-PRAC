#include <stdio.h>
#include <math.h>

#define  UPPERLIM  2000000

int main(void)
{
	unsigned int primes[UPPERLIM + 2] = {0};	// 0 = prime, 1 = composite
	                                          // primes[UPPERLIM + 1] is sentinel

	primes[0] = 1;
	primes[1] = 1;

	unsigned int nextPrime = 2;
	while(nextPrime <= (int) sqrt(UPPERLIM))
	{
		primes[nextPrime] = 0;

		for(unsigned int i = nextPrime * nextPrime; i <= UPPERLIM; i += nextPrime)
		{
			primes[i] = 1;
		}

		while(primes[++nextPrime] == 1)
			;
	}

	// Find the sum of primes

	unsigned long long sum = 0;
	for(unsigned int i = 0; i <= UPPERLIM; i++)
	{
		if(primes[i] == 0)
		{
			sum += i;
			printf("|%llu\n", i);
		}
	}
	printf("%llu\n", sum);

	return 0;
}
