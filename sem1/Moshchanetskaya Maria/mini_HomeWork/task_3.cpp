
#include <iostream>

int main() //ЗАДАНИЕ 3
{
    setlocale(LC_ALL, "Russian");
    int elem_a = 1;
    int elem_b = 0;
    int elem_c = 1;
    int cnt = 1;
    int number;
    std::cout << "введите натуральное число "<< std::endl;
    std::cin >> number;
    std::cout << "ряд первых " << number << " чисел Фибоначи:" << std::endl;
    while (cnt <= number)
    {
        std::cout << ' ' << elem_c;
        elem_c = elem_a + elem_b;
        elem_b = elem_a;
        elem_a = elem_c;
        cnt++;
    }

}