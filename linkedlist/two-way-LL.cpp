#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;

    Node(int el) : data(el), next(nullptr), prev(nullptr) {}
};

void insertAtEnd(Node *&head, Node *&tail, int el) {
    Node *newNode = new Node(el);

    if (head == nullptr) {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insertAtBeginning(Node *&head, Node *&tail, int el) {
    Node *newNode = new Node(el);

    if (head == nullptr) {
        head = tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void printList(Node *head) {
    Node *temp = head;

    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteAtBeginning(Node *&head, Node *&tail) {
    if (head == nullptr)
        return;
    if (head->next == nullptr) {
        delete head;
        head = tail = nullptr;
        return;
    }

    Node *delNode = head;
    head = head->next;
    head->prev = nullptr;
    delete delNode;
}

void deleteAtEnd(Node *&head, Node *&tail) {
    if (head == nullptr || tail == nullptr)
        return;
    if (head->next == nullptr) {
        delete head;
        head = tail = nullptr;
        return;
    }

    Node *delNode = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete delNode;
}

void insertAtPosition(Node *&head, Node *&tail, int pos, int el) {
    Node *newNode = new Node(el);
    Node *temp = head;

    if (pos == 0) {
        insertAtBeginning(head, tail, el);
        return;
    }
    if (head == nullptr) {
        head = tail = newNode;
        return;
    }

    for (int i = 0; i < pos - 1; i++)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

int main() {
    Node *head = nullptr;
    Node *tail = nullptr;

    int n, el;
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Linked List is empty" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> el;

        // insertAtBeginning(head, tail, el);
        insertAtEnd(head, tail, el);
    }

    printList(head);

    cout << "Would you like to insert at position? (y/n): ";
    char ch;
    int pos;
    cin >> ch;

    if (ch == 'y') {
        cout << "Enter the position: ";
        cin >> pos;

        cout << "Enter the element: ";
        cin >> el;

        insertAtPosition(head, tail, pos, el);
    }

    printList(head);

    cout << "Would you like to delete? b: beginning, e: end, p: position, n: no" << endl;
    cin >> ch;

    if (ch == 'p') {
        cout << "Enter the position: ";
        cin >> pos;
        // deleteAtPosition(head, tail, pos);
    } else if (ch == 'b') {
        deleteAtBeginning(head, tail);
    } else if (ch == 'e') {
        deleteAtEnd(head, tail);
    } else {
        cout << "No deletion" << endl;
    }

    printList(head);

    return 0;
}
