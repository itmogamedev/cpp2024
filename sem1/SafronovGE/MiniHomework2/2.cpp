#include <iostream>

bool Sirakuza(int number) {
    while (true)
    {
        if (number == 1) {
            return true;
        }
        else if (number < 1) {
            return false;
        }
        else if (number % 2 == 0) {
            number /= 2;
        }
        else {
            number = ((number * 3) + 1) / 2;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int number;

    std::cin >> number;
    if (Sirakuza(number) == true) {
        std::cout << "Число подтвердило теорию!";
    }
    else {
        std::cout << "Число неподтвердило теорию!";
    }
}

