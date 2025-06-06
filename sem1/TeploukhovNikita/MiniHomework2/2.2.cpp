#include <iostream>

int num;

void check();

int main()
{
    std::cout << "Let's check Syracuse hypothesis: any your number must be converted to 1" << std::endl;
    std::cout << "Enter your number: ";
    std::cin >> num;
    while (num != 1){
        check();
    }
}

void check() {
    if (num % 2 == 0) {
        num /= 2;
        std::cout << num << std::endl;
    }
    else {
        num *= 3;
        num += 1;
        num /= 2;
        std::cout << num << std::endl;
    }

}