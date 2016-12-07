/*
ID: erm
PROG: gift1
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  NAMELEN  14

int getIndex(char A[][NAMELEN + 1], char str[]);

int NP;

int main(void)
{
	FILE *fin  = fopen("gift1.in", "r");
	FILE *fout = fopen("gift1.out", "w");

	fscanf(fin, "%d", &NP);

	char names[NP][NAMELEN + 1];
	int fmoney[NP];

	for(int i = 0; i < NP; i++)
	{
		fscanf(fin, "%s", names[i]);
		fmoney[i] = 0;
	}

	char curStr[NAMELEN + 1];
	while(fscanf(fin, "%s", curStr) != EOF)
	{
		int curStrInd = getIndex(names, curStr);

		int money, friends;
		fscanf(fin, "%d %d", &money, &friends);

		if(friends > 0)
		{
			fmoney[curStrInd] -= money;

			int moneyDiv = money / friends;
			char cFriend[NAMELEN + 1];

			for(int i = 0; i < friends; i++)
			{
				fscanf(fin, "%s", cFriend);
				int fIndex = getIndex(names, cFriend);

				fmoney[fIndex] += moneyDiv;
				money -= moneyDiv;
			}

			fmoney[curStrInd] += money; 
		}
	}

	for(int i = 0; i < NP; i++)
	{
		fprintf(fout, "%s %d\n", names[i], fmoney[i]);
	}

	return 0;
}

int getIndex(char A[][NAMELEN + 1], char str[])
{
	for(int i = 0; i < NP; i++)
	{
		if(strcmp(A[i], str) == 0)
		{
			return i;
		}
	}
	return EOF;
}
