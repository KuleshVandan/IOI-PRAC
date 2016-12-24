#include <stdio.h>


int longestIncSSlen(int A[], int length);

int main(void)
{
  int A[] = {10, 22, 9, 33, 21, 50, 41, 60};
  int len = sizeof(A) / sizeof(A[0]);

  printf("%d\n", longestIncSSlen(A, len));
  return 0;
}

int longestIncSSlen(int A[], int length)
{
  int SSlen[length];

  int globalMax = 0;
  for(int i = 0; i < length; i++)
  {
    int tempMax = 0;
    for(int j = i - 1; j >= 0; j--)
    {
      if(A[j] < A[i] && SSlen[j] > tempMax)
      {
        tempMax = SSlen[j];
      }
    }
    SSlen[i] = tempMax + 1;

    if(SSlen[i] > globalMax) globalMax = SSlen[i];
  }

  return globalMax;
}
