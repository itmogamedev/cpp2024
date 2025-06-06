

#include <iostream>
int number = 0;
int counter = 1;
int a = 1;
int b = 1;
int c = 0;
int main()
{
    std::cout << "Введите номер: ";
    std::cin >> number;
    while (counter <= number) {
        std::cout << a << " ";
        counter = counter + 1;
        c = a + b;
        a = b;
        b = c;
    }
}

