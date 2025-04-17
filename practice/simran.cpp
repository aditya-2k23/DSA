#include <bits/stdc++.h>
using namespace std;

int main() {
    int el;
    vector<int> arr;
    do {
        cin >> el;
        arr.push_back(el);
    } while (el != -1);

    int n = arr.size();

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        if (arr[i] == -1)
            continue;
        cout << arr[i] << " ";
    }

    return 0;
}
