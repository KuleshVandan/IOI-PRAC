#include <stdio.h>
#include <string.h>


int longestCommonSS(char A[], int aEnd, char B[], int bEnd);

int main(void)
{
  char A[] = "AGGTAB";
  char B[] = "GXTXAYB";

  int lenA = strlen(A);
  int lenB = strlen(B);

  printf("%d\n", longestCommonSS(A, lenA, B, lenB));
  return 0;
}

int max(int a, int b)
{
  return a > b ? a : b;
}

int longestCommonSS(char A[], int aLen, char B[], int bLen)
{
  int memo[aLen + 1][bLen + 1];

  for(int i = 0; i <= aLen; i++)
  {
    memo[i][0] = 0;
  }
  for(int j = 0; j <= bLen; j++)
  {
    memo[0][j] = 0;
  }

  for(int i = 1; i <= aLen; i++)
  {
    for(int j = 1; j <= bLen; j++)
    {
      if(A[i] == B[j])
      {
        memo[i][j] = memo[i - 1][j - 1] + 1;
      }
      else
      {
        memo[i][j] = max(memo[i][j - 1], memo[i - 1][j]);
      }
    }
  }

  return memo[aLen][bLen];
}
