#include <iostream>
void displayFibonacciNumbers(int numbersCount);
int main()
{
    int numbersCount = 0;
    std::cout << "Введите количество чисел Фибоначчи" << std::endl;
    std::cin >> numbersCount;
    displayFibonacciNumbers(numbersCount);
}
void displayFibonacciNumbers(int numbersCount){
    if (numbersCount == 1){
        std::cout << "0";
    } else if (numbersCount == 2){
        std::cout << "0" << std::endl;
        std::cout << "1";
    } else {
        int firstNumber = 0;
        int firstNumberDublicate = 0;
        int secondNumber = 1;
        std::cout << "0" << std::endl;
        std::cout << "1" << std::endl;
        for (int i = 0; i < numbersCount-2; i++){
            std::cout << firstNumber + secondNumber << std::endl;
            firstNumberDublicate = firstNumber;
            firstNumber = secondNumber;
            secondNumber = firstNumberDublicate + secondNumber;
        }
    }
}