

#include <iostream>

int main() {
    int n;

    std::cout << "Enter a number: ";
    
    if (!(std::cin >> n) or n == 0) {
        std::cout << "OOPS! Invalid " << std::endl;
        return 1;
    }
    else {
        std::cout << "The Syracuse Sequence: " << n << " ";


        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;
            }
            else {
                n = (3 * n + 1) / 2;
            }
            std::cout << n << " ";
        }


        std::cout << "  Congratulations!" << std::endl;

        return 0;
    }
}