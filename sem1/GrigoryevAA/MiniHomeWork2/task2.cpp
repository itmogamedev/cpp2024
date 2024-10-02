#include <iostream>
#include <string>


int main()
{
    long long num;


    std::cout << "Hi! Welcome to program for testing the Syracuse hypothesis!" << std::endl;
    while (true)
    {
        std::cout << "Please, enter the number: ";
        std::cin >> num;

        while (num != 1)
        {
            if (num % 2 == 0)
            {
                std::cout << num << " it's a even number, so we divide by 2" << std::endl;
                num /= 2;
                std::cout << "Result: " << num << std::endl;

            }
            else
            {
                std::cout << num << " it's a odd number, so we multiply by 3, add 1, divide by 2" << std::endl;
                num *= 3;
                num += 1;
                num /= 2;
                std::cout << "Result: " << num << std::endl;
            }
        }
        std::cout << "" << std::endl;
    }
    
    
    
    
}
