#include "node.h"
class circular {
private:
  Node *head = NULL;
  Node *tail = NULL;

public:
  void insert(int n);
  void remove(int n);
  void print();
};

void circular::insert(int n) {
  Node *newNode = new Node(n);
  if (head == NULL) {
    head = tail = new Node(n);
    tail->next = head;
    return;
  }
  if (n < head->value) {
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
    return;
  }
  Node *temp = head;
  while (temp->next != head && temp->next->value < n)
    temp = temp->next;
  newNode->next = temp->next;
  temp->next = newNode;
  if (temp == tail)
    tail = newNode;
}

void circular::print() {
  int round = 3;
  for (Node *temp = head; temp != head || round--; temp = temp->next)
    cout << temp->value << " -> ";
  cout << "(head)" << endl;
}

void circular::remove(int n) {
  if (head == NULL) {
    return;
  }
  if (n < head->value || n > tail->value)
    return;
  if (head->value == n) {
    tail->next = head->next;
    Node *temp = head;
    head = tail->next;
    delete temp;
    return;
  }

  Node *temp = head;
  for (int first = 1; temp->next->value != n && (temp != head || first--);
       temp = temp->next)
    ;
  if (temp->next->value != n)
    return;
  Node *toRemove = temp->next;
  temp->next = toRemove->next;
  if (toRemove == tail)
    tail = temp;

  delete toRemove;
}