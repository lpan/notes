#include <iostream>
#include <string>
#include <cassert>

using namespace std;

string *myAlloc(int n) {
  assert(n > 0);
  return new string[n];
}

int main() {
  int n;
  cin >> n;
  int *a = new int[n];
  string *b = myAlloc(n);

  for (int i = 0; i < n; i ++) {
    cin >> a[i] >> b[i];
  }

  /* fun stuff */

  delete[] a;
  delete[] b;

  return 0;
}
