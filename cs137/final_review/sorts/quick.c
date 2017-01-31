#include "utils.h"

/*
 * Basic idea:
 * 1. use a pivot and divide array into three parts (> pivot, < pivot, = pivot)
 * 2. sort the upper and lower parts recursively
 */
void q_sort(int list[], int n) {
  if (n <= 1)
    return;

  // index of the element to swap
  int m = 0;

  // let's iterate through the array (we use first elemenet as pivot)
  for (int i = 1; i < n; i ++) {
    if (list[i] < list[0]) {
      m ++;
      swap(&list[i], &list[m]);
    }
  }

  swap(&list[m], &list[0]);

  q_sort(list, m + 1);
  q_sort(list + m + 1, n - m - 1);
}

int main (void) {
  int list[6] = { 32, 1, 8, 99, -24, 0 };
  print_list(list, 6);
  q_sort(list, 6);
  print_list(list, 6);
  return 0;
}
