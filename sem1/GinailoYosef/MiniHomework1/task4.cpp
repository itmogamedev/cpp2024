#include <iostream>

void printReverseDigits(int number){
    while (number >= 10){
        std::cout << number % 10;
        number /= 10;
    };

    std::cout << number;
};

int main(){
    int number;
    std::cin >> number;
    printReverseDigits(number);
};