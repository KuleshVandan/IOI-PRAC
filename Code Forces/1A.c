#include <stdio.h>

long long ceiling(long long a, long long d)
{
	if(a % d == 0)
	{
		return a/d;
	}
	else
	{
		return a/d + 1;
	}
}

int main(void)
{
	long long n, m, a;
	scanf("%I64d %I64d %I64d", &n, &m, &a);

	printf("%I64d\n", ceiling(n, a) * ceiling(m, a));
	return 0;
}
