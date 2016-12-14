#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);

	int ai, bi, current = 0, max = 0;

	while(n--)
	{
		scanf("%d %d", &ai, &bi);
		current += bi - ai;

		if(current > max) max = current;
	}

	printf("%d\n", max);

	return 0;
}
