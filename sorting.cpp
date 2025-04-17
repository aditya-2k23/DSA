#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
        if (arr[j] <= pivot)
            swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

class Sorting {
public:
    int n, *arr;

    void bubbleSort(int arr[], int n) { // * T.C. O(n^2), S.C. O(1)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
    }

    void selectionSort(int arr[], int n) { // * T.C. O(n^2), S.C. O(1)
        for (int i = 0; i < n - 1; i++) {
            int min = i;
            for (int j = i + 1; j < n; j++)
                if (arr[j] < arr[min])
                    min = j;
            swap(arr[i], arr[min]);
        }
    }

    void insertionSort(int arr[], int n) { // * T.C. O(n^2), S.C. O(1)
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

    void mergeSort(int arr[], int left, int right) { // * T.C. O(nlogn), S.C. O(n)
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    void quickSort(int arr[], int left, int right) { // * T.C. O(nlogn), S.C. O(log n)
        if (left < right) {
            int pivot = partition(arr, left, right);
            quickSort(arr, left, pivot - 1);
            quickSort(arr, pivot + 1, right);
        }
    }

    void heapSort(int arr[], int n) { // * T.C. O(nlogn), S.C. O(1)
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

    ~Sorting() {
        delete[] arr;
    }
} sort;

int main() {
    cin >> sort.n;
    sort.arr = new int[sort.n]; // ? dynamic memory allocation

    for (int i = 0; i < sort.n; i++)
        cin >> sort.arr[i];

    // * -------------------------------------
    // sort.bubbleSort(sort.arr, sort.n);
    // sort.selectionSort(sort.arr, sort.n);
    // sort.insertionSort(sort.arr, sort.n);
    // sort.mergeSort(sort.arr, 0, sort.n - 1);
    // sort.quickSort(sort.arr, 0, sort.n - 1);
    sort.heapSort(sort.arr, sort.n);
    // * -------------------------------------

    for (int i = 0; i < sort.n; i++)
        cout << sort.arr[i] << " ";

    delete[] sort.arr; // ? dynamic memory deallocation

    return 0;
}
