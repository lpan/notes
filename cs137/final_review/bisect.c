#include <stdio.h>
#include <assert.h>
#include <math.h>

double my_func(double x) {
  return x * x - 1;
}

double bisect(double (*f)(double), double begin, double end, double epsilon) {
  double m = (begin + end) / 2;
  assert(f(begin) < 0);
  assert(f(end) > 0);

  if (fabs(f(m)) < epsilon)
    return m;

  if (f(m) < 0)
    return bisect(f, m, end, epsilon);

  return bisect(f, begin, m, epsilon);
}

int main(void) {
  printf("%g\n", bisect(my_func, 0, 30, 0.0001));
  return 0;
}
