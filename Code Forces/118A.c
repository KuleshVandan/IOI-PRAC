#include <stdio.h>
#include <ctype.h>
#include <string.h>

int inVowel(char elem);

int main(void)
{
	char str[101];
	scanf("%s", str);

	char c;

	for(int i = 0; i < strlen(str); i++)
	{
		if(!inVowel(c = tolower(str[i])))
		{
			putchar('.');
			putchar(c);
		}
	}
	putchar('\n');

	return 0;
}

int inVowel(char elem)
{
	static char vowels[6] = {'a', 'o', 'y', 'e', 'u','i'};

	for(int i = 0; i < 6; i++)
	{
		if(vowels[i] == elem)
		{
			return 1;
		}
	}
	return 0;
}
