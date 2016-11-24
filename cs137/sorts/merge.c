#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void print_list (int arr[], int n)
{
  for (int i = 0; i < n; i ++)
    printf ("%d ", arr[i]);
  printf ("\n");
}

/*
 * Basic idea
 * - divide array in half
 * - sort each half
 * - merge the results
 */
void merge_sort (int *a, int *tmp, int n)
{
  if (n <= 1)
    return;

  merge_sort (a, tmp, n / 2);
  merge_sort (a + n / 2, tmp, n - n / 2);

  // i: left index, j: right index, k: tmp index
  int i = 0, j = n / 2, k = 0;

  while (i < n / 2 && j < n)
  {
    if (a[i] <= a[j])
      tmp[k++] = a[i++];
    else
      tmp[k++] = a[j++];
  }

  while (i < n / 2)
    tmp[k++] = a[i++];

  while (j < n)
    tmp[k++] = a[j++];

  for (int i = 0; i < n; i ++)
    a[i] = tmp[i];
}

void sort (int a[], int n)
{
  int *tmp = malloc (n * sizeof (int));
  assert (tmp);
  merge_sort (a, tmp, n);
  free (tmp);
}

int main (void)
{
  int list[6] = { 12, 34, -3, 3, 98, 0 };
  print_list (list, 6);
  sort (list, 6);
  print_list (list, 6);
  return 0;
}
