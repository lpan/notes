#include <stdio.h>

/*
 * Time complexity of selection sort
 *
 * A, C: setup
 * B: swap & incr + test
 * D: body + incr + test
 *
 * -> Outer loop: A + B (n - 1) + [inner loop] (n - 1)
 *
 * -> Inner loop: C + D (n - (i + 1))
 *
 * -> Total time = A + B (n - 1) + C (n - 1) + D ((n - 1) + (n - 2) + ... + 1)
 *               = A + (B + C) (n - 1) + D sum (1 -> n-1)
 *               = A + (B + C) (n - 1) + D (n-1) (n) (1/2) -> O (n^2)
 *
 */
void swap (int *m, int *n)
{
  int tmp = *m;
  *m = *n;
  *n = tmp;
}

void sort (int a[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j ++)
      if (a[j] < a[i])
        swap (a + j, a + i);
  }
}

int main (void)
{
  return 0;
}
