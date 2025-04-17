#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

Node *insertAtEnd(Node *head, int data) {
    Node *newNode = new Node(data);

    if (head == nullptr)
        return newNode;

    Node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

Node *insertAtBeginning(Node *head, int element) {
    Node *newNode = new Node(element);
    newNode->next = head;
    head = newNode;

    return head;
}

void printList(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node *head = nullptr;
    int n, element;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> element;
        head = insertAtEnd(head, element);
    }
    printList(head);

    return 0;
}
