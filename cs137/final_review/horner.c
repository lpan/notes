#include <stdio.h>
#include <assert.h>

/*
 * O(n) while the normal approach is O(n^2)
 * Basic idea:
 * 1. (((2) * x + 3) * x + 2) * x + 5 = 2x^3 + 3x^2 + 2x + 5
 * 2. start with first coefficient
 * 3. coefficient * x
 * 4. result += next coefficient
 */
double horner (double f[], int degree, double value) {
  double result = f[degree];
  for (int i = degree - 1; i >= 0; i --) {
    result *= value;
    result += f[i];
  }
}

int main(void) {
  double f[] = { 2, 1, 2, 1 };
  printf ("f(x) = x^3 + 2x^2 + x + 2\nf(2) = %g\n", horner(f, 3, 2.0));
  return 0;
}
