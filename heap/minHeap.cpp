#include <climits>
#include <iostream>
using namespace std;

// ! Min Heap
// * Time Complexity: O(log n)
// * Space Complexity: O(n)

class Heap {
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

        while (i != 0 && arr[parent(i)] > arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }

        return this;
    }

    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < size && arr[l] < arr[i])
            smallest = l;

        if (r < size && arr[r] < arr[smallest])
            smallest = r;

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }

    int search(int key) {
        for (int i = 0; i < size; i++)
            if (arr[i] == key)
                return i;

        return -1;
    }

    int extractMin() {
        if (size <= 0)
            return INT_MAX;

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

    void decreaseKey(int i, int new_val) {
        arr[i] = new_val;
        while (i != 0 && arr[parent(i)] > arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void deleteKey(int i) {
        decreaseKey(i, INT_MIN);
        extractMin();
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void printHeap() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void printArray() {
        for (int i = 0; i < capacity; i++) {
            cout << arr[i] << " ";
        }
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

    void printExtractMin() {
        cout << "Extract Min: " << extractMin() << endl;
    }

    void printDecreaseKey(int i, int new_val) {
        decreaseKey(i, new_val);
        cout << "Decrease Key: " << new_val << endl;
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
        print();
        printHeap();
        printArray();
        printSize();
        printCapacity();
        printParent(3);
        printLeft(3);
        printRight(3);
        printExtractMin();
        printDecreaseKey(2, 1);
        printDeleteKey(1);
        printInsert(3);
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

    heap->printAll();

    return 0;
}
