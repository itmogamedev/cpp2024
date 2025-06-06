#include <iostream>
#include<iomanip>
#include<cmath>


int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "Введите число которое хотите перевернуть: ";
    long long n; std::cin >> n;
    long long tmp = n;
    long long l = 1, r = 10;
    long long result = 0;

    while (tmp > 0) {
        tmp /= 10;
        l *= 10;
    }
    while (l > 1) {
        result += ((n % r) / (r / 10)) * l;
        l /= 10;
        r *= 10;
    }
    result /= 10;
    std::cout << result;
    return 0;
}