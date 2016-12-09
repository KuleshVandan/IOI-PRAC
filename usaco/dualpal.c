/*
ID: args
PROG: dualpal
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>

#define  MAXLEN  32

int palIn2B(int n);

int main(void)
{
	FILE *fin  = fopen("dualpal.in", "r");
	FILE *fout = fopen("dualpal.out", "w");

	int N, S;
	fscanf(fin, "%d %d", &N, &S);

	int count = 0;
	while(count < N)
	{
		S++;
		if(palIn2B(S))
		{
			fprintf(fout, "%d\n", S);
			count++;
		}
	}

	return 0;
}

int digits[MAXLEN + 1];

int isPalInB(int n, int B)		// B <= 10
{
	int len = 0;
	while(n > 0)
	{
		digits[len++] = n % B;
		n /= B;
	}

	for(int i = len - 1, j = 0; j < len / 2; i--, j++)
	{
		if(digits[i] != digits[j])
		{
			return 0;
		}
	}

	return 1;
}

int palIn2B(int n)						// is n pal in atleast 2 B
{
	int count = 0;
	for(int i = 2; i <= 10 && count < 2; i++)
	{
		count += isPalInB(n, i);
	}
	return count == 2;
}
