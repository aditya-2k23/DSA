#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int front = 0;
    int rear = 0;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[rear];
        rear++;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[front] << " ";
        front++;
    }

    return 0;
}
