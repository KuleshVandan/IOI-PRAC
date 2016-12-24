#include <stdio.h>
#include <stdlib.h>


int SmallestKthElem(int A[], int k, int p, int q);

int main(void)
{
  int A[] = {4, 5, 6, 2, 1, 3, 5, 4};
  int len = sizeof(A) / sizeof(A[0]);

  printf("%d\n", SmallestKthElem(A, 2, 0, len - 1));

  return 0;
}

void swap(int *a, int *b)
{
  int c = *a;
  *a = *b;
  *b = c;
}

/**
 * Modification of randomized Lomuto partition
 * to find the kth smallest element in O(n) time
 *
 * Warning k is 0-indexed
 */

int SmallestKthElem(int A[], int k, int p, int q)
{
  swap(&A[p + (rand() % (q - p + 1))], &A[q]);  // A[q] is the pivot

  int i = p - 1;
  for(int j = p; j <= q; j++)
  {
    if(A[j] <= A[q])
    {
      swap(&A[++i], &A[j]);
    }
  }

  if(i == k)
  {
    return A[i];
  }
  else if(i > k)
  {
    return SmallestKthElem(A, k, p, i - 1);
  }
  else
  {
    return SmallestKthElem(A, k, i + 1, q);
  }
}
