#include <iostream>
using namespace std;

class Heap {
private:
    int *arr, capacity, size;

public:
    Heap(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->arr = new int[capacity];
    }

    ~Heap() {
        delete[] arr;
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    Heap *insert(int key) {
        if (capacity == size)
            return this;

        int i = size++;
        arr[i] = key;

        while (i != 0 && arr[parent(i)] < arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }

        return this;
    }

    void maxHeapify(int i) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest = i;

        if (l < size && arr[l] > arr[i])
            largest = l;

        if (r < size && arr[r] > arr[largest])
            largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            maxHeapify(largest);
        }
    }

    void buildMaxHeap() {
        for (int i = size / 2 - 1; i >= 0; i--)
            maxHeapify(i);
    }

    void heapify(int i) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
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

    void deleteValue(int key) {
        int i = search(key);
        if (i == -1)
            return;

        arr[i] = arr[--size];
        heapify(i);
    }

    void print() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
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

    heap->print();

    cin >> el;
    heap->deleteValue(el);

    heap->print();

    delete heap;

    return 0;
}
