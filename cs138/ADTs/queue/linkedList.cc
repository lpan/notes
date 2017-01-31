#include <iostream>
#include <cassert>
#include <string>

using namespace std;

struct Node {
  string val;
  Node *next;
};

struct Queue {
  Node *first;
  Node *last;
};

bool isEmpty(Queue &q) {
  return q.first == nullptr;
}

void enter(Queue &q, string val) {
  Node *p = new Node();
  p->val = val;

  if (q.first == nullptr) {
    q.first = p;
  } else {
    q.last->next = p;
  }

  q.last = p;
  p->next = nullptr;
}

string first(Queue &q) {
  assert(!isEmpty(q));
  return q.first->val;
}

void leave(Queue &q) {
  assert(!isEmpty(q));
  Node *p = q.first;
  q.first = q.first->next;

  if (q.first == nullptr) {
    q.last = nullptr;
  }

  delete p;
}

void nuke(Queue &q) {
  while (!isEmpty(q)) {
    leave(q);
  }
}

int main() {
  return 0;
}
