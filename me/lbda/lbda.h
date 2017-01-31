void *map (const void *l, size_t n, size_t elem_a);

void reduce (const void *a, size_t n, size_t elem_a, void (*f)(const void *a, void *b));
