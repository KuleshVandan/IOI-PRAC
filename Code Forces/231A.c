#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);

	int count = 0;
	int p, v, t;

	while(n--)
	{
		scanf("%d %d %d", &p, &v, &t);
		if(p + v + t >= 2) count++;
	}

	printf("%d\n", count);

	return 0;
}
