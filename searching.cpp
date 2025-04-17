#include <iostream>
using namespace std;

class Searching {
public:
    int linearSearch(int arr[], int n, int key) {
        for (int i = 0; i < n; i++)
            if (arr[i] == key)
                return i;

        return -1;
    }

    int binarySearch(int arr[], int n, int key) {
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == key)
                return mid;
            else if (arr[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }
};

int recursiveLinearSearch(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;
    if (arr[low] == key)
        return low;
    if (arr[high] == key)
        return high;

    return recursiveLinearSearch(arr, low + 1, high - 1, key);
}

int main() {
    Searching search;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5, result;

    result = search.linearSearch(arr, n, key);
    if (result == -1)
        cout << "Element not found" << endl;
    else
        cout << "Element found at index: " << result << endl;

    result = search.binarySearch(arr, n, key);
    if (result == -1)
        cout << "Element not found" << endl;
    else
        cout << "Element found at index: " << result << endl;

    return 0;
}
