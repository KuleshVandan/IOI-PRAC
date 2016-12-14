#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);

	int  X = 0;
	char statement[4];

	while(n--)
	{
		scanf("%s", statement);
		if(statement[1] == '+')
		{
			X++;
		}
		else
		{
			X--;
		}
	}

	printf("%d\n", X);

	return 0;
}
