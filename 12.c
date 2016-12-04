#include <stdio.h>

int divisorCount(int N);

int main(void)
{
	int trnum = 1;
	for(int i = 2; divisorCount(trnum) <= 500; i++)
	{
		trnum += i;
	}
	printf("%d\n", trnum);

	return 0;
}

int divisorCount(int N)
{
	int counter = 1;
	int prime = 1;

	while(N != 1)
	{
		while(N % ++prime != 0)
			;

		int power = 0;
		while(N % prime == 0)
		{
			N /= prime;
			power++;
		}
		counter *= power + 1;
	}

	return counter;
}
