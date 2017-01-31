#include <stdio.h>
#include <stdlib.h>

int *sieves (int n) {
  int *primes = malloc (sizeof (int) * n);
  for (int i = 0; i < n; i ++)
    primes[i] = 1;

  primes[0] = 0;
  primes[1] = 0;

  for (int i = 2; i < n; i ++)
    for (int j = i * 2; j < n && primes[i]; j += i)
      primes[j] = 0;

  return primes;
}

int main (void) {
  int *primes = sieves (40);
  printf ("%d\n", primes[39]);
  printf ("%d\n", primes[31]);
  printf ("%d\n", primes[33]);
  return 0;
}
