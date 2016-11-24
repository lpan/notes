#include <stdio.h>

void print_list (int a[], int n)
{
  for (int i = 0; i < n; i ++)
    printf ("%d ", a[i]);
  printf ("\n");
}

/*
 * Time complexity
 * Outer loop: n - 1 iterations
 * Inner loop: 0 to i iterations
 * Best case -> Already sorted (inner loop is always 0 iterations) -> O (n)
 * Worst case -> Sorted in reverse order -> inner: sum (1 -> n-1) -> O (n ^ 2)
 */
void sort(int a[], int n)
{
  for (int i = 1; i < n; i ++)
  {
    int x = a[i];
    int j = i;
    while (j > 0 && a[j - 1] > x)
    {
      a[j] = a[j - 1];
      --j;
    }
    a[j] = x;
  }
}

int main (void)
{
  int list[6] = { 34, 2, -23, -99, 12, 9 };
  print_list (list, 6);
  sort (list, 6);
  print_list (list, 6);
  return 0;
}
