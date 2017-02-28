// we need initList, insert, remove, has, isEmpty, print

#include <iostream>
#include <string>

using namespace std;

struct Node {
  string val;
  string otherstuff;
  Node *next;
};

typedef Node* SortedList;

void initList (SortedList &first) {
  first = nullptr;
}

bool lookup(const SortedList &first, string val) {
  Node *cur = first;
  while (cur && cur->val < val) {
    cur = cur->next;
  }

  return cur && cur->val == val;
}

void insert(SortedList &first, string val) {
  Node *newNode = new Node();
  newNode->val = val;

  if (!first || first->val > val) {
    newNode->next = first;
    first = newNode;
  }

  Node *cur = first;
  while (cur->next && val > cur->next->val) {
    cur = cur->next;
  }
}

void remove(SortedList &first, string val) {
  // assertion goes here
  Node *tmp;

  if (first->val == val) {
    Node *cur = first;
    first = first->next;
    tmp = cur;
  } else {
    Node *cur = first;
    while (cur && cur->next->val < val) {
      cur = cur->next;
    }
    // TODO
}

int main() {
  return 0;
}
