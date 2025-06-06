#include <iostream>
#include <string>

int to_oct(long long num)
{
    std::string result;

    while (num != 0)
    {
        result += std::to_string(num % 8);
        num /= 8;
    }

    std::reverse(result.begin(), result.end());

    return std::stoi(result);
}

std::string to_hex(long long num)
{
    std::string result;

    while (num != 0)
    {
        int current_mod = num % 16;

        switch (current_mod)
        {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            result += std::to_string(current_mod);
            break;
        case 10:
            result += 'A';
            break;
        case 11:
            result += 'B';
            break;
        case 12:
            result += 'C';
            break;
        case 13:
            result += 'D';
            break;
        case 14:
            result += 'E';
            break;
        case 15:
            result += 'F';
            break;
        }

        num /= 16;
    }
    std::reverse(result.begin(), result.end());

    return result;
}



int main()
{
    long long num;

    int num_sys;

    std::cout << "Hi! Welcome to program for conversion from decimal to octal and hexadecimal number systems!" << std::endl;
    while (true)
    {
        std::cout << "Enter number: ";
        std::cin >> num;
        std::cout << "Choose number system." << std::endl;
        std::cout << "1 - octal (8)" << std::endl;
        std::cout << "2 - hexadecimal (16)" << std::endl;
        std::cin >> num_sys;

        switch (num_sys)
        {
        case 1:
            std::cout << to_oct(num);
            break;
        case 2:
            std::cout << to_hex(num);
            break;
        }

        std::cout << "" << std::endl;
    }
    
}
