#include <stdio.h>

typedef struct {
  int src;
  int dst;
} link;

void pageRank(link l[], int nLink, double r[], int nPage, double delta, int iters);

int main(void) {
  link l[] = {{0, 1}, {0, 2}, {1, 2}, {2, 0}};
  double r[3];

  int nLink = sizeof(l) / sizeof(l[0]);
  int nPage = sizeof(r) / sizeof(r[0]);

  pageRank(l, nLink, r, nPage, 0.8, 20);

  for (int i = 0; i < nPage; i ++)
    printf("%g\n", r[i]);

  return 0;
}

void pageRank(link l[], int nLink, double r[], int nPage, double delta, int iters) {
  // calculate the number of outgoing links per page
  int out[nPage];

  for (int i = 0; i < nPage; i ++)
    out[i] = 0;

  for (int i = 0; i < nLink; i ++)
    out[l[i].src] ++;

  // initial guess
  for (int i = 0; i < nPage; i ++)
    r[i] = 1.0 / nPage;

  // iterate
  for (int i = 0; i < iters; i ++) {
    double t[nPage]; // temp storage for new rank calculations

    // random jump part
    for (int j = 0; j < nPage; j ++)
      t[j] = (1.0 - delta) / nPage;

    for (int j = 0; j < nLink; j ++)
      t[l[j].dst] += delta * r[l[i].src] / out[l[j].src];

    // copy back to r[]
    for (int j = 0; j < nPage; j ++)
      r[j] = t[j];
  }
}
