#include <stdio.h>

int fib(int n) {
  int a = 0, b = 1, final;
  for (int i = 1; i < n; i ++) {
    final = a + b;
    a = b;
    b = final;
  }

  return b;
}

int slow_fib(int n) {
  if (n == 0 || n == 1)
    return n;

  return fib(n - 1) + fib(n - 2);
}

int main(void) {
  printf("%d\n", fib(10));
  return 0;
}
