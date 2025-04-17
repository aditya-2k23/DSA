#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;

    int total_size = 0;
    int arrays[10000];
    int index = 0;

    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;
        total_size += n;

        for (int j = 0; j < n; j++)
            cin >> arrays[index++];
    }

    for (int i = 0; i < total_size - 1; i++)
        for (int j = 0; j < total_size - i - 1; j++)
            if (arrays[j] < arrays[j + 1]) {
                int temp = arrays[j];
                arrays[j] = arrays[j + 1];
                arrays[j + 1] = temp;
            }

    for (int i = 0; i < total_size; i++)
        cout << arrays[i] << " ";

    return 0;
}
