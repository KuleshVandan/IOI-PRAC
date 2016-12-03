#include <stdio.h>
#include <math.h>

int main(void)
{
	int n = 1000;			// a + b + c = n
	n /= 2;

	for(int r = (int) sqrt(n / 2); r <= (int) sqrt(n); r++)
	{
		if(n % r == 0)
		{
			int s = (n / r) - r;
			printf("%d %d %d\n", r*r - s*s, 2*r*s, r*r + s*s);
			// now just find their product
		}
	}

	return 0;
}
