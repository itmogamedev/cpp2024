#include <iostream>

int main()
{
    std::cout << "Let's check the Syracuse hypothesis!" << std::endl;

    int num;
    while (true)
    {
        std::cout << "Enter any integer (type 1 for exit): ";
        std::cin >> num;

        if (num == 1)
            return 0;

        while (num != 1)
        {
            if (num % 2 == 0)
                num /= 2;
            else
                num = (num * 3 + 1) / 2;
        }

        std::cout << "Wow! It's work!" << std::endl;
    }
}