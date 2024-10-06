#include <iostream>
using namespace std;

int fibonachi(int n, int t1, int t2, int next) {
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            cout << t1 << ", ";
        }
        if (i == 2) {
            cout << t2 << ", ";
        }
        next = t1 + t2;
        t1 = t2;
        t2 = next;

        cout << next << ", ";
    }
    return 1;
}

int main() {
    int n, number_1 = 0, number_2 = 1, next_number = 0;
    cout << "Enter N: ";
    cin >> n;
    cout << "Fibonacci Series: ";
    cout << fibonachi(n, number_1, number_2, next_number);
}
