#include <iostream>

int main() {
    int num, system;
    std::cout << "Enter the system of convertion \n";
    std::cout << "Enter the value you want to convert \n";
    std::cin >> system >> num;
    switch (system) {
    case 8:
        std::cout << std::oct << num;
        break;
    case 16:
        std::cout << std::hex << num;
        break;
    default: std::cout << "Sorry, you have entered an unsupported system";
    }

}