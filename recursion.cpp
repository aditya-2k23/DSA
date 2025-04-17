#include <iostream>
using namespace std;

int sumOfnNumbers(int n) {
    if (n == 0)
        return 0;
    return n + sumOfnNumbers(n - 1);
}

int main() {
    int n;
    cin >> n;

    cout << sumOfnNumbers(n) << endl;

    return 0;
}
