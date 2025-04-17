/*
Rishi is working on a program that manages a hash table to store a set of integer keys. He wants to implement a hash table of fixed size (10) and has asked for your help to develop the code.

Your task is to assist him in implementing this functionality with collision resolution and provide the first and last key values, along with their respective indices, in the hash table.

Input format :
The first line of input consists of an integer, N, denoting the number of keys to be inserted into the hash table.

The second line of input consists of a space-separated integer, representing the keys to be inserted.

Output format :
The output displays two lines, each containing the index and value of the first and last keys in the hash table, in the following format:

"First index: <index>, Value: <value>"
"Last index: <index>, Value: <value>"


Refer to the sample output for the formatting specifications.

Code constraints :
table size = 10

1 <= n <= 10

1<= keys <= 106

Sample test cases :
Input 1 :
6
1024 1056 2045 3145 1210 3512
Output 1 :
First index: 0, Value: 1210
Last index: 7, Value: 3145
Input 2 :
6
1230 1123 1450 1256 1425 1520
Output 2 :
First index: 0, Value: 1230
Last index: 6, Value: 1256
*/

#include <iostream>
using namespace std;

void readKeys(int keys[], int numKeys) {
    for (int i = 0; i < numKeys; i++)
        cin >> keys[i];
}

void initializeHashTable(int hashTable[], int tableSize) {
    for (int i = 0; i < tableSize; i++)
        hashTable[i] = -1;
}

int hashFunction(int key, int tableSize) {
    return key % tableSize;
}

void insertKeys(int hashTable[], int tableSize, int keys[], int numKeys) {
    for (int i = 0; i < numKeys; i++) {
        int index = hashFunction(keys[i], tableSize);
        while (hashTable[index] != -1)
            index = (index + 1) % tableSize;
        hashTable[index] = keys[i];
    }
}

void findFirstAndLast(int hashTable[], int tableSize, int &first, int &last, int &firstIndex, int &lastIndex) {
    first = -1;
    last = -1;
    firstIndex = -1;
    lastIndex = -1;

    for (int i = 0; i < tableSize; i++)
        if (hashTable[i] != -1) {
            if (first == -1) {
                first = hashTable[i];
                firstIndex = i;
            }
            last = hashTable[i];
            lastIndex = i;
        }
}

int main() {
    const int tableSize = 10;
    int numKeys;
    cin >> numKeys;

    int keys[numKeys];
    readKeys(keys, numKeys);

    int hashTable[tableSize];
    initializeHashTable(hashTable, tableSize);

    insertKeys(hashTable, tableSize, keys, numKeys);

    int first, last, firstIndex, lastIndex;
    findFirstAndLast(hashTable, tableSize, first, last, firstIndex, lastIndex);

    if (first != -1 && last != -1) {
        cout << "First index: " << firstIndex << ", Value: " << first << endl;
        cout << "Last index: " << lastIndex << ", Value: " << last << endl;
    }

    return 0;
}
