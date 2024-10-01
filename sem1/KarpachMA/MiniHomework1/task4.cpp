#include <iostream>
int numberBackwards(int number);
int main()
{
    int number = 0;
    std::cout << "Введите число" << std::endl;
    std::cin >> number;
    std::cout << "Число наоборот это ";
    std::cout << numberBackwards(number);
}
int numberBackwards(int number){
    int numberLength = 0;
    int numberDublciate = number;
    int transformedNumber = 0;
    while (number > 0)
    {
        numberLength++;
        number /= 10;
    }
     while (numberDublciate > 0)
    {
        transformedNumber += ((pow(10, numberLength - 1)) * (numberDublciate % 10));
        numberDublciate /= 10;
        numberLength--;
    }

    return transformedNumber;
}
