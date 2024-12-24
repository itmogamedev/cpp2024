#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    int firstnumber = 0, secondnumber = 0;
    std::cout << "Введите число:";
    std::cin >> firstnumber;
    while (firstnumber > 0) {
        secondnumber *= 10;
        secondnumber += firstnumber % 10;
        firstnumber /= 10;
    }
    std::cout << secondnumber;
}
