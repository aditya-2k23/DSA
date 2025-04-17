#include <iostream>
using namespace std;

void readKeys(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void initialize(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = -1;
}

int division(int key, int TABLE_SIZE) {
    return key % TABLE_SIZE;
}

void printKeys(int arr[], int n) {
    for (int i = 0; i < n; i++)
        if (arr[i] != -1)
            cout << i << " ";
}

void insertKeys(int hashTable[], int TABLE_SIZE, int keys[], int n) {
    for (int i = 0; i < n; i++) {
        int key = keys[i];
        int hashIndex = division(key, TABLE_SIZE);

        while (hashIndex < TABLE_SIZE) {
            if (hashTable[hashIndex] == -1) {
                hashTable[hashIndex] = key;
                break;
            } else
            
                hashIndex = (hashIndex + 1) % TABLE_SIZE;
        }
    }
}

int main() {
    int TABLE_SIZE = 10;

    int n;
    cin >> n;
    int keys[n];
    int hashTable[TABLE_SIZE];
    readKeys(keys, n);

    initialize(hashTable, TABLE_SIZE);

    insertKeys(hashTable, TABLE_SIZE, keys, n);

    printKeys(hashTable, TABLE_SIZE);

    return 0;
}
