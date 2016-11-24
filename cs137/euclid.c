#include <stdio.h>

int main(void) {
  int a = 806;
  int b = 338;
  int r = 0;

  while (b) {
    r = a % b;
    a = b;
    b = r;
  }

  printf("%d\n", a);
  return 0;
}
