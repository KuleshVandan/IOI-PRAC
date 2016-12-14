#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);

	int si[4] = {0};
	int cur;

	while(n--)
	{
		scanf("%d", &cur);
		si[cur - 1]++;
	}

	int count = si[2] + si[3];

	si[0] -= si[2];
	si[0]  = si[0] < 0 ? 0 : si[0];

	count += si[1]/2;

	if(si[1] % 2 == 1)
	{
		count++;
		if(si[0] >= 2)
		{
			si[0] -= 2;
		}
		else if(si[0] == 1)
		{
			si[0] -= 1;
		}
	}

	count += si[0] / 4 + (si[0] % 4 != 0);

	printf("%d\n", count);

	return 0;
}
