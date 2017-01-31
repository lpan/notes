/**
 * iniStack: -> stack
 * Pre: true
 * Post: returned value is a (new) empty stack
 *
 * isEmpty: stack -> boolean
 * Pre: true
 * Post: return value is the same as N == 0
 *
 * push: stack X element -> stack
 * Pre: true
 * Post: 1
 *
 * pop: stack -> stack
 * Pre: !isEmpty
 * Post: stack
 *
 * ....
 *
 * Stack initStack() {};
 * Stack push(Stack s, string val) {}
 * bool isEmpty(Stack s) {}
 * Stack pop(Stack s) {}
 * string peek(Stack s) {}
 */
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

struct Node {
  string value;
  Node *next;
};

typedef Node* Stack;

Node *initStack() {
  return NULL;
}

Node *push(Node *head, string value) {
  Node *newNode = new Node();
  newNode->value = value;
  newNode->next = head;
  return newNode;
}

bool isEmpty(Node *head) {
  return head == NULL;
}

string peek(Node *head) {
  assert(!isEmpty(head));
  return head->value;
}

Node *pop(Node *head) {
  assert(!isEmpty(head));
  Node *p = head->next;
  delete head;
  return p;
}

int main() {
  Stack s = initStack();
  s = push(s, "lmao");
  s = push(s, "ayyy");
  s = push(s, "paninos");
  cout << peek(s) << endl;
  s = pop(s);
  cout << peek(s) << endl;
  s = pop(s);
  cout << peek(s) << endl;
  return 0;
}
