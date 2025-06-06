#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    int firstnumber = 0, secondnumber = 1, thirdnumber, amount, counter = 0;
    std::cout << "Введите количество элементов числа Фибоначчи:";
    std::cin >> amount;
    std::cout << firstnumber << " " << secondnumber << " ";
    for (counter; amount - 1 > counter; ++counter) {
        thirdnumber = firstnumber + secondnumber;
        firstnumber = secondnumber;
        secondnumber = thirdnumber;
        std::cout << thirdnumber << " ";
    }
}
