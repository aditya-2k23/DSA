#include <iostream>
using namespace std;

class LinkedList {
private:
    struct Node {
        int data;
        Node *next;

        Node(int element) : data(element), next(nullptr) {}
    };

    Node *head = nullptr;

public:
    void insertAtEnd(int el) {
        Node *newNode = new Node(el);

        if (head == nullptr)
            head = newNode;
        else {
            Node *temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void insertAtBeginning(int el) {
        Node *newNode = new Node(el);

        newNode->next = head;
        head = newNode;
    }

    void insertAtPosition(int el, int pos) {
        Node *newNode = new Node(el);

        if (pos == 1) {
            insertAtBeginning(el);
            return;
        } else {
            Node *temp = head;
            for (int i = 1; i < pos - 1; i++) {
                if (temp == nullptr) {
                    cout << "Position out of range.\n";
                    return;
                }
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "Linked List is empty.\n";
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "Linked List is empty.\n";
            return;
        }

        Node *temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteAtPosition(int pos) {
        if (head == nullptr) {
            cout << "Linked List is empty.\n";
            return;
        }

        Node *temp = head;
        if (pos == 1) {
            deleteAtBeginning();
            return;
        }

        for (int i = 1; i < pos - 1; i++) {
            if (temp == nullptr) {
                cout << "Position out of range.\n";
                return;
            }
            temp = temp->next;
        }
        Node *delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
    }

    void deleteByValue(int el) {
        if (head == nullptr) {
            cout << "Linked List is empty.\n";
            return;
        }

        Node *temp = head;
        if (head->data == el) {
            deleteAtBeginning();
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
        cout << "Element not found.\n";
    }

    void printList() {
        cout << "Linked List: ";
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
} List;

class Sorting {
private:
    int n;
    int *arr;

public:
    Sorting(int n) {
        this->n = n;
        arr = new int[n];
    }

    void arrInput() {
        for (int i = 0; i < n; i++)
            cin >> arr[i];
    }

    void printArr() {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
    }

    void bubbleSort() {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
    }

    void selectionSort() {
        for (int i = 0; i < n - 1; i++) {
            int min = i;
            for (int j = i + 1; j < n; j++)
                if (arr[j] < arr[min])
                    min = j;
            swap(arr[i], arr[min]);
        }
    }

    void insertionSort() {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
};

void sort() {
    int n;
    cin >> n;

    Sorting s(n);

    s.arrInput();

    // s.bubbleSort();
    // s.selectionSort();
    // s.insertionSort();

    s.printArr();
}

void linkedList() {
    cout << "Enter the number of elements: ";
    int n, element;
    cin >> n;

    if (n <= 0) {
        cout << "Linked List is empty.\n";
        return;
    }

    cout << "Enter the elements (space-separated): ";
    for (int i = 1; i <= n; i++) {
        cin >> element;
        List.insertAtEnd(element);
        // List.insertAtBeginning(element);
    }
    int pos;
    cout << "Enter the element and position to insert (space-separated): ";
    cin >> element >> pos;
    List.insertAtPosition(element, pos);

    List.printList();

    cout << "Would you like to delete any element? (y/n): ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        cout << "At which position would you like to delete the element? ";
        cin >> pos;
        if (pos == 1)
            List.deleteAtBeginning();
        else if (pos > n)
            cout << "Position out of range.\n";
        else if (pos == n)
            List.deleteAtEnd();
        else
            List.deleteAtPosition(pos);
    }

    cout << "After Deletion ";
    List.printList();

    cout << "Would you like to delete any element by value? (y/n): ";
    cin >> choice;
    if (choice == 'y') {
        cout << "Enter the element to delete: ";
        cin >> element;
        List.deleteByValue(element);
    }

    cout << "After Deletion by Value ";
    List.printList();
}

int main() {
    // sort();
    linkedList();

    return 0;
}
