#include <stdio.h>

long long sumSquare(long long n);
long long squareSum(long long n);

int main(void)
{
	printf("%lli\n", sumSquare(100) - squareSum(100));
	return 0;
}

long long sumSquare(long long n)
{
	return (n * n * (n + 1) * (n + 1)) / 4;
}

long long squareSum(long long n)
{
	return (n * (n + 1) * (n + n + 1)) / 6;
}
