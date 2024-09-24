#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    int N;
    std::cout << "Введите количество элементов ряда Фибоначчи: ";
    std::cin >> N;
    int a = 0;
    int b = 1;
    int buffer;

    for (int i = 0; i < N; ++i) {
        if (i == 0) {
            std::cout << a << " ";
            continue;
        }
        if (i == 1) {
            std::cout << b << " ";
            continue;
        }
        buffer = a + b;
        a = b;
        b = buffer;
        std::cout << buffer << " ";
    }

    return 0;
}