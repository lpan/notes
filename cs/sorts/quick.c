#include <stdio.h>

/*
 * 1. Pick a pivot element 'p' from the array. eg. p = a[0] or p = a[random]
 *
 * 2. Partition the array as follows
 * | | | | | | | |p| | | | | | | | (p in the middle)
 * Every element in front of p is smaller than p
 * Every element after p is larger than p
 *
 * 3. Recursively sort the two partitions
 */

/***** Utils *****/

void swap (int a[], int i, int j)
{
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

void print_array (int a[], int n)
{
  for (int i = 0; i < n; i ++)
    printf ("%d ", a[i]);
  printf ("\n");
}

/*
 * How to partition?
 * 1. Lumato partitionar -> sweeps from left to right
 * 2. Use two indices:
 *   m = last elemetn of the <p partition
 *   i = first elemetn of the unpartiioned part
 *   if x >= p -> increment i;
 *   else -> increment m; swap (a[m], a[i]); increment i;
 *
 *   Last case -> swap (a[0], a[m])
 */
int partition (int a[], int n)
{
  int m = 0;
  for (int i = 1; i < n; i ++)
    if (a[i] < a[0])
    {
      m ++;
      swap (a, m, i);
    }
  swap (a, 0, m);
  return m;
}

/*
 * Time complexity for merge sort
 *
 * - Best case: each partitioning yields two equal sized partitions
 *
 * - Average case: is also O (n logn)
 *
 * - if P is in the 25th to 75th percentile, you get 3:1 partition sizes at 
 *   worst (result in log 4/3 n)
 *
 * - Worst case: P is always smallest or largest element
 *
 * - Depth = n, work at each level -> n, n-1, n-2, ... , 1
 * - Time = n + (n + 1) + (n + 2) = O (n^2)
 */
void quicksort (int a[], int n)
{
  if (n <= 1)
    return;

  int m = partition (a, n);

  quicksort (a, m);
  quicksort (a + m + 1, n - m - 1);
}

int main (void)
{
  int a[8] = { 2, -10, 14, 42, 11, -7, 0, 38 };
  print_array (a, 8);
  quicksort (a, 8);
  print_array (a, 8);
  return 0;
}
