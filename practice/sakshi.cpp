#include <iostream>
#include <string>
using namespace std;

// struct Node {
//     int data;
//     Node *next;

//     Node(int el) : data(el), next(nullptr) {}
// };

// // circular header linked list
// void insertAtEnd(Node *&header, int el) {
//     Node *newNode = new Node(el);
//     Node *temp = header;

//     if (header == nullptr) {
//         header = new Node(0);
//         header->next = newNode;
//         newNode->next = header;
//         header->data++;
//         return;
//     }

//     if (header->next == header) {
//         header->next = newNode;
//         newNode->next = header;
//         header->data++;
//         return;
//     }

//     while (temp->next != header)
//         temp = temp->next;
//     temp->next = newNode;
//     newNode->next = header;

//     header->data++;
// }

// void printAlternate(Node *header, int n) {
//     Node *temp = header->next;
//     cout << "Alternate: ";

//     if (n % 2 != 0) {
//         while (temp->next != header) {
//             cout << temp->data << " ";
//             temp = temp->next->next;
//         }
//         cout << temp->data;
//     } else {
//         while (temp->next->next != header) {
//             cout << temp->data << " ";
//             temp = temp->next->next;
//         }
//         cout << temp->data;
//     }
//     cout << endl;
// }

// main() {
//     int n;
//     cin >> n;

//     Node *header = nullptr;
//     for (int i = 0; i < n; i++) {
//         int el;
//         cin >> el;
//         insertAtEnd(header, el);
//     }

//     printAlternate(header, n);
// }

/*
Write a code to implement Quadratic probing in Hashing.



If the slot hash(x) % S is full, then we try (hash(x) + 1*1) % S.

If (hash(x) + 1*1) % S is also full, then we try (hash(x) + 2*2) % S.

If (hash(x) + 2*2) % S is also full, then we try (hash(x) + 3*3) % S.



This process is repeated for all the values of i until an empty slot is found.

Input format :
The first line of input consists of the size of the array.

The second line of input consists of the array of elements separated by space.

The last line of input consists of the size of the hashtable.

Output format :
The output prints the space separated array elements after implementing the conditions mentioned in the problem statement.



Refer to the sample input and output for formatting specifications.

Sample test cases :
Input 1 :
7
50 700 76 85 92 73 101
7
Output 1 :
700 50 85 73 101 92 76
Input 2 :
4
76 101 50 700
3
Output 2 :
50 76 101
*/

int hashFunction(int key, int size) {
    return key % size;
}

void insertKey(int hashTable[], int size, int key) {
    int index = hashFunction(key, size);
    int i = 0;
    while (hashTable[(index + i * i) % size] != -1)
        i++;
    hashTable[(index + i * i) % size] = key;
}

void print(int hashTable[], int size) {
    for (int i = 0; i < size; i++)
        if (hashTable[i] != -1)
            cout << hashTable[i] << " ";
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int hash_size;
    cin >> hash_size;

    int hashTable[hash_size];
    for (int i = 0; i < hash_size; i++)
        hashTable[i] = -1;

    for (int i = 0; i < hash_size; i++)
        insertKey(hashTable, hash_size, arr[i]);
    print(hashTable, hash_size);
}
