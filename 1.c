#include <stdio.h>

int multipleSum(int a, int N);

int main(void)
{
	int a = 3, b = 5;

	printf("%d\n", multipleSum(3, 999) + multipleSum(5, 999) - multipleSum(15, 999));

	return 0;
}

int multipleSum(int a, int N)
{
	N /= a;
	return (a * (N) * (N + 1)) / 2;
}
