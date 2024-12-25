#include <iostream>
#include <math.h>

int number_length(int number) {
    int num_length = 0;

    for (; number > 0; num_length++) { // число, начинающиеся с ноля считается числом без него
        number /= 10;
    }
    return num_length;
}

int number_backwards_that_returns_number(int given_num) {
    long double new_num = 0;

    for (int num_length = number_length(given_num); num_length > 0; num_length--) {
        new_num += (given_num % 10) * pow(10, num_length - 1);
        given_num /= 10;
    }

    return new_num;
}

void number_backwards(int number) {

    while (number > 0) { // число, начинающиеся с ноля считается числом без него
        std::cout << number % 10;
        number /= 10;
    }
}


int main()
{
    int given_num;
    std::cout << "Enter the number: ";
    std::cin >> given_num;

    std::cout << "\nsimple method:" << std::endl;
    number_backwards(given_num);

    std::cout << "\n\nmethod that returns a number:\n" << number_backwards_that_returns_number(given_num) << std::endl;
}
