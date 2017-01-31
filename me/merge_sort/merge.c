#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int n) {
  for (int i = 0; i < n; i ++)
    printf ("%d ", arr[i]);
  printf ("\n");
}

void divide(int *arr, int n, int *tmp) {
  if (n <= 1)
    return;

  int mid = (int) n / 2;

  divide(arr, mid, tmp);
  divide(arr + mid, n - mid, tmp);

  int left = 0, right = mid, tmp_index = 0;

  while (left < mid && right < n) {
    if (arr[left] >= arr[right])
      tmp[tmp_index ++] = arr[left ++]; 
    else
      tmp[tmp_index ++] = arr[right ++];
  }

  while (left < mid)
    tmp[tmp_index ++] = arr[left ++];

  while (right < n)
    tmp[tmp_index ++] = arr[right ++];

  for (int i = 0; i < n; i ++)
    arr[i] = tmp[i];
}

void sort(int *arr, int n) {
  int *tmp = malloc (n * sizeof (int));
  divide(arr, n, tmp);
  free(tmp);
}

int main (void)
{
  int arr[] = { 34, -1, 9, 0, 38, 44 };
  int len = sizeof (arr) / sizeof (arr[0]);
  print_array (arr, len);
  sort (arr, len);
  print_array (arr, len);
  return 0;
}
