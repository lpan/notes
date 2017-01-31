#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "poly.h"

poly *poly_init(void)
{
  return NULL;
}

poly *poly_insert(poly *p, int power, double coeff)
{
  // insert at the head of the list
  if (!p || p->power < power) {
    poly *q = malloc(sizeof(poly));
    assert(q);
    q->power = power;
    q->coeff = coeff;
    q->next = p;
    return q;
  }

  // find the insert position (curr points to node so we insert the new term
  // after)
  poly *curr = p;
  while (curr->next && curr->next->power > power)
    curr = curr->next;

  // if degree exists, just change coeff
  if (curr->next && curr->next->power == power) {
    curr->next->coeff = coeff;
  } else {
    poly *q = malloc(sizeof(poly));
    assert(q);
    q->power = power;
    q->coeff = coeff;

    // now we want to link q to the list
    q->next = curr->next;
    curr->next = q;
  }

  return p;
}
