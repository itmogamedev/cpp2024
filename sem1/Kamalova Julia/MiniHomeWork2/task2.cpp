
#include<iostream>
int main() {
    setlocale(LC_ALL, "RUS");
    int x;
    std::cout << "Введите число: ";
    std::cin >> x;

    while (x != 1) {
        if (x % 2 == 0) {
            x /= 2;
            std::cout << x << " ";
        }
        else {
            x = (x * 3) + 1;
            std::cout << x << " ";
        }
    }
    std::cout << std::endl;
    std::cout << "Гипотеза верна";
    return 0;
}
