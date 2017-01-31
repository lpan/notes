#include <stdlib.h>
#include "utils.h"

void merge(int list[], int tmp[], int n) {
  // when n <= 1, we stop dividing
  if (n <= 1)
    return;

  // divide the array into two parts
  int middle = n / 2;
  int *lower = list;
  int *upper = list + middle;

  merge(lower, tmp, middle);
  merge(upper, tmp, n - middle);

  // now we merge the results
  // we know lower and upper are sorted lists now
  int l_i = 0, u_i = middle, t_i = 0;
  while (l_i < middle && u_i < n)
    tmp[t_i ++] = list[l_i] < list[u_i] ? list[l_i ++] : list[u_i ++];

  // now we gotta deal with the leftovers
  while (l_i < middle) tmp[t_i ++] = list[l_i ++];
  while (u_i < n) tmp[t_i ++] = list[u_i ++];

  // then we copy tmp to the original piece
  for (int i = 0; i < n; i ++)
    list[i] = tmp[i];
}

void m_sort(int list[], int n) {
  int *tmp = malloc(sizeof (int) * n);
  merge(list, tmp, n);
  free(tmp);
}

int main (void) {
  int list[6] = { 32, 1, 8, 99, -24, 0 };
  print_list(list, 6);
  m_sort(list, 6);
  print_list(list, 6);
  return 0;
}
