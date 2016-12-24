/* Statement - http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/ */

#include <stdio.h>
#include <string.h>


int coinChange(int coins[], int m, int val);

int main(void)
{
  int coins[] = {2, 5, 3, 6};
  int len = sizeof(coins) / sizeof(coins[0]);
  int change = 10;

  printf("%d\n", coinChange(coins, len - 1, change));
  return 0;
}

int coinChange(int coins[], int m, int val)
{
  if(val == 0)    // you've hit a solution!
  {
    return 1;
  }

  if(val < 0 || m < 0)
  {
    return 0;
  }

  return coinChange(coins, m - 1, val) + coinChange(coins, m, val - coins[m]);
}
