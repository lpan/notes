#include <stdio.h>
#include <assert.h>
#include "vector.h"

int main (void)
{
  struct vector *v = vector_create ();
  // grow automatically then set index 10 to 2
  vector_set (v, 10, 2);

  assert (vector_length (v) == 11);
  assert (vector_get (v, 10) == 2);
  v = vector_delete (v);
}
