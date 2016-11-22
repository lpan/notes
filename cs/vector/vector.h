#ifndef VECTOR_H

#define VECTOR_H

struct vector;

struct vector* vector_create ();

struct vector* vector_delete (struct vector *v);

void vector_set (struct vector *v, int index, int value);

int vector_get (struct vector *v, int index);

int vector_length (struct vector *v);

#endif
