#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
	int n;
	scanf("%d", &n);

	char str1[101], str2[101];
	int index = 0;

	while((str1[index++] = tolower(getchar())) != '\n')
		;

	str1[index] = '\0';
	index = 0;

	while((str2[index++] = tolower(getchar())) != '\n')
		;

	str2[index] = '\0';

	int comp = strcmp(str1, str2);

	if(comp < 0)
	{
		printf("-1\n");
	}
	else if(comp > 0)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}

	return 0;
}
