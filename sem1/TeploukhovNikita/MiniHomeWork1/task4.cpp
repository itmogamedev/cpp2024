#include <iostream>

int main()
{
    int num;
    int revd_num = 0;
    
    std::cout << "Number reverse\nEnter your number: ";
    std::cin >> num;
    std::cout << "Reversed number: ";

    while (num != 0) {
        revd_num += num % 10;
        num -= num % 10;
        num /= 10;
        if (num != 0) {
            revd_num *= 10;
        }
    }

    std::cout << revd_num << std::endl;

    return 0;
}
