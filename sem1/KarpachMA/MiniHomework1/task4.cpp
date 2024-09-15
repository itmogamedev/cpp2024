#include <iostream>
void numberBackwards(int number);
int main()
{
    int number = 0;
    std::cout << "Введите число" << std::endl;
    std::cin >> number;
    numberBackwards(number);
}
void numberBackwards(int number){
    while (number > 0){
        std::cout << number % 10;
        number /= 10;
    }
}