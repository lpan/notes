#include <cassert>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct queue {
  vector<string> store;
  int first;
};

bool isEmpty(const queue &q){
  return q.store.empty();
}

void init(queue &q) {
  q.first = 0;
}

void enter(queue &q, string val) {
  q.store.push_back(val);
}

void leave(queue &q) {
  assert(!isEmpty(q));
  q.first++;
}

size_t size(queue &q) {
  return q.store.size() - q.first;
}

string first(const queue &q){
  assert(!isEmpty(q));
  return q.store.at(q.first);
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
