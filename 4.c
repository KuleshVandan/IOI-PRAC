#include <stdio.h>

/**
 * Bad solution
 */

int isPalindrome(int N);

int main(void)
{
	int largest = 0;
	for(int i = 100; i < 1000; i++)
	{
		for(int j = i; j < 1000; j++)
		{
			int product = i * j;
			if(product > largest && isPalindrome(product))
			{
				largest = product;
			}
		}
	}

	printf("%d\n", largest);

	return 0;
}

int isPalindrome(int N)
{
	int reverse = 0, temp = N;
	while(temp != 0)
	{
		reverse = (reverse * 10) + (temp % 10);
		temp /= 10;
	}
	return N == reverse;
}
