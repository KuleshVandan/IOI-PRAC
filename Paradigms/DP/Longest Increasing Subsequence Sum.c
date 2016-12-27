#include <stdio.h>


int incSumSS(int A[], int n);

int main(void)
{
  int A[] = {1, 101, 2, 3, 100, 4, 5};
  int len = sizeof(A) / sizeof(A[0]);

  printf("%d\n", incSumSS(A, len));

  return 0;
}

int incSumSS(int A[], int n)
{
  int maxSums[n];
  maxSums[0] = 1;

  int globalMax = 0;

  for(int i = 1; i < n; i++)
  {
    int localMax = 0;
    for(int j = i - 1; j >= 0; j--)
    {
      if(A[i] > A[j] && maxSums[j] > localMax)
      {
        localMax = maxSums[j];
      }
    }
    maxSums[i] = localMax + A[i];

    if(maxSums[i] > globalMax) globalMax = maxSums[i];
  }

  return globalMax;
}
