#include <iostream>
#include <string>

int main()
{
    int num;

    std::cout << "enter any number: ";
    std::cin >> num;
    std::cout << std::endl;

    while (num != 1) {
        switch (num % 2) {
        case 0:
            num /= 2;
            break;
        case 1:
            num = (num * 3 + 1) / 2;
            break;
        }

        std::cout << "now your number is " << num << std::endl;
    }

    std::cout << "\nCollatz conjecture turned out to be correct this time" << std::endl;

    return 0;
}