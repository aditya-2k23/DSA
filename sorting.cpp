#include <iostream>
using namespace std;

class Sorting {
private:
  void merge(int arr[], int low, int mid, int high) {
    int newArr[high+1];
    int c = 0;
    int left = low, right = mid+1;
    
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right])
          newArr[c++] = arr[left++];
        else
          newArr[c++] = arr[right++];
    }
    
    while (left <= mid)
      newArr[c++] = arr[left++];
    while (right <= high)
      newArr[c++] = arr[right++];
     
    for (int i = low; i <= high; i++)
      arr[i] = newArr[i - low];
  }
  
  int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;
    
    while (i<j) {
        while (arr[i] <= pivot && i < high)
          i++;
        while (arr[j] > pivot && j > low)
          j--;
        if (i < j)
          swap(arr[i], arr[j]);
    }
    
    swap(arr[low], arr[j]);
    return j;
  }
    
public:
  void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
      int min = i;
      for (int j = i; j < n; j++)
        if (arr[j] < arr[min])
          min = j;
      swap(arr[min], arr[i]);
    }
  }
  
  void bubbleSort(int arr[], int n) {
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
          if (arr[j+1] < arr[j])
             swap(arr[j+1], arr[j]);
   }
   
   void insertionSort(int arr[], int n) {
       for (int i = 0; i < n; i++) {
           int j = i;
           while (j > 0 && arr[j] < arr[j - 1]) {
             swap(arr[j], arr[j - 1]);
             j--;
           }
       }
   }
   
   void mergeSort(int arr[], int low, int high) {
       if (low < high) {
           int mid = (low + high) / 2;
           mergeSort(arr, low, mid);
           mergeSort(arr, mid+1, high);
           merge(arr, low, mid, high);
       }
   }
   
   void recursiveBubbleSort(int arr[], int n) {
       if (n == 1) return; 
       for (int i = 0; i < n - 1; i++)
         if (arr[i] > arr[i+1])
           swap(arr[i], arr[i+1]); 
       recursiveBubbleSort(arr, n - 1);
   }
   
   void recursiveInsertionSort(int arr[], int i, int n) {
       if (i == n) return;
       int j = i;
       while (j >= 0 && arr[j-1] > arr[j]) {
         swap(arr[j-1], arr[j]);
         j--;
       }
       recursiveInsertionSort(arr, i+1, n);
   }
   
   void quickSort(int arr[], int low, int high) {
       if (low < high) {
           int pIndex = partition(arr, low, high);
           quickSort(arr, low, pIndex-1);
           quickSort(arr, pIndex+1, high);
       }
   }
};

int main() {
  int n = 7;
  int arr[7] = {56, 89, 3, 27, 62, 14, 7};
  
  Sorting sort;
  // sort.selectionSort(arr, n);
  // sort.bubbleSort(arr, n);
  // sort.insertionSort(arr, n);
  // sort.mergeSort(arr, 0, n - 1);
  // sort.recursiveBubbleSort(arr, n);
  // sort.recursiveInsertionSort(arr, 0, n);
  sort.quickSort(arr, 0, n-1);
  
  for (int i : arr)
    cout << i << " ";

  return 0;
}