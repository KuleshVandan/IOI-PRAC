/*
ID: erm
PROG: friday
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>

int isleapyear(int year);

int main(void)
{
	FILE *fin  = fopen("friday.in", "r");
	FILE *fout = fopen("friday.out", "w");

	int N;
	fscanf(fin, "%d", &N);

	int days[2][12] = {
		{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	};

	int freq[7] = {0};

	int day13 = 0;			// 0 = Sat, 1 = Sun, 2 = Mon..
	for(int year = 1900; year < 1900 + N; year++)
	{
		int isleap = isleapyear(year);

		for(int month = 0; month < 12; month++)
		{
			freq[day13]++;
			day13 = (day13 + days[isleap][month]) % 7;
		}
	}

	for(int i = 0; i < 7; i++)
	{
		fprintf(fout, "%d", freq[i]);
		if(i < 6) fprintf(fout, " ");
	}
	fprintf(fout, "\n");

	return 0;
}

int isleapyear(int year)
{
	return year % 4 == 0 && !((year % 100 == 0) ^ (year % 400 == 0));
}
