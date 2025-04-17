#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int top = 0;
    int arr[n];

    for (int i = n; i > 0; i--) {
        arr[top] = i;
        top++;
    }

    for (int i = n; i > 0; i--) {
        cout << arr[top - 1] << " ";
        top--;
    }

    return 0;
}
