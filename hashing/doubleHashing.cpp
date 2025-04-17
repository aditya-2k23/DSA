#include <iostream>
using namespace std;

// ! Double hashing

// * What is double hashing?
// TODO: Double hashing is a collision resolution technique in open addressing. It uses two hash functions to calculate the index of the next slot to be probed.

// * How does double hashing work?
// TODO: The first hash function calculates the initial index of the key. If the slot is already occupied, the second hash function is used to calculate the next slot to be probed. This process continues until an empty slot is found.

int main() {
    int TABLE_SIZE = 10;

    int n;
    cin >> n;

    int keys[n];
    int hashTable[TABLE_SIZE];

    for (int i = 0; i < n; i++)
        cin >> keys[i];

    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;

    for (int i = 0; i < n; i++) {
        int key = keys[i];
        int hashIndex = key % TABLE_SIZE;

        while (hashTable[hashIndex] != -1)
            hashIndex = 1 + (key % (TABLE_SIZE - 1));

        hashTable[hashIndex] = key;
    }

    for (int i = 0; i < TABLE_SIZE; i++)
        if (hashTable[i] != -1)
            cout << i << " ";

    return 0;
}
