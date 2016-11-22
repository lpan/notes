int square(int num) {
  return num * num;
}

int cube(int num) {
  return num * square(num);
}

int quartic(int num) {
  return num * cube(num);
}

int quintic(int num) {
  return num * quartic(num);
}
