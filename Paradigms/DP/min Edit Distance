#include <stdio.h>
#include <string.h>


int editDistance(char A[], int aEnd, char B[], int bEnd);

int main(void)
{
  char A[] = "cat";
  char B[] = "cut";

  int lenA = strlen(A);
  int lenB = strlen(B);

  printf("%d\n", editDistance(A, lenA, B, lenB));
  return 0;
}

int min(int a, int b, int c)
{
  if(b < a) a = b;
  if(c < a) a = c;
  return a;
}

int editDistance(char A[], int aLen, char B[], int bLen)
{
  int memo[aLen + 1][bLen + 1];

  for(int i = 0; i <= aLen; i++)
  {
    memo[i][0] = i;
  }
  for(int j = 0; j <= bLen; j++)
  {
    memo[0][j] = j;
  }

  for(int i = 1; i <= aLen; i++)
  {
    for(int j = 1; j <= bLen; j++)
    {
      if(A[i] == B[j])
      {
        memo[i][j] = memo[i - 1][j - 1];
      }
      else
      {
        memo[i][j] = min(memo[i - 1][j - 1], memo[i - 1][j], memo[i][j - 1]) + 1;
      }
    }
  }

  return memo[aLen][bLen];
}
