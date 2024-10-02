#include <iostream>

int main() {
    int n;
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите натуральное число: ";
    std::cin >> n;
    if (n <= 0) {
        std::cout << "Ошибка: введите натуральное число." << std::endl;
        return 1;
    }

    std::cout << "Результат проверки гипотезы: " << std::endl;
    
    while (n != 1) {
        std::cout << n << " ";

        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = (n * 3 + 1);
        }
    }
    std::cout << n << std::endl;
    return 0;
}