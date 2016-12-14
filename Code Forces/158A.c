#include <stdio.h>

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);

	int list[50];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &list[i]);
	}

	int count = 0;
	while(count < n && list[count] > 0 && list[count] >= list[k - 1])
	{
		count++;
	}

	printf("%d\n", count);

	return 0;
}
