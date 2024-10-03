#include <iostream>

int main()
{
    int num;
    std::cout << "Enter number to use it on Syracuse hypothesis: ";
    std::cin >> num;
    while (num != 1) {
        if ((num % 2) == 1) {
            num = num * 3 + 1;
        }
        num /= 2;
        std::cout << "Current number: " << num << std::endl;
    }
    std::cout << "Hypothesis is correct";
    return 0;
}