#include <assert.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>

double f(double x) {
  return x - cos(x);
}

double bisect(double a, double b, double epsilon);

int main(void) {
  printf("%g\n", bisect(-10, +10, 0.001));
  printf("%g\n", bisect(+10, -10, 0.001));

  return 0;
}

double bisect(double a, double b, double epsilon) {
  assert(f(a) < 0 && f(b) > 0 && epsilon > 0);

  double m = (a + b) / 2;
  if (fabs(m - a) < epsilon || f(m) == 0)
    return m;

  if (f(m) > 0)
    return bisect(a, m, epsilon);

  return bisect(m, b, epsilon);
}

double bisectLoop(double a, double b, double epsilon) {
  assert(f(a) < 0 && f(b) > 0 && epsilon > 0);

  double m;
  while (true) {
    m = (a + b) / 2;
    if (fabs(m - a) < epsilon)
      return m;

    if (f(m) > 0)
      b = m;
    else
      a = m;
  }
}
