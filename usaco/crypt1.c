/*
ID: need help in writing horrible unreadable code?
PROG: crypt1
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>

int N;
int digits[9];

int inDigit(int n);

int main(void)
{
	FILE *fin  = fopen("crypt1.in", "r");
	FILE *fout = fopen("crypt1.out", "w");

	fscanf(fin, "%d", &N);

	for(int i = 0; i < N; i++)
	{
		fscanf(fin, "%d", &digits[i]);
	}

	int count = 0;
	for(int product = 1111; product <= 9999; product++)
	{
		if(inDigit(product))
		{
			for(int d = 11; d <= 99; d++)
			{
				if(product % d == 0)
				{
					int m = product / d;
					if(
						m >= 111 							&&
						(m * (d % 10)) >= 111 &&
						(m * (d / 10)) >= 111 &&
						(m * (d % 10)) <= 999 &&
						(m * (d / 10)) <= 999 &&
						inDigit(d) 						&&
						inDigit(m) 						&&
						inDigit(m * (d % 10)) &&
						inDigit(m * (d / 10))
						)
					{
						count++;
					}
				}
			}
		}
	}

	fprintf(fout, "%d\n", count);

	return 0;
}

int search(int d)
{
	for(int i = 0; i < N; i++)
	{
		if(digits[i] == d)
		{
			return 1;
		}
	}
	return 0;
}

int inDigit(int n)
{
	while(n > 0)
	{
		if(!search(n % 10))
		{
			return 0;
		}
		n /= 10;
	}
	return 1;
}
