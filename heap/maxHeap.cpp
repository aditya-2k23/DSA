#include <climits>
#include <iostream>
using namespace std;

// ! Max Heap
// * Time Complexity: O(log n)
// * Space Complexity: O(n)

class Heap {
private:
    int *arr, capacity, size;

public:
    Heap(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->arr = new int[capacity];
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    Heap *insert(int key) {
        if (size == capacity) {
            cout << "Overflow: Could not insert key" << endl;
            return this;
        }

        int i = size;
        size++;
        arr[i] = key;

        while (i != 0 && arr[parent(i)] < arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }

        return this;
    }

    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < size && arr[l] > arr[largest])
            largest = l;

        if (r < size && arr[r] > arr[largest])
            largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    void buildHeap() {
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(i);
    }

    int search(int key) {
        for (int i = 0; i < size; i++)
            if (arr[i] == key)
                return i;

        return -1;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void printHeap() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void printArray() {
        for (int i = 0; i < capacity; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void printSize() {
        cout << "Size: " << size << endl;
    }

    void printCapacity() {
        cout << "Capacity: " << capacity << endl;
    }

    void printParent(int i) {
        cout << "Parent of " << i << " is " << parent(i) << endl;
    }

    void printLeft(int i) {
        cout << "Left of " << i << " is " << left(i) << endl;
    }

    void printRight(int i) {
        cout << "Right of " << i << " is " << right(i) << endl;
    }

    int extractMax() {
        if (size <= 0)
            return INT_MIN;

        if (size == 1) {
            size--;
            return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(0);

        return root;
    }

    void increaseKey(int i, int new_val) {
        arr[i] = new_val;
        while (i != 0 && arr[parent(i)] < arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void deleteKey(int i) {
        increaseKey(i, INT_MAX);
        extractMax();
    }

    void printExtractMax() {
        cout << "Extract Max: " << extractMax() << endl;
    }

    void printIncreaseKey(int i, int new_val) {
        increaseKey(i, new_val);
        cout << "Increase Key: " << new_val << endl;
    }

    void printDeleteKey(int i) {
        deleteKey(i);
        cout << "Delete Key: " << i << endl;
    }

    void printInsert(int key) {
        insert(key);
        cout << "Insert: " << key << endl;
    }

    void printHeapify(int i) {
        heapify(i);
        cout << "Heapify: " << i << endl;
    }

    void printAll() {
        printHeap();
        printArray();
        printSize();
        printCapacity();
        printParent(2);
        printLeft(2);
        printRight(2);
        printExtractMax();
        printIncreaseKey(2, 10);
        printDeleteKey(1);
        printInsert(15);
        printHeapify(0);
    }

    ~Heap() {
        delete[] arr;
    }
};

int main() {
    int n, el;
    cin >> n;

    Heap *heap = new Heap(n);

    for (int i = 0; i < n; i++) {
        cin >> el;
        heap->insert(el);
    }

    heap->buildHeap();
    heap->printAll();

    return 0;
}
