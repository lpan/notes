#include <stdio.h>

/*
 * For searching a sorted array
 * - Probe middle element a[m]
 * - if equal to value -> return m
 *   else if a[m] > value -> search lower half
 *   else if a[m] < value -> search upper half
 *
 * Time complexity
 * - worst case: found/not found when lo == hi
 *   O(log n)
 */
int search(int *a, int n, int value) {
  int m, lo = 0, hi = n - 1;
  while (lo <= hi) {
    m = lo + (hi - lo) / 2;

    if (a[m] == value)
      return m;

    if (a[m] > value)
      hi = m - 1;
    else
      lo = m + 1;
  }

  return -1;
}

// TODO
int my_search(int *a, int n, int number) {
  int m = (int) n / 2;

  if (number < a[m])
    return search(a, m, number);

  if (number > a[m])
    return search(a + m, n - m, number);

  return m;
}

void print_search(int *a, int n, int number) {
  printf("index of %d: %d\n", number, search(a, n, number));
}

int main(void) {
  // sorted array
  int a[] = { -10, -7, 0, 2, 11, 14, 38, 42 };
  const int n = sizeof(a) / sizeof(a[0]);

  print_search(a, n, 11); // 4
  print_search(a, n, 10); // -1
  print_search(a, n, -100); // -1
  return 0;
}
