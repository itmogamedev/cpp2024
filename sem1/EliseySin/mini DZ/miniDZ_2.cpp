#include <iostream>

void gipotizaSirakuzi(int n) 
{
    if (n <= 0) 
    {
        std::cout << "Введите положительное целое число: " << std::endl;
        return;
    }
    std::cout << "Последовательность для числа " << n << ": ";

    while (n != 1) {
        std::cout << n << " ";
        if (n % 2 == 0) 
        {
            n /= 2;
        } 
        else 
        {
            n = 3 * n + 1;
        }
    }
    std::cout << n << std::endl;
}
int main() 
{
    int chislo;
    
    std::cout << "Введите положительное целое число: ";
    std::cin >> chislo;

    gipotizaSirakuzi(chislo);
}