#include <stdio.h>

#define  PRIMEIND  10001

/**
 * Bad solution
 *
 * Use sieve along with prime approximation
 * for faster solution
 */

int isprime(int n);

int main(void)
{
	int i, counter = 0;
	for(i = 1; counter < PRIMEIND; i++)
	{
		if(isprime(i))
		{
			counter++;
		}
	}

	printf("%d\n", i - 1);

	return 0;
}

int isprime(int n)
{
	if(n == 2)
	{
		return 1;
	}

	if(n % 2 == 0 || n == 1)
	{
		return 0;
	}

	for(int i = 3; i * i <= n; i += 2)
	{
		if(n % i == 0)
		{
			return 0;
		}
	}

	return 1;
}
