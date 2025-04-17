#include <iostream>
using namespace std;

struct Node {
    int data = 0;
    Node *next;

    Node(int el) : data(el), next(nullptr) {}
};

void insertAtBeginning(Node *&header, int el) {
    Node *newNode = new Node(el);

    if (header == nullptr)
        header = new Node(0);

    newNode->next = header->next;
    header->next = newNode;

    header->data++;
}

void insertAtEnd(Node *&header, int el) {
    Node *newNode = new Node(el);
    Node *temp = header;

    if (header == nullptr) {
        insertAtBeginning(header, el);
        return;
    } else {
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    header->data++;
}

void insertAtPosition(Node *&header, int el, int pos) {
    Node *newNode = new Node(el);
    Node *temp = header->next;

    if (pos == 1) {
        insertAtBeginning(header, el);
        return;
    } else if (pos == header->data + 1) {
        insertAtEnd(header, el);
        return;
    } else {
        for (int i = 1; i < pos - 1; i++)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    header->data++;
}

void deleteAtEnd(Node *&header) {
    Node *temp = header->next;

    while (temp->next->next != nullptr)
        temp = temp->next;
    Node *delNode = temp->next;
    temp->next = nullptr;
    delete delNode;

    header->data--;
}

void deleteAtBeginning(Node *&header) {
    Node *delNode = header->next;
    header->next = delNode->next;
    delete delNode;

    header->data--;
}

void deleteAtPosition(Node *&header, int pos) {
    Node *temp = header->next;

    if (pos == 1) {
        deleteAtBeginning(header);
        return;
    } else if (pos == header->data) {
        deleteAtEnd(header);
        return;
    }
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;
    Node *delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;

    header->data--;
}

void deleteByValue(Node *&header, int el) {
    Node *temp = header->next;

    if (header->next->data == el) {
        deleteAtBeginning(header);
        return;
    }
    while (temp->next->data != el && temp->next != nullptr)
        temp = temp->next;
    Node *delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;

    header->data--;
}

void printList(Node *header) {
    Node *temp = header->next;
    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "Count: " << header->data << endl;
}

int main() {
    Node *header = nullptr;
    int n, el;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> el;
        insertAtEnd(header, el);
    }
    printList(header);
    deleteAtBeginning(header);
    printList(header);

    // int pos;
    // cin >> pos >> el;
    // insertAtPosition(header, el, pos);
    // printList(header);

    // cin >> pos;
    // deleteAtPosition(header, pos);
    // printList(header);

    cin >> el;
    deleteByValue(header, el);
    printList(header);
}
