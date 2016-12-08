/*
ID: abadddasstrashh
PROG: namenum
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>

#define  MAXLINELEN  12

long long hash(char *str);

int main(void)
{
	FILE *fin  = fopen("namenum.in", "r");
	FILE *fout = fopen("namenum.out", "w");

	FILE *dict = fopen("dict.txt", "r");

	long long N;
	fscanf(fin, "%lli", &N);

	int occurance = 0;

	char line[MAXLINELEN];

	while(fscanf(dict, "%s", line) != EOF)
	{
		if(hash(line) == N)
		{
			fprintf(fout, "%s\n", line);
			occurance = 1;
		}
	}

	if(occurance == 0) fprintf(fout, "NONE\n");

	return 0;
}

int value(char s)
{
	int v = s - 'A' + 1;

	if(1 <= v && v <= 3)
	{
		return 2;
	}
	else if(4 <= v && v <= 6)
	{
		return 3;
	}
	else if(7 <= v && v <= 9)
	{
		return 4;
	}
	else if(10 <= v && v <= 12)
	{
		return 5;
	}
	else if(13 <= v && v <= 15)
	{
		return 6;
	}
	else if(16 <= v && v <= 19)
	{
		return 7;
	}
	else if(20 <= v && v <= 22)
	{
		return 8;
	}
	else
	{
		return 9;
	}
}

long long hash(char *str)		// convert string to number
{
	long long result = value(*(str++));
	while(*str != '\0')
	{
		result = result * 10 + value(*(str++));
	}
	return result;
}
