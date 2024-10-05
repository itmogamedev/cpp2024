#include <iostream>

int main(){
    while (true) {
        int number;

        std::cout << "Enter a natural number\nYour number: ";
        std::cin >> number;

        int countOfTries = 0;
        if (number <= 0){
            std::cout << "This is not a natural number\n\n";
        } else {
            while (number != 1){
                countOfTries += 1;
                
                if (number % 2 == 0){
                    number /= 2;
                } else {
                    number = (number * 3 + 1)/2;
                };
            };

            std::cout << "Algorithm finished after " << countOfTries <<" actions. Result = 1\n\n";
        };
    };
};