#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int element) : data(element), next(nullptr) {}
};

void insertAtEnd(Node *&head, int element) {
    Node *newNode = new Node(element);

    if (head == nullptr)
        head = newNode;
    else {
        Node *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}

void printList(Node *head) {
    if (head == nullptr) {
        cout << "Linked List is empty.\n";
        return;
    }

    cout << "Linked List: ";
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr)
            cout << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node *head = nullptr;
    int element;

    while (true) {
        cin >> element;

        if (element < 0)
            break;

        insertAtEnd(head, element);
    }

    printList(head);

    return 0;
}
