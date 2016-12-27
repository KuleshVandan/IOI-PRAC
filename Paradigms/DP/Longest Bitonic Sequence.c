#include <stdio.h>


int maxBitonicSumSS(int A[], int n);

int main(void)
{
  int A[] = {80, 60, 30, 40, 20, 10};
  int len = sizeof(A) / sizeof(A[0]);

  printf("%d\n", maxBitonicSumSS(A, len));

  return 0;
}

int maxBitonicSumSS(int A[], int n)
{
  int longIncF[n];
  int longIncB[n];

  longIncF[0] = 1;
  longIncB[n-1] = 1;

  for(int i = 1; i < n; i++)
  {
    int localMax = 0;
    for(int j = i - 1; j >= 0; j--)
    {
      if(A[i] > A[j] && longIncF[j] > localMax)
      {
        localMax = longIncF[j];
      }
      longIncF[i] = localMax + 1;
    }
  }
  for(int i = n - 2; i >= 0; i--)
  {
    int localMax = 0;
    for(int j = i + 1; j < n; j++)
    {
      if(A[i] > A[j] && longIncB[j] > localMax)
      {
        localMax = longIncB[j];
      }
      longIncB[i] = localMax + 1;
    }
  }

  int globalMax = 0;
  for(int i = 0; i < n; i++)
  {
    if(longIncF[i] + longIncB[i] - 1 > globalMax)
    {
      globalMax = longIncF[i] + longIncB[i] - 1;
    }
  }
  return globalMax;
}
