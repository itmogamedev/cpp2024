#include <iostream>

int fibba(int input);


int main() {
    int input;
    std::cout << "Enter a number: ";
    std::cin >> input;
    std::cout << fibba(input);
    return 0;
}

int fibba(int input) {
    int first_num = 0;
    int second_num = 1;
    int result = 0;
    for (int i = 0; i < input; i++) {
        first_num = second_num;
        second_num = result;
        result = first_num + second_num;
    }
    return result;
}