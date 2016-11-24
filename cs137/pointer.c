#define LENGTH 5

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int sum_array (int a[], int n)
{
  int sum = 0;
  for (int *p = a; p < a + n; p ++)
    sum += *p;

  return sum;
}

// return pointer to the largest element in the array
int* largest_element (int a[], int n)
{
  int *max = a;
  for (int *p = a + 1; p < a + n; p ++)
    if (*p > *max)
      max = p;
  return max;
}

// create array of ints
int* number (int n)
{
  int *p = malloc (n * sizeof (int));
  assert (p != NULL);

  for (int i = 0; i < n; i ++)
    p[i] = i;

  return p;
}

int main (void)
{
  int a1[LENGTH] = { 1, 2, 3, 4, 5 };
  int a2[LENGTH] = { 34, 20 ,435, 23, 3 };

  printf ("sum: %d\n", sum_array (a1, LENGTH));

  int* largest = largest_element (a2, LENGTH);
  printf ("Largest address: %zu, value: %d\n", largest, *largest);

  // create an array
  int *q = number (100);
  printf ("%d\n", q[50]);
  free (q); // avoid memory leaks
  return 0;
}
