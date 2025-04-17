#include <iostream>
using namespace std;

// Circular header linked list
struct Node {
    int data = 0;
    Node *next;

    Node(int el) : data(el), next(nullptr) {}
};

void insertAtEnd(Node *&header, int el) {
    Node *newNode = new Node(el);
    Node *temp = header->next;
}

void printList(Node *header) {
    Node *temp = header->next;
    cout << "List: ";
    while (temp != header) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "Number of elements: " << header->data << endl;
}

int main() {
    int n, el;
    cin >> n;

    Node *header = new Node(0);

    for (int i = 0; i < n; i++) {
        cin >> el;
        insertAtEnd(header, el);
    }
    printList(header);
}
