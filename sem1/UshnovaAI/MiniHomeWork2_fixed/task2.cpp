#include <iostream>

int main()
{
    while (1) {
        std::cout << "Enter any natural number\n";
        int num;
        std::cin >> num;
        while (num > 1) {
            if (num % 2 == 0) {
                num = num / 2;
                std::cout << num << std::endl;
            }
            else if (num % 2 == 1) {
                num = (num * 3 + 1) / 2;
                std::cout << num << std::endl;
            }
        }
    }
    return 0;
}