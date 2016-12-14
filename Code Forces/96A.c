#include <stdio.h>

int main(void)
{
	int cons0 = 0;
	int cons1 = 0;

	int situation = 0;

	char c;
	while((c = getchar()) != '\n' && situation == 0)
	{
		if(c == '0')
		{
			cons0++;
			cons1 = 0;
		}
		else
		{
			cons1++;
			cons0 = 0;
		}

		if(cons0 == 7 || cons1 == 7)
		{
			situation = 1;
		}
	}

	printf("%s\n", situation == 1 ? "YES" : "NO");

	return 0;
}
