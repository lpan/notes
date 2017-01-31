#include <stdio.h>

int search(int list[], int n, int value) {
  int m, low = 0, high = n - 1;
  while (high - low >= 0) {
    m = low + (high - low) / 2;

    if (value == list[m])
      return m;

    if (value < list[m])
      high = m - 1;
    else
      low = m + 1;
  }

  return -1;
}

int main(void) {
  int a[] = { -10, -7, 0, 2, 11, 14, 38, 42 };
  const int n = sizeof(a) / sizeof(a[0]);

  printf("%d\n", search(a, n, 11));
  printf("%d\n", search(a, n, 10));
  printf("%d\n", search(a, n, 42));
  return 0;
}
