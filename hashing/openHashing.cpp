// ! Open Hashing

// ? What is open hashing?
// * Open hashing is a collision resolution technique that stores all the colliding keys in the same slot of the hash table.

// ? How does open hashing work?
// * Open hashing uses linked lists to store all the colliding keys in the same slot of the hash table.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void readKeys(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void initialize(Node *hashTable[], int TABLE_SIZE) {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;
}

int division(int key, int TABLE_SIZE) {
    return key % TABLE_SIZE;
}

void printKeys(Node *hashTable[], int TABLE_SIZE) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *temp = hashTable[i];
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}

void insertKeys(Node *hashTable[], int TABLE_SIZE, int keys[], int n) {
    for (int i = 0; i < n; i++) {
        int key = keys[i];
        int hashIndex = division(key, TABLE_SIZE);

        Node *newNode = new Node;
        newNode->data = key;
        newNode->next = NULL;

        if (hashTable[hashIndex] == NULL)
            hashTable[hashIndex] = newNode;
        else {
            Node *temp = hashTable[hashIndex];
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

int main() {
    int TABLE_SIZE = 10;

    int n;
    cin >> n;
    int keys[n];
    Node *hashTable[TABLE_SIZE];
    readKeys(keys, n);

    initialize(hashTable, TABLE_SIZE);

    insertKeys(hashTable, TABLE_SIZE, keys, n);

    printKeys(hashTable, TABLE_SIZE);

    return 0;
}
