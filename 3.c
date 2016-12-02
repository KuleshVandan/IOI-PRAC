#include <stdio.h>

/**
 * Bad solution
 */

int main(void)
{
	long long N = 600851475143;

	long long p = 2;
	while(N != 1)
	{
		while(N % p == 0)
		{
			N /= p;
		}
		p++;
	}

	printf("%lli\n", p - 1);

	return 0;
}
