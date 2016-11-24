#include <stdio.h>
#include <stdlib.h>

int compare (const void *a, const void *b)
{
  int val_a = *(int *) a;
  int val_b = *(int *) b;

  if (val_a < val_b)
    return -1;
  else if (val_a == val_b)
    return 0;
  else
    return 1;
}

void print_list (int a[], int n)
{
  for (int i = 0; i < n; i ++)
    printf ("%d ", a[i]);
  printf ("\n");
}

int main (void)
{
  int a[] = { 2, -10, 14, 42, 11, -7, 0, 38 };
  const int n = sizeof (a) / sizeof (a[0]);

  print_list (a, n);
  qsort (a, n, sizeof (int), compare);
  print_list (a, n);
}
