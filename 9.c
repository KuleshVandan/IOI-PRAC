#include <stdio.h>

int main(void)
{
	int n = 1000;			// a + b + c = n
  
	n /= 2;
	for(int r = 1; r <= n; r++)
	{
		if(n % r == 0)
		{
			int s = (n / r) - r;
			if(s > 0 && r > s)
			{
				printf("%d %d %d\n", r*r - s*s, 2*r*s, r*r + s*s);
				printf("Product is %d\n", (2*r*s) * (r*r - s*s) * (r*r + s*s));
			}
		}
	}

	return 0;
}
