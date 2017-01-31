#include "utils.h"

/*
 * Basic idea:
 * 1. Split the array in half -> sorted vs unsorted
 * 2. Start with the second element
 * 3. if the element is smaller, we shift the sorted list
 * 4. if we are out of index or the element is greater, we insert it
 */
void i_sort(int list[], int n) {
  for (int i = 1; i < n; i ++) {
    int tmp = list[i], j = i;
    while (tmp < list[j - 1] && j >= 1) {
      list[j] = list[j - 1];
      j --;
    }
    list[j] = tmp;
  }
}

int main(void) {
  int list[6] = { 32, 1, 8, 99, -24, 0 };
  print_list(list, 6);
  i_sort(list, 6);
  print_list(list, 6);
  return 0;
}
