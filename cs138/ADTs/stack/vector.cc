#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

typedef vector<string> Stack;

bool isEmpty(Stack s) {
  return s.empty();
}

Stack push(Stack s, string value) {
  s.push_back(value);
  return s;
}

Stack pop(Stack s) {
  assert(!isEmpty(s));
  s.pop_back();
  return s;
}

string peek(Stack s) {
  assert(!isEmpty(s));
  return s.back();
}
