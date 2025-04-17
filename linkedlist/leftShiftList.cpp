#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *createNode(int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    return newNode;
}

Node *insertNode(Node *head, int data) {
    if (head == nullptr)
        head = createNode(data);
    else {
        Node *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = createNode(data);
    }
    return head;
}

Node *leftShiftLinkedList(Node *head, int k) {
    if (head == nullptr || k == 0)
        return head;

    int length = 1;
    Node *temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }

    k = k % length;

    if (k == 0)
        return head;

    Node *new_tail = head;
    for (int i = 0; i < k - 1; i++)
        new_tail = new_tail->next;

    Node *new_head = new_tail->next;

    Node *current = new_head;
    while (current->next != nullptr)
        current = current->next;

    current->next = head;

    new_tail->next = nullptr;
    head = new_head;

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
    int N, k;
    cin >> N;

    Node *head = nullptr;
    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;
        head = insertNode(head, value);
    }

    cin >> k;

    head = leftShiftLinkedList(head, k);

    printList(head);

    return 0;
}
