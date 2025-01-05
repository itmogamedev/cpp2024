#include <iostream>
#include <string>
#include <sstream>


std::string to_hex(const int x) {
    std::stringstream ss;
    ss << std::hex << x;
    return ss.str();
    
}

std::string to_oct(const int x) {
    std::stringstream ss;
    ss << std::oct << x;
    return ss.str();
}

int main() {
    int user_number;
    
    std::cout << "Enter the number: ";
    std::cin >> user_number;
    
    const std::string hex = to_hex(user_number);
    const std::string oct = to_oct(user_number);
    
    std::cout << "HEX: " << hex << '\n';
    std::cout << "OCT: " << oct << '\n';

    /* Simple solution
    std::cout << "HEX: " << std::hex << user_number << '\n';
    std::cout << "OCT: " << std::oct << user_number << '\n';
    */
    
    return 0;
}