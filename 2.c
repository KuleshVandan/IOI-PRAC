#include <stdio.h>

int main(void)
{
	int count = 0;

	int a = 1, b = 1;
	while(b < 4000000)
	{
		a += b;
		b += a;

		if(a % 2 == 0)
		{
			count += a;
		}

		if(b % 2 == 0)
		{
			count += b;
		}
	}

	printf("%d\n", count);

	return 0;
}
