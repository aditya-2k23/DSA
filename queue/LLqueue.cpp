// ! Queue is a linear data structure that follows the First In First Out (FIFO) principle.

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int el) : data(el), next(NULL) {}
};

class Queue {
private:
    Node *front;
    Node *rear;

public:
    Queue() : front(NULL), rear(NULL) {}

    void enqueue(int el) {
        Node *newNode = new Node(el);
        if (front == NULL && rear == NULL) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow" << endl;
            return;
        }

        Node *temp = front;
        front = front->next;
        delete temp;
    }

    void display() {
        Node *temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Queue q;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int el;
        cin >> el;
        q.enqueue(el);
    }

    cout << "Queue: ";
    q.display();

    cout << "Dequeue: ";
    q.dequeue();

    q.display();

    return 0;
}
