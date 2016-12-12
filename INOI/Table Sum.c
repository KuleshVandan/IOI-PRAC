#include <stdio.h>

#define  MAXN  200000

// sorry bad code

int main (void)
{
  int N;
  scanf("%d", &N);

  int tempMax[MAXN][2];
  int index = 0;

  int current;
  scanf("%d", &current);

  tempMax[index][0] = current + 1;
  tempMax[index++][1] = N - 1;

  for(int i = 1; i < N; i++)
  {
    scanf("%d", &current);
    if(current + i + 1 > tempMax[index - 1][0])
    {
       tempMax[index][0] = current + i + 1;
       tempMax[index++][1] = N - i - 1;
    }
  }

  int minima = tempMax[index - 1][0] + tempMax[index - 1][1] + 1 - N, i;
  for(i = 0; i < index && minima >= tempMax[i][0] + tempMax[index - 1][1] + 1; i++)
    ;

  if(i != 0)
  {
    tempMax[i - 1][0] = tempMax[index - 1][0] - N;
    tempMax[i - 1][1] = N;
  }

  for(int j = 0; j < N; j++)
  {
    printf("%d ", tempMax[index - 1][0] + j);

    if(tempMax[index - 1][1] == j)
    {
      index--;
    }
  }
  printf("\n");

  return 0;
}
