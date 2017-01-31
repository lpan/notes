#include <stdlib.h>
#include <string.h>

void
map (const void *a, const int n, size_t elem_a, void *b, size_t elem_b, void (*f)(const void *a, void *b))
{
  for(int i = 0; i < n; i++) {
    f(a,b);
    a = (char *)a + elem_a;
    b = (char *)b + elem_b;
  }
}

void
reduce (const void *a, const int n, size_t elem_a, void *b, void (*f)(const void *a, void *b))
{
  for (int i = 0; i < n; i ++)
  {
    f (a, b);
    a = (const char *) a + elem_a;
  }
}

void map_to_length (const void *a, const void *b)
{
  *(int *) b = strlen (* (char **) a);
}

void find_max (const void *accum, const void *current)
{
  if (*(int *) current > *(int *) accum)
    *(int *) accum = *(int *) current;
}

main (void)
{
  char *sentence[] = { "A", "day", "without", "sunshine" };
  const int n = sizeof (sentence) / sizeof (sentence[0]);

  // find word lengths
  int lengths[n];
  map (sentence, n, sizeof (char *), lengths, sizeof (int));

  reduce (lengths, n, sizeof (int), &max, find_max);
}
