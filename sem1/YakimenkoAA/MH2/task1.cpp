#include <iostream>
#include <string>

std::string sixteen(int number);

std::string eight(int number);

int main()
{
    int number;
    std::cout << "Enter number:";
    std::cin >> number;
    std::cout << "8: "<< eight(number) << std::endl;
    std::cout << "16 :" << sixteen(number) << std::endl;
    return 0;
}

std::string eight(int number) {
    std::string result = "";
    while (number != 0) {
        result = std::to_string(number % 8) + result;
        number = number / 8;
    }
    return result;
}
std::string sixteen(int number) {
    std::string result = "";
    while (number > 0) {
        if (number % 16 < 10) {
            result = std::to_string(number % 16) + result;
            number = number / 16;
        }
        else {
            result = (char)(number % 16 + 'A' - 10) + result;
            number = number / 16;
        }
    }
    return result;
}