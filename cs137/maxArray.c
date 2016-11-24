#include <stdio.h>

int maxSubArray(int arr[], int size) {
  int max = 0;
  int sum = 0;
  for (int i = 0; i < size; i ++) {
    sum += arr[i];
    if (sum > max) {

    } else {
      sum = 0;
    }
  }
}

int maxSubArrayN2(int arr[], int size) {
}

int main(void) {
  int size = 6;
  int arr[6] = { -1, 2, -1, 2, -4, 1 };
  printf("%d\n", maxSubArray(arr, size));
  return 0;
}
