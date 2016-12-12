#include <stdio.h>
#include <limits.h>

long long LBsums[1000001];
long long A[1000000], B[1000000];

long long maxSSum(int i, int j);

int N;

int main (void)
{
  scanf("%d", &N);

  LBsums[0] = 0;

  for(int i = 0; i < N; i++)
  {
    scanf("%lli", &A[i]);
  }

  for(int i = 0; i < N; i++)
  {
    scanf("%lli", &B[i]);
    LBsums[i + 1] += LBsums[i] + B[i];
  }

  printf("%lli\n", maxSSum(0, N - 1));
  return 0;
}

long long MAX(long long a, long long b)
{
  return a > b ? a : b;
}

/**
 * Pardon me for horrible variable names.
 * 
 * maxSSum(i, j):
 * Given any i, j finds the max SSum such that
 * for a[p], a[q], p and q satisfy i <= p, q <= j
 *
 * To do this, use divide and conquer. First find
 * maxSSum(i, floor(i + j)) and maxSSum(floor(i+j)/2+1,j)
 * Then also find crossing sum, ie, for a[p], a[q],
 * i <= p <= (i + j)/2 and j >= q >= (i+j)/2 + 1
 *
 * Once a[p], a[q] are fixed, just find the sum of b
 * either completely inside them or completely outside them
 *
 * Complexity = O(N lgN)
 */

long long maxSSum(int i, int j)
{
  if(i == j)
  {
    return A[i];
  }

  long long left  = maxSSum(i, (i + j) / 2);
  long long right = maxSSum((i + j) / 2 + 1, j);


  long long lminSum, lmaxSum, lcurSum;

  lminSum = LLONG_MIN;
  lmaxSum = LLONG_MIN;

  lcurSum = 0;

  for(int x = (i + j) / 2; x >= i; x--)
  {
    if(LBsums[x] + A[x] > lminSum) lminSum = LBsums[x] + A[x];
    if(lcurSum + A[x] > lmaxSum) lmaxSum = lcurSum + A[x];

    lcurSum += B[x];
  }

  long long rminSum, rmaxSum, rcurSum;

  rminSum = LLONG_MIN;
  rmaxSum = LLONG_MIN;

  rcurSum = 0;

  for(int x = (i + j) / 2 + 1; x <= j; x++)
  {
    if(LBsums[N] - LBsums[x + 1] + A[x] > rminSum) rminSum = LBsums[N] - LBsums[x + 1] + A[x];
    if(rcurSum + A[x] > rmaxSum) rmaxSum = rcurSum + A[x];

    rcurSum += B[x];
  }

  return MAX(left, MAX(right, MAX(lminSum + rminSum, lmaxSum + rmaxSum)));
}
