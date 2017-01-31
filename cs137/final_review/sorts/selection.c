#include "utils.h"

/*
 * Basic idea:
 * 1. Start at index = 0;
 * 2. Find the smallest element
 * 3. Swap it with element at index = 0
 * 4. index ++
 */
void s_sort(int list[], int n) {
  for (int i = 0; i < n - 1; i ++) {
    for (int j = i + 1; j < n; j ++) {
      int min = i;
      if (list[j] < list[i])
        min = j;

      int tmp = list[i];
      list[i] = list[min];
      list[min] = tmp;
    }
  }
}

int main (void) {
  int list[6] = { 32, 1, 8, 99, -24, 0 };
  print_list(list, 6);
  s_sort(list, 6);
  print_list(list, 6);
  return 0;
}
