#include <stdio.h>

long long lcm(long long a, long long b);

int main(void)
{
	long long num = 1;
	for(int i = 2; i <= 20; i++)
	{
		num = lcm(num, i);
	}

	printf("%d\n", num);

	return 0;
}

long long gcd(long long a, long long b)
{
	long long temp;
	while (b != 0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

long long lcm(long long a, long long b)
{
	return (a * b) / gcd(a, b);
}
