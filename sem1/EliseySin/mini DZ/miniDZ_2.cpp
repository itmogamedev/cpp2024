#include <iostream>

void HypothesisSyracuse(int n) 
{
    if (n <= 0) 
    {
        std::cout << "Ошибка: Введите положительное целое число!" << std::endl;
        return;
    }
    
    std::cout << "Последовательность для числа " << n << ": ";
    while (n != 1) 
    {
        std::cout << n << " ";
        if (n % 2 == 0) 
        {
            n /= 2;
        } 
        else 
        {
            n = (3 * n + 1) / 2;
        }
    }
    std::cout << n << std::endl;
    std::cout << "Гипотеза подтверждена!" << std::endl;
}

int main() 
{
    int number;
    
    std::cout << "Введите положительное целое число: ";
    std::cin >> number;

    HypothesisSyracuse(number);
    return 0;
}
