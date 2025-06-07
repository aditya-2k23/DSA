#include <iostream>
using namespace std;

int main() {
    // * Insertion: At the Beginning

    // int array[10] = {1, 2, 3, 4, 5};
    // int newElement = 7;

    // for (int i = 5; i >= 1; i--) {
    //     array[i] = array[i - 1];
    // }
    // array[0] = newElement;

    // for (int i = 0; i < 6; i++) {
    //     cout << array[i] << " ";
    // }
    // ? Output: 0 1 2 3 4 5

    // * Insertion: At the End
    /*
    int array[10] = {1, 2, 3, 4, 5};
    int newElement = 6;

    cout << array[5] << endl;

    int size = 0;
    while (size < 10 && array[size] != 0) {
        size++;
    }

    array[size] = newElement;

    for (int i = 0; i < 6; i++) {
        cout << array[i] << " ";
    } // ? Output: 1 2 3 4 5 6
    */

    // * Insertion: At the Specified Position
    /*
    int array[10] = {1, 2, 3, 4, 5};
    int newElement = 0;
    int position = 2;

    int size = 5;

    for (int i = size; i > position; i--) {
        array[i] = array[i - 1];
    }

    array[position] = newElement;
    size++;

    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    } // ? Output: 1 2 0 3 4 5
    */

    // * Deletion: At the Beginning
    /*
    int array[10] = {1, 2, 3, 4, 5};
    int size = 5;

    for (int i = 0; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    // cout << array[size - 1] << endl; // ? 5
    size--;

    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    } // ? Output: 2 3 4 5
    */

    // * Deletion: At the End
    /*
    int array[10] = {1, 2, 3, 4, 5};
    int size = 5;

    array[size - 1] = 0;
    size--;

    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    } // ? Output: 1 2 3 4
    */

    // * Deletion: At the Specified Position
    /*
    int array[10] = {1, 2, 3, 4, 5};
    int size = 5;
    int position = 2;

    for (int i = position; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;

    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    } // ? Output: 1 2 4 5
    */

    // * Merging Two Arrays
    /*
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {6, 7, 8, 9, 10};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int mArr[size1 + size2];

    for (int i = 0; i < size1; i++) {
        mArr[i] = arr1[i];
    }

    for (int i = 0; i < size2; i++) {
        mArr[size1 + i] = arr2[i];
    }

    for (int i = 0; i < size1 + size2; i++) {
        cout << mArr[i] << " ";
    } // ? Output: 1 2 3 4 5 6 7 8 9 10
    */

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++) {
        arr[i] *= 2;
        cout << arr[i] << " ";
    }

    return 0;
}
