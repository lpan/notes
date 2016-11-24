#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "vector.h"

struct vector {
  int *a;
  int size;
  int length;
};

struct vector* vector_create ()
{
  struct vector *v = malloc (sizeof (struct vector));
  assert (v);
  v->size = 1;
  v->a = malloc (sizeof (int));
  assert (v->a);
  v->length = 0;
  return v;
}

void vector_set (struct vector *v, int index, int value)
{
  assert (index >= 0 && v);
  if (index >= v->size)
  {
    do
    {
      v->size *= 2;
    } while (index >= v->size);

    v->a = realloc (v->a, v->size * sizeof (int));
  }

  while (index >= v->length)
  {
    v->a[v->length] = 0;
    v->length ++;
  }
  v->a[index] = value;
}

int vector_length (struct vector *v)
{
  assert (v);
  return v->length;
}

int vector_get (struct vector *v, int index)
{
  assert (v && index < v->length && index >= 0);
  return v->a[index];
}

struct vector* vector_delete (struct vector *v)
{
  if (v)
  {
    free (v->a);
    free (v);
  }

  return NULL;
}
