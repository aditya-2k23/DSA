#include <cmath>
#include <iostream>
#include <windows.h>
using namespace std;

void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 0)
        return;

    towerOfHanoi(n - 1, from, aux, to);

    cout << "Move disk " << n << " from " << from << " to " << to << endl;

    towerOfHanoi(n - 1, aux, to, from);
}

int toh(int n, int from, int to, int aux) {
    if (n == 1) {
        cout << "Move disk 1 from rod " << from << " to rod " << to << endl;
        return 1;
    }

    int count = 0;
    count += toh(n - 1, from, aux, to);
    cout << count << endl;
    cout << "Move disk " << n << " from rod " << from << " to rod " << to << endl;
    // Sleep(5000);
    count++;
    count += toh(n - 1, aux, to, from);
    // Sleep(5000);

    return count;
}

int main() {
    int n;
    cin >> n;

    towerOfHanoi(n, 'A', 'C', 'B');
    cout << "Total number of moves: " << pow(2, n) - 1;
    // cout << "Total number of moves: " << toh(n, 1, 3, 2) << endl;

    return 0;
}
