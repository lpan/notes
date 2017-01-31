#include <stdio.h>

int gcd(int a, int b) {
  if (b == 0)
    return a;

  return gcd(b, a % b);
}

int main(void) {
  int a = 806, b = 338;

  printf ("%d\n", gcd(a, b));
  return 0;
}
