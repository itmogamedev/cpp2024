#include <iostream>

bool check_syracuse_hypothesis(int n) {

    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        }
        else {
            n = (n * 3 + 1) / 2;
        }

        std::cout << "N = "<<  n << '\n';
    }
    
    return true;
}

int main() {
    int user_number;

    std::cout << "Enter the number: ";
    std::cin >> user_number;
    
    if (check_syracuse_hypothesis(user_number))
    {
        std::cout << "The hypothesis is correct" << '\n';
    }
    
    return 0;
}