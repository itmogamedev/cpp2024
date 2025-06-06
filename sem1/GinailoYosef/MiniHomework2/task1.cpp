#include <iostream>
#include <cmath>

std::string convertNumber(int number, int base){
    std::string tempResult, result;

    while (number != 0){
        int remainder = number % base;

        if (remainder > 9){ 
            tempResult += (char)(remainder + 55); 
        } else { 
            tempResult += (char)(remainder + 48); 
        };

        number = round(number / base);
    };

    for (int i = tempResult.length()-1; i >= 0; i--){ 
        result += tempResult[i]; 
    };

    return result;
};

int main(){
    while (true) {
        std::cout << "Do you want to convert number to:\n1. octal number\n2. hexadecimal number\nYour choice: ";

        int input, number;
        std::cin >> input;

        if (input != 1 && input != 2){ 
            std::cout << "Thats not an option\n\n"; 

        } else {
            std::cout << "Enter a natural number: ";
            std::cin >> number;

            if (number <= 0) {
                std::cout << "This number is not a natural number\n\n";
            } else {
                std::cout << "Result: " << convertNumber(number, input * 8) << "\n\n";
            };
        };
    };
};