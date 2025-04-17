#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int el) : data(el), next(nullptr) {}
};

void insertAtEnd(Node *&head, int el) {
    Node *newNode = new Node(el);
    Node *temp = head;

    if (head == nullptr)
        head = newNode;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

void deleteAtEnd(Node *&head) {
    Node *temp = head;

    while (temp->next->next != nullptr)
        temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

void insertAtBeginning(Node *&head, int el) {
    Node *newNode = new Node(el);

    newNode->next = head;
    head = newNode;
}

void deleteAtBeginning(Node *&head) {
    Node *temp = head;

    head = temp->next;
    delete temp;
}

void insertAtPosition(Node *&head, int el, int pos) {
    Node *newNode = new Node(el);
    Node *temp = head;

    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtPosition(Node *&head, int pos) {
    Node *temp = head;

    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;
    Node *delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
}

void deleteByValue(Node *&head, int el) {
    Node *temp = head;
    if (head->data == el) {
        deleteAtBeginning(head);
        return;
    }

    while (temp->next != nullptr) {
        if (temp->next->data == el) {
            Node *delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
            return;
        }
        temp = temp->next;
    }
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

    int n, el;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> el;
        insertAtBeginning(head, el);
        // insertAtEnd(head, el);
    }

    int pos;
    cin >> el >> pos;

    if (pos == 1)
        insertAtBeginning(head, el);
    else if (pos == n + 1)
        insertAtEnd(head, el);
    else if (pos > n + 1) {
        cout << "Position out of range.\n";
        return 0;
    } else {
        insertAtPosition(head, el, pos);
    }

    printList(head);

    cin >> pos;
    if (pos == 1)
        deleteAtBeginning(head);
    else if (pos == n + 1)
        deleteAtEnd(head);
    else if (pos > n + 1)
        cout << "Position out of range.\n";
    else
        deleteAtPosition(head, pos);

    printList(head);

    cin >> el;
    deleteByValue(head, el);

    printList(head);

    return 0;
}
