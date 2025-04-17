// ! Hashing

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    for (auto x : mp)
        cout << x.first << " " << x.second << endl;

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << mp[x] << endl;
    }

    return 0;
}

// Input
// 5
// 1 2 3 4 5

// Output
// 1 1
// 2 1
// 3 1
// 4 1
// 5 1

// Time Complexity: O(n)
// Space Complexity: O(n)
