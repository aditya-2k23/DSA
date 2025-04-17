// 5
// 10 20 30 40 50 -1
// 10 50 20 40 30

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    int el;
    for (int i = 0; i < n + 1; i++) {
        cin >> el;
        if (el == -1) {
            break;
        }
        arr[i] = el;
    }

    for (int i = 0; i <= n / 2; i++) {
        cout << arr[i] << " ";
        if (i == n - i - 1)
            continue;
        cout << arr[n - i - 1] << " ";
    }
}
