#include <iostream>

int nums_amount;


int main()
{
    std::cout << "Fibonacci sequence output \nEnter number of Fibonacci numbers: ";
    std::cin >> nums_amount;
    std::cout << "Your sequence: " << std::endl;


    if (nums_amount > 1 or nums_amount < -1) {
        std::cout << 0 << std::endl << 1 << std::endl;
    }
    else if(nums_amount != 0) {
        std::cout << 0;
    }
    else {
             std::cout << "Nothing here...\n";
    }


    if (nums_amount > 1) {
        int num1 = 0;
        int num2 = 1;

        while (nums_amount > 2) {
            int summ = num2 + num1;
            std::cout << summ << std::endl;
            num1 = num2;
            num2 = summ;

            nums_amount -= 1;
        }
    }

    else if(nums_amount < -1) {
        int num1 = 1;
        int num2 = 0;

        while (nums_amount < -2) {
            int def = num2 - num1;
            std::cout << def << std::endl;
            num2 = num1;
            num1 = def;

            nums_amount += 1;
        }
    }

    return 0;
}
