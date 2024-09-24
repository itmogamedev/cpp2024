#include <iostream>

int main() {
    int a;
    std::cin >> a;
    int b[10000];
    b[0] = 0;
    b[1] = 1;
    for (int i = 0; i < a; i++) {
        if (i >= 2) {
            b[i] = b[i - 1] + b[i - 2];
        }
        std::cout << b[i] << " ";
    }
    return 0;
}