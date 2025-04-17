#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int el) : data(el), next(NULL) {}
};

class Stack {
private:
    Node *top;

public:
    Stack() : top(NULL) {}

    void push(int el) {
        Node *newNode = new Node(el);
        if (top == NULL) {
            top = newNode;
            return;
        }

        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow" << endl;
            return;
        }

        Node *temp = top;
        top = top->next;
        delete temp;
    }

    void display() {
        Node *temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Stack s;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int el;
        cin >> el;
        s.push(el);
    }

    cout << "Stack: ";
    s.display();

    cout << "Stack Popped: ";
    s.pop();
    s.pop();

    s.display();

    return 0;
}
