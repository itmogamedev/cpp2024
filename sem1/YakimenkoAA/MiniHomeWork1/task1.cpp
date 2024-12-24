#include <iostream>
int square(int input);

int main() {
    int input;
    std::cout << "Enter a number:";
    std::cin >> input;
    std::cout << square(input);
    return 0;
}

int square(int input) {
    return input*input;
}