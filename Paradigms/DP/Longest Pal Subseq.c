#include <stdio.h>
#include <string.h>


int longestPalSS(char str[]);

int main(void)
{
  char str[] = "GEEKSFORGEEKS";
  printf("%d\n", longestPalSS(str));
  return 0;
}

int max(int a, int b)
{
  return a > b ? a : b;
}

int longestPalSS(char str[])
{
  int len = strlen(str);
  int ssTab[len][len];

  for(int i = len - 1; i >= 0; i--)
  {
    ssTab[i][i] = 1;
    for(int j = i + 1; j < len; j++)
    {
      if(str[i] != str[j])
      {
        ssTab[i][j] = max(ssTab[i+1][j], ssTab[i][j-1]);
      }
      else if(j == i + 1)
      {
        ssTab[i][j] = 2;
      }
      else
      {
        ssTab[i][j] = ssTab[i+1][j-1] + 2;
      }
    }
  }

  return ssTab[0][len - 1];
}
