#include <iostream>
#include<iomanip>
#include<cmath>

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "Введите количество чисел Фибоначчи: ";
    int n; std::cin >> n;
    int prev = 0;
    int cur = 1;

    std::cout << 0 << ' ';

    for (int i = 0; i < n; ++i) {
        int tmp = prev;

        std::cout << cur << ' ';
        prev = cur;
        cur += tmp;
    }

    return 0;
}