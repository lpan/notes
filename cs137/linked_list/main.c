#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

int main(void) {
  poly *p = poly_init();
  p = poly_insert(p, 3, 3.0);
  p = poly_insert(p, 0, 3.0);
  p = poly_insert(p, 1, 3.0);
  printf ("%g\n", poly_eval(p, 5.0));
  p = poly_del(p);
  return 0;
}
