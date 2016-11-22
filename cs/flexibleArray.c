#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
  int length;
  // has to be last member and has size 0
  // sizeof (flex_array) => 4
  int a[];
} flex_array;

int main (void)
{
  int array_size;
  scanf ("%d\n", &array_size);

  flex_array *f = malloc (sizeof (flex_array) + array_size * sizeof (int));

  assert (f);

  f -> length = array_size;

  for (int i = 0; i < f -> length; i ++)
    f -> a[i] = i;

  for (int i = 0; i < f -> length; i ++)
    printf ("%d\n", f -> a[i]);

  return 0;
}
