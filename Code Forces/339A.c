#include <stdio.h>

int main(void)
{
	int one = 0,two = 0, three = 0;

	char c;
	while((c = getchar()) != '\n')
	{
		switch(c)
		{
			case '1':
				one++;
				break;
			case '2':
				two++;
				break;
			case '3':
				three++;
				break;
		}
	}

	int total = one + two + three;

	for(int i = 0; i < one; i++)
	{
		putchar('1');
		if(i < total - 1)
		{
			putchar('+');
		}
	}
	total -= one;

	for(int i = 0; i < two; i++)
	{
		putchar('2');
		if(i < total - 1)
		{
			putchar('+');
		}
	}
	total -= two;

	for(int i = 0; i < three; i++)
	{
		putchar('3');
		if(i < total - 1)
		{
			putchar('+');
		}
	}

	return 0;
}
