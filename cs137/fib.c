// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

#include <stdio.h>

// inefficient fib
int fib(int n) {
  if (n == 0 || n == 1)
    return n;

  return fib(n - 1) + fib(n - 2);
}

int main(void) {
  printf("%d\n", fib(38)); // < 1 second
  printf("%d\n", fib(42)); // ~= 3 seconds
  printf("%d\n", fib(45)); // ~= 13 seconds
  return 0;
}
