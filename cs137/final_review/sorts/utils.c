#include <stdio.h>
#include "utils.h"

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void print_list(int list[], int n) {
  for (int i = 0; i < n; i ++)
    printf ("%d ", list[i]);

  printf("\n");
}
