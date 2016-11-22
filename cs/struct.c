#include <stdio.h>

typedef struct {
  int hours;
  int minutes;
} tod;

void print(tod when) {
  printf("%02d:%02d\n", when.hours, when.minutes);
}

tod addTime(tod when, int hours, int minutes) {
  when.minutes += minutes;
  when.hours += hours + when.minutes / 60;
  when.minutes %= 60;
  when.hours %= 24;
  return when;
}

int main(void) {
  tod now = { 16, 50 };
  now = addTime(now, 1, 10);
  print(now);
  return 0;
}
