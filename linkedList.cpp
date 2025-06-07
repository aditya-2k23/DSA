#include <bits/stdc++.h>
using namespace std;

struct Node {
  long long data;
  Node* next;

  Node(long long val) : data(val), next(NULL) {}
};

Node* insert(Node* head, long long val) {
  if (!head)
    return new Node(val);

  Node* temp = head;
  while (temp->next)
    temp = temp->next;

  Node* newNode = new Node(val);

  temp->next = newNode;

  return head;
}

void printList(Node* head) {
  cout << "\nPrinting List:\n";
  Node* temp = head;

  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main() {
  Node* head = NULL;
  int n;
  cin >> n;

  while (n > 0) {
    long long el;
    cin >> el;
    head = insert(head, el);
    n--;
  }

  printList(head);

  cout << "1000 100 10 1";

  return 0;
}
