#include <math.h>
#include <stdio.h>

double g(double x) {
  return cos(x);
}

double fixed(double x_0, double epsilon, int max_iters, double (*h)(double)) {
  double x_n = x_0;

  for (int i = 0; i < max_iters; i ++) {
    double next = h(x_n);
    if (fabs(next - x_n) < epsilon)
      return next;
    x_n = next;
  }

  return x_n;
}

int main(void) {
  printf("%g\n", fixed(12, 0.0001, 100, cos));
  return 0;
}
