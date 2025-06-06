#include <iostream>

void printFibonacciSequence(int ke) 
{
    int e0 = 0;
    int e1 = 1;
    int enext;

    if (ke >= 1) 
    {
        std::cout << e0 << " ";
    }
    if (ke >= 2) 
    {
        std::cout << e1 << " ";
    }

    for (int b = 3; b <= ke; b++) 
    {
        enext = e0 + e1;
        e0 = e1;
        e1 = enext;

        std::cout << enext << " ";
    }
}

int main() 
{
    int ke;
    std::cout << "Введите кол-во элементов последовательности Фибоначчи: ";
    std::cin >> ke;

    printFibonacciSequence(ke);
    return 0;
}
